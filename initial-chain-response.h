#pragma once

#include <vector>
#include "domino.h"

struct InitialChainResponse
{
  vector<Domino> chain;
  int ridOf;
};
