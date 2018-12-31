#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"




ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	CreateVehicle();

	s.radius = 2;
	s.color = Blue;	
	s.SetPos(0, 5, -40);
	Ball = App->physics->AddBody(s, 150);

	vehicle->SetPos(0, 12, -60);

	App->audio->LoadFx("assets/lose.wav");
	App->audio->LoadFx("assets/win.wav");

	
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

update_status ModulePlayer::Update(float dt)
{
	if (App->scene_intro->touched_the_sky) 
	{
		App->scene_intro->touched_the_sky = false;
		InitialPosition();
		App->audio->PlayFx(1);
	}
	if (lose) 
	{
		lose = false;
		InitialPosition();
		App->scene_intro->time.Stop();
		App->scene_intro->time.Start();
		App->audio->PlayFx(2);
	}
	
	CheckTime(); 
	UpdateVehicle(); 

	Ball->GetTransform(&s.transform);
	vehicle->Render();
	s.Render();

	return UPDATE_CONTINUE;
}


void ModulePlayer::ResetPosition()
{
	turn = acceleration = brake = 0.0f;
	vehicle->SetRotation({ 0, vehicle->vehicle->getForwardVector().getX(), 0, vehicle->vehicle->getForwardVector().getZ()});

	vehicle->SetPos(GetPos().x, GetPos().y + 5, GetPos().z);
}

void ModulePlayer::InitialPosition()
{
	vehicle->SetPos(0, 12, -60);
	Ball->SetPos(0, 5, -40);
	s.SetPos(0, 5, -40);
	brake = BRAKE_POWER;
}

void ModulePlayer::UpdateVehicle()
{
	turn = acceleration = brake = 0.0f;

	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
	}

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		if (turn < TURN_DEGREES)
			turn += TURN_DEGREES;
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		if (turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		acceleration = -MAX_ACCELERATION * 0.5;
	}

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		ResetPosition();
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
	{
		brake = BRAKE_POWER;
	}

	if (App->input->GetKey(SDL_SCANCODE_Q) == KEY_REPEAT)
	{
		look_up += LOOK_UP_SPEED;
		if (look_up >= MAX_LOOK_UP)
			look_up = MAX_LOOK_UP;
	}
	if (App->input->GetKey(SDL_SCANCODE_Q) == KEY_IDLE)
	{
		look_up -= LOOK_UP_SPEED;
		if (look_up <= STANDARD_LOOK_UP)
			look_up = STANDARD_LOOK_UP;
	}

	if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN)
	{
		InitialPosition();
		App->scene_intro->time.Stop();
		App->scene_intro->time.Start();
	}

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);
}

void ModulePlayer::CheckTime()
{
	Uint32 act_time = App->scene_intro->time.Read();
	char title[120];
	sprintf_s(title, "--- PutTheBolInTheHold --- Time: %.1f s || Best_time: %1.f || Time To Beat: 240 seconds ||", (float)act_time / 1000, (float)App->scene_intro->finished_time);
	App->window->SetTitle(title);

	if (act_time >= 240000) {
		lose = true;
	}
}

void ModulePlayer::CreateVehicle()
{

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(3, 2, 6);
	car.chassis_offset.Set(0, 1.5, 0);
	car.pale_size.Set(6, 3, 1);
	car.pale_offset.Set(0, 2, 2.9);
	car.cabin_size.Set(1, 1, 2);
	car.cabin_offset.Set(-0.5, 3, 0);
	car.mass = 500.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.5f;
	float wheel_radius = 0.9f;
	float wheel_width = 0.12f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;

	vec3 direction(0, -1, 0);
	vec3 axis(-1, 0, 0);

	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
}

vec3 ModulePlayer::GetPos()
{
	return vec3(vehicle->GetPos().getX(), vehicle->GetPos().getY(), vehicle->GetPos().getZ());
}

// Update: draw background
