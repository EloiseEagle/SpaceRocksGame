#include "GameManager.h"
#include "HtGraphics.h"

GameManager::GameManager() : GameObject(ObjectType::GAMEMANAGER)
{
}

void GameManager::Initialise()
{
	m_score = 0;
	m_lives = 3;
	m_level = 1;
	m_image = HtGraphics::instance.LoadPicture("assets/ship.bmp");

	SetDrawDepth(10);
}

void GameManager::HandleEvent(Event evt)
{
	if (evt.type == EventType::ROCKDESTROYED)
	{
		m_score = m_score + 100;
	}
	if (evt.type == EventType::SPACESHIPDESTROYED)
	{
		m_lives = m_lives - 1;
	}
}

void GameManager::Render()
{
	HtGraphics::instance.WriteTextAligned(1100, 900, "Score: ", HtGraphics::WHITE, 1, 2);
	HtGraphics::instance.WriteIntAligned(1400,900, m_score, HtGraphics::WHITE, 1, 2);

	HtGraphics::instance.WriteTextAligned(-1600, 900, "Level: ", HtGraphics::WHITE, 1, 2);
	HtGraphics::instance.WriteIntAligned(-1300, 900, m_level, HtGraphics::WHITE, 1, 2);

	HtGraphics::instance.WriteTextAligned(1100, 750, "Lives: ", HtGraphics::WHITE, 1, 2);
	if (m_lives == 1)
	{
		HtGraphics::instance.DrawAt(Vector2D(1450.0, 690.0), m_image, 1.5, 0, 0, FlipType::NONE);
	}
	else if (m_lives == 2)
	{
		HtGraphics::instance.DrawAt(Vector2D(1450.0, 690.0), m_image, 1.5, 0, 0, FlipType::NONE);
		HtGraphics::instance.DrawAt(Vector2D(1550.0, 690.0), m_image, 1.5, 0, 0, FlipType::NONE);
	}
	else
	{
		HtGraphics::instance.DrawAt(Vector2D(1450.0, 690.0), m_image, 1.5, 0, 0, FlipType::NONE);
		HtGraphics::instance.DrawAt(Vector2D(1550.0, 690.0), m_image, 1.5, 0, 0, FlipType::NONE);
		HtGraphics::instance.DrawAt(Vector2D(1650.0, 690.0), m_image, 1.5, 0, 0, FlipType::NONE);
	}
}


