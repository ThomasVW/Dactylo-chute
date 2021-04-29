#include "Menu.h"

void Menu::draw(sf::RenderWindow& window)
{
    for (int i=0;i<MAX_NUMBER_OF_ITEMS;i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemsIndex - 1 >= 0) {
        menu[selectedItemsIndex].setFillColor(sf::Color::White);
        selectedItemsIndex--;
        menu[selectedItemsIndex].setFillColor(sf::Color::Green);
    }
}

void Menu::MoveDown()
{
    if (selectedItemsIndex + 1 < MAX_NUMBER_OF_ITEMS) {
        menu[selectedItemsIndex].setFillColor(sf::Color::White);
        selectedItemsIndex++;
        menu[selectedItemsIndex].setFillColor(sf::Color::Green);
    }
}

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("../resources/arial.ttf"))
    {
        //handle error
    }
    menu[0].setFont(font);
    menu[0].setString("Jeu");
    menu[0].setFillColor(sf::Color(100, 250, 50));
    menu[0].setPosition(((width - 30 -menu[0].getGlobalBounds().width) / 2), height / (MAX_NUMBER_OF_ITEMS + 1) * 2);

    menu[1].setFont(font);
    menu[1].setString("Options");
    menu[1].setPosition(((width - 30 - menu[0].getGlobalBounds().width) / 2), height / (MAX_NUMBER_OF_ITEMS + 1) * 2.5);

    menu[2].setFont(font);
    menu[2].setString("Sortie");
    menu[2].setPosition(((width - 30 - menu[0].getGlobalBounds().width) / 2), height / (MAX_NUMBER_OF_ITEMS + 1) * 3);

    selectedItemsIndex = 0;
}

Menu::~Menu()
{
}

