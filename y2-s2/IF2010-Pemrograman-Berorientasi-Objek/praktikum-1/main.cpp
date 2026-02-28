#include "Paper.hpp"
#include <iostream>

using namespace std;

int main() {
  Paper *a = new Paper('A');
  Paper b('B');
  Paper c('C');
  Paper ccopy(c);

  a->fold();
  b.fold();
  c.fold();

  c.glue();

  delete a;

  c.setName('X');
  ccopy.fold();
  ccopy.glue();

  return 0;
}
