#include <stdio.h>
#include "mergesort.h"

int Compare(const void *data1, const void *data2);

int main(int argc, char* argv[], char** envp)
{
	int array[] = {2, 8, 7, 1, 3, 5, 6, 4, 4, 1};
		int i = 0;

		for(; i < 10; ++i)
		{
			printf("array before: ");
			printf("i[%d]: %d	", i, array[i]);
			printf("\n");
		}

		MergeSort(array, 10, sizeof(int), &Compare);

		for(i = 0; i < 10; ++i)
			{
				printf("		array after:  ");
				printf("i[%d]: %d	", i, array[i]);
				printf("\n");
			}

		return(0);
}


int Compare(const void *data1, const void *data2)
{
	if(*(int*)data1 <= *(int*)data2)
	{
		return(1);
	}

	return(0);
}
