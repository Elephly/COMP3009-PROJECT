#include <stdio.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include "windows.h"
#include "glew.h"
#include <GL/gl.h>
#include <glut.h>
#include "soil.h"
#include <wglew.h>

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif // _USE_MATH_DEFINES

#include "math.h"
#include "assert.h"
#endif

#include "MyImageUtil.h"
#include "MyGeometry.h"


/************************************************************************/

// DEFINES

#define NUM_VTX 4           /* number of end "points" to draw */


/************************************************************************/

using namespace MyGeometry;

// GLOBALS

enum MOUSE_HANDLE_TOOL
{
	MOUSE_HANDLE_TOOL_NONE,
	MOUSE_HANDLE_TOOL_SELECT,
	MOUSE_HANDLE_TOOL_PASTE,
	MOUSE_HANDLE_TOOL_BLACKHOLE,
	MOUSE_HANDLE_TOOL_EXPAND,
	MOUSE_HANDLE_TOOL_SWIRL
};
enum RIGHT_CLICK_MENU_VALUE { RIGHT_CLICK_MENU_SELECT, RIGHT_CLICK_MENU_COPY, RIGHT_CLICK_MENU_PASTE };
enum PHOTOBOOTH_SUB_MENU_VALUE { PHOTOBOOTH_SUB_MENU_BLACKHOLE, PHOTOBOOTH_SUB_MENU_EXPAND, PHOTOBOOTH_SUB_MENU_SWIRL };
enum COORDINATE_VALUE { COORDINATE_X, COORDINATE_Y, COORDINATE_Z };

// First Window
int wid1;
GLint winWidth, winHeight;   /* window width and height */
int vtx1[NUM_VTX][2];       /* array of 2D points */
MyImage *image;
MyImage *renderImage;
MyImage *imageClipboard;
MyImage *renderClipboard;
char keys[256];
char mouse[3];
int mouseCoordinates[2];
int mouseHandleTool;
int grayscaleType;
int rightClickMenu;
int photoboothSubMenu;
MyRectangle selectionRect;
MyCircle distortionCircle;

void quit();

void initGeom(char *imageFileName)
{

}

/* Called when the corresponsing window is created or resized. */
void resizeWinCB(int w, int h)
{
	/* save new screen dimensions */
	winWidth = w;
	winHeight = h;

	/* use the full view port */
	glViewport(0, 0, winWidth, winHeight);

	/* use 2D  orthographic parallel projection  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}

/* Redner funciton of window 1 */
void renderWinCB(void)
{
	int x = 0, y = 0;
	float r = 100.0f / 255.0f;
	float g = 149.0f / 255.0f;
	float b = 237.0f / 255.0f;
	float a = 1.0f;

	/* clear the window and fill it with white colour */
	//glClearColor(0.0, 0.0, 1.0, 0.0);
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);

	glRasterPos2i(x, y);
	GLubyte *buffer = renderImage->GetImageBuffer();
	glDrawPixels(renderImage->GetImageWidth(), renderImage->GetImageHeight(), GL_RGBA, GL_UNSIGNED_BYTE, (void *)(buffer));

	if (!selectionRect.IsZeroDimensional())
	{
		int red = 0, green = 0, blue = 255;
		int x1 = min(selectionRect.GetX1(), selectionRect.GetX2());
		int y1 = min(selectionRect.GetY1(), selectionRect.GetY2());
		int x2 = max(selectionRect.GetX1(), selectionRect.GetX2());
		int y2 = max(selectionRect.GetY1(), selectionRect.GetY2());
		int width = abs(selectionRect.GetWidth());
		int height = abs(selectionRect.GetHeight());
		int srcWidth = renderImage->GetImageWidth();
		int srcHeight = renderImage->GetImageHeight();
		int channels = renderImage->GetImageChannels();
		GLubyte *selectionBuffer = new GLubyte[width * height * channels]();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				for (int k = 0; k < channels; k++)
				{
					int xorVal;
					switch (k % 4)
					{
					case 0:
						xorVal = red;
						break;
					case 1:
						xorVal = green;
						break;
					case 2:
						xorVal = blue;
						break;
					default:
						xorVal = 0;
						break;
					}
					selectionBuffer[(i * width * channels) + (j * channels) + k] = buffer[(y1 * srcWidth * channels) +
						(i * srcWidth * channels) + (x1 * channels) + (j * channels) + k] ^ xorVal;
				}
			}
		}
		glRasterPos2i(x1, y1);
		glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, (void *)(selectionBuffer));
		delete[] selectionBuffer;

		// I was told that I might lose marks if I used the code below to draw a rubber-band, so
		// I quickly implemented the drawing of a rectangle myself above, however, I did end up
		// using GL functionality for drawing the circle further below
		/*
		glEnable(GL_COLOR_LOGIC_OP);
		glLogicOp(GL_XOR);

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glRecti(selectionRect.GetX1(), selectionRect.GetY1(), selectionRect.GetX2(), selectionRect.GetY2());

		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glRecti(selectionRect.GetX1(), selectionRect.GetY1(), selectionRect.GetX2(), selectionRect.GetY2());
		
		glDisable(GL_COLOR_LOGIC_OP);
		*/
	}

	if (!distortionCircle.IsZeroDimensional())
	{
		glEnable(GL_COLOR_LOGIC_OP);
		glLogicOp(GL_XOR);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		int num_segments = 128;
		double theta = 2 * M_PI / float(num_segments);
		double cs = cos(theta);
		double sn = sin(theta);
		double t;
		int circleX = distortionCircle.GetCenterX();
		int circleY = distortionCircle.GetCenterY();
		double radius = distortionCircle.GetRadius();
		double cx = radius;//we start at angle = 0 
		double cy = 0;

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glBegin(GL_TRIANGLE_FAN);
		for (int ii = 0; ii < num_segments; ii++)
		{
			glVertex2d(cx + circleX, cy + circleY);//output vertex

			//apply the rotation matrix
			t = cx;
			cx = cs * cx - sn * cy;
			cy = sn * t + cs * cy;
		}
		glEnd();

		glDisable(GL_COLOR_LOGIC_OP);
	}

	delete[] buffer;

	glFlush();

	glutPostRedisplay();
}

