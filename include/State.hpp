#ifndef __STATE_H__
#define __STATE_H__

#include <iostream>
#include <SFML/Graphics.hpp>

class State {
  public:
    State(sf::RenderWindow* window);
    ~State();

    virtual void Update(const float &dt) = 0;
    virtual void Render(sf::RenderTarget* target = nullptr) = 0;
    virtual void Init() = 0;

  private:
    sf::RenderWindow* m_window;
};

#endif // __STATE_H__