#include <iostream>
#include "Score.h"
using namespace std;


void Score::draw(sf::RenderWindow& window) {

    sf::Texture t;
    t.loadFromFile("score.png");
    sf::Sprite s(t);

    std::wstring input_text;
    sf::Font font;
    font.loadFromFile("../resources/arial.ttf");
    sf::Text text("", font);

    while (window.isOpen())
    {
        window.clear(sf::Color::White);
        window.draw(s);
        window.draw(text);
        window.display();
    }
}


Score::Score(float width, float height)
{
}

Score::~Score()
{
}