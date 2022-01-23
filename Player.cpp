#include <Player.hpp>

Player::Player() {

}

Player::~Player() {

}

void Player::Init(sf::Vector2f position, float mass) {
  m_position = position;
  m_mass = mass;

  m_grounded = false;

  if (!m_texture.loadFromFile("assets/images/FlappyBird.png")) {
    std::cout << "Missing player texture" << std::endl;
  }

  m_sprite.setTexture(m_texture);
  m_sprite.setPosition(sf::Vector2f(40.0f, 60.0f));
  m_sprite.setOrigin(sf::Vector2f(8, 8));
}

void Player::Update(const float dt) {
  m_velocity -= m_mass * m_gravity * dt;
  m_position.y -= m_velocity * dt;

  m_sprite.setPosition(m_position);

  if (m_position.y >= 149.0f) {
    m_position.y = 149.0f;
    m_velocity = 0;
    m_grounded = true;
    jumpCount = 0;
  }
}

void Player::Jump(float velocity) {
  jumpCount++;
  m_velocity = velocity;
  m_grounded = false;
}

sf::Sprite Player::GetSprite() {
  return m_sprite;
}