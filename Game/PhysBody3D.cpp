#include "PhysBody3D.h"
#include "glmath.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// =================================================
PhysBody3D::PhysBody3D(btRigidBody* body) : body(body)
{
	body->setUserPointer(this);
}


// ---------------------------------------------------------
PhysBody3D::~PhysBody3D()
{
	delete body;
}

// ---------------------------------------------------------
void PhysBody3D::Push(float x, float y, float z)
{
	body->applyCentralImpulse(btVector3(x, y, z));
}

// ---------------------------------------------------------
void PhysBody3D::GetTransform(float* matrix) const
{
	if(body != NULL && matrix != NULL)
	{
		body->getWorldTransform().getOpenGLMatrix(matrix);
	}
}

// ---------------------------------------------------------
void PhysBody3D::SetTransform(const float* matrix) const
{
	if(body != NULL && matrix != NULL)
	{
		btTransform t;
		t.setFromOpenGLMatrix(matrix);
		body->setWorldTransform(t);
	}
}

// ---------------------------------------------------------
void PhysBody3D::SetPos(float x, float y, float z)
{
	btTransform t = body->getWorldTransform();
	t.setOrigin(btVector3(x, y, z));
	body->setWorldTransform(t);
}

btQuaternion PhysBody3D::GetRotation() {

	btTransform t = body->getWorldTransform();

	return t.getRotation();
}

void PhysBody3D::SetRotation(btQuaternion rotation) {

	btTransform t = body->getWorldTransform();
	t.setRotation(rotation);
	body->setWorldTransform(t);
}
btVector3 PhysBody3D::GetPos() {
	btTransform t = body->getWorldTransform();
	return t.getOrigin();
}

