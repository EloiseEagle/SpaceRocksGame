#pragma once
#include "GameObject.h"
#include "HtAudio.h"

class Spaceship :
    public GameObject
{
private:
    Vector2D m_velocity;
    static const double ACCELERATION;
    static const double FRICTION;
    static const double TURNSPEED;
    static const double SIZE;
    SoundIndex m_thrustSound;
    bool m_isThrustPlaying;
    int m_thrustSoundChannel;
    Circle2D m_collisionShape;
    SoundIndex m_zapSound;
    bool m_isZapPlaying;
    int m_zapSoundChannel;
    SoundIndex m_explosionSound;
    int m_explosionSoundChannel;
    bool m_isExplosionPlaying;
    double m_shootDelay;
public:
    Spaceship();

    void Update(double frametime) override;

    void Initialise();

    void ProcessCollision(GameObject& other) override;

    IShape2D& GetCollisionShape() override;
};

