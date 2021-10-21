#include <iostream>
#include "phraseGraph.h"

using namespace std;

sf::Clock fall;

PhraseGraph::PhraseGraph(wstring str,sf::Font* font){
  font_ = font;
  sf::Text premierMot(str, *font_);
  premierMot.setPosition(130,90);
  this->push_back(premierMot);
  LastMot_.setPosition(130,100);
}

PhraseGraph::PhraseGraph(){
}

void PhraseGraph::pushMot(const wstring & str, int windowWidth){
  sf::Text mot(str, *font_);
  if (!this->empty()) LastMot_ = this->back();
  mot.setPosition((int)(LastMot_.getPosition().x+20) % (windowWidth-185-(int)LastMot_.getLocalBounds().width) + 85, 90);
  this->push_back(mot);
}

void PhraseGraph::updatePosAndDraw(double pChute, sf::RenderWindow& window){
  static sf::Time fallTimer;
  fallTimer += fall.restart();
    for (int i = 0; i<(int)this->size(); i++){
      sf::Vector2f posi = (*this)[i].getPosition();
      if (fallTimer >= sf::seconds(pChute) && posi.y <1080) {
        (*this)[i].setPosition(posi.x, posi.y+1);
      }
      window.draw((*this)[i]);
    }

    if (fallTimer >= sf::seconds(pChute)) {
      fallTimer = sf::Time::Zero;
    }
}

void PhraseGraph::operator=(PhraseGraph &p){
  while (size() != p.size()){
    this->pop_back();
  }
  for (int i = 0; i < (int)this->size(); i++){
    (*this)[i] = p[i];
  }
}
