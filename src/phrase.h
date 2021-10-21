// Auteur: Flavien
#ifndef _Phrase
#define _Phrase
#include <vector>
#include <string>

using namespace std;

class Phrase: public vector<wstring>
{
public:
  Phrase();
  Phrase(const char* path);
  void loadFromFile(const char* path); // Charger le texte d'un fichier situé dans "path" dans le vecteur de Phrase
};

#endif //_Phrase
