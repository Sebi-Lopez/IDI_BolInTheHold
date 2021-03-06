#pragma once

#include "PugiXml\src\pugixml.hpp"
#include "p2SString.h"

class Application;
struct PhysBody3D;

class Module
{
private :
	bool enabled;

public:
	Application* App;

	p2SString name;

	Module(Application* parent, bool start_enabled = true) : App(parent)
	{}

	virtual ~Module()
	{}

	virtual bool Init() 
	{
		return true; 
	}

	virtual bool Start()
	{
		return true;
	}

	virtual update_status PreUpdate(float dt)
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status Update(float dt)
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status PostUpdate(float dt)
	{
		return UPDATE_CONTINUE;
	}

	virtual bool CleanUp() 
	{ 
		return true; 
	}

	virtual bool Save(pugi::xml_node&)
	{
		return true;
	}

	virtual void OnCollision(PhysBody3D* body1, PhysBody3D* body2)
	{}
};