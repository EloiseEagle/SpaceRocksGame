#pragma once
#include "GameObject.h"
class GameManager :
    public GameObject
{
private:
    int m_score;
    int m_lives;
    int m_level;
    PictureIndex m_image;
public:
    GameManager();

    void Initialise();

    void Render() override;

    void HandleEvent(Event evt) override;
};

