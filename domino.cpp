#include <iostream>
#include <string>
#include "domino.h"

using namespace std;

Domino Domino::DominoFromString(const string& sides) {
  Domino domino;
  domino.side1 = stoi(&sides[0]);
  domino.side2 = stoi(&sides[2]);
  return domino;
}

int Domino::getSum() {
  return side1+side2;
}

void Domino::print() {
  cout << "Domino: side1 is " << side1 << " side2 " << side2 << endl;
}
