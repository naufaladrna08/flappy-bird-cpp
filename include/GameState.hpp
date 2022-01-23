#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__
#include <State.hpp>
#include <Player.hpp>

class GameState : public State {
  public:
    GameState(sf::RenderWindow* window);
    ~GameState();

    void Update(const float dt);
    void UpdateInput(sf::Event e);
    void Render(sf::RenderTarget* target = nullptr);
    void Init();

  private:
    Player* player;
  
    sf::Texture* im_bg;
    sf::RectangleShape* m_bg;
};

#endif