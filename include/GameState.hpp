#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__
#include <State.hpp>

class GameState : public State {
  public:
    GameState(sf::RenderWindow* window);
    ~GameState();

    void Update(const float dt);
    void Render(sf::RenderTarget* target = nullptr);
    void Init();

  private:
    sf::Sprite* sp_player;
    sf::Texture* tx_player;
    sf::Texture* im_bg;
    sf::RectangleShape* m_bg;
};

#endif