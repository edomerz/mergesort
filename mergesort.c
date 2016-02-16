#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#include "mergesort.h"

static void Merge(char *start, char *mid, char *end, size_t elem_size, compare_func fp);


void MergeSort(void *base, size_t num_elem, size_t elem_size, compare_func fp)
{
	char *start = (char*)base;
	char *end = ((char*)base) + ((num_elem - 1) * elem_size);
	
	if(start < end)
	{
		char *q = start + ((num_elem / 2) * elem_size );
		MergeSort(start, num_elem / 2, elem_size, fp);
		MergeSort(q , num_elem - (num_elem / 2), elem_size, fp);
		Merge(start, q, end + elem_size, elem_size, fp);
	}
}

static void Merge(char *start, char *mid, char *end, size_t elem_size, compare_func fp)
{
	size_t r_size = (end - mid) / elem_size;
	size_t l_size = (mid - start) / elem_size;
	char *l =  (assert(start),
				assert(mid),
				assert(end),
				assert(fp),
				(char*)malloc(mid - start));

	char *r = (char*)malloc(end - mid);

	char *s_l = l;
	char *s_r = r;

	char *i = 0;
	char *j = 0;
	char *iter = start;
	assert(l);
	assert(r);

	memcpy(l, start, (size_t)(mid - start));
	memcpy(r, mid, (size_t)(end - mid));

	i = l;
	j = r;

	for(iter = start; iter < end; iter += elem_size)
	{
		if((r_size) && (l_size))
		{
			if(fp(i, j))
			{
				memcpy(iter, i, elem_size);
				i += elem_size;
				--l_size;
			}
			else
			{
				memcpy(iter, j, elem_size);
				j += elem_size;
				--r_size;
			}
		}
		else if(!r_size)
		{
			memcpy(iter, i, l_size * elem_size);

			break;
		}
		else
		{
			memcpy(iter, j, r_size * elem_size);

			break;
		}
	}
	free(s_l);
	free(s_r);
	return;
}
