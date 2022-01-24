#include <GameState.hpp>

GameState::GameState(sf::RenderWindow* window)
  : State(window) {

}

GameState::~GameState() {
  delete m_bg[0];
  delete m_bg[1];
  delete im_bg;
}

void GameState::Init() {
  player = new Player();
  player->Init(sf::Vector2f(200.0f / 2.0f, 150.0f / 2.0f), 50.0f);
  
  im_bg = new sf::Texture;
  if (!im_bg->loadFromFile("assets/images/Background.png")) {
    std::cout << "Missing background texture" << std::endl;
  }

  for (int i = 0; i < 2; i++) {
    m_bg[i] = new sf::RectangleShape(sf::Vector2f(200.0f, 150.0f));
    m_bg[i]->setTexture(im_bg);
    m_bg[i]->setPosition(0, i * 200.0f);
  }
}

void GameState::Update(const float dt) {
  player->Update(dt);
}

void GameState::UpdateInput(sf::Event e) {
  if (e.type == sf::Event::KeyPressed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      player->Jump(200.0f);
  }
};


void GameState::Render(sf::RenderTarget* target) {
  target->draw(*m_bg[0]);
  target->draw(*m_bg[1]);
  target->draw(player->GetSprite());
}