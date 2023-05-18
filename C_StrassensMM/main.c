#include <stdio.h>
#include <stdlib.h>

void printMatrix(int n, int A[][n])
{
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            printf("\t%d",A[i][j]);
        printf("\n");
    }
}

void MM(int n, int A[][n], int B[][n])
{
    int C[n][n];

    int m1,m2,m3,m4,m5,m6,m7;

    m1= (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    m2= (A[1][0] + A[1][1]) * B[0][0];
    m3= A[0][0] * (B[0][1] - B[1][1]);
    m4= A[1][1] * (B[1][0] - B[0][0]);
    m5= (A[0][0] + A[0][1]) * B[1][1];
    m6= (A[1][0] - A[0][0]) * (B[0][0]+B[0][1]);
    m7= (A[0][1] - A[1][1]) * (B[1][0]+B[1][1]);

    C[0][0] = m1 + m4- m5 + m7;
    C[0][1] = m3 + m5;
    C[1][0] = m2 + m4;
    C[1][1] = m1 - m2 + m3 + m6;

    printf("\nRESULTANT MATRIX: \n");
    printMatrix(n, C);
}

int main()
{
    int n=4;
	int A[4][4] = { { 5, 7, 9, 10 },{ 2, 3, 3, 8 },{ 8, 10, 2, 3 },{ 3, 3, 4, 8 } };
	int B[4][4] = { {3, 10, 12, 18},{ 12, 1, 4, 9},{ 9, 10, 12,2 },{ 3, 12, 4,10} };

    printf("\nFIRST MATRIX: \n");
    printMatrix(n, A);

    printf("\nSECOND MATRIX: \n");
    printMatrix(n, B);

    MM(n,A,B);
}
