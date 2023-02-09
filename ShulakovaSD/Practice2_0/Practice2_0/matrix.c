#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void alloc_matrix(TMatrix** matrix, int n)
{
	*matrix = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix)->n = n;
	(*matrix)->x = (double*)malloc(sizeof(double) * n * n);
}

void free_matrix(TMatrix** matrix)
{
	free((*matrix)->x);
	free(*matrix);
}

void fill_matrix(TMatrix* matrix)
{
	int i, j;
	for (i = 0; i < matrix->n; i++)
		for (j = 0; j < matrix->n; j++)
			scanf_s("%lf", &(matrix->x[i * matrix->n + j]));
}

void print_matrix(TMatrix* matrix)
{
	int i, j;
	for (i = 0; i < matrix->n; i++)
	{
		for (j = 0; j < matrix->n; j++)
			printf("%.1lf ", matrix->x[i * matrix->n + j]);

		printf("\n");
	}
}

TMatrix* add_matrix(TMatrix* matrix1, TMatrix* matrix2) {
	TMatrix* res;
	int i, j;
	if (matrix1->n != matrix2->n) {
		printf("ERROR\n");
		return NULL;
	}
	alloc_matrix(&res, matrix1->n);
	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i * res->n + j] = matrix1->x[i * res->n + j] + matrix2->x[i * res->n + j];
		}
	}
	return res;
}
TMatrix* add_const(TMatrix* matrix, double c) {
	TMatrix* res;
	int i, j;
	alloc_matrix(&res, matrix->n);
	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i * res->n + j] = matrix->x[i * res->n + j] + c;
		}
	}
	return res;
}

/*TMatrix* multi_const(TMatrix* matrix, double c) {
	TMatrix* res;
	int i, j;
	alloc_matrix(&res, matrix->n);
	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i * res->n + j] = matrix->x[i * res->n + j] * c;
		}
	}
	return res;
}*/