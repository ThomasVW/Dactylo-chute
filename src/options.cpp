#include <iostream>
#include <filesystem>
#include "options.h"
#include "menu.h"
using namespace std;


void Options::draw(sf::RenderWindow& window) {

    bool exitW = false;
    //Menu menu(window.getSize().x, window.getSize().y);

    sf::Texture t;
    t.loadFromFile("../resources/options.png");
    sf::Sprite s(t);

    std::wstring input_text;

    while (window.isOpen() && exitW ==false)
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
                case sf::Keyboard::Right:
                    MoveRight();
                    break;
                case sf::Keyboard::Left:
                    MoveLeft();
                    break;
                case sf::Keyboard::Return:
                    switch (GetPressedItem())
                    {
                    case 3:
                        exitW = true;
                        break;
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
        for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
        {
            window.draw(menuOptions[i]);
        }
        window.display();
    }
}
void Options::MoveUp()
{
    if (selectedItemsIndex_ - 1 >= 0) {
        menuOptions[selectedItemsIndex_].setFillColor(sf::Color::White);
        selectedItemsIndex_--;
        menuOptions[selectedItemsIndex_].setFillColor(sf::Color::Yellow);
    }
}

void Options::MoveDown()
{
    if (selectedItemsIndex_ + 1 < MAX_NUMBER_OF_ITEMS) {
        menuOptions[selectedItemsIndex_].setFillColor(sf::Color::White);
        selectedItemsIndex_++;
        menuOptions[selectedItemsIndex_].setFillColor(sf::Color::Yellow);
    }
}

void Options::MoveRight()
{
    if (selectedItemsIndex_ == 0)
    {
        if (selectedRapidite_ + 1 < 4) {

            selectedRapidite_++;
            menuOptions[0].setString("Vitesse : " + rapidite[selectedRapidite_]);
            menuOptions[0].setPosition(((WIDTH - menuOptions[0].getGlobalBounds().width) / 2), HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 2);
        }
    }
    if (selectedItemsIndex_ == 1)
    {
        if (selectedType_ + 1 < 2) {
            selectedType_++;
            menuOptions[1].setString("Type de Texte : " + typeTexte[selectedType_]);
            menuOptions[1].setPosition(((WIDTH - menuOptions[1].getGlobalBounds().width) / 2), HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 2.5);
        }
    }

    if (selectedItemsIndex_ == 2){
      if (selectedText_ + 1 < choixTexte.size()){
        selectedText_++;
        menuOptions[2].setString("Texte : " + choixTexte[selectedText_]);
        menuOptions[2].setPosition(((WIDTH - menuOptions[2].getGlobalBounds().width) / 2), HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 3);
      }
    }

}

void Options::MoveLeft()
{
    if (selectedItemsIndex_ == 0)
    {
        if (selectedRapidite_ - 1 >= 0) {
            selectedRapidite_--;
            menuOptions[0].setString("Vitesse : " + rapidite[selectedRapidite_]);
            menuOptions[0].setPosition(((WIDTH - menuOptions[0].getGlobalBounds().width) / 2), HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 2);
        }
    }
    if (selectedItemsIndex_ == 1)
    {
        if (selectedType_ - 1 >= 0) {
            selectedType_--;
            menuOptions[1].setString("Type de Texte : " + typeTexte[selectedType_]);
            menuOptions[1].setPosition(((WIDTH - menuOptions[1].getGlobalBounds().width) / 2), HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 2.5);
        }
    }


    if (selectedItemsIndex_ == 2){
      if (selectedText_ -1 >= 0){
        selectedText_--;
        menuOptions[2].setString("Texte : " + choixTexte[selectedText_]);
        menuOptions[2].setPosition(((WIDTH - menuOptions[2].getGlobalBounds().width) / 2), HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 3);
      }
    }

}

int Options::getRapidite() const{
  switch(selectedRapidite_){
    case 0: return 30;
    case 1: return 60;
    case 2: return 100;
    case 3: return 130;}
  return 200;}

Options::Options(float width, float height)
{
    if (!font_.loadFromFile("../resources/arial.ttf"))
      exit(0);

    for (const auto & entry : filesystem::directory_iterator("../resources/text/"))
      choixTexte.push_back(entry.path().filename());

    selectedItemsIndex_ = 0;
    selectedRapidite_ = 0;
    selectedType_ = 0;
    selectedText_ = 0;

    menuOptions[0].setFont(font_);
    menuOptions[0].setString("Vitesse : " + rapidite[selectedRapidite_]);
    menuOptions[0].setFillColor(sf::Color::Yellow);
    menuOptions[0].setPosition(((width - menuOptions[0].getGlobalBounds().width) / 2), height / (MAX_NUMBER_OF_ITEMS + 1) * 2);

    menuOptions[1].setFont(font_);
    menuOptions[1].setString("Type de Texte : " + typeTexte[selectedType_]);
    menuOptions[1].setFillColor(sf::Color::White);
    menuOptions[1].setPosition(((width - menuOptions[1].getGlobalBounds().width) / 2), height / (MAX_NUMBER_OF_ITEMS + 1) * 2.5);

    menuOptions[2].setFont(font_);
    menuOptions[2].setString("Texte : " + choixTexte[0]);
    menuOptions[2].setFillColor(sf::Color::White);
    menuOptions[2].setPosition(((width - menuOptions[2].getGlobalBounds().width) / 2), height / (MAX_NUMBER_OF_ITEMS + 1) * 3);

    menuOptions[3].setFont(font_);
    menuOptions[3].setString("Retour");
    menuOptions[3].setFillColor(sf::Color::White);
    menuOptions[3].setPosition(((width - menuOptions[3].getGlobalBounds().width) / 2), height / (MAX_NUMBER_OF_ITEMS + 1) * 3.5);

}

Options::Options(): Options::Options(1000,659){
}
