#pragma once
#include "GameObject.h"
class GameManager :
    public GameObject
{
private:
    int m_score;
    int m_lives;
    int m_level;
    bool m_playerActive;
    PictureIndex m_image;
public:
    GameManager();

    void Initialise();
    void Update(double frametime);
    void Render() override;
    void HandleEvent(Event evt) override;
    void StartLevel();
};

