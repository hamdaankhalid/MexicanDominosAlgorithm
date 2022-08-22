#pragma once

#include <vector>
#include <set>

#include "initial-chain-response.h"
#include "domino.h"

class BestInitialChain
{
public:
  InitialChainResponse Solve(vector<Domino>& dominos, int startingNumber, set<int> usedIdxs, int currSum, vector<Domino>& runningChainSoFar);
};