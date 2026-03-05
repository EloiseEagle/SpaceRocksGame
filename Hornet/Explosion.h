#pragma once
#include "GameObject.h"
class Explosion :
    public GameObject
{
private:
    double m_timer;
public:
    Explosion();

    void Initialise(Vector2D position);

    void Update(double frametime) override;
};

