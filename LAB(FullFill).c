#include <stdio.h>
#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT] = {
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1, 0, 0,-1,-1,-1, 0,-1,-1,
  -1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
  -1,-1,-1, 0,-1,-1,-1,-1,-1,-1,
  -1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
  -1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
  -1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
  -1,-1,-1, 0,-1, 0, 0, 0,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};

void flood_fill(int x, int y)
{
  if (screen[x][y] == 0)
  {
    screen[x][y] = 9;
    
    flood_fill((x - 1), y);
    flood_fill((x + 1), y);
    flood_fill(x, (y - 1));
    flood_fill(x, (y + 1));
  }
}

void print_all()
{
  for (int x = 0; x < HEIGHT; x++)
  {
    for (int y = 0; y < WIDTH; y++)
    {
      printf("%2d ", screen[x][y]);
    }
    printf("\n");
  }
}

int main()
{
  printf("\n");
  print_all();
  printf("\n");
  flood_fill(3, 3);
  print_all();
}
