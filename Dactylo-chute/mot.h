#ifndef __mot__
#define __mot__

#include <SFML/Graphics.hpp>

class Mot
{
	sf::Text text_;
	int posx_;
	int posy_;
	bool cible;
public:
	Mot(std::wstring text, sf::Font* font, int px = 100);
	~Mot();
	int GetPosy() { return posy_; }
	sf::Text getText() const { return text_; }
	sf::Vector2<int> upgetPos();
};

#endif // __mot__