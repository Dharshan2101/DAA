#include <stdio.h>
#include <time.h>

#define N 100 

void multiplyMatrices(int mat1[N][N], int mat2[N][N], int res[N][N], int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            res[i][j] = 0; 
            for (int k = 0; k < dim; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j]; 
            }
        }
    }
}

int main() {
    int mat1[N][N], mat2[N][N], res[N][N];
    int dim;

    // Input the dimension of matrices
    printf("Enter the dimension of matrices: ");
    scanf("%d", &dim);

    
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    clock_t start = clock();

    multiplyMatrices(mat1, mat2, res, dim); 

    clock_t end = clock(); 

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC; 

    printf("Time taken for matrix multiplication: %f seconds\n", time_spent);

    return 0;
}
