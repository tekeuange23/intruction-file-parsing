#ifndef PARSING_FILE
#define PARSING_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_LIST_LENGTH 6
#define OP_TYPE_LENGTH 6
#define OP_NAME_LENGTH 10
#define GET_VARIABLE_NAME(Variable) (#Variable)

enum Operator
{
  SUM,
  AVG,
  SORT_ASC,
  SORT_DESC
};

typedef union Input
{
  int number;
  int array[INPUT_LIST_LENGTH];
  char *str;
} Input;
// typedef struct Input
// {
//   int array[INPUT_LIST_LENGTH];
// } Input;

typedef struct UnaryOperation
{
  int opName;
  Input param;
} UnaryOperation;

typedef struct BinaryOperation
{
  int opName;
  Input param1;
  Input param2;
} BinaryOperation;

typedef struct Operation
{
  char *type;
  union
  {
    UnaryOperation unaryOp;
    BinaryOperation binaryOp;
  } info;
} Operation;

typedef Operation *Collection;

/***********************************************************/
/*                        Prototypes                       */
/***********************************************************/
Collection *read_operations(Collection *collection, FILE *file);
void show_operations(Collection *collection, int iterator);
Collection *compute(Collection *collection, int iterator);

#endif