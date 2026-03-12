#include "Rock.h"
#include "ObjectManager.h"

Rock::Rock(): GameObject(ObjectType::ROCK)
{

}



void Rock::Update(double frametime)
{
	
	m_position = m_position + m_velocity * frametime;

	if (m_position.XValue > 1600)
	{
		m_velocity.XValue = 0 - m_velocity.XValue;
	}
	else if(m_position.XValue < -1600)
	{
		m_velocity.XValue = m_velocity.XValue * -1;
	}

	if (m_position.YValue > 1000)
	{
		m_velocity.YValue = 0 - m_velocity.YValue;
	}
	else if (m_position.YValue < -1000)
	{
		m_velocity.YValue = m_velocity.YValue * -1;
	}

	m_collisionShape.PlaceAt(m_position, 64*m_scale);

}

void Rock::ProcessCollision(GameObject& other)
{
	if (other.GetType() == ObjectType::BULLET)
	{
		Deactivate();
		if (m_scale > 0.8)
		{
			for (int i = 0; i < 3; i++)
			{
				Rock* pRock = new Rock;
				pRock->Initialise(m_position, m_angle, m_scale);
				ObjectManager::instance.AddItem(pRock);
				m_angle = m_angle + 120;
			}
		}

		Event evt;
		evt.type = EventType::ROCKDESTROYED;
		evt.pSource = this;
		evt.position = m_position;
		ObjectManager::instance.HandleEvent(evt);
	}
}

void Rock::Initialise()
{
	
	m_position.setBearing(rand() % 360, rand() % 1000 + 400);
	
	m_velocity.setBearing(rand() % 360, rand() % 190 + 40);
	m_angle = rand() % 360;
	int r = rand() % 4;
	if (r == 0)
	{
		LoadImage("assets/rock1.bmp");
	}
	if (r == 1)
	{
		LoadImage("assets/rock2.bmp");
	}
	if (r == 2)
	{
		LoadImage("assets/rock3.bmp");
	}
	if (r == 3)
	{
		LoadImage("assets/rock4.bmp");
	}
	m_scale = (rand() % 20 + 10) / 10.0;
	
	SetCollidable();
	
	SetHandleEvents();
}

void Rock::Initialise(Vector2D position, double angle, double size)
{
	m_position = position;

	m_angle = angle;

	m_velocity.setBearing(rand() % 360, rand() % 190 + 40);
	
	m_scale = size / 2;

	int r = rand() % 4;
	if (r == 0)
	{
		LoadImage("assets/rock1.bmp");
	}
	if (r == 1)
	{
		LoadImage("assets/rock2.bmp");
	}
	if (r == 2)
	{
		LoadImage("assets/rock3.bmp");
	}
	if (r == 3)
	{
		LoadImage("assets/rock4.bmp");
	}
	

	SetCollidable();

	SetHandleEvents();
}

IShape2D& Rock::GetCollisionShape()
{
	return m_collisionShape;
}