#include "phrase.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Phrase::Phrase(){}

void Phrase::loadFromFile(const char* path){
  this->clear();
  wifstream txtfile(path);
  txtfile.imbue(locale("en_US.utf8")); // Defini la locale pour les char speciaux dans les fichiers
  wstring line;
  wstring word;
  while(  getline(txtfile,line)){
    //wcout << line << endl;
    for (auto c : line){
      if(c != ' '){
        word += c;
      }
      else{
        this->push_back(word);
        word = L"";
      }
    }
    if (word != L"") {
      this->push_back(word);
      word = L"";
    }
  }
}


Phrase::Phrase(const char* path){
  loadFromFile(path);
}
