#pragma once
#include "GameObject.h"
class Bullet :
    public GameObject
{
private:
    Vector2D m_velocity;
    double m_timer;
    static const double SPEED;
    Circle2D m_collisionShape;
public:
    Bullet();

    void Initialise(Vector2D position, Vector2D velocity);

    void Update(double frametime) override;

    IShape2D& GetCollisionShape() override;

    virtual void ProcessCollision(GameObject& other) override;
};

