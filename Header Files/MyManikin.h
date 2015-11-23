#ifndef MYMANIKIN_H
#define MYMANIKIN_H

#include "MyObject3D.h"
#include "MySphere.h"
#include "MyAnimation.h"

class MyManikin : public MyObject3D
{
public:
	MyManikin(MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D());
	~MyManikin();

	virtual void Initialize(MyShaderProgram *shader, MyMaterial *material);
	virtual void Update(float const & deltaTime);

	MySphere *abdomen; // pivot point for upper body
	MySphere *leftHip; // pivot point for left leg
	MySphere *rightHip; // pivot point for right leg

	// Torso - children of abdomen
	MySphere *midTorso; // pivot point for upper body
	MySphere *torso; // chest area
	
	// Head and neck - children of torso
	MySphere *neck; // pivot point for head
	MySphere *head;

	// Arms - children of torso
	MySphere *leftShoulder; // pivot point for left arm
	MySphere *leftUpperArm; // bicep and tricep area
	MySphere *leftElbow; // pivot point for left forearm
	MySphere *leftForearm; // wrist and forearm
	MySphere *leftWrist; // pivot point for left hand
	MySphere *leftHand;
	MySphere *rightShoulder; // pivot point for right arm
	MySphere *rightUpperArm; // bicep and tricep area
	MySphere *rightElbow; // pivot point for right forearm
	MySphere *rightForearm; // wrist and forearm
	MySphere *rightWrist; // pivot point for right hand
	MySphere *rightHand;

	// Legs - children of hips
	MySphere *leftThigh; // leg above the knee
	MySphere *leftKnee; // pivot point for left calf
	MySphere *leftCalf; // calf and shin area
	MySphere *leftAnkle; // pivot point for left foot
	MySphere *leftFoot;
	MySphere *rightThigh; // leg above the knee
	MySphere *rightKnee; // pivot point for right calf
	MySphere *rightCalf; // calf and shin area
	MySphere *rightAnkle; // pivot point for right foot
	MySphere *rightFoot;

	// Body Animation
	MyAnimation *animation;

};

#endif // MYMANIKIN_H
