#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
  public:
    void Run();

  private:
    sf::RenderWindow* m_window;

    sf::Sprite* sp_player;
    sf::Texture* tx_player;
    sf::RectangleShape* m_bg;
    sf::Texture* im_bg;
};

#endif // __GAME_H__