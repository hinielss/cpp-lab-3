#include <iostream>

int Min(int a, int b) { return (a < b) ? a : b; }

int GetResult(int i, int n, const int array[], int first_sum, int second_sum) {
	if (i == n)
		return abs(second_sum - first_sum);
	int v1 = GetResult(i + 1, n, array, first_sum + array[i], second_sum);
	int v2 = GetResult(i + 1, n, array, first_sum, second_sum + array[i]);
	return Min(v1, v2);
}
