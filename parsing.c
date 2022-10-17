#include "parsing.h"
#include "util.h"

void show_operations(Collection *collection, int iterator)
{
  int i;
  for (i = 0; i < iterator; i++)
  {
    printf("line %d --> {%d} ", i + 1, collection[i]->info.unaryOp.opName);
    show_array(collection[i]->info.unaryOp.param.array, INPUT_LIST_LENGTH);
  }
}

Collection *compute(Collection *collection, int iterator)
{
  Collection *result = (Collection *)malloc(iterator * sizeof(Collection));
  if (result == NULL)
    exit(0);
  int i = 0;

  while (i < iterator)
  {
    result[i] = (Operation *)malloc(sizeof(Operation));
    result[i]->type = "unary";
    if (result[i] == NULL)
      exit(0);

    result[i]->info.unaryOp.opName = collection[i]->info.unaryOp.opName;
    int data;
    switch (collection[i]->info.unaryOp.opName)
    {
    case SUM:
      data = sum(collection[i]->info.unaryOp.param.array, INPUT_LIST_LENGTH);
      printf("{ %s } : ", GET_VARIABLE_NAME(SUM));
      printf("%d \n", data);
      break;
    case AVG:
      data = avg(collection[i]->info.unaryOp.param.array, INPUT_LIST_LENGTH);
      printf("{ %s } : ", GET_VARIABLE_NAME(AVG));
      printf("%d \n", data);
      break;
    case SORT_ASC:
      quick_sort(collection[i]->info.unaryOp.param.array, INPUT_LIST_LENGTH, 1);
      printf("{ %s } : ", GET_VARIABLE_NAME(SORT_ASC));
      show_array(collection[i]->info.unaryOp.param.array, INPUT_LIST_LENGTH);
      break;
    case SORT_DESC:
      quick_sort(collection[i]->info.unaryOp.param.array, INPUT_LIST_LENGTH, 0);
      printf("{ %s } : ", GET_VARIABLE_NAME(SORT_DESC));
      show_array(collection[i]->info.unaryOp.param.array, INPUT_LIST_LENGTH);
      break;

    default:
      break;
    }

    i++;
  }

  return result;
}
