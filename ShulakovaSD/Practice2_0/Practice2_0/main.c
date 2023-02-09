#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
	int i, j;
	TMatrix matrix;
	TMatrix* matrix_dynamic, * m1, * m2, * res;

	alloc_matrix(&m1, 2);
	alloc_matrix(&m2, 2);
	fill_matrix(m1);
	fill_matrix(m2);

	return 0;
}