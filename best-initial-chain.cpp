#include <vector>
#include <set>

#include "domino.h"
#include "best-initial-chain.h"
#include "initial-chain-response.h"

InitialChainResponse BestInitialChain::Solve(vector<Domino>& dominos, int startingNumber, set<int> usedIdxs, int currSum, vector<Domino>& runningChainSoFar) { 
  vector<int> candidateIdx;
  for (int i = 0; i < dominos.size(); i ++) {
    if (usedIdxs.find(i) != usedIdxs.end()) {
      continue;
    }
    
    Domino candidate = dominos[i];
    if (candidate.side1 == startingNumber || candidate.side2 == startingNumber) {
      candidateIdx.push_back(i);
    }
  }
  
  if (candidateIdx.size() == 0) {
    InitialChainResponse icr;
    icr.chain = runningChainSoFar;
    icr.ridOf = currSum;
    return icr;
  }

  vector<Domino> bestDominoChain;
  int bestSum = 0;
  for (int i = 0; i < candidateIdx.size(); i++) {

    if (usedIdxs.find(candidateIdx[i]) != usedIdxs.end()) {
      continue;
    }

    Domino candidateDomino = dominos[candidateIdx[i]];

    // does domino have either side that fits the startingNumber?
    if (candidateDomino.side1 == startingNumber) {

      usedIdxs.insert(candidateIdx[i]);
      runningChainSoFar.push_back(candidateDomino);

      InitialChainResponse scenario1 = BestInitialChain::Solve(dominos, candidateDomino.side2, usedIdxs, currSum + candidateDomino.getSum(), runningChainSoFar);
      
      usedIdxs.erase(candidateIdx[i]);
      runningChainSoFar.pop_back();

      if (scenario1.ridOf >= bestSum) {
        bestSum = scenario1.ridOf;
        bestDominoChain = scenario1.chain;
      }
    }

    if (candidateDomino.side2 == startingNumber) {

      usedIdxs.insert(candidateIdx[i]);
      runningChainSoFar.push_back(candidateDomino);

      InitialChainResponse scenario2 = BestInitialChain::Solve(dominos, candidateDomino.side1, usedIdxs, currSum + candidateDomino.getSum(), runningChainSoFar);

      usedIdxs.erase(candidateIdx[i]);
      runningChainSoFar.pop_back();

      if (scenario2.ridOf >= bestSum) {
        bestSum = scenario2.ridOf;
        bestDominoChain = scenario2.chain;
      }
    }
  }

  InitialChainResponse i;
  i.chain = bestDominoChain;
  i.ridOf = bestSum;
  return i;
}
