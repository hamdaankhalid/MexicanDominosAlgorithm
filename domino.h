#pragma once
#include <iostream>

using namespace std;

class Domino {
  public:
    int side1;
    int side2;

    static Domino DominoFromString(const string& sides);

    int getSum();

    void print();
};