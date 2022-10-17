#ifndef UTIL_FILE
#define UTIL_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************/
/*                        Utilities                        */
/***********************************************************/
void show_array(int *tab, int n);

/***********************************************************/
/*                        SUM - AVG                        */
/***********************************************************/
int sum(int *t, int size);
int avg(int *t, int size);

/***********************************************************/
/*                        QUICK-SORT                       */
/***********************************************************/
void exchange(int *t, int i, int j);
int partition_asc(int *t, int begin, int end);
int partition_desc(int *t, int begin, int end);
void quick_sort_rec_asc(int *t, int begin, int end);
void quick_sort_rec_desc(int *t, int begin, int end);
void quick_sort(int *t, int n, int asc);

#endif