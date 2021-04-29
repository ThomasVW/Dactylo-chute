#include <iostream>
#include "mot.h"

sf::Clock clk;

Mot::Mot(std::wstring text, sf::Font* font, int px) {
    posx_ = px;
    posy_ = 0;
    cible = false;
    text_ = sf::Text(text, *font);
    std::wcout << "le mot " << text << " a ete cree" << std::endl;
}

Mot::~Mot() {
    std::wcout << "le mot " << (std::wstring)text_.getString() << " est supprime" << std::endl;
}

sf::Vector2<int> Mot::upgetPos() {
    static sf::Time speedTimer;
    static float freq = 0.04f;
    speedTimer += clk.restart();
    if (speedTimer >= sf::seconds(freq) && posy_ < 1000) {
        posy_+=2;
        posx_+=2;// cascade
        text_.setPosition(posx_, posy_);
        speedTimer = sf::Time::Zero;
    }
    if (posy_ == 670) { 
        posy_ = 0; 
        posx_ = 10;
    }

    return sf::Vector2<int>(posx_, posy_);
}