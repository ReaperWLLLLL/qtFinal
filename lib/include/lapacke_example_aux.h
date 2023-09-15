#ifndef _LAPACKE_EXAMPLE_AUX_
#define _LAPACKE_EXAMPLE_AUX_


void print_matrix_rowmajor(const char* desc, lapack_int m, lapack_int n, double* mat, lapack_int ldm );
void print_matrix_colmajor(const char* desc, lapack_int m, lapack_int n, double* mat, lapack_int ldm );
void print_vector(const char* desc, lapack_int n, lapack_int* vec );

#endif /* _LAPACKE_EXAMPLE_AUX_*/
