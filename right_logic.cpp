#include <stdio.h>
#include <stdlib.h>

int n;
int array[32];
int all_sum;

int CalculateRightResult(int i, int first_sum, int mask)
{
  if (mask > ~mask)
  {
    return all_sum;
  }
  else if (i == 0)
  {
    int double_first_sum = (first_sum << 1);
    int variant1;
    if (all_sum > double_first_sum)
      variant1 = all_sum - double_first_sum;
    else
      variant1 = double_first_sum - all_sum;

    int variant2;
    double_first_sum += (array[i] << 1);
    if (all_sum > double_first_sum)
      variant2 = all_sum - double_first_sum;
    else 
      variant2 = double_first_sum - all_sum;

    if (variant1 < variant2)
      return variant1;
    else
      return variant2;
  }
  else if (i != 0)
  {
    const int variant1 = CalculateRightResult(i - 1, first_sum + array[i], mask | (1 << i));
    if (variant1 == 0)
      return 0;
    else
    {
      const int variant2 = CalculateRightResult(i - 1, first_sum, mask);
      if (variant1 <= variant2)
        return variant1;
      else
        return variant2;
    }
  }
  else
  {
    const int double_first_sum = (first_sum << 1);
    if (all_sum > double_first_sum)
      return all_sum - double_first_sum;
    else
      return double_first_sum - all_sum;
  }
}

int GetRightResult(int input_n, int input_array[])
{
  all_sum = 0;
  n = input_n;
  for (int i = 0; i < n; i++)
  {
    array[i] = input_array[i];
    all_sum += array[i];
  }
  return CalculateRightResult(n - 1, 0, 0);
}
