
#include <stdio.h>
#include <string.h>


int calculateReverse(int n)
{
    int result = 0, last;

    while (n != 0) {
        last = n % 10;
        result = result * 10 + last;
        n /= 10;
    }
    return result;
}

int main(void)
{
    int n, rn;
    int count = 0;

    scanf("%d", &n);
    
    
  rn = calculateReverse(n);
  while (rn != n) {
        if (rn < 0) break;
        n += rn;
    rn = calculateReverse(n);
    count++;
  }

  if (rn < 0)
        printf("Overflow\n");
    else
        printf("%d %d\n", count, n);
}
