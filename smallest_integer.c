#include <stdio.h>

int main(void)
{
  int N, NUM1, SMALL;
  int COUNT = 2;

  printf("Enter the Number of Integers to compare: ");
  scanf("%d", &N);
  printf("First Integer: ");
  scanf("%d", &NUM1);
  printf("Second Integer: ");
  scanf("%d", &SMALL);

  if (NUM1 < SMALL)
  {
    SMALL = NUM1;
  }

  while (COUNT != N)
  {
    printf("Enter the next Integer to compare: ");
    scanf("%d", &NUM1);

    if (NUM1 < SMALL)
    {
      SMALL = NUM1;
    }
    COUNT++;
  }
  printf("\nSmallest Number: %d ", SMALL);
}