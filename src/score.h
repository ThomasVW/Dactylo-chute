// Auteur: Thomas
#ifndef _Score
#define _Score

#include <SFML/Graphics.hpp>
#include <string>

class Score
{
 	sf::Font font_;
 	int scoreJoueur_;
 	int motsParMinute_;
 	std::string nomJoueur_ = "Entrez votre nom";
 	std::string meilleur_joueur[3];
 	int score_meilleur_joueur[3];
public:
	Score();
	~Score();
	void draw(sf::RenderWindow& window); // Affiche le score de l'utilisateur
	void MVPdraw(sf::RenderWindow& window); // Affiche le top 3
 	void setscore();
 	int getscore() { return scoreJoueur_; };
	void resetScore() {scoreJoueur_ = 0;}
	void setMPM(int mpm) { motsParMinute_ = mpm;}
 	void temps_de_frappe(double temps); // calcule les mots par minutes avec (nb mots/temps écoulé) (pb avec accélération)
 	void enregistrermodification(); // enregistre le score dans le fichier des top 3
 	void chargeMVP(); // charge le fichier des top 3 utilisateurs

};

#endif // _Score
