#include <Game.hpp>

void Game::Run() {
  sf::View mainView(sf::Vector2f(100.0f, 75.0f), sf::Vector2f(200.0f, 150.0f));
  m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Flappy Bird");
  m_window->setView(mainView);
  m_window->setFramerateLimit(60);

  /* Init state */
  if (m_states.empty())
    m_states.push(new GameState(m_window));

  m_states.top()->Init();


  while (m_window->isOpen()) {
    sf::Event e;

    while (m_window->pollEvent(e)) {
      if (e.type == sf::Event::Closed)
        m_window->close();
    }

    sf::Time dt = m_clock.restart();
    m_states.top()->Update(dt.asSeconds());

    m_window->clear();
    m_states.top()->Render(this->m_window);
    m_window->display();
  }
}