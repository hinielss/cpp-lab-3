#include <iostream>
#include "logic.h"

int main() {
  int n;
  std::cin >> n;
  int array[n];
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }
  int res = GetResult(0, n, array, 0, 0);
  std::cout << res << "\n";
}
