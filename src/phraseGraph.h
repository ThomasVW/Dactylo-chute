// Auteur: Flavien


#ifndef _PhraseGraph
#define _PhraseGraph
#include <assert.h>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class PhraseGraph: public std::vector<Text>
{
  Font* font_;
  Text LastMot_;
public:
  PhraseGraph(std::wstring str, Font* font);
  PhraseGraph();
  void updatePosAndDraw(double pChute, RenderWindow& window); // Mets à jour la position de chaque mots affiché
  void pushMot(const std::wstring& str, int windowWidth); //     et appelle draw() sur chaque element (mot) du vecteur
  bool popFront() { if(!this->empty()) {this->erase(this->begin()); return true;} return false;}
  void operator=(PhraseGraph &p);
};

#endif //_Phrase
