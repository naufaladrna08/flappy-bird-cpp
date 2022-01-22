#include <Game.hpp>

void Game::Run() {
  sf::View mainView(sf::Vector2f(100.0f, 75.0f), sf::Vector2f(200.0f, 150.0f));

  m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Flappy Bird");
  m_window->setView(mainView);


  tx_player = new sf::Texture;
  if (!tx_player->loadFromFile("assets/images/FlappyBird.png")) {
    std::cout << "Missing player texture" << std::endl;
  }

  sp_player = new sf::Sprite(*tx_player);
  
  im_bg = new sf::Texture;
  if (!im_bg->loadFromFile("assets/images/Background.png")) {
    std::cout << "Missing background texture" << std::endl;
  }

  sf::RectangleShape m_bg;
  m_bg.setSize(sf::Vector2f(200.0f, 150.0f));
  m_bg.setTexture(im_bg);
  m_bg.setPosition(0, 0);

  while (m_window->isOpen()) {
    sf::Event e;

    while (m_window->pollEvent(e)) {
      if (e.type == sf::Event::Closed)
        m_window->close();
    }

    m_window->clear();
    m_window->draw(m_bg);
    m_window->draw(*sp_player);
    m_window->display();
  }
}