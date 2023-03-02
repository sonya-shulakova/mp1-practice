#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct {
	int n;
	double* x;
} TMatrix;

void alloc_matrix(TMatrix** matrix, int n);
void free_matrix(TMatrix** matrix);
void fill_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix);
TMatrix* add_matrix(TMatrix* m1, TMatrix* m2);
TMatrix* add_constant(TMatrix* matrix, double constant);
TMatrix* multi_constant(TMatrix* matrix, double constant);
TMatrix* multi_matrix(TMatrix* m1, TMatrix* m2);


/*typedef struct {
	int size;
	double* x;
} TMatrix;

void alloc_matrix(TMatrix** matrix, int n);
void free_matrix(TMatrix** matrix);

void fill_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix);

TMatrix* add_matrix(TMatrix* m1, TMatrix* m2);
TMatrix* add_const(TMatrix* matrix, float scalar);
TMatrix* multi_const(TMatrix* matrix, float scalar);
TMatrix* multi_matrix(TMatrix* m1, TMatrix* m2);*/

#endif
