#include "parsing.h"

void show_students(Collection *collection, int iterator)
{
  int i, j;
  for (i = 0; i < iterator; i++)
  {
    // printf("DATA line[%d]: %d %d %d %d %d %d %d %s \n", i, collection[i]->id, collection[i]->scores[0], collection[i]->scores[1], collection[i]->scores[2], collection[i]->scores[3], collection[i]->scores[4], collection[i]->scores[5], collection[i]->name);
    printf("DATA line[%d]: %d ", i, collection[i]->id);
    for (j = 0; j < SCORES_LENGTH; j++)
    {
      printf("%d ", collection[i]->scores[j]);
    }
    printf("%s \n", collection[i]->name);
  }
}
