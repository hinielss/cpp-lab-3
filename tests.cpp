#include <iostream>
#include <random>
#include <cassert>
#include "logic.h"
#include "right_logic.h"

using namespace std;

void RunTests() {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> n_dist(1, 32);
  uniform_int_distribution<> j_dist(1, 100000000);

  for (int i = 0; i < 100; i++) {
    int n = n_dist(gen);
    int array[n];
    for (int j = 0; j < n; j++) {
      array[j] = j_dist(gen);
    }
    int res1 = GetRightResult(n, array);
    cout << "res1 calculated\n";
    int res2 = GetResult(0, n, array, 0, 0);
    cout << "res2 calculated\n";
    assert(res1 == res2);
    cout << "Test №" << i + 1 << " completed\n";
  }
}

int main() {
  RunTests();
}