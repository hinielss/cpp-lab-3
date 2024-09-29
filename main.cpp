#include <iostream>
#include <time.h>
#include "logic.h"

int main() {
  int n;
  std::cin >> n;
  int array[n];
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }

  clock_t start = clock();
  int res = GetResult(0, n, array, 0, 0);
  clock_t end = clock();

  std::cout << "Answer: " << res << "\n";
  std::cout << std::fixed << "Res calculated in " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
}
