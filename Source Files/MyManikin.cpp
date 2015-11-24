#include "MyManikin.h"

#include "MyDefines.h"

MyManikin::MyManikin(MyVector3D &position, MyVector3D &scale, MyVector3D &rotation) :
	MyObject3D(position, scale, rotation)
{
	body = new MyObject3D();

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

	children->push_back(body);

	body->AddChild(abdomen);
	body->AddChild(leftHip);
	body->AddChild(rightHip);

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

	runAnimation = new MyAnimation(20, 24.0f, true);

	direction = MyVector3D(0.0f, 0.0f, -1.0f);
}

MyManikin::~MyManikin()
{
	MyDelete(runAnimation);
}

void MyManikin::Initialize(MyShaderProgram * shader, MyMaterial * material)
{
	for (std::vector<MyObject3D *>::iterator it = body->GetChildren()->begin(); it != body->GetChildren()->end(); ++it)
	{
		((MyGraphicsObject3D *)(*it))->Initialize(shader, material, true);
	}

	InitializePose();

	MyAnimationTrack *bodyAnim = new MyAnimationTrack(body);
	runAnimation->AddTrack("body", bodyAnim);
	MyAnimationTrack *torsoAnim = new MyAnimationTrack(midTorso);
	runAnimation->AddTrack("torso", torsoAnim);
	MyAnimationTrack *headAnim = new MyAnimationTrack(neck);
	runAnimation->AddTrack("head", headAnim);
	MyAnimationTrack *leftArmAnim = new MyAnimationTrack(leftShoulder);
	runAnimation->AddTrack("leftArm", leftArmAnim);
	MyAnimationTrack *leftForearmAnim = new MyAnimationTrack(leftElbow);
	runAnimation->AddTrack("leftForearm", leftForearmAnim);
	MyAnimationTrack *rightArmAnim = new MyAnimationTrack(rightShoulder);
	runAnimation->AddTrack("righttArm", rightArmAnim);
	MyAnimationTrack *rightForearmAnim = new MyAnimationTrack(rightElbow);
	runAnimation->AddTrack("rightForearm", rightForearmAnim);
	MyAnimationTrack *leftLegAnim = new MyAnimationTrack(leftHip);
	runAnimation->AddTrack("leftLeg", leftLegAnim);
	MyAnimationTrack *leftCalfAnim = new MyAnimationTrack(leftKnee);
	runAnimation->AddTrack("leftCalf", leftCalfAnim);
	MyAnimationTrack *rightLegAnim = new MyAnimationTrack(rightHip);
	runAnimation->AddTrack("rightLeg", rightLegAnim);
	MyAnimationTrack *rightCalfAnim = new MyAnimationTrack(rightKnee);
	runAnimation->AddTrack("rightCalf", rightCalfAnim);
	MyAnimationTrack *leftFootAnim = new MyAnimationTrack(leftAnkle);
	runAnimation->AddTrack("leftFoot", leftFootAnim);
	MyAnimationTrack *rightFootAnim = new MyAnimationTrack(rightAnkle);
	runAnimation->AddTrack("rightFoot", rightFootAnim);

	bodyAnim->AddKeyFrame(0, new MyKeyframe(MyVector3D(0.0f, 0.0f, 0.0f), (MyVector3D)body->GetScale(), MyVector3D(-30.0f)));
	bodyAnim->AddKeyFrame(2, new MyKeyframe(MyVector3D(0.0f, 0.25f, -0.5f), (MyVector3D)body->GetScale(), MyVector3D(-30.0f)));
	bodyAnim->AddKeyFrame(5, new MyKeyframe(MyVector3D(0.0f, 0.1f, -0.4f), (MyVector3D)body->GetScale(), MyVector3D(-30.0f)));
	bodyAnim->AddKeyFrame(10, new MyKeyframe(MyVector3D(0.0f, 0.0f, 0.0f), (MyVector3D)body->GetScale(), MyVector3D(-30.0f)));
	bodyAnim->AddKeyFrame(12, new MyKeyframe(MyVector3D(0.0f, 0.25f, -0.5f), (MyVector3D)body->GetScale(), MyVector3D(-30.0f)));
	bodyAnim->AddKeyFrame(15, new MyKeyframe(MyVector3D(0.0f, 0.1f, -0.4f), (MyVector3D)body->GetScale(), MyVector3D(-30.0f)));

	torsoAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)neck->GetPosition(), (MyVector3D)neck->GetScale(), MyVector3D(10.0f)));

	headAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)neck->GetPosition(), (MyVector3D)neck->GetScale(), MyVector3D(10.0f)));

	leftArmAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)leftShoulder->GetPosition(), (MyVector3D)leftShoulder->GetScale(), MyVector3D(0.0f)));
	leftArmAnim->AddKeyFrame(5, new MyKeyframe((MyVector3D)leftShoulder->GetPosition(), (MyVector3D)leftShoulder->GetScale(), MyVector3D(90.0f)));
	leftArmAnim->AddKeyFrame(10, new MyKeyframe((MyVector3D)leftShoulder->GetPosition(), (MyVector3D)leftShoulder->GetScale(), MyVector3D(0.0f)));
	leftArmAnim->AddKeyFrame(15, new MyKeyframe((MyVector3D)leftShoulder->GetPosition(), (MyVector3D)leftShoulder->GetScale(), MyVector3D(-70.0f)));

	rightArmAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)rightShoulder->GetPosition(), (MyVector3D)rightShoulder->GetScale(), MyVector3D(0.0f)));
	rightArmAnim->AddKeyFrame(5, new MyKeyframe((MyVector3D)rightShoulder->GetPosition(), (MyVector3D)rightShoulder->GetScale(), MyVector3D(-70.0f)));
	rightArmAnim->AddKeyFrame(10, new MyKeyframe((MyVector3D)rightShoulder->GetPosition(), (MyVector3D)rightShoulder->GetScale(), MyVector3D(0.0f)));
	rightArmAnim->AddKeyFrame(15, new MyKeyframe((MyVector3D)rightShoulder->GetPosition(), (MyVector3D)rightShoulder->GetScale(), MyVector3D(90.0f)));

	leftForearmAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)leftElbow->GetPosition(), (MyVector3D)leftElbow->GetScale(), MyVector3D(100.0f)));
	leftForearmAnim->AddKeyFrame(5, new MyKeyframe((MyVector3D)leftElbow->GetPosition(), (MyVector3D)leftElbow->GetScale(), MyVector3D(60.0f)));
	leftForearmAnim->AddKeyFrame(10, new MyKeyframe((MyVector3D)leftElbow->GetPosition(), (MyVector3D)leftElbow->GetScale(), MyVector3D(100.0f)));
	leftForearmAnim->AddKeyFrame(15, new MyKeyframe((MyVector3D)leftElbow->GetPosition(), (MyVector3D)leftElbow->GetScale(), MyVector3D(130.0f)));

	rightForearmAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)rightElbow->GetPosition(), (MyVector3D)rightElbow->GetScale(), MyVector3D(100.0f)));
	rightForearmAnim->AddKeyFrame(5, new MyKeyframe((MyVector3D)rightElbow->GetPosition(), (MyVector3D)rightElbow->GetScale(), MyVector3D(130.0f)));
	rightForearmAnim->AddKeyFrame(10, new MyKeyframe((MyVector3D)rightElbow->GetPosition(), (MyVector3D)rightElbow->GetScale(), MyVector3D(100.0f)));
	rightForearmAnim->AddKeyFrame(15, new MyKeyframe((MyVector3D)rightElbow->GetPosition(), (MyVector3D)rightElbow->GetScale(), MyVector3D(60.0f)));

	leftLegAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)leftHip->GetPosition(), (MyVector3D)leftHip->GetScale(), MyVector3D(30.0f)));
	leftLegAnim->AddKeyFrame(5, new MyKeyframe((MyVector3D)leftHip->GetPosition(), (MyVector3D)leftHip->GetScale(), MyVector3D(-30.0f)));
	leftLegAnim->AddKeyFrame(10, new MyKeyframe((MyVector3D)leftHip->GetPosition(), (MyVector3D)leftHip->GetScale(), MyVector3D(30.0f)));
	leftLegAnim->AddKeyFrame(15, new MyKeyframe((MyVector3D)leftHip->GetPosition(), (MyVector3D)leftHip->GetScale(), MyVector3D(100.0f)));

	rightLegAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)rightHip->GetPosition(), (MyVector3D)rightHip->GetScale(), MyVector3D(30.0f)));
	rightLegAnim->AddKeyFrame(5, new MyKeyframe((MyVector3D)rightHip->GetPosition(), (MyVector3D)rightHip->GetScale(), MyVector3D(100.0f)));
	rightLegAnim->AddKeyFrame(10, new MyKeyframe((MyVector3D)rightHip->GetPosition(), (MyVector3D)rightHip->GetScale(), MyVector3D(30.0f)));
	rightLegAnim->AddKeyFrame(15, new MyKeyframe((MyVector3D)rightHip->GetPosition(), (MyVector3D)rightHip->GetScale(), MyVector3D(-30.0f)));

	leftCalfAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)leftKnee->GetPosition(), (MyVector3D)leftKnee->GetScale(), MyVector3D(-30.0f)));
	leftCalfAnim->AddKeyFrame(5, new MyKeyframe((MyVector3D)leftKnee->GetPosition(), (MyVector3D)leftKnee->GetScale(), MyVector3D(-40.0f)));
	leftCalfAnim->AddKeyFrame(10, new MyKeyframe((MyVector3D)leftKnee->GetPosition(), (MyVector3D)leftKnee->GetScale(), MyVector3D(-100.0f)));
	leftCalfAnim->AddKeyFrame(15, new MyKeyframe((MyVector3D)leftKnee->GetPosition(), (MyVector3D)leftKnee->GetScale(), MyVector3D(-130.0f)));

	rightCalfAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)rightKnee->GetPosition(), (MyVector3D)rightKnee->GetScale(), MyVector3D(-100.0f)));
	rightCalfAnim->AddKeyFrame(5, new MyKeyframe((MyVector3D)rightKnee->GetPosition(), (MyVector3D)rightKnee->GetScale(), MyVector3D(-130.0f)));
	rightCalfAnim->AddKeyFrame(10, new MyKeyframe((MyVector3D)rightKnee->GetPosition(), (MyVector3D)rightKnee->GetScale(), MyVector3D(-30.0f)));
	rightCalfAnim->AddKeyFrame(15, new MyKeyframe((MyVector3D)rightKnee->GetPosition(), (MyVector3D)rightKnee->GetScale(), MyVector3D(-40.0f)));

	leftFootAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)leftAnkle->GetPosition(), (MyVector3D)leftAnkle->GetScale(), MyVector3D(30.0f)));
	leftFootAnim->AddKeyFrame(5, new MyKeyframe((MyVector3D)leftAnkle->GetPosition(), (MyVector3D)leftAnkle->GetScale(), MyVector3D(-90.0f)));
	leftFootAnim->AddKeyFrame(10, new MyKeyframe((MyVector3D)leftAnkle->GetPosition(), (MyVector3D)leftAnkle->GetScale(), MyVector3D(-70.0f)));
	leftFootAnim->AddKeyFrame(15, new MyKeyframe((MyVector3D)leftAnkle->GetPosition(), (MyVector3D)leftAnkle->GetScale(), MyVector3D(-60.0f)));

	rightFootAnim->AddKeyFrame(0, new MyKeyframe((MyVector3D)rightAnkle->GetPosition(), (MyVector3D)rightAnkle->GetScale(), MyVector3D(-70.0f)));
	rightFootAnim->AddKeyFrame(5, new MyKeyframe((MyVector3D)rightAnkle->GetPosition(), (MyVector3D)rightAnkle->GetScale(), MyVector3D(-60.0f)));
	rightFootAnim->AddKeyFrame(10, new MyKeyframe((MyVector3D)rightAnkle->GetPosition(), (MyVector3D)rightAnkle->GetScale(), MyVector3D(30.0f)));
	rightFootAnim->AddKeyFrame(15, new MyKeyframe((MyVector3D)rightAnkle->GetPosition(), (MyVector3D)rightAnkle->GetScale(), MyVector3D(-90.0f)));
}

