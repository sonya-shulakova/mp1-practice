#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
	TMatrix* m1, *m2, *res;
	int	n;
	float add;
	float multi;

	printf("n = ");
	scanf_s("%d", &n);
	printf("add = ");
	scanf_s("%f", &add);
	printf("multi = ");
	scanf_s("%f", &multi);

	alloc_matrix(&m1, n);
	alloc_matrix(&m2, n);

	printf("Enter 1st matrix:\n");
	fill_matrix(m1);
	printf("Enter 2nd matrix:\n");
	fill_matrix(m2);

	printf("add_matrix:\n");
	res = add_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);

	printf("add_constant:\n");
	res = add_constant(m1, add);
	print_matrix(res);
	free_matrix(&res);

	printf("multi_matrix:\n");
	res = multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);

	printf("multi_constant:\n");
	res = multi_constant(m2, multi);
	print_matrix(res);
	free_matrix(&res);

	free_matrix(&m1);
	free_matrix(&m2);
	return 0;
}

/*int main()
{
	int size;
	float scalar;
	TMatrix* m1, *m2, *res;

	printf("n = ");
	scanf_s("%d", &size);
	printf("scalar = ");
	scanf_s("%f", &scalar);
	
	alloc_matrix(&m1, size);
	alloc_matrix(&m2, size);
	fill_matrix(m1);
	fill_matrix(m2);
	print_matrix(m1);
	print_matrix(m2);

	printf("sum_matrix:\n");
	res = add_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);

	printf("add_const:\n");
	res = add_const(m1, scalar);
	print_matrix(res);
	free_matrix(&res);

	printf("multi_matrix:\n");
	res = multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);

	printf("multi_const:\n");
	res = multi_const(m1, scalar);
	print_matrix(res);
	free_matrix(&res);

	free_matrix(&m1);
	free_matrix(&m2);

	return 0;
}*/