#include <stdio.h>

int COINS[4] = {10, 50, 100, 500};

int pick(int* picked, int change, int pocket, int toPick)
{
 
  int n = 4;
  int m = (change / 10);
  int i, lastIndex, smallest, item;
  int pickedIndex;
  lastIndex = m - toPick - 1;

  if (pocket == change)
  {
    return 1;
  }
 
  else if (pocket > change)
  {
    return 0;
  }

  else
  {
    if (m == toPick)
    {
      smallest = 0;
    }
    else
    {
      smallest = picked[lastIndex];
    }

    int count = 0;
    for (item = smallest; item < n; item++)
    {
      picked[lastIndex + 1] = item;
      int c = COINS[item];
      count += pick(picked, change, pocket + c, toPick - 1);
    }
    return count;
  }
}

int main()
{
  int change;
 
  printf("입력: ");
  scanf("%d", &change);
  int n = change / 10;
  int picked[n];

  int count = pick(picked, change, 0, n);
  printf("%d\n", count);
}