void MyManikin::Update(float const & deltaTime)
{
	MyObject3D::Update(deltaTime);

	runAnimation->Update(deltaTime);
}

void MyManikin::InitializePose()
{
	body->SetPosition(0.0f, 0.0f, 0.0f);
	body->SetScale(1.0f, 1.0f, 1.0f);
	body->SetRotation(0.0f, 0.0f, 0.0f);
	abdomen->SetPosition(0.0f, 0.0f, 0.0f);
	abdomen->SetScale(1.0f, 1.0f, 1.0f);
	abdomen->SetRotation(0.0f, 0.0f, 0.0f);
	midTorso->SetScale(0.75f, 0.75f, 0.75f);
	midTorso->SetPosition(0.0f, 0.5f, 0.0f);
	midTorso->SetRotation(0.0f, 0.0f, 0.0f);
	torso->SetScale(1.25f, 1.25f, 1.25f);
	torso->SetPosition(0.0f, 0.5f, 0.0f);
	torso->SetRotation(0.0f, 0.0f, 0.0f);
	neck->SetScale(0.5f, 0.5f, 0.5f);
	neck->SetPosition(0.0f, 0.625f, 0.0);
	neck->SetRotation(0.0f, 0.0f, 0.0f);
	head->SetScale(0.825f, 0.825f, 0.825f);
	head->SetPosition(0.0f, 0.375f, 0.0f);
	head->SetRotation(0.0f, 0.0f, 0.0f);
	leftShoulder->SetScale(0.75f, 0.75f, 0.75f);
	leftShoulder->SetPosition(-0.825f, 0.25f, 0.0f);
	leftShoulder->SetRotation(0.0f, 0.0f, 0.0f);
	leftUpperArm->SetScale(0.5f, 1.5f, 0.5f);
	leftUpperArm->SetPosition(0.0f, -0.75f, 0.0f);
	leftUpperArm->SetRotation(0.0f, 0.0f, 0.0f);
	leftElbow->SetScale(0.375f, 0.375f, 0.375f);
	leftElbow->SetPosition(0.0f, -0.75f, 0.0f);
	leftElbow->SetRotation(0.0f, 0.0f, 0.0f);
	leftForearm->SetScale(0.35f, 1.125f, 0.35f);
	leftForearm->SetPosition(0.0f, -0.5f, 0.0f);
	leftForearm->SetRotation(0.0f, 0.0f, 0.0f);
	leftWrist->SetScale(0.25f, 0.25f, 0.25f);
	leftWrist->SetPosition(0.0f, -0.5f, 0.0f);
	leftWrist->SetRotation(0.0f, 0.0f, 0.0f);
	leftHand->SetScale(0.125f, 0.5f, 0.3f);
	leftHand->SetPosition(0.0f, -0.25f, 0.0f);
	leftHand->SetRotation(0.0f, 0.0f, 0.0f);
	rightShoulder->SetScale(0.75f, 0.75f, 0.75f);
	rightShoulder->SetPosition(0.825f, 0.25f, 0.0f);
	rightShoulder->SetRotation(0.0f, 0.0f, 0.0f);
	rightUpperArm->SetScale(0.5f, 1.5f, 0.5f);
	rightUpperArm->SetPosition(0.0f, -0.75f, 0.0f);
	rightUpperArm->SetRotation(0.0f, 0.0f, 0.0f);
	rightElbow->SetScale(0.375f, 0.375f, 0.375f);
	rightElbow->SetPosition(0.0f, -0.75f, 0.0f);
	rightElbow->SetRotation(0.0f, 0.0f, 0.0f);
	rightForearm->SetScale(0.35f, 1.125f, 0.35f);
	rightForearm->SetPosition(0.0f, -0.5f, 0.0f);
	rightForearm->SetRotation(0.0f, 0.0f, 0.0f);
	rightWrist->SetScale(0.25f, 0.25f, 0.25f);
	rightWrist->SetPosition(0.0f, -0.5f, 0.0f);
	rightWrist->SetRotation(0.0f, 0.0f, 0.0f);
	rightHand->SetScale(0.125f, 0.5f, 0.3f);
	rightHand->SetPosition(0.0f, -0.25f, 0.0f);
	rightHand->SetRotation(0.0f, 0.0f, 0.0f);
	leftHip->SetScale(0.6f, 0.6f, 0.6f);
	leftHip->SetPosition(-0.325f, -0.5f, 0.0f);
	leftHip->SetRotation(0.0f, 0.0f, 0.0f);
	leftThigh->SetScale(0.6f, 1.6f, 0.6f);
	leftThigh->SetPosition(0.0f, -0.75f, 0.0f);
	leftThigh->SetRotation(0.0f, 0.0f, 0.0f);
	leftKnee->SetScale(0.4f, 0.4f, 0.4f);
	leftKnee->SetPosition(0.0f, -0.8f, 0.0f);
	leftKnee->SetRotation(0.0f, 0.0f, 0.0f);
	leftCalf->SetScale(0.4f, 1.2f, 0.4f);
	leftCalf->SetPosition(0.0f, -0.5f, 0.0f);
	leftCalf->SetRotation(0.0f, 0.0f, 0.0f);
	leftAnkle->SetScale(0.3f, 0.3f, 0.3f);
	leftAnkle->SetPosition(0.0f, -0.6f, 0.0f);
	leftAnkle->SetRotation(0.0f, 0.0f, 0.0f);
	leftFoot->SetScale(0.35f, 0.2f, 0.75f);
	leftFoot->SetPosition(0.0f, -0.15f, -0.15f);
	leftFoot->SetRotation(0.0f, 0.0f, 0.0f);
	rightHip->SetScale(0.6f, 0.6f, 0.6f);
	rightHip->SetPosition(0.325f, -0.5f, 0.0f);
	rightHip->SetRotation(0.0f, 0.0f, 0.0f);
	rightThigh->SetScale(0.6f, 1.6f, 0.6f);
	rightThigh->SetPosition(0.0f, -0.75f, 0.0f);
	rightThigh->SetRotation(0.0f, 0.0f, 0.0f);
	rightKnee->SetScale(0.4f, 0.4f, 0.4f);
	rightKnee->SetPosition(0.0f, -0.8f, 0.0f);
	rightKnee->SetRotation(0.0f, 0.0f, 0.0f);
	rightCalf->SetScale(0.4f, 1.2f, 0.4f);
	rightCalf->SetPosition(0.0f, -0.5f, 0.0f);
	rightCalf->SetRotation(0.0f, 0.0f, 0.0f);
	rightAnkle->SetScale(0.3f, 0.3f, 0.3f);
	rightAnkle->SetPosition(0.0f, -0.6f, 0.0f);
	rightAnkle->SetRotation(0.0f, 0.0f, 0.0f);
	rightFoot->SetScale(0.35f, 0.2f, 0.75f);
	rightFoot->SetPosition(0.0f, -0.15f, -0.15f);
	rightFoot->SetRotation(0.0f, 0.0f, 0.0f);
}

void MyManikin::TogglePlay()
{
	if (runAnimation->IsPlaying())
	{
		runAnimation->Pause();
	}
	else
	{
		runAnimation->Play();
	}
}

void MyManikin::ToggleLooping()
{
	runAnimation->SetLooping(!runAnimation->IsLooping());
}

void MyManikin::Stop()
{
	runAnimation->Stop();
	InitializePose();
}

void MyManikin::ChangeSpeed(float const & factor)
{
	runAnimation->SetFrameRate(max(runAnimation->GetFrameRate() * factor, 0.1f));
}

const MyVector3D & MyManikin::GetDirection() const
{
	return direction;
}

void MyManikin::Yaw(float const & angle, bool isDegree)
{
	MyObject3D::Yaw(angle, isDegree);
	direction = (MyMatrix4::RotationAboutVectorAxisMatrix(MyVector3D(0.0f, 1.0f, 0.0f), angle, isDegree) * direction);
	direction.SetY(0.0f);
	direction.Normalize();
}
