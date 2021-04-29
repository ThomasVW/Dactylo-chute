#ifndef __Jeu__
#define __Jeu__

#include <SFML/Graphics.hpp>
#include <string>

class Jeu
{
public:
	Jeu(float width, float height);
	~Jeu();
	void draw(sf::RenderWindow& window);

private:
	int vitesse_de_chute;
	//Joueur joueur_;
	// Phrase texte_;
	int freq_apparition;
	sf::Font font;
};

#endif // __Jeu__