#include "Explosion.h"

Explosion::Explosion() : GameObject(ObjectType::EXPLOSION)
{
}

void Explosion::Initialise(Vector2D position)
{
	m_position = position;
	m_timer = 0;
	LoadImage("explosionA1.bmp");
	LoadImage("explosionA2.bmp");
	LoadImage("explosionA3.bmp");
	LoadImage("explosionA4.bmp");
	LoadImage("explosionA5.bmp");
	LoadImage("explosionA6.bmp");
	LoadImage("explosionA7.bmp");
	LoadImage("explosionA8.bmp");

	m_scale = 4;

	SetDrawDepth(35);
}

void Explosion::Update(double frametime)
{
	m_timer = m_timer + (frametime * 4);

	m_imageNumber = static_cast<int>(m_timer);

	if (m_timer >= 8)
	{
		Deactivate();
	}
}
