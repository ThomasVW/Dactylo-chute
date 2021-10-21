// Auteurs: Flavien, Thomas
#ifndef _Options
#define _Options

#define MAX_NUMBER_OF_ITEMS 4
#define WIDTH 1000
#define HEIGHT 659


#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Options
{
	int selectedItemsIndex_;
	int selectedRapidite_;
 	int selectedType_;
	int selectedText_;
  sf::Font font_;
  sf::Text menuOptions[MAX_NUMBER_OF_ITEMS];
 	std::string rapidite[4] = { "Lente (30 mpm)","Moyenne (60 mpm)","Rapide (100 mpm)","Ludicrous (130 mpm)" };
 	std::string typeTexte[2] = { "Basique","Ponctue"};
  std::vector<std::string> choixTexte;
public:
	Options(float width, float height);
	Options();
	void draw(sf::RenderWindow& window); // Affiche les options
	void MoveUp(); // option précédente
	void MoveDown(); // option suivante
	void MoveRight(); // choix du paramètre
	void MoveLeft(); // choix du paramètre
	int GetPressedItem() const { return selectedItemsIndex_; }
	int getRapidite() const; // lie la sélection avec les mots par minutes
	int getType() const { return selectedType_; }
	std::string getPath() const { return "../resources/text/" + choixTexte[selectedText_]; }
};

#endif // __Options__
