#include <locale>
#include <iostream>
#include "menu.h"
#include "phrase.h"

int main()
{

  std::ios_base::sync_with_stdio(false);
  std::wcout.imbue(std::locale("en_US.utf8"));
  sf::RenderWindow window({ 1000, 659}, "Dactylo-chute",sf::Style::Titlebar | sf::Style::Close);
  window.setFramerateLimit(120);


  Menu menu(window.getSize().x, window.getSize().y);
  menu.draw(window);
  window.display();
}
