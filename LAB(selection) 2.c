#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int my_rand(int max_number)
{
  int r = rand() % (max_number + 1);
  return r;
}

int scan_max_index(int list[], int end_index)
{
  int i;
  int max_index = 0;

  for (i = 1; i <= end_index; i++)
  {
    int a = list[max_index];
    int b = list[i];
    if (a < b) 
    {
      max_index = i;
    }
  }

  return max_index;
}
void selectionSort(int list[], int n)
{

  int i, max_index, end_index;
  for (i = 0; i < (n - 1); i++)
  {
    end_index = (n - 1 - i);
    int end = list[end_index];
    
    max_index = scan_max_index(list, end_index);
    int min = list[max_index];

    list[end_index] = min;
    list[max_index] = end;
  }
}

int main()
{
  srand(time(NULL));
  
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  int *list = (int *)malloc(sizeof(int) * n);
  int i;
  for (i = 0; i < n; i++) {
    int number = my_rand(999);
    list[i] = number;
  }

  for (i = 0; i < n;i++)
  {
    int number = list[i];
    printf("%d ", number);
  }
  printf("\n");

  selectionSort(list, n);
  printf("정렬된 후:\n");
  for (i = 0; i < n; i++)
  {
    int number = list[i];
    printf("%d ", number);
  }
  printf("\n");
}
