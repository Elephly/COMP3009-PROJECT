# COMP3009-PROJECT
COMP3009 Term Project

### Setup
1. Install Visual C++ (currently using Visual Studio 2015)
2. Download and place GLUT, GLEW, and SOIL libraries, DLLs, and includes in a GL directory somewhere on your machine
  - I won't tell you where you should download these utilities or how to structure your GL directory, but the examples of my configuration under point 5 should give you an idea of how my GL directory is structured
3. Create an environment variable %GL_HOME% and set it to your GL directory
4. On first time opening the project in Visual Studio, set the solution platform to x86
5. It may be necessary to reconfigure project properties for finding the additional includes and libraries in your GL directory
  - Make sure "C/C++ -> General -> Additional Include Directories" is correct
    - For me, this property looks like the following: .\Header Files;%GL_HOME%\include;%(AdditionalIncludeDirectories)
  - Make sure "Linker -> General -> Additional Library Directories" is correct
    - For me, this property looks like the following: %GL_HOME%\lib;%(AdditionalLibraryDirectories)
  - Make sure that "Linker -> Input -> Additional Dependencies" includes all of your statically linked library files
    - For me, this property looks like the following: freeglut.lib;glew32.lib;SOIL.lib;%(AdditionalDependencies)
  - Make sure that "Debugging -> Environment" looks like the following: PATH=%GL_HOME%\bin;%PATH%

### TODO (Unordered)
- [ ] Modify camera to use a quaternion orientation
- [x] Object origin for orbital rotation
  - No longer an issue - proper hierarchical object transformations inherently solves this problem
- [ ] Lighting
- [ ] Blending
- [ ] Textured meshes
- [ ] Normal mapping (?)
- [ ] Wavefront (.OBJ) file parser
