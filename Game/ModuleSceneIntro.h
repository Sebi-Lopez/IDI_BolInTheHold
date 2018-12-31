#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;
struct Fan {

	Fan() {}
	Fan(Cube c, Cube c2, PhysBody3D* bc, PhysBody3D* bc2) : cube(c), cube_down(c2), body_cube(bc), body_cube_down(bc2) {}

	Cube cube;
	Cube cube_down;
	PhysBody3D* body_cube = nullptr;
	PhysBody3D* body_cube_down = nullptr;

};

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	void AddWall(vec3 size, vec3 position, Color color, float angle = 0.0f, vec3 rotvec =  vec3(0,0,0), float mass = 0);

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	void PrintWalls();
	void CreateFan(float x, float y, float z, Color color = Black);
	void UpdateFans();
	PhysBody3D* CreateFinishLane(vec3 size, vec3 position);
public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/
	Timer time;
	Uint32 finished_time = 0;
	PhysBody3D* FinishLane;
	bool touched_the_sky = false;
	

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;
private:
	p2List<Cube> Walls;
	p2List<Fan> fan;

};
