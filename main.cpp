#include <iostream>
#include <Game.hpp>


int main(int argc, char const *argv[]) {
  std::cout << "Start Engine..." << std::endl;

  Game game;
  game.Run();

  return 0;
}
