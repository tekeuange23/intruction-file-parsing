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
  {
    // printf("Enter the filename: ");
    // scanf("%s", filename);
    printf("Filename: %s\n", filename);
  }

  /***********************************************************/
  /*      2- file reading    (read only mode)                */
  /***********************************************************/
  {
    file = fopen(filename, "r");
    if ((file == NULL))
    {
      fprintf(stderr, "\nError opened file \"%s\"\n", filename);
      exit(1);
    }
  }

  /***********************************************************/
  /*      2 & 3a- file reading    (read only mode)           */
  /***********************************************************/
  printf("Parsing ...\n");
  int collection_iterator = 1;
  char c;
  {
    for (c = getc(file); c != EOF; c = getc(file)) // count the total line in the file
    {
      // printf("%c", c);
      if (c == '\n')
        collection_iterator++;
    }
    printf("======== Size : %d =======\n", collection_iterator);
  }

  // char buffer[collection_iterator][100];
  Collection *collection = (Collection *)malloc(collection_iterator * sizeof(Collection));
  if (collection == NULL)
    exit(0);
  int i = 0;

  fseek(file, 0, SEEK_SET); // replace the cusor at the begining of the file

  printf("======== Reading ========= ...\n");
  {
    while (!feof(file) && i < collection_iterator)
    {
      collection[i] = (Operation *)malloc(sizeof(Operation));
      collection[i]->info.unaryOp.opName = (char *)malloc(OP_NAME_LENGTH * sizeof(char));
      collection[i]->type = "unary";
      if (collection[i] == NULL || collection[i]->type == NULL || collection[i]->info.unaryOp.opName == NULL)
        exit(0);

      fscanf(file, "[#%d, #%d, #%d, #%d, #%d, #%d]; { %s }\n",
             &(collection[i]->info.unaryOp.param.array[0]),
             &(collection[i]->info.unaryOp.param.array[1]),
             &(collection[i]->info.unaryOp.param.array[2]),
             &(collection[i]->info.unaryOp.param.array[3]),
             &(collection[i]->info.unaryOp.param.array[4]),
             &(collection[i]->info.unaryOp.param.array[5]),
             collection[i]->info.unaryOp.opName);
      i++;
    }
  }

  printf("======== Printing ========\n");
  {
    show_operations(collection, collection_iterator);
  }

  /***********************************************************/
  /*      2- file reading    (read only mode)                */
  /***********************************************************/

  fclose(file);
  return 0;
}

// print students
