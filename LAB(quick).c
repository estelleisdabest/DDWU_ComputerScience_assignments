#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int my_rand(int max_number)
{
  int r = rand() % (max_number + 1);
  return r;
}

void init_list(int A[], int n)
{
  int i;
  for (i = 0; i < n; i++) {
    A[i] = my_rand(999);
  }
}

void printA(int* A, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int partition(int*A, int p, int r)
{
  int pivot = A[r];
  int temp;

  int pp = p;
  int rr = r - 1;

  while(pp < rr)
  {
    while(A[pp] < pivot && pp <= r)
    {
      pp++;
    }

    while(pivot < A[rr] && p <= rr)
    {
      rr--;
    }

    if (pp < rr)
    {
      temp = A[pp];
      A[pp] = A[rr];
      A[rr] = temp;
    }
  }

  temp = A[pp];
  A[pp] = pivot;
  A[r] = temp;
  return pp;
}

void quickSort(int* A, int p, int r)
{
  if (p < r)
  {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

int main()
{
  srand(time(NULL));

  printf("임의의 정수 n을 입력하세요: ");
  int n;
  scanf("%d", &n);

  int *A = (int *)malloc(sizeof(int) * n);
  init_list(A, n);
  quickSort(A, 0, n - 1);
  printA(A, n);
}