void keyboardCB(unsigned char key, int x, int y)
{
	if (keys[key] == 0)
	{
		if (key == 'R' || key == 'r')
		{
			MyImageUtil::SeparateChannel(image, renderImage, RBGA_CHANNEL_RED, SEPARATION_DARK);
		}
		if (key == 'G' || key == 'g')
		{
			MyImageUtil::SeparateChannel(image, renderImage, RBGA_CHANNEL_GREEN, SEPARATION_DARK);
		}
		if (key == 'B' || key == 'b')
		{
			MyImageUtil::SeparateChannel(image, renderImage, RBGA_CHANNEL_BLUE, SEPARATION_DARK);
		}
		if (key == 'D' || key == 'd')
		{
			MyImageUtil::GrayscaleImage(image, renderImage, GRAYSCALE_LIGHTNESS);
		}
		if (key == 'N' || key == 'n')
		{
			MyImageUtil::GrayscaleImage(image, renderImage, GRAYSCALE_LIGHTNESS);
			renderImage->Negative();
		}
		if (key == 'C' || key == 'c')
		{
			renderImage->Negative();
		}
		if (key == 'H' || key == 'h')
		{
			image->FlipHorizontal();
			renderImage->FlipHorizontal();
		}
		if (key == 'V' || key == 'v')
		{
			image->FlipVertical();
			renderImage->FlipVertical();
		}
		if (key == ' ')
		{
			renderImage->SetImage(image);
		}
		if (key == 27)
		{
			quit();
		}
	}
	keys[key] = 1;
}

void keyboardUpCB(unsigned char key, int x, int y)
{
	keys[key] = 0;
}

void mouseCB(int button, int state, int x, int y)
{
	int winWidth = glutGet(GLUT_WINDOW_WIDTH);
	int winHeight = glutGet(GLUT_WINDOW_HEIGHT);
	int glX = x;
	int glY = winHeight - y;

	// mouse press event
	if (mouse[button] == GLUT_UP && state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			if (mouseHandleTool == MOUSE_HANDLE_TOOL_NONE)
			{
				selectionRect = MyRectangle();
				distortionCircle = MyCircle();
			}
			if (mouseHandleTool == MOUSE_HANDLE_TOOL_SELECT)
			{
				selectionRect.SetX1(min(max(0, glX), renderImage->GetImageWidth()));
				selectionRect.SetY1(min(max(0, glY), renderImage->GetImageHeight()));
				selectionRect.SetWidth(0);
				selectionRect.SetHeight(0);
			}
			if (mouseHandleTool == MOUSE_HANDLE_TOOL_PASTE)
			{
				if (imageClipboard != 0 && renderClipboard != 0)
				{
					MyImageUtil::PasteToImage(imageClipboard, image, glX, glY);
					MyImageUtil::PasteToImage(renderClipboard, renderImage, glX, glY);
				}
				mouseHandleTool = MOUSE_HANDLE_TOOL_NONE;
			}
			if (mouseHandleTool == MOUSE_HANDLE_TOOL_BLACKHOLE ||
				mouseHandleTool == MOUSE_HANDLE_TOOL_EXPAND ||
				mouseHandleTool == MOUSE_HANDLE_TOOL_SWIRL)
			{
				distortionCircle.SetCenterX(min(max(0, glX), renderImage->GetImageWidth()));
				distortionCircle.SetCenterY(min(max(0, glY), renderImage->GetImageHeight()));
				distortionCircle.SetRadius(0.0);
			}
		}
		if (button == GLUT_MIDDLE_BUTTON)
		{

		}
		if (button == GLUT_RIGHT_BUTTON)
		{

		}
	}

	// mouse release event
	if (mouse[button] == GLUT_DOWN && state == GLUT_UP)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			if (mouseHandleTool == MOUSE_HANDLE_TOOL_SELECT)
			{
				selectionRect.SetX2(min(max(0, glX), renderImage->GetImageWidth()));
				selectionRect.SetY2(min(max(0, glY), renderImage->GetImageHeight()));
				mouseHandleTool = MOUSE_HANDLE_TOOL_NONE;
			}
			if (mouseHandleTool == MOUSE_HANDLE_TOOL_BLACKHOLE ||
				mouseHandleTool == MOUSE_HANDLE_TOOL_EXPAND ||
				mouseHandleTool == MOUSE_HANDLE_TOOL_SWIRL)
			{
				double deltaX = glX - distortionCircle.GetCenterX();
				double deltaY = glY - distortionCircle.GetCenterY();
				double radius = sqrt((deltaX * deltaX) + (deltaY * deltaY));
				distortionCircle.SetRadius(radius);
				switch (mouseHandleTool)
				{
				case MOUSE_HANDLE_TOOL_BLACKHOLE:
					MyImageUtil::BlackHoleEffect(image, distortionCircle);
					MyImageUtil::BlackHoleEffect(renderImage, distortionCircle);
					break;
				case MOUSE_HANDLE_TOOL_EXPAND:
					MyImageUtil::ExpandEffect(image, distortionCircle);
					MyImageUtil::ExpandEffect(renderImage, distortionCircle);
					break;
				case MOUSE_HANDLE_TOOL_SWIRL:
					MyImageUtil::SwirlEffect(image, distortionCircle, 1);
					MyImageUtil::SwirlEffect(renderImage, distortionCircle, 1);
					break;
				default:
					break;
				}
				distortionCircle = MyCircle();
				mouseHandleTool = MOUSE_HANDLE_TOOL_NONE;
			}
		}
		if (button == GLUT_MIDDLE_BUTTON)
		{

		}
		if (button == GLUT_RIGHT_BUTTON)
		{

		}
	}

	mouse[button] = state;
}

void mouseMoveCB(int x, int y)
{
	int winWidth = glutGet(GLUT_WINDOW_WIDTH);
	int winHeight = glutGet(GLUT_WINDOW_HEIGHT);
	int glX = x;
	int glY = winHeight - y;

	if (mouse[GLUT_LEFT_BUTTON] == GLUT_DOWN)
	{
		if (mouseHandleTool == MOUSE_HANDLE_TOOL_SELECT)
		{
			selectionRect.SetX2(min(max(0, glX), renderImage->GetImageWidth()));
			selectionRect.SetY2(min(max(0, glY), renderImage->GetImageHeight()));
		}
		if (mouseHandleTool == MOUSE_HANDLE_TOOL_BLACKHOLE ||
			mouseHandleTool == MOUSE_HANDLE_TOOL_EXPAND ||
			mouseHandleTool == MOUSE_HANDLE_TOOL_SWIRL)
		{
			double deltaX = glX - distortionCircle.GetCenterX();
			double deltaY = glY - distortionCircle.GetCenterY();
			double radius = sqrt((deltaX * deltaX) + (deltaY * deltaY));
			distortionCircle.SetRadius(radius);
		}
	}
	if (mouse[GLUT_MIDDLE_BUTTON] == GLUT_DOWN)
	{

	}
	if (mouse[GLUT_RIGHT_BUTTON] == GLUT_DOWN)
	{

	}
	mouseCoordinates[COORDINATE_X] = glX;
	mouseCoordinates[COORDINATE_Y] = glY;
}

void mouseMovePassiveCB(int x, int y)
{
	int winWidth = glutGet(GLUT_WINDOW_WIDTH);
	int winHeight = glutGet(GLUT_WINDOW_HEIGHT);
	int glX = x;
	int glY = winHeight - y;
	mouseCoordinates[COORDINATE_X] = glX;
	mouseCoordinates[COORDINATE_Y] = glY;
}

void rightClickMenuCB(int value)
{
	switch (value)
	{
	case RIGHT_CLICK_MENU_SELECT:
		mouseHandleTool = MOUSE_HANDLE_TOOL_SELECT;
		selectionRect = MyRectangle();
		distortionCircle = MyCircle();
		break;
	case RIGHT_CLICK_MENU_COPY:
		if (!selectionRect.IsZeroDimensional())
		{
			MyImageUtil::CopyFromImage(image, &imageClipboard, selectionRect);
			MyImageUtil::CopyFromImage(renderImage, &renderClipboard, selectionRect);
			selectionRect = MyRectangle();
			distortionCircle = MyCircle();
		}
		break;
	case RIGHT_CLICK_MENU_PASTE:
		mouseHandleTool = MOUSE_HANDLE_TOOL_PASTE;
		selectionRect = MyRectangle();
		distortionCircle = MyCircle();
		break;
	default:
		break;
	}
}

void photoboothSubMenuCB(int value)
{
	switch (value)
	{
	case PHOTOBOOTH_SUB_MENU_BLACKHOLE:
		mouseHandleTool = MOUSE_HANDLE_TOOL_BLACKHOLE;
		selectionRect = MyRectangle();
		distortionCircle = MyCircle();
		break;
	case PHOTOBOOTH_SUB_MENU_EXPAND:
		mouseHandleTool = MOUSE_HANDLE_TOOL_EXPAND;
		selectionRect = MyRectangle();
		distortionCircle = MyCircle();
		break;
	case PHOTOBOOTH_SUB_MENU_SWIRL:
		mouseHandleTool = MOUSE_HANDLE_TOOL_SWIRL;
		selectionRect = MyRectangle();
		distortionCircle = MyCircle();
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	//*
	//* general  initialization which are private to the application
	// This is not related to OpenGL
	//	HGLRC	 m_hrc1=NULL, m_hrc2=NULL;

	//  initialize GLUT and pass it the command variables
	glutInit(&argc, argv);

	//* Initialize key states
	for (int i = 0; i < 256; i++)
	{
		keys[i] = 0;
	}

	//* Initialize mouse button states
	for (int i = 0; i < 3; i++)
	{
		mouse[i] = GLUT_UP;
	}

	for (int i = 0; i < 2; i++)
	{
		mouseCoordinates[i] = 0;
	}

	mouseHandleTool = MOUSE_HANDLE_TOOL_NONE;

	grayscaleType = GRAYSCALE_MIN;

	selectionRect = MyRectangle();
	distortionCircle = MyCircle();
	
	//* initialize image
	image = new MyImage("Resource Files\\sample.png");
	image->FlipVertical();
	image->FlipHorizontal();

	renderImage = new MyImage(*image);

	imageClipboard = 0;
	renderClipboard = 0;

	winWidth = renderImage->GetImageWidth();
	winHeight = renderImage->GetImageHeight();

	// Set the first window
	// instruct openGL where to put the window on the screen
	glutInitWindowPosition(10, 10);

	//  instruct openGL to use a single display buffer and use 4 values for a colour RGB and Alpha
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	// instuct openGL what window size ot use
	glutInitWindowSize(winWidth, winHeight);

	// create the fist window and obtain a handle to it 
	wid1 = glutCreateWindow("My First Window");

	// create a menu for right clicking
	rightClickMenu = glutCreateMenu(rightClickMenuCB);
	glutAddMenuEntry("Select", RIGHT_CLICK_MENU_SELECT);
	glutAddMenuEntry("Copy", RIGHT_CLICK_MENU_COPY);
	glutAddMenuEntry("Paste", RIGHT_CLICK_MENU_PASTE);
	photoboothSubMenu = glutCreateMenu(photoboothSubMenuCB);
	glutAddMenuEntry("Black Hole", PHOTOBOOTH_SUB_MENU_BLACKHOLE);
	glutAddMenuEntry("Expand", PHOTOBOOTH_SUB_MENU_EXPAND);
	glutAddMenuEntry("Swirl", PHOTOBOOTH_SUB_MENU_SWIRL);
	glutSetMenu(rightClickMenu);
	glutAddSubMenu("Photo Booth", photoboothSubMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// register the corresponnding call back functions of the window

	// register the resize/create function 
	glutReshapeFunc(resizeWinCB);

	//* register window rendering function
	glutDisplayFunc(renderWinCB);
	//	m_hrc1 = wglGetCurrentContext();

	//* register keyboard functions
	glutKeyboardFunc(keyboardCB);
	glutKeyboardUpFunc(keyboardUpCB);

	//* register mouse functions
	glutMouseFunc(mouseCB);
	glutMotionFunc(mouseMoveCB);
	glutPassiveMotionFunc(mouseMovePassiveCB);

	/* start the main loop *///*
	glutMainLoop();
	//*/

	return 0;
}

void quit()
{
	glutDestroyWindow(wid1);
	if (image != 0)
	{
		delete image;
		image = 0;
	}
	if (renderImage != 0)
	{
		delete renderImage;
		renderImage = 0;
	}
	if (imageClipboard != 0)
	{
		delete imageClipboard;
		imageClipboard = 0;
	}
	if (renderClipboard != 0)
	{
		delete renderClipboard;
		renderClipboard = 0;
	}
	_CrtDumpMemoryLeaks();
}