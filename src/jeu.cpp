#include <iostream>
#include <fstream>
#include "jeu.h"
#include "phrase.h"
#include "phraseGraph.h"
#include "score.h"

using namespace std;

void Jeu::applyOptions(){
      freqApparition_ = options_->getRapidite();
      switch(options_->getType()){
        case 0:
          {//tab = Phrase("../resources/text/Text1");
          nonPonctue(options_->getPath().c_str());
          tab_ = Phrase("../resources/Text_Non_Ponctue.txt");
          break;}
        case 1:
          {//tab = Phrase("../resources/text/Text2");
          tab_ = Phrase(options_->getPath().c_str());
          break;}
      }
}

void Jeu::draw(sf::RenderWindow& window) {

    int indiceApparition = 0;
    int indiceFrappe = 0;
    sf::Texture t;
    if(!t.loadFromFile("../resources/bg.png"))
      exit(0);
    sf::Sprite s(t);

    std::wstring input_text;
    sf::Font font;
    if(!font.loadFromFile("../resources/arial.ttf"))
      exit(0);
    sf::Text text("", font);
    sf::Clock clock;
    sf::Clock timer;
    sf::Clock apparitionTimer;

    applyOptions();


    PhraseGraph tabCharg_(tab_[0], &font);

    Score score_;

    bool exitW = false;

    while (window.isOpen() && !exitW)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::TextEntered){
                if (event.text.unicode == 8){// Backspace
                    if (!input_text.empty()){
                        input_text.pop_back();
                    }
                }
                else if (event.text.unicode >= 33){// Enleve les combinaisons control+touche
                    input_text += event.text.unicode;
                }
                else if (event.text.unicode == 8){
                    input_text = L"";
                }
                else if ((event.text.unicode == 32 || event.text.unicode == 13) && input_text == tab_[indiceFrappe]){
                    if (tabCharg_.popFront()){
                      if (indiceFrappe+1 < tab_.size()) indiceFrappe++;
                      else indiceFrappe = 0;
                      input_text = L"";
                      score_.setscore();

                      freqApparition_ ++;
                    }
                }
                else if (event.text.unicode == 27) exitW = true;

            }
            if (event.type == sf::Event::Resized) // Preciser la nouvelle taille pour eviter des etirements d'objets
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            if (!tabCharg_.empty()){
              if(tab_[indiceFrappe].find(input_text) != 0) {
                tabCharg_[0].setFillColor(sf::Color::Red);
                text.setFillColor(sf::Color::Red);
              }
              else {
                tabCharg_[0].setFillColor(sf::Color::White);
                text.setFillColor(sf::Color::White);
              }
            }
        }
        if (!tabCharg_.empty() && tabCharg_.front().getPosition().y > 600) {
            if (score_.getscore() > 10) score_.setMPM(freqApparition_ - 15); // il y a en moyenne 13 mots affichés à l'écran
            else score_.temps_de_frappe(timer.getElapsedTime().asSeconds());
            score_.draw(window);
            break;
        }

        static sf::Time text_effect_time;
        static bool show_cursor;

        text_effect_time += clock.restart();

        if (text_effect_time >= sf::seconds(0.5f)) // Clignotement du curseur
        {
            show_cursor = !show_cursor;
            text_effect_time = sf::Time::Zero;
        }

        static sf::Time mot_spawn_time;
        mot_spawn_time += apparitionTimer.restart();

        if (mot_spawn_time >= sf::seconds(60.0/(float)freqApparition_)){
          if (indiceApparition+1 < tab_.size()){
            indiceApparition++;
          }
          else indiceApparition = 0;
          tabCharg_.pushMot(tab_[indiceApparition], (int)window.getSize().x);
          mot_spawn_time = sf::Time::Zero;
        }
        text.setString(input_text + (show_cursor ? L"|" : L" "));

        text.setPosition((window.getSize().x - text.getLocalBounds().width - (show_cursor * 1.5f)) / 2, // posx, le showcursor*1.5f sert a fixer le texte lors du clignotement (difference d'espacement entre l'esepace et '|')
            window.getSize().y - 60.0f);

        window.clear(sf::Color::White);
        window.draw(s);
        window.draw(text);
        tabCharg_.updatePosAndDraw(1.6/freqApparition_, window);
        window.display();
    }
}

Jeu::Jeu(){}

void Jeu::nonPonctue(string path)
{
    ifstream fichier(path); //texte avec ponctutation
    ofstream fic("../resources/Text_Non_Ponctue.txt", ios::out | ios::trunc); //fichier de stockage du texte non ponctué
    if (fichier)
    {
        string ligne;
        while (getline(fichier, ligne))
        {
            //supprime la ponctuation des lignes du texte et les enregistre dans fic
            ligne.erase(std::remove_if(ligne.begin(), ligne.end(), ::ispunct), ligne.end());
            std::transform(ligne.begin(), ligne.end(), ligne.begin(),
    [](unsigned char c){ return std::tolower(c); });
            fic << ligne <<endl;
        }
    }
    fichier.close();
    fic.close();
}
