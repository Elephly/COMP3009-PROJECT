#ifndef MYMANIKIN_H
#define MYMANIKIN_H

#include "MyObject3D.h"
#include "MyGraphicsObject3D.h"
#include "MyAnimation.h"

class MyManikin : public MyObject3D
{
public:
	MyManikin(MyIndexedVertexArray *vertexArray = 0, MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D());
	~MyManikin();

	virtual void Initialize(MyShaderProgram *shader, MyMaterial *material, MyIndexedVertexArray *vertexArray = 0);
	virtual void Update(float const & deltaTime);

	virtual void InitializePose();

	virtual void TogglePlay();
	virtual void ToggleLooping();
	virtual void Stop();
	virtual void ChangeSpeed(float const & factor);

	// TEMP
	virtual const MyVector3D &GetDirection() const;
	virtual void Yaw(float const & angle, bool isDegree = true);

private:
	MyObject3D *body;

	MyGraphicsObject3D *abdomen; // pivot point for upper body
	MyGraphicsObject3D *leftHip; // pivot point for left leg
	MyGraphicsObject3D *rightHip; // pivot point for right leg

	// Torso - children of abdomen
	MyGraphicsObject3D *midTorso; // pivot point for upper body
	MyGraphicsObject3D *torso; // chest area
	
	// Head and neck - children of torso
	MyGraphicsObject3D *neck; // pivot point for head
	MyGraphicsObject3D *head;

	// Arms - children of torso
	MyGraphicsObject3D *leftShoulder; // pivot point for left arm
	MyGraphicsObject3D *leftUpperArm; // bicep and tricep area
	MyGraphicsObject3D *leftElbow; // pivot point for left forearm
	MyGraphicsObject3D *leftForearm; // wrist and forearm
	MyGraphicsObject3D *leftWrist; // pivot point for left hand
	MyGraphicsObject3D *leftHand;
	MyGraphicsObject3D *rightShoulder; // pivot point for right arm
	MyGraphicsObject3D *rightUpperArm; // bicep and tricep area
	MyGraphicsObject3D *rightElbow; // pivot point for right forearm
	MyGraphicsObject3D *rightForearm; // wrist and forearm
	MyGraphicsObject3D *rightWrist; // pivot point for right hand
	MyGraphicsObject3D *rightHand;

	// Legs - children of hips
	MyGraphicsObject3D *leftThigh; // leg above the knee
	MyGraphicsObject3D *leftKnee; // pivot point for left calf
	MyGraphicsObject3D *leftCalf; // calf and shin area
	MyGraphicsObject3D *leftAnkle; // pivot point for left foot
	MyGraphicsObject3D *leftFoot;
	MyGraphicsObject3D *rightThigh; // leg above the knee
	MyGraphicsObject3D *rightKnee; // pivot point for right calf
	MyGraphicsObject3D *rightCalf; // calf and shin area
	MyGraphicsObject3D *rightAnkle; // pivot point for right foot
	MyGraphicsObject3D *rightFoot;

	// Body Animation
	MyAnimation *runAnimation;

	MyVector3D direction; // temp

};

#endif // MYMANIKIN_H
