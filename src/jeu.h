// Auteurs: Flavien, Thomas
#ifndef _Jeu
#define _Jeu

#include <SFML/Graphics.hpp>
#include <string>
#include "options.h"
#include "phrase.h"
#include "phraseGraph.h"
#include "score.h"

class Jeu
{
	Options* options_;
	Score score_; // Mots par minute max
	Phrase tab_; // Pour les mots du fichier texte
	PhraseGraph tabCharg_; // Pour les mots à afficher à l'écran
	int freqApparition_; // En mots par minute
public:
	Jeu();
	void draw(sf::RenderWindow& window); // Affiche cette fenêtre
	void setOptions(Options* options) {options_ = options;}
	void applyOptions(); // Lie la classe options aux paramètres de la classe jeu
	void nonPonctue(string path); // (Thomas) créé un fichier temporaire sans ponctuation pour un texte plus simple
};

#endif // _Jeu
