#include <Game.hpp>

void Game::Run() {
  sf::View mainView(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(200.0f, 150.0f));

  m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Flappy Bird");
  m_window->setView(mainView);

  tx_player = new sf::Texture;
  if (!tx_player->loadFromFile("assets/images/FlappyBird.png")) {
    std::cout << "Missing player texture" << std::endl;
  }

  sp_player = new sf::Sprite(*tx_player);

  while (m_window->isOpen()) {
    sf::Event e;

    while (m_window->pollEvent(e)) {
      if (e.type == sf::Event::Closed)
        m_window->close();
    }

    m_window->clear();
    m_window->draw(*sp_player);
    m_window->display();
  }
}