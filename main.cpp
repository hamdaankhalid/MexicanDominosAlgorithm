#include <iostream>
#include <vector>
#include "domino.h"
#include "best-initial-chain.h"
#include "initial-chain-response.h"

using namespace std;

// g++ main.cpp domino.cpp best-initial-chain.cpp initial-chain-response.cpp -o main -lstdc++

int main() {
  int n;

  cout << "Enter the N*N version of the game being played" << endl;
  
  cin >> n ;

  cout << "You will now be prompted till you input " << n << " total dominos" << endl;

  cout << "Each Domino pair can be entered with the following configuration => 'N,M' where N is "
          "the number on one side and M on the other" << endl;

  vector<Domino> dominos;

  string userInput;
  for (int i = 0; i < n; i++) {
    cout << "Enter domino " << i << endl;
    cin >> userInput;

    dominos.push_back(
      Domino::DominoFromString(userInput)
    );
  }

  int startingNumber;

  cout << "Enter the starting number" << endl;

  cin >> startingNumber;

  BestInitialChain b;
  set<int> usedIdxs;
  vector<Domino> runningchain;
  InitialChainResponse result = b.Solve(dominos, startingNumber, usedIdxs, 0, runningchain);

  cout << "******* Result ******" << endl;
  cout << "Best chain takes out a sum of: "<< result.ridOf << endl;

  for (int i = 0; i < result.chain.size(); i++) {
    cout << "Chain item " << i << ": "<< result.chain[i].side1 << ", " << result.chain[i].side2 << endl;
  }
}
