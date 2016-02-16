/*
	mergesort
*/
	
#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <stdio.h>

typedef int (*compare_func)(const void *data1, const void *data2);

void MergeSort(void *base,
			   size_t num_elem,
			   size_t elem_size,
			   compare_func fp);
	
#endif /* ifndef __MERGESORT_H__*/
