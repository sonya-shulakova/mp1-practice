#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void alloc_matrix(TMatrix** matrix, int n) {
	*matrix = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix)->n = n;
	(*matrix)->x = (double*)malloc(n * n * sizeof(double));
}

void free_matrix(TMatrix** matrix) {
	free((*matrix)->x);
	free(*matrix);
}

void fill_matrix(TMatrix* matrix) {
	int i = 0;
	for (; i < matrix->n; i++) {
		int j;
		for (j = 0; j < matrix->n; j++) {
			scanf_s("%lf", &(matrix->x[i * matrix->n + j]));
		}
	}
	printf("\n");
}

void print_matrix(TMatrix* matrix) {
	int i = 0;
	for (i = 0; i < matrix->n; i++) {
		int j = 0;
		for (; j < matrix->n; j++) {
			printf("%.2lf ", matrix->x[i * matrix->n + j]);
		}
		printf(" \n");
	}
	printf("\n");
}

TMatrix* add_matrix(TMatrix* m1, TMatrix* m2) {
	int i = 0;
	int n;
	TMatrix* res;
	if (m1->n != m2->n) {
		printf("ERROR");
		return NULL;
	}
	n = m1->n;
	alloc_matrix(&res, n);
	for (; i < n * n; i++) {
		res->x[i] = m1->x[i] + m2->x[i];
	}
	return res;
}

TMatrix* add_constant(TMatrix* matrix, double constant) {
	int i = 0;
	TMatrix* res;
	int n = matrix->n;
	alloc_matrix(&res, n);
	for (; i < n * n; i++) {
		res->x[i] = matrix->x[i] + constant;
	}
	return res;
}

TMatrix* multi_constant(TMatrix* matrix, double constant) {
	int i = 0;
	TMatrix* res;
	int n = matrix->n;
	alloc_matrix(&res, n);
	for (; i < n * n; i++) {
		res->x[i] = matrix->x[i] * constant;
	}
	return res;
}

TMatrix* multi_matrix(TMatrix* m1, TMatrix* m2) {
	TMatrix* res;
	int i, j, k, n;
	if (m1->n != m2->n) {
		printf("ERROR");
		return NULL;
	}
	n = m1->n;
	alloc_matrix(&res, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			res->x[i * n + j] = 0;
			for (k = 0; k < n; k++) {
				res->x[i * n + j] += m1->x[i * n + k] * m2->x[k * n + j];
			}
		}
	}
	return res;
}

/*void alloc_matrix(TMatrix** matrix, int n)
{
	*matrix = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix) -> size = n;
	(*matrix) -> x = (double*)malloc(sizeof(double) * n*n);
}

void free_matrix(TMatrix** matrix)
{
	free((*matrix)->x);
	free(*matrix);
}

void fill_matrix(TMatrix* matrix)
{
	int i;
	for (i = 0; i < matrix->size; i++) {
		int j;
		for (j = 0; j < matrix->size; j++) {
			scanf_s("%lf", &(matrix->x[i * matrix->size + j]));
		}
	}
	printf("\n");	
}

void print_matrix(TMatrix* matrix)
{
	int i;
	for (i = 0; i < matrix->size; i++){
		int j;
		for (j = 0; j < matrix->size; j++) {
			printf("%.1lf ", matrix->x[i * matrix->size + j]);
		}
		printf("\n");
	}
	printf("\n");
}

TMatrix* add_matrix(TMatrix* m1, TMatrix* m2) {
	TMatrix* res;
	int i, j;
	if (m1->size != m2->size) {
		printf("ERROR\n");
		return NULL;
	}
	alloc_matrix(&res, m1->size);
	for (i = 0; i < res->size; i++) {
		for (j = 0; j < res->size; j++) {
			res->x[i * res->size + j] = m1->x[i * res->size + j] + m2->x[i * res->size + j];
		}
	}
	return res;
}
TMatrix* add_const(TMatrix* matrix, float scalar) {
	TMatrix* res;
	int i, j;
	alloc_matrix(&res, matrix->size);
	for (i = 0; i < res->size; i++) {
		for (j = 0; j < res->size; j++) {
			res->x[i * res->size + j] = matrix->x[i * res->size + j] + scalar;
		}
	}
	return res;
}

TMatrix* multi_const(TMatrix* matrix, float scalar) {
	TMatrix* res;
	int i, j;
	alloc_matrix(&res, matrix->size);
	for (i = 0; i < res->size; i++) {
		for (j = 0; j < res->size; j++) {
			res->x[i * res->size + j] = matrix->x[i * res->size + j] * scalar;
		}
	}
	return res;
}

TMatrix* muili_matrix(TMatrix* m1, TMatrix* m2) {
	TMatrix* res;
	int i, j, k;
	if (m1->size != m2->size) {
		printf("ERROR: Square matrixes should have the same lenght and height.\n");
		return NULL;
	}
	alloc_matrix(&res, m1->size);
	for (i = 0; i < res->size; i++) {
		for (j = 0; j < res->size; j++) {
			res->x[i * res->size + j] = 0.0f;
			for (k = 0; k < res->size; k++) {
				res->x[i * res->size + j] += m1->x[i * res->size + k] * m2->x[k * res->size + j];
			}
		}
	}
	return res;
}*/
