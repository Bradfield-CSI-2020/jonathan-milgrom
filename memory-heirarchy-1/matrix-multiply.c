/*
Naive code for multiplying two matrices together.

There must be a better way!
*/

#include <stdio.h>
#include <stdlib.h>

/*
  A naive implementation of matrix multiplication.

  DO NOT MODIFY THIS FUNCTION, the tests assume it works correctly, which it
  currently does
*/
void matrix_multiply(double **C, double **A, double **B, int a_rows, int a_cols,
                     int b_cols) {
  for (int i = 0; i < a_rows; i++) {
    for (int j = 0; j < b_cols; j++) {
      C[i][j] = 0;
      for (int k = 0; k < a_cols; k++)
        C[i][j] += A[i][k] * B[k][j];
    }
  }
}

/*
  A = A_rows (M) x N
  B = N X B_cols
*/ 
void fast_matrix_multiply(double **C, double **A, double **B, int A_rows, int N, int B_cols) {
  for (int i = 0; i < A_rows; i++) {
    for (int j = 0; j < B_cols; j++) {
      double vd_product = 0;
      for (int k = 0; k < N; k++) {
        vd_product += A[i][k] * B[k][j];
      }
      C[i][j] = vd_product;
    }
  }
}
