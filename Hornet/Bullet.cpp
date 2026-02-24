#include "Bullet.h"

const double BULLET_LIFETIME = 0;

Bullet::Bullet() : GameObject(ObjectType::BULLET)
{

}

void Bullet::Initialise(Vector2D position, Vector2D velocity)
{
	m_position = position;
	m_velocity = velocity;
	LoadImage("assets/laserbolt.png");
	m_collisionShape.PlaceAt(m_position, 12);
	m_timer = BULLET_LIFETIME;
	SetCollidable();
	m_scale = 7.0;
	m_angle = m_velocity.angle();
}

void Bullet::Update(double frametime)
{
	m_timer = m_timer + frametime;
	m_position = m_position + m_velocity * frametime;

	if (m_timer > 3.0)
	{
		Deactivate();
	}
	if (m_timer < 0)
	{
		m_transparency = 1 - m_timer / 0.5;
	}

	m_collisionShape.PlaceAt(m_position, 4);
}

IShape2D& Bullet::GetCollisionShape()
{
	return m_collisionShape;
}

void Bullet::ProcessCollision(GameObject& other)
{
	if (other.GetType() == ObjectType::ROCK)
	{
		Deactivate();
	}
}