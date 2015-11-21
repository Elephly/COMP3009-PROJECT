#include "MyManikin.h"

MyManikin::MyManikin(MyVector3D &position, MyVector3D &scale, MyVector3D &rotation) :
	MyObject3D(position, scale, rotation)
{
	abdomen = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));

	// Torso - children of abdomen
	midTorso = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	torso = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));

	// Head and neck - children of torso
	neck = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	head = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));

	// Arms - children of torso
	leftShoulder = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	leftUpperArm = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	leftElbow = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	leftForearm = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	leftWrist = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	leftHand = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightShoulder = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightUpperArm = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightElbow = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightForearm = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightWrist = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightHand = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));

	// Legs - children of abdomen
	leftHip = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	leftThigh = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	leftKnee = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	leftCalf = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	leftAnkle = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	leftFoot = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightHip = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightThigh = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightKnee = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightCalf = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightAnkle = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));
	rightFoot = new MySphere(MyColorRGBA(1.0f, 1.0f, 1.0f));

	children->push_back(abdomen);
	children->push_back(leftHip);
	children->push_back(rightHip);

	abdomen->AddChild(midTorso);
	leftHip->AddChild(leftThigh);
	rightHip->AddChild(rightThigh);

	midTorso->AddChild(torso);
	leftThigh->AddChild(leftKnee);
	rightThigh->AddChild(rightKnee);

	torso->AddChild(neck);
	torso->AddChild(leftShoulder);
	torso->AddChild(rightShoulder);
	leftKnee->AddChild(leftCalf);
	rightKnee->AddChild(rightCalf);

	neck->AddChild(head);
	leftShoulder->AddChild(leftUpperArm);
	rightShoulder->AddChild(rightUpperArm);
	leftCalf->AddChild(leftAnkle);
	rightCalf->AddChild(rightAnkle);

	leftUpperArm->AddChild(leftElbow);
	rightUpperArm->AddChild(rightElbow);
	leftAnkle->AddChild(leftFoot);
	rightAnkle->AddChild(rightFoot);

	leftElbow->AddChild(leftForearm);
	rightElbow->AddChild(rightForearm);

	leftForearm->AddChild(leftWrist);
	rightForearm->AddChild(rightWrist);

	leftWrist->AddChild(leftHand);
	rightWrist->AddChild(rightHand);
}

MyManikin::~MyManikin()
{
}

void MyManikin::Initialize(MyShaderProgram * shader, MyMaterial * material)
{
	for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
	{
		((MyGraphicsObject3D *)(*it))->Initialize(shader, material, true);
	}

	midTorso->Scale(0.75f, 0.75f, 0.75f);
	midTorso->Translate(0.0f, 0.5f, 0.0f);
	torso->Scale(1.5f, 1.5f, 1.5f);
	torso->Translate(0.0f, 0.5f, 0.0f);
	neck->Scale(0.5f, 0.5f, 0.5f);
	neck->Translate(0.0f, 0.5f, 0.0f);
	head->Scale(1.5f, 1.5f, 1.5f);
	head->Translate(0.0f, 0.75f, 0.0f);
	leftShoulder->Scale(0.5f, 0.5f, 0.5f);
	leftShoulder->Translate(-0.7f, 0.125f, 0.0f);
	leftUpperArm->Scale(0.75f, 2.0f, 0.75f, false);
	leftUpperArm->Translate(0.0f, -1.0f, 0.0f);
	leftElbow->Scale(0.5f, 0.5f, 0.5f);
	leftElbow->Translate(0.0f, -0.5f, 0.0f);
	leftForearm->Scale(1.0f, 3.0f, 1.0f, false);
	leftForearm->Translate(0.0f, -1.25f, 0.0f);
	leftWrist->Scale(0.75f, 0.75f, 0.75f);
	leftWrist->Translate(0.0f, -0.5f, 0.0f);
	leftHand->Scale(0.75f, 1.5f, 1.25f);
	leftHand->Translate(0.0f, -1.0f, 0.0f);
	rightShoulder->Scale(0.5f, 0.5f, 0.5f);
	rightShoulder->Translate(0.7f, 0.125f, 0.0f);
	rightUpperArm->Scale(0.75f, 2.0f, 0.75f, false);
	rightUpperArm->Translate(0.0f, -1.0f, 0.0f);
	rightElbow->Scale(0.5f, 0.5f, 0.5f);
	rightElbow->Translate(0.0f, -0.5f, 0.0f);
	rightForearm->Scale(1.0f, 3.0f, 1.0f, false);
	rightForearm->Translate(0.0f, -1.25f, 0.0f);
	rightWrist->Scale(0.75f, 0.75f, 0.75f);
	rightWrist->Translate(0.0f, -0.5f, 0.0f);
	rightHand->Scale(0.75f, 1.5f, 1.25f);
	rightHand->Translate(0.0f, -1.0f, 0.0f);
	leftHip->Scale(0.5f, 0.5f, 0.5f);
	leftHip->Translate(-0.3f, -0.5f, 0.0f);
	leftThigh->Scale(1.0f, 2.5f, 1.0f, false);
	leftThigh->Translate(0.0f, -1.0f, 0.0f);
	leftKnee->Scale(0.75f, 0.75f, 0.75f);
	leftKnee->Translate(0.0f, -0.5f, 0.0f);
	leftCalf->Scale(1.0f, 2.5f, 1.0f, false);
	leftCalf->Translate(0.0f, -1.0f, 0.0f);
	leftAnkle->Scale(0.75f, 0.75f, 0.75f);
	leftAnkle->Translate(0.0f, -0.5f, 0.0f);
	leftFoot->Scale(1.25f, 0.5f, 2.0f);
	leftFoot->Translate(0.0f, -0.5f, -0.5f);
	rightHip->Scale(0.5f, 0.5f, 0.5f);
	rightHip->Translate(0.3f, -0.5f, 0.0f);
	rightThigh->Scale(1.0f, 2.5f, 1.0f, false);
	rightThigh->Translate(0.0f, -1.0f, 0.0f);
	rightKnee->Scale(0.75f, 0.75f, 0.75f);
	rightKnee->Translate(0.0f, -0.5f, 0.0f);
	rightCalf->Scale(1.0f, 2.5f, 1.0f, false);
	rightCalf->Translate(0.0f, -1.0f, 0.0f);
	rightAnkle->Scale(0.75f, 0.75f, 0.75f);
	rightAnkle->Translate(0.0f, -0.5f, 0.0f);
	rightFoot->Scale(1.25f, 0.5f, 2.0f);
	rightFoot->Translate(0.0f, -0.5f, -0.5f);
}
