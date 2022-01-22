#include <Game.hpp>

void Game::Run() {
  m_window = new sf::RenderWindow(sf::VideoMode((float) width, (float) height), "Game");

  sf::View mainView(sf::Vector2f(0, 0), sf::Vector2f(width / 4, height / 4));
  m_window->setView(mainView);

  m_spr_texture = new sf::Texture();
  if (!m_spr_texture->loadFromFile("Assets/Player.png")) {
    std::cout << "Missing player texture" << std::endl;
  }

  m_spr_player = new sf::Sprite(*m_spr_texture);

  while (m_window->isOpen()) {
    sf::Event e;

    while (m_window->pollEvent(e)) {
      if (e.type == sf::Event::Closed)
        m_window->close();
    }

    m_window->clear(sf::Color::White);
    m_window->draw(*m_spr_player);
    m_window->display();
  }
}