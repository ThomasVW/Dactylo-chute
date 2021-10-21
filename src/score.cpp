#include <iostream>
#include <string>
#include <fstream>
#include "score.h"
#include "menu.h"

using namespace std;


void Score::draw(sf::RenderWindow& window) {
    bool exitW = false;
    sf::Texture t;
    t.loadFromFile("../resources/score.png");
    sf::Sprite s(t);

    std::wstring input_text;
    sf::Text scoretext1("Vous avez ecrit " + to_string(scoreJoueur_) + " mots !", font_);
    scoretext1.setPosition(320, 320);

    sf::Text scoretext2("Soit environ " + to_string(motsParMinute_) + " mots par minute !", font_);
    scoretext2.setPosition(280, 385);

    while (window.isOpen() && exitW == false)
    {
        sf::Texture exitButton;
        sf::Sprite exitButtonImage;

        sf::Text nomdujoueur("", font_);
        nomdujoueur.setString(" Votre nom :  " + nomJoueur_);
        nomdujoueur.setPosition(320, 450);

        if (!exitButton.loadFromFile("../resources/Bouton suivant.png"))
            std::cout << "Can't find the image" << std::endl;
        exitButtonImage.setPosition(620, 508);

        float exitButtonWidth = exitButtonImage.getLocalBounds().width;
        float exitButtonHeight = exitButtonImage.getLocalBounds().height;
        exitButtonImage.setTexture(exitButton);

        sf::Event Event;

        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::TextEntered :
                if (Event.text.unicode == 8)
                {// Backspace
                    if (!input_text.empty())
                    {
                        input_text.pop_back();
                    }
                }
                else {
                    input_text += Event.text.unicode;
                }
                nomJoueur_ = string(input_text.begin(), input_text.end()); // convert wstring en string
                nomdujoueur.setString(" Votre nom :  " + nomJoueur_);
                nomdujoueur.setPosition(320, 450);
                break;

            case sf::Event::MouseButtonPressed:
               int x = Event.mouseButton.x;
               int  y = Event.mouseButton.y;
                if (Event.mouseButton.button == sf::Mouse::Left && x> 620 && x<771 && y > 508 && y<568) // Attention parametrage non responsive
                    {
                        MVPdraw(window);
                        exitW = true;
                    }

            }
        }
        window.clear(sf::Color::White);
        window.draw(s);
        window.draw(exitButtonImage);
        window.draw(nomdujoueur);
        window.draw(scoretext1);
        window.draw(scoretext2);
        window.display();

    }
}

void Score::MVPdraw(sf::RenderWindow& window) {

    bool exitW = false;


    sf::Texture t;
    t.loadFromFile("../resources/mvp.png");
    sf::Sprite s(t);

    chargeMVP();

    std::wstring input_text;
    sf::Text text("Meilleurs Scores :", font_);
    text.setPosition(380, 180);

    sf::Text score1("1. " + meilleur_joueur[0] +  " ~>  " + to_string(score_meilleur_joueur[0]), font_);
    score1.setPosition(380, 250);
    sf::Text score2("2. "+ meilleur_joueur[1] +" ~> " + to_string(score_meilleur_joueur[1]), font_);
    score2.setPosition(380, 310);
    sf::Text score3("3. "+ meilleur_joueur[2] + " ~>  " + to_string(score_meilleur_joueur[2]), font_);
    score3.setPosition(380, 370);
    sf::Text scorejoueurT(nomJoueur_ + "  votre score est de  " + to_string(motsParMinute_), font_);
    scorejoueurT.setPosition(280, 450);

    sf::Texture exitButton;
    sf::Sprite exitButtonImage;

    if (!exitButton.loadFromFile("../resources/Bouton quitter.png"))
        std::cout << "Can't find the image" << std::endl;
    exitButtonImage.setPosition(620, 508);
    float exitButtonWidth = exitButtonImage.getLocalBounds().width;
    float exitButtonHeight = exitButtonImage.getLocalBounds().height;
    exitButtonImage.setTexture(exitButton);

    sf::Texture menuButton;
    sf::Sprite menuButtonImage;

    if (!menuButton.loadFromFile("../resources/Bouton menu.png"))
        std::cout << "Can't find the image" << std::endl;
    menuButtonImage.setPosition(240, 508);

    float menuButtonWidth = menuButtonImage.getLocalBounds().width;
    float menuButtonHeight = menuButtonImage.getLocalBounds().height;
    menuButtonImage.setTexture(menuButton);

    while (window.isOpen() && exitW == false)
    {

        sf::Event Event;

        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                int x = Event.mouseButton.x;
                int  y = Event.mouseButton.y;
                if (Event.mouseButton.button == sf::Mouse::Left && x > 620 && x < 771 && y > 508 && y < 568) // Attention paramètrage non responsive
                {
                    enregistrermodification();
                    window.close();
                }
                if (Event.mouseButton.button == sf::Mouse::Left && x > 240 && x < 391 && y > 508 && y < 568)
                {
                    enregistrermodification();
                    exitW = true;
                }
                break;
            }
        }
        window.clear(sf::Color::White);
        window.draw(s);
        window.draw(exitButtonImage);
        window.draw(menuButtonImage);
        window.draw(text);
        window.draw(score1);
        window.draw(score2);
        window.draw(score3);
        window.draw(scorejoueurT);
        window.display();
    }
}

void Score::setscore()
{
    scoreJoueur_++;
}

void Score::chargeMVP()
{
    ifstream fichier("../resources/MVP.txt", ios::in);
    if (fichier)
    {
        fichier >> meilleur_joueur[0] >> meilleur_joueur[1] >> meilleur_joueur[2] >> score_meilleur_joueur[0] >> score_meilleur_joueur[1] >> score_meilleur_joueur[2];  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    if (motsParMinute_ > score_meilleur_joueur[0]) {
        score_meilleur_joueur[2] = score_meilleur_joueur[1];
        score_meilleur_joueur[1] = score_meilleur_joueur[0];
        score_meilleur_joueur[0] = motsParMinute_;
        meilleur_joueur[2] = meilleur_joueur[1];
        meilleur_joueur[1] = meilleur_joueur[0];
        meilleur_joueur[0] = nomJoueur_;
    }
    else if (motsParMinute_ > score_meilleur_joueur[1]) {
        score_meilleur_joueur[2] = score_meilleur_joueur[1];
        score_meilleur_joueur[1] = motsParMinute_;
        meilleur_joueur[2] = meilleur_joueur[1];
        meilleur_joueur[1] = nomJoueur_;
    }
    else if (motsParMinute_ > score_meilleur_joueur[2]) {
        score_meilleur_joueur[2] = motsParMinute_;
        meilleur_joueur[2] = nomJoueur_;
    }
}

Score::Score()
{
     if(!font_.loadFromFile("../resources/arial.ttf"))
        exit(0);
     scoreJoueur_ = 0;
}

Score::~Score()
{
}

void Score::enregistrermodification()
{
    //on enregistre les mvp dans un fichier .txt
    ofstream fic("../resources/MVP.txt", ios::out | ios::trunc);
    if (fic) {
        for (int j = 0; j < 3; j++) {
            fic << meilleur_joueur[j] << " ";
        }
        fic << endl;
        for (int j = 0; j < 3; j++) {
            fic << score_meilleur_joueur[j] << " ";
        }
        fic.close();
    }
    else { cout << "Impossible d'ouvrir le fichier"; };
}

void Score::temps_de_frappe(double temps) {
    motsParMinute_ = scoreJoueur_ * 60 / temps;
}
