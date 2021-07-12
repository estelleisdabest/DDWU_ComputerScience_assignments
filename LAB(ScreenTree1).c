#define MAX_LEVEL 5
#define MAX_WIDTH 70
char screen[MAX_LEVEL][MAX_WIDTH];

#include <stdio.h>

void draw_tree(int rowIndex, int leftIndex, int rightIndex)
{
  if (rightIndex - leftIndex < 2) return; 
  int midIndex = (rightIndex + leftIndex) / 2;
  screen[rowIndex][midIndex] = 'x';
 
  draw_tree((rowIndex + 1), leftIndex, midIndex);
  draw_tree((rowIndex + 1), midIndex + 1, rightIndex);
    
}


void init(char s[][MAX_WIDTH])
{
  int i, j;
  for (i = 0; i < MAX_LEVEL; i++)
    for (j = 0; j < MAX_WIDTH;j++)
      s[i][j] = '-';
}

void display(char s[][MAX_WIDTH], int width)
{
  int i, j;
  for (i = 0; i < MAX_LEVEL; i++) {
    for (j = 0; j < width; j++)
      printf(" %c", s[i][j]);
    printf("\n");
  }
}

int main()
{
  int width;
  init(screen);

  printf("Enter a width(<= 70) of a screen:");
  scanf("%d", &width);

  draw_tree(0, 0, width - 1);
  display(screen, width);
}
