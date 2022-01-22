#include <GameState.hpp>

GameState::GameState(sf::RenderWindow* window)
  : State(window) {

}

GameState::~GameState() {
  delete tx_player;
  delete sp_player;
  delete m_bg;
  delete im_bg;
}

void GameState::Init() {
  tx_player = new sf::Texture;
  if (!tx_player->loadFromFile("assets/images/FlappyBird.png")) {
    std::cout << "Missing player texture" << std::endl;
  }

  sp_player = new sf::Sprite(*tx_player);
  sp_player->setPosition(sf::Vector2f(40.0f, 60.0f));
  
  im_bg = new sf::Texture;
  if (!im_bg->loadFromFile("assets/images/Background.png")) {
    std::cout << "Missing background texture" << std::endl;
  }

  m_bg = new sf::RectangleShape(sf::Vector2f(200.0f, 150.0f));
  m_bg->setTexture(im_bg);
  m_bg->setPosition(0, 0);
}

void GameState::Update(const float dt) {

}

void GameState::Render(sf::RenderTarget* target) {
  target->draw(*m_bg);
  target->draw(*sp_player);
}