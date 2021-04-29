#ifndef __Score__
#define __Score__

#include <SFML/Graphics.hpp>
#include <string>

class Score
{
public:
	Score(float width, float height);
	~Score();
	void draw(sf::RenderWindow& window);

private:
	sf::Font font;
	int score;
	string nom_du_joueur;
};

#endif // __Score__