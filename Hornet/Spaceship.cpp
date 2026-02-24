#include "Spaceship.h"
#include "HtKeyboard.h"
#include "HtAudio.h"
#include "Bullet.h"
#include "ObjectManager.h"

const double Spaceship::ACCELERATION = 500;
const double Spaceship::TURNSPEED = 90;
const double Spaceship::FRICTION = 0.5;
const double Spaceship::SIZE = 2;
const double BULLETSPEED = 800;

Spaceship::Spaceship() : GameObject(ObjectType::SPACESHIP)
{

}

void Spaceship::Initialise()
{
	m_position.set(0, 0);
	m_velocity.set(0, 0);
	LoadImage("assets/ship.bmp");
	m_thrustSound = HtAudio::instance.LoadSound("assets/thrustloop.wav");
	m_zapSound = HtAudio::instance.LoadSound("assets/zap.wav");
	m_isThrustPlaying = false;
	m_thrustSoundChannel = -1;
	m_zapSoundChannel = -1;
	m_scale = SIZE;
	SetCollidable();
	m_shootDelay = 0;
}

void Spaceship::ProcessCollision(GameObject& other)
{
	if (other.GetType() == ObjectType::ROCK)
	{
		Deactivate();
	}
}

void Spaceship::Update(double frametime)
{
	if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_A))
	{
		m_angle = m_angle - TURNSPEED * frametime;
	}
	if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_D))
	{
		m_angle = m_angle + TURNSPEED * frametime;
	}
	if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_W))
	{
		Vector2D acceleration;
		acceleration.setBearing(m_angle, ACCELERATION);
		m_velocity = m_velocity + acceleration * frametime;
		if (m_isThrustPlaying == false)
		{
			m_thrustSoundChannel = HtAudio::instance.Play(m_thrustSound, true);
			m_isThrustPlaying = true;
		}
		else
		{
			if (m_isThrustPlaying == true)
			{
				HtAudio::instance.Stop(m_thrustSoundChannel);
				m_isThrustPlaying = false;
			}
		}
	}
	m_shootDelay = m_shootDelay - frametime;
	if (HtKeyboard::instance.NewKeyPressed(SDL_SCANCODE_SPACE) && m_shootDelay <=0)
	{
		Bullet* pBullet = new Bullet();
		Vector2D bulletDirection;
		bulletDirection.setBearing(m_angle, BULLETSPEED);
		pBullet->Initialise(m_position, bulletDirection);
		ObjectManager::instance.AddItem(pBullet);
		m_shootDelay = 0.5;
		if (m_isZapPlaying == false)
		{
			m_zapSoundChannel = HtAudio::instance.Play(m_zapSound, true);
			m_isZapPlaying = true;
		}
		else
		{
			if (m_isZapPlaying == true)
			{
				HtAudio::instance.Stop(m_zapSoundChannel);
				m_isZapPlaying = false;
			}
		}
	}
	
	
	m_velocity = m_velocity - m_velocity * FRICTION * frametime;
	m_position = m_position + m_velocity * frametime;

	if (m_position.XValue > 1600)
	{
		m_velocity.XValue = 0 - m_velocity.XValue;
	}
	else if (m_position.XValue < -1600)
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

	m_collisionShape.PlaceAt(m_position, 64);
}

IShape2D& Spaceship::GetCollisionShape()
{
	return m_collisionShape;
}