#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3


class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemsIndex; }
private:
    int selectedItemsIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};