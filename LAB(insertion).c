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

void insertionSort(int* A, int n)
{
  int i;
  int j, k, temp;

  for (i = 1; i < n; i++)
  {
    for (j = 0; j < i; j++)
    {
      if (A[j] > A[i])
      {
        break;
      }
    }

    temp = A[i];
    
    for (k = i; k > j; k--)
    {
      A[k] = A[k - 1];
    }
    A[j] = temp;
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

int main()
{
  srand(time(NULL));

  printf("임의의 정수 n을 입력하세요: ");
  int n;
  scanf("%d", &n);

  int *A = (int *)malloc(sizeof(int) * n);
  init_list(A, n);

  insertionSort(A, n);
  printA(A, n);
}
