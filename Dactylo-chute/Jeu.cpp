#include <iostream>
#include "mot.h"
#include "Jeu.h"

#include "Score.h"
using namespace std;


int k = 0;

void Jeu::draw(sf::RenderWindow& window) {


    Score score(window.getSize().x, window.getSize().y);

    sf::Texture t;
    t.loadFromFile("bg.png");
    sf::Sprite s(t);

    std::wstring input_text;
    sf::Font font;
    font.loadFromFile("../resources/arial.ttf");
    sf::Text text("", font);
    sf::Clock clock;

    std::wstring tabmots[]= { L"Je",L"m" ,L"attendais",L"à",L"rien",L"et",L"je" ,L"suis" ,L"quand", L"même" ,L"décu", L"!" };

    Mot test(tabmots[k], &font);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::TextEntered){
                std::wcout << input_text << std::endl;
                if (event.text.unicode == 8){// Backspace
                    if (!input_text.empty()){
                        input_text.pop_back();
                    }
                }
                else if (event.text.unicode == 13){// Enter
                    input_text = L"";
                }
                else if (event.text.unicode >= 65){// Enleve les combinaisons control+touche
                    input_text += event.text.unicode;
                }
                else if (input_text == tabmots[k]){
                    input_text = L"";
                    std::wcout << "Good Job !" << std::endl;
                    k++;
                    Mot test(tabmots[k], &font);
                    draw(window);
                }
                
            }
            if (event.type == sf::Event::Resized) // Preciser la nouvelle taille pour éviter des etirements d'objets
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        }
        if (test.GetPosy() > 600 and input_text != tabmots[k]) {
            std::wcout << "Perdu !" << std::endl;
            score.draw(window);
        }

        static sf::Time text_effect_time;
        static bool show_cursor;

        text_effect_time += clock.restart();

        if (text_effect_time >= sf::seconds(0.5f)) // Clignotement du curseur
        {
            show_cursor = !show_cursor;
            text_effect_time = sf::Time::Zero;
        }
        text.setString(input_text + (show_cursor ? L"|" : L" "));

        text.setPosition((window.getSize().x - text.getLocalBounds().width - (show_cursor * 1.5f)) / 2, // posx, le showcursor*1.5f sert a fixer le texte lors du clignotement (difference d'espacement entre l'esepace et '|')
            window.getSize().y - 60.0f);
        test.upgetPos();

        window.clear(sf::Color::White);
        window.draw(s);
        window.draw(text);
        window.draw(test.getText());
        window.display();
    }
}
  

Jeu::Jeu(float width, float height)
{
}

Jeu::~Jeu()
{
}

