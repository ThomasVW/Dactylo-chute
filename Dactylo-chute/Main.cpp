#include <SFML/Graphics.hpp>
#include <locale>
#include <iostream>
#include "mot.h"
#include "Menu.h"
#include "Jeu.h"
using namespace std;

int main()
{
    sf::RenderWindow window({ 1000 ,659 }, "Dactylo-chute");

    Menu menu(window.getSize().x, window.getSize().y);
    Jeu jeu(window.getSize().x, window.getSize().y);
    
    // Create a sprite / background image
    sf::Texture t;
    t.loadFromFile("menu.png");
    sf::Sprite s(t);
   
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;
                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        cout << "Vous avez appuye sur le bouton Jeu !" << endl;
                        jeu.draw(window);
                        break;
                    case 1:
                        cout << "Vous avez appuye sur le bouton Options !" << endl;
                        break;
                    case 2:
                        cout << "Vous avez appuye sur le bouton Sortie !" << endl;
                        window.close();
                    }
                    break;
                }
                break;

            case sf::Event::Closed:
                window.close();
                break;
            }
        }
    window.clear();
    window.draw(s);
    menu.draw(window);
    window.display();
    }
}