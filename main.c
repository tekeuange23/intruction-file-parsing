#include "parsing.h"

#define FILE_NAME_LENGTH 100
#define CLASS_LENGTH 10

int main(int argc, char **argv)
{
  char filename[FILE_NAME_LENGTH] = "dataflow.csv";
  FILE *file = NULL;

  /***********************************************************/
  /*      1- user enter the file name                        */
  /***********************************************************/
  // printf("Enter the filename: ");
  // scanf("%s", filename);
  printf("Filename: %s\n", filename);

  /***********************************************************/
  /*      2- file reading    (read only mode)                */
  /***********************************************************/
  file = fopen(filename, "r");
  if ((file == NULL))
  {
    fprintf(stderr, "\nError opened file \"%s\"\n", filename);
    exit(1);
  }

  /***********************************************************/
  /*      2 & 3a- file reading    (read only mode)           */
  /***********************************************************/
  printf("Parsing ...\n");

  int collection_iterator = 1;
  char c;
  for (c = getc(file); c != EOF; c = getc(file)) // count the total line in the file
  {
    // printf("%c", c);
    if (c == '\n')
      collection_iterator++;
  }
  printf("======== Size : %d =======\n", collection_iterator);

  Collection *collection = (Collection *)malloc(collection_iterator * sizeof(Collection));
  if (collection == NULL)
    exit(0);
  // Student *collection[i] = NULL;
  int i = 0;
  fseek(file, 0, SEEK_SET); // replace the cusor at the begining of the file

  printf("======== Reading ========= ...\n");
  while (!feof(file) && i < collection_iterator)
  {
    collection[i] = (Student *)malloc(sizeof(Student));
    collection[i]->name = (char *)malloc(NAME_LENGTH * sizeof(char));
    if (collection[i] == NULL || collection[i]->name == NULL)
      exit(0);

    fscanf(file, "%d, %d, %d, %d, %d, %d, %d, %s", &(collection[i]->id), &(collection[i]->scores[0]), &(collection[i]->scores[1]), &(collection[i]->scores[2]), &(collection[i]->scores[3]), &(collection[i]->scores[4]), &(collection[i]->scores[5]), collection[i]->name);
    i++;
  }

  printf("======== Printing ========\n");
  show_students(collection, collection_iterator);

  /***********************************************************/
  /*      2- file reading    (read only mode)                */
  /***********************************************************/

  fclose(file);
  return 0;
}

// print students
