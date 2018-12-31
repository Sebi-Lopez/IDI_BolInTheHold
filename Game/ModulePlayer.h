#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Timer.h"
struct PhysVehicle3D;

#define MAX_ACCELERATION 1500.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

#define MAX_LOOK_UP 10
#define LOOK_UP_SPEED 0.5
#define STANDARD_LOOK_UP 1

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void ResetPosition(); 
	void InitialPosition(); 
	void UpdateVehicle(); 
	void CheckTime(); 
	void CreateVehicle();
	vec3 GetPos();
	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:

	PhysBody3D* Ball;
	bool lose = false;

	Sphere s;
	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;
	float look_up = STANDARD_LOOK_UP;
	Timer contact_ball;
	Timer without_ball;

};