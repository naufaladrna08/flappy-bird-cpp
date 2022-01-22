#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include <GameState.hpp>

class Game {
  public:
    void Run();

  private:
    sf::RenderWindow* m_window;

    std::stack<State*> m_states;
};

#endif // __GAME_H__