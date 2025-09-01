#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// ----------------- Convert -----------------
void convertToCompact(int rows, int cols, int mat[MAX][MAX], int compact[MAX][3]) {
    int k = 1;
    compact[0][0] = rows;
    compact[0][1] = cols;
    compact[0][2] = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = mat[i][j];
                k++;
                compact[0][2]++;
            }
        }
    }
}

// ----------------- Print -----------------
void printCompact(int compact[MAX][3]) {
    int nonZero = compact[0][2];
    printf("Row\tCol\tVal\n");
    for (int i = 0; i <= nonZero; i++) {
        printf("%d\t%d\t%d\n", compact[i][0], compact[i][1], compact[i][2]);
    }
}

// ----------------- Add -----------------
void addCompact(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("Matrix dimensions do not match!\n");
        return;
    }

    int i = 1, j = 1, k = 1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2];
            i++; k++;
        } else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2];
            j++; k++;
        } else {
            C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
    }

    while (i <= A[0][2]) {
        C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= B[0][2]) {
        C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;
}

// ----------------- Multiply -----------------
void multiplyCompact(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][1] != B[0][0]) {
        printf("Incompatible dimensions for multiplication!\n");
        return;
    }

    int temp[MAX][MAX] = {0};

    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B[0][2]; j++) {
            if (A[i][1] == B[j][0]) {
                temp[A[i][0]][B[j][1]] += A[i][2] * B[j][2];
            }
        }
    }

    int k = 1;
    C[0][0] = A[0][0];
    C[0][1] = B[0][1];
    C[0][2] = 0;

    for (int i = 0; i < A[0][0]; i++) {
        for (int j = 0; j < B[0][1]; j++) {
            if (temp[i][j] != 0) {
                C[k][0] = i; C[k][1] = j; C[k][2] = temp[i][j];
                k++; C[0][2]++;
            }
        }
    }
}

// ----------------- Read from file -----------------
void readMatrixFromFile(char *filename, int mat[MAX][MAX], int *rows, int *cols) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(0);
    }

    fscanf(fp, "%d %d", rows, cols);
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(fp, "%d", &mat[i][j]);
        }
    }

    fclose(fp);
}

// ----------------- MAIN -----------------
int main() {
    int choice;
    int rows, cols, mat[MAX][MAX];
    int A[MAX][3], B[MAX][3], C[MAX][3];

    while (1) {
        printf("\n---- Sparse Matrix Operations ----\n");
        printf("1. Convert Sparse Matrix to Compact\n");
        printf("2. Add Two Compact Matrices\n");
        printf("3. Multiply Two Compact Matrices\n");
        printf("4. Read Two Matrices from Files & Perform Add/Multiply\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter rows and cols: ");
                scanf("%d %d", &rows, &cols);

                printf("Enter matrix:\n");
                for (int i = 0; i < rows; i++)
                    for (int j = 0; j < cols; j++)
                        scanf("%d", &mat[i][j]);

                convertToCompact(rows, cols, mat, A);

                printf("\nCompact Matrix:\n");
                printCompact(A);
                break;

            case 2:
                printf("Enter first compact matrix (rows cols nonZero + elements):\n");
                scanf("%d %d %d", &A[0][0], &A[0][1], &A[0][2]);
                for (int i = 1; i <= A[0][2]; i++)
                    scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);

                printf("Enter second compact matrix:\n");
                scanf("%d %d %d", &B[0][0], &B[0][1], &B[0][2]);
                for (int i = 1; i <= B[0][2]; i++)
                    scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);

                addCompact(A, B, C);

                printf("Resultant Compact Matrix (Addition):\n");
                printCompact(C);
                break;

            case 3:
                printf("Enter first compact matrix (rows cols nonZero + elements):\n");
                scanf("%d %d %d", &A[0][0], &A[0][1], &A[0][2]);
                for (int i = 1; i <= A[0][2]; i++)
                    scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);

                printf("Enter second compact matrix:\n");
                scanf("%d %d %d", &B[0][0], &B[0][1], &B[0][2]);
                for (int i = 1; i <= B[0][2]; i++)
                    scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);

                multiplyCompact(A, B, C);

                printf("Resultant Compact Matrix (Multiplication):\n");
                printCompact(C);
                break;

            case 4: {
                int rows1, cols1, rows2, cols2;
                int mat1[MAX][MAX], mat2[MAX][MAX];

                readMatrixFromFile("matrix1.txt", mat1, &rows1, &cols1);
                readMatrixFromFile("matrix2.txt", mat2, &rows2, &cols2);

                convertToCompact(rows1, cols1, mat1, A);
                convertToCompact(rows2, cols2, mat2, B);

                printf("\nCompact Matrix from File 1:\n");
                printCompact(A);
                printf("\nCompact Matrix from File 2:\n");
                printCompact(B);

                addCompact(A, B, C);
                printf("\nAddition Result:\n");
                printCompact(C);

                multiplyCompact(A, B, C);
                printf("\nMultiplication Result:\n");
                printCompact(C);
                break;
            }

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
