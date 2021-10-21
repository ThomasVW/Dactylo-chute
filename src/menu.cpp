#include <SFML/Graphics.hpp>
#include <locale>
#include <iostream>
#include "menu.h"
#include "jeu.h"
#include "options.h"
using namespace std;

void Menu::draw(sf::RenderWindow& window)
{

    // Create a sprite / background image
    sf::Texture t;
    t.loadFromFile("../resources/menu.png");
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
                    MoveUp();
                    break;
                case sf::Keyboard::Down:
                    MoveDown();
                    break;
                case sf::Keyboard::Return:
                    switch (GetPressedItem())
                    {
                    case 0:
                        // cout << "Vous avez appuye sur le bouton Jeu !" << endl;
                        jeu_.draw(window);
                        break;
                    case 1:
                        // wcout << "Vous avez appuye sur le bouton Options !" << endl;
                        options_.draw(window);
                        break;
                    case 2:
                        // cout << "Vous avez appuye sur le bouton Sortie !" << endl;
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
        for (int i = 0; i < NB_ITEMS; i++)
            {
                window.draw(menu_[i]);
            }
        window.display();
    }
}

void Menu::MoveUp()
{
    if (selectedItemsIndex_ - 1 >= 0) {
        menu_[selectedItemsIndex_].setFillColor(sf::Color::White);
        selectedItemsIndex_--;
        menu_[selectedItemsIndex_].setFillColor(sf::Color::Yellow);
    }
}

void Menu::MoveDown()
{
    if (selectedItemsIndex_ + 1 < NB_ITEMS) {
        menu_[selectedItemsIndex_].setFillColor(sf::Color::White);
        selectedItemsIndex_++;
        menu_[selectedItemsIndex_].setFillColor(sf::Color::Yellow);
    }
}

Menu::Menu(float width, float height)
{
    if (!font_.loadFromFile("../resources/arial.ttf"))
      exit(0); // un message d'erreur est automatiquement affiché
    jeu_.setOptions(&options_);
    menu_[0].setFont(font_);
    menu_[0].setString("Jeu");
    menu_[0].setFillColor(sf::Color::Yellow);
    menu_[0].setPosition(((width - menu_[0].getGlobalBounds().width) / 2), height / (NB_ITEMS + 1) * 2);

    menu_[1].setFont(font_);
    menu_[1].setString("Options");
    menu_[1].setPosition(((width - menu_[1].getGlobalBounds().width) / 2), height / (NB_ITEMS + 1) * 2.5);

    menu_[2].setFont(font_);
    menu_[2].setString("Sortie");
    menu_[2].setPosition(((width - menu_[2].getGlobalBounds().width) / 2), height / (NB_ITEMS + 1) * 3);

    selectedItemsIndex_ = 0;
}
