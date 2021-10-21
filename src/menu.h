// Auteur: Thomas
#ifndef _menu
#define _menu
#include <SFML/Graphics.hpp>
#include "jeu.h"
#include "options.h"

#define NB_ITEMS 3


class Menu
{
    int selectedItemsIndex_;
    sf::Font font_;
    sf::Text menu_[NB_ITEMS];
    Jeu jeu_;
    Options options_;
public:
    Menu(float width, float height);
    void draw(sf::RenderWindow& window); // Affiche le menu
    void MoveUp(); // Monter dans la sélection
    void MoveDown(); // Descendre dans la sélection
    int GetPressedItem() { return selectedItemsIndex_; }
};

#endif //_menu
