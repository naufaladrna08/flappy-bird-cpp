#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <Base.hpp>

class Player {
  public:
    Player();
    ~Player();

    void Init(std::string textureName, sf::Vector2f position, float mass);
    void Update(const float dt);
    void Jump(float velocity);
    sf::Sprite GetSprite();

  private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;

    int jumpCount = 0;
    float m_mass;
    float m_velocity;
    const float m_gravity = 9.80f;
    bool m_grounded;
};

#endif // __PLAYER_H__