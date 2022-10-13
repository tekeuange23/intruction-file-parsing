#ifndef PARSING_FILE
#define PARSING_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SCORES_LENGTH 6
#define NAME_LENGTH 100

typedef struct student
{
  int id;
  char *name;
  int scores[SCORES_LENGTH];
} Student;

typedef Student *Collection;

/***********************************************************/
/*                        Prototypes                       */
/***********************************************************/
Collection *read_students(Collection *collection, FILE *file);
void show_students(Collection *collection, int iterator);

#endif