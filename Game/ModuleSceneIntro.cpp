#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#define XXL 60
#define XL 15
#define RMP 30

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	name.create("Scene");
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	//Beacon Lane---------------------------------------------------
	AddWall(vec3(5, 5, 5), vec3(20-20,-1, 460 -32.5), White,45.0F,vec3(1,0,0));
	AddWall(vec3(5, 5, 5), vec3(20-20,-1, 460 -37.5), White, 45.0F, vec3(1, 0, 0));
	AddWall(vec3(5, 5, 5), vec3(20-22.5, -1, 460 -35), White, 45.0F, vec3(0, 0, 1));
	AddWall(vec3(5, 5, 5), vec3(20-17.5, -1,460 -35), White, 45.0F, vec3(0, 0, 1));
	FinishLane = CreateFinishLane(vec3(3, 3, 3), vec3(20-20, 0.7F, 460 -35));
	//Finished------------------------------------------------------
	
	// Right Side Fans
	CreateFan(-94, 13, 50);
	CreateFan(-94, 13, 70);
	CreateFan(-94, 13, 90);

	CreateFan(-94, 13, 230);
	CreateFan(-94, 13, 250);
	CreateFan(-94, 13, 270);
	CreateFan(-94, 13, 290);
	CreateFan(-100, 13, 390);


	// Left Side Fans
	CreateFan(115, 13, 70);
	CreateFan(115, 13, 90);
	CreateFan(115, 13, 110);
	CreateFan(115, 13, 130);
	CreateFan(-50, 13, 90);
	CreateFan(-40, 13, 110);

	AddWall(vec3(5, 5,5 ), vec3(121, 3.5f, 158), Blue);
	AddWall(vec3(5, 5, 5), vec3(109, 8.5f, 167), Blue);
	AddWall(vec3(5, 5, 5), vec3(125, 9.5f, 170), Blue);

	// Spikes
	AddWall(vec3(5, 5, 5), vec3(80, -1, 70), Red, 67.0F, vec3(0, 2, 1));
	AddWall(vec3(5, 5, 5), vec3(65, -1, 70), Red, 55.0F, vec3(1, 1, 0));
	AddWall(vec3(5, 5, 5), vec3(90, -1, 75), Red, 33.0F, vec3(1, 0, 1));
	AddWall(vec3(5, 5, 5), vec3(95, -1, 62), Red, 87.0F, vec3(0, 4, 1));
	AddWall(vec3(5, 5, 5), vec3(80-10, -1, 70+12), Red, 67.0F, vec3(0, 2, 1));
	AddWall(vec3(5, 5, 5), vec3(65-10, -1, 70+20), Red, 55.0F, vec3(1, 1, 0));
	AddWall(vec3(5, 5, 5), vec3(90-10, -1, 75+10), Red, 33.0F, vec3(1, 0, 1));
	AddWall(vec3(5, 5, 5), vec3(95-10, -1, 62+15), Red, 87.0F, vec3(0, 4, 1));

	AddWall(vec3(5, 5, 5), vec3(123, -1, 260), Red, 55.0F, vec3(1, 1, 0));
	AddWall(vec3(5, 5, 5), vec3(108, -1, 280), Red, 87.0F, vec3(0, 4, 1));
	AddWall(vec3(5, 5, 5), vec3(115, -1, 300), Red, 67.0F, vec3(0, 2, 1));
	AddWall(vec3(5, 5, 5), vec3(123, -1, 320), Red, 55.0F, vec3(1, 1, 0));
	AddWall(vec3(5, 5, 5), vec3(115, -1, 340), Red, 87.0F, vec3(0, 4, 1));
	AddWall(vec3(5, 5, 5), vec3(108, -1, 360), Red, 87.0F, vec3(0, 4, 1));
	AddWall(vec3(5, 5, 5), vec3(115, -1, 380), Red, 67.0F, vec3(0, 2, 1));
	AddWall(vec3(5, 5, 5), vec3(123, -1, 400), Red, 55.0F, vec3(1, 1, 0));
	AddWall(vec3(5, 5, 5), vec3(108, -1, 420), Red, 87.0F, vec3(0, 4, 1));
	AddWall(vec3(5, 5, 5), vec3(123, -1, 420), Red, 55.0F, vec3(1, 1, 0));


	AddWall(vec3(20, 20, 20), vec3(-50, 5, 160), Red);
	AddWall(vec3(100, XL, 3), vec3(54, 7.5F, 40), Green);
	AddWall(vec3(100, XL, 3), vec3(-54, 7.5F, 40), Green); //RIGHT
	AddWall(vec3(3, XL, 150), vec3(-75, 7.5F, 116.5F), Green); //RIGHT
	AddWall(vec3(30, XL, 3), vec3(-100, 7.5F, 116), Green); //RIGHT
	AddWall(vec3(50, XL, 3), vec3(-101, 7.5F, 137), Green,55.F,vec3(0,1,0)); //RIGHT
	AddWall(vec3(30, XL, 3), vec3(-90+1.5F, 7.5F, 166), Green); //RIGHT
	AddWall(vec3(50, XL, 3), vec3(-91+1.5F, 7.5F, 147), Green, 55.F, vec3(0, 1, 0)); //RIGHT
	AddWall(vec3(120, XL, 3), vec3(10, 7.5F, 65), Green); //RIGHT
	AddWall(vec3(40, XL, 3), vec3(-41.6 + 1.5F, 7.5F, 83.6), Green, -65.F, vec3(0, 1, 0)); //RIGHT
	AddWall(vec3(3, XL, 60), vec3(-60, 7.5F, 95), Green); //RIGHT
	AddWall(vec3(31, XL, 3), vec3(-45, 7.5F, 125), Green); //RIGHT
	AddWall(vec3(3, XL, 65), vec3(-31, 7.5F, 157), Green); //RIGHT
	AddWall(vec3(30, XL, 3), vec3(-60, 7.5F, 190), Green); //RIGHT
	AddWall(vec3(90, XL, 3), vec3(-74.5F, 7.5F, 210), Green); //RIGHT
	AddWall(vec3(3, XL, 150), vec3(102.5F, 7.5F, 116.5F), Green); //LEFT
	AddWall(vec3(66, XL, 3), vec3(70.5F, 7.5F, 100), Green); //LEFT
	AddWall(vec3(55, XL, 3), vec3(-6.5F, 7.5F, 100), Green); //LEFT
	AddWall(vec3(3, XL, 15), vec3(40, 7.5F, 48), Green); //LEFT
	AddWall(vec3(3, XL, 15), vec3(68.5F, 7.5F, 56), Green); //LEFT
	AddWall(vec3(49, 3, 40), vec3(108, 13.5f, 200), Green); //PLATFORM
	AddWall(vec3(30, 30, 1), vec3(98.5F, 7, 200-33), Green, 60.f, vec3(1, 0, 0)); //RAMP
	AddWall(vec3(30, 30, 1), vec3(115, 7, 200-33), Green, 60.f, vec3(1, 0, 0)); //RAMP
	AddWall(vec3(30, 30, 1), vec3(98.5F, 7, 200 + 32.6F), Green, -60.f, vec3(1, 0, 0)); //RAMP
	AddWall(vec3(30, 30, 1), vec3(115, 7, 200 +32.6F), Green, -60.f, vec3(1, 0, 0)); //RAMP
	AddWall(vec3(3, XL+7, 170), vec3(82.5F, 7.5F+3.5F, 205), Green); //LEFT
	AddWall(vec3(3, XL, 180), vec3(102.5F, 7.5F, 335.5F), Green); //LEFT
	AddWall(vec3(3, XL, 40), vec3(82.5F, 7.5F, 330), Green); //LEFT
	AddWall(vec3(3, XL, 20), vec3(82.5F, 7.5F, 400), Green); //LEFT
	AddWall(vec3(3, XL, 20), vec3(82.5F, 7.5F, 440), Green); //LEFT
	AddWall(vec3(185, XL, 3), vec3(10, 7.5F, 390), Green); //LEFT
	AddWall(vec3(28, XL, 3), vec3(90, 7.5F, 350), Green); //LEFT
	AddWall(vec3(40, XL, 3), vec3(40, 7.5F, 350), Green); //LEFT
	AddWall(vec3(3, XL, 65), vec3(-31, 7.5F, 243), Green); //RIGHT
	AddWall(vec3(3, XL, 125), vec3(-31, 7.5F, 360), Green); //RIGHT
	AddWall(vec3(37, XL, 3), vec3(-12, 7.5F, 350), Green); //LEFT
	AddWall(vec3(60, XL, 3), vec3(-90, 7.5F, 350), Green); //RIGHT
	AddWall(vec3(30, XL, 3), vec3(14, 7.5F, 370), Green); //LEFT
	AddWall(vec3(30, XL, 3), vec3(-44.5, 7.5F, 297), Green); //RIGHT
	AddWall(vec3(3, XL, 75), vec3(-60, 7.5F, 261), Green); //RIGHT
	AddWall(vec3(3, XL, 75), vec3(-80, 7.5F, 261), Green); //RIGHT
	AddWall(vec3(20, XL, 3), vec3(-70, 7.5F, 225.5F), Green); //RIGHT
	AddWall(vec3(3, XL, 20), vec3(-31, 7.5F, 450), Green); //RIGHT
	AddWall(vec3(3, XL, 60), vec3(30, 7.5F, 420), Green); //RIGHT
	AddWall(vec3(3, XL, 42.8F), vec3(50, 7.5F, 370), Green); //RIGHT
	AddWall(vec3(1, 30, 60), vec3(30+14.5F, 7, 420), Green, 60.f, vec3(0, 0, 1)); //RAMP
	AddWall(vec3(1, 30, 40), vec3(102.5- + 14.5F, 7, 371), Green, -60.f, vec3(0, 0, 1)); //RAMP
	AddWall(vec3(20, 30, 1), vec3(-70, 7,225.5F+14.3F), Green, -60.f, vec3(1, 0, 0)); //RAMP
	AddWall(vec3(7, XXL, 800), vec3(-115.5F, 30, 100), Blue); //RIGHT
	AddWall(vec3(7, XXL, 800), vec3(130.5F, 30, 100), Blue); //LEFT
	AddWall(vec3(350, XXL, 7), vec3(0, 30, 450), Blue); //FINAL

	AddWall(vec3(350, XXL, 7), vec3(0, 30, -100), Blue); // START

	AddWall(vec3(1, 300, 1), vec3(0, 160, 425), Red); // BEACON

	AddWall(vec3(2000, 1, 2000), vec3(0, -0.5, 0), Color(1,1,1,1));
	App->audio->PlayMusic("assets/journey.ogg");
	time.Start();


	zones[0].init = { -100 , -175 };
	zones[0].end = { 175, 3 };

	zones[1].init = { -60,6 };
	zones[1].end = { 90, 100 };

	zones[2].init = { -85,50 };
	zones[2].end = { -25,180 };

	zones[3].init = { -170,3 };
	zones[3].end = { -60,180 };

	zones[4].init = { 100,3 };
	zones[4].end = { 130,180 };

	zones[5].init = { 60,100 };
	zones[5].end = { 100,180 };

	zones[6].init = { -25, 100 };
	zones[6].end = { 70,330 };

	zones[7].init = { 70,180 };
	zones[7].end = { 130,500 };

	zones[8].init = { -25, 330 };
	zones[8].end = { 60, 380 };

	zones[9].init = { -170,180 };
	zones[9].end = { -25,500 };

	zones[10].init = { -25, 380 };
	zones[10].end = { 40, 500 };

	for (int i = 0; i < NUM_ZONES; ++i)
	{
		zones[i].timer.Stop(); 
	}

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	PrintWalls();
	UpdateFans();
	CheckZones();


	for (uint i = 0; i < NUM_ZONES; i++)
	{
		if (zones[i].timer.isRunning())
		{
			
		}
	}



	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::PrintWalls() {

	p2List_item<Cube>* def_wall;
	def_wall = Walls.getFirst();

	while (def_wall != nullptr) {
		def_wall->data.Render();
		def_wall = def_wall->next;
	}
}
void ModuleSceneIntro::AddWall(vec3 size, vec3 position, Color color, float angle, vec3 rotvec, float mass) {

	Cube c(size.x, size.y, size.z);
	c.SetPos(position.x, position.y, position.z);

	if (angle != 0)
	{
		c.SetRotation(angle, vec3(rotvec.x, rotvec.y, rotvec.z));
	}

	c.color = color;
	App->physics->AddBody(c, mass);

	Walls.add(c);
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{

	if (body1 == FinishLane && body2 == (PhysBody3D*)App->player->Ball) {
		touched_the_sky = true;
		time.Stop();
		Uint32 helper = time.Read();
		if (helper <= finished_time) {
			finished_time = helper;
		}
		time.Start();

	}
}

PhysBody3D* ModuleSceneIntro::CreateFinishLane(vec3 size, vec3 pos) {

	Cube c(size.x, size.y, size.z);
	c.SetPos(pos.x, pos.y, pos.z);

	PhysBody3D* flane;
	flane = App->physics->AddBody(c, 0.0f);
	flane->collision_listeners.add(this);

	return flane;
}

void ModuleSceneIntro::CheckZones()
{
	int x, y;
	x = App->player->GetPos().x;
	y = App->player->GetPos().z;

	for (uint i = 0; i < NUM_ZONES; i++)
	{
		Zone check = zones[i]; 
		if (x > check.init.x && y > check.init.y && x < check.end.x && y < check.end.y)
		{
			zones[i].timer.Resume();
			LOG("Zone No. %i: %.2f", i, zones[i].timer.ReadSec());
		}
		else zones[i].timer.Stop();
	}
}

void ModuleSceneIntro::CreateFan(float x, float y, float z, Color color) {

	Cube c(1, 1, 1);
	c.SetPos(x, y, z);
	PhysBody3D* c_body = App->physics->AddBody(c, 0);

	Cube c2(0.1f, 7.5f, 1);
	c2.SetPos(x + 2, y, z);
	PhysBody3D* c2_body = App->physics->AddBody(c2, 1000);
	c2.color = color;


	App->physics->AddConstraintHinge(*c_body, *c2_body, { 0,0,0 }, { 0,8,0 }, { 0,0,1 }, { 1,0,0 }, true);
	Fan bl(c, c2, c_body, c2_body);
	fan.add(bl);
}

void ModuleSceneIntro::UpdateFans()
{
	for (p2List_item<Fan>* item = fan.getFirst(); item; item = item->next)
	{
		btQuaternion quat = item->data.body_cube_down->GetRotation();
		quat = quat.normalized();
		float angle = 2 * acos(quat.w()) * 180 / 3.14;
		float den = sqrt(1 - quat.w() *quat.w());
		item->data.cube_down.SetRotation(angle, { quat.x() / den,quat.y() / den,quat.z() / den });
		item->data.cube_down.SetPos(item->data.body_cube_down->GetPos().x(), item->data.body_cube_down->GetPos().y(), item->data.body_cube_down->GetPos().z());
		item->data.cube_down.Render();
	}
}
