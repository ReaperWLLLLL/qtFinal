/*
   LAPACKE_dgesv Example
   =====================

   The program computes the solution to the system of linear
   equations with a square matrix A and multiple
   right-hand sides B, where A is the coefficient matrix
   and b is the right-hand side matrix:

   Description
   ===========

   The routine solves for X the system of linear equations A*X = B,
   where A is an n-by-n matrix, the columns of matrix B are individual
   right-hand sides, and the columns of X are the corresponding
   solutions.

   The LU decomposition with partial pivoting and row interchanges is
   used to factor A as A = P*L*U, where P is a permutation matrix, L
   is unit lower triangular, and U is upper triangular. The factored
   form of A is then used to solve the system of equations A*X = B.

   LAPACKE Interface
   =================

   LAPACKE_dgesv (col-major, high-level) Example Program Results

  -- LAPACKE Example routine (version 3.7.0) --
  -- LAPACK is a software package provided by Univ. of Tennessee,    --
  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
	 December 2016

*/
/* Includes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lapacke.h"
#include "lapacke_example_aux.h"

/* Main program */
int main() {

	/* Locals */
	lapack_int n = 3, nrhs = 1, lda = n, ldb = n, info;
	/* Local arrays */
	double A[9] = { 1,1,0,1,-2,1,0,3,1 };
	double b[3] = { 3,6,5 };
	lapack_int ipiv[3];

	/* Print Entry Matrix */
	print_matrix_colmajor("Entry Matrix A", n, n, A, lda);
	/* Print Right Rand Side */
	print_matrix_colmajor("Right Rand Side b", n, nrhs, b, ldb);
	printf("\n");

	/* Executable statements */
	printf("LAPACKE_dgesv (row-major, high-level) Example Program Results\n");
	/* Solve the equations A*X = B */
	info = LAPACKE_dgesv(LAPACK_COL_MAJOR, n, nrhs, A, lda, ipiv,
		b, ldb);

	/* Check for the exact singularity */
	if (info > 0) {
		printf("The diagonal element of the triangular factor of A,\n");
		printf("U(%i,%i) is zero, so that A is singular;\n", info, info);
		printf("the solution could not be computed.\n");
		exit(1);
	}
	if (info < 0) exit(1);
	/* Print solution */
	print_matrix_colmajor("Solution", n, nrhs, b, ldb);
	/* Print details of LU factorization */
	//print_matrix_colmajor( "Details of LU factorization", n, n, A, lda );
	/* Print pivot indices */
	//print_vector( "Pivot indices", n, ipiv );
	return 0;
} /* End of LAPACKE_dgesv Example */

