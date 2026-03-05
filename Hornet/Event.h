#pragma once
#include "vector2D.h"
enum EventType { NONE, EXPLOSION, OBJECTCREATED, OBJECTDESTROYED, SPACESHIPCREATED, SPACESHIPDESTROYED, ROCKDESTROYED, MISSIONCOMPLETE };

class GameObject;

struct Event
{
	GameObject* pSource;
	EventType type;
	Vector2D position;
	double data1;
	double data2;
};

