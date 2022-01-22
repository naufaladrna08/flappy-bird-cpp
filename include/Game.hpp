#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <SFML/Graphics.hpp>

const int width = 800;
const int height = 600;

class Game {
  public:
    void Run();

  private:
    sf::RenderWindow* m_window;

    sf::Sprite* m_spr_player;
    sf::Texture* m_spr_texture;

    float m_gravity = 1;
};

#endif // __GAME_H__