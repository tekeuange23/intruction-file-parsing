#include "util.h"

/***********************************************************/
/*                         Utilities                       */
/***********************************************************/
void show_array(int *tab, int n)
{
  int i;
  printf("[");
  for (i = 0; i < n; i++)
  {
    printf("%d", tab[i]);
    if (i != n - 1)
    {
      printf(", ");
    }
  }
  printf("] ");
  printf("\n");
}
/***********************************************************/
/*                        SUM  - AVG                       */
/***********************************************************/
int sum(int *t, int size)
{
  int i, sum = 0;
  for (i = 0; i < size; i++)
  {
    sum += t[i];
  }
  return sum;
}
int avg(int *t, int size)
{
  int i, sum = 0;
  for (i = 0; i < size; i++)
  {
    sum += t[i];
  }
  return sum / size;
}

/***********************************************************/
/*                        QUICK-SORT                       */
/***********************************************************/
void exchange(int *t, int i, int j)
{
  int tmp;
  tmp = t[i];
  t[i] = t[j];
  t[j] = tmp;
}
int partition_asc(int *t, int begin, int end)
{
  int ptr = begin;
  int pivot = t[begin];
  int i;

  for (i = begin + 1; i <= end; i++)
  {
    if (t[i] < pivot)
    {
      ptr++;
      exchange(t, ptr, i);
    }
  }
  exchange(t, ptr, begin);
  return ptr;
}
int partition_desc(int *t, int begin, int end)
{
  int ptr = begin;
  int pivot = t[begin];
  int i;

  for (i = begin + 1; i <= end; i++)
  {
    if (t[i] > pivot)
    {
      ptr++;
      exchange(t, ptr, i);
    }
  }
  exchange(t, ptr, begin);
  return ptr;
}
void quick_sort_rec_asc(int *t, int begin, int end)
{
  if (begin < end)
  {
    int pivot = partition_asc(t, begin, end);
    quick_sort_rec_asc(t, begin, pivot - 1);
    quick_sort_rec_asc(t, pivot + 1, end);
  }
}
void quick_sort_rec_desc(int *t, int begin, int end)
{
  if (begin < end)
  {
    int pivot = partition_desc(t, begin, end);
    quick_sort_rec_desc(t, begin, pivot - 1);
    quick_sort_rec_desc(t, pivot + 1, end);
  }
}
void quick_sort(int *t, int n, int asc)
{
  if (asc)
    quick_sort_rec_asc(t, 0, n - 1);
  else
    quick_sort_rec_desc(t, 0, n - 1);
}