#include <stdio.h>
#define MAX 100

int main()
{
    int n = 4;
    int a[] = {5, 30, 53, 97};
    int p[] = {2, 3, 1, 2};
    int q[] = {2, 2, 1, 1, 2};

    OBST(p, q, n);

    return 0;
}

int Find(int c[MAX][MAX], int r[MAX][MAX], int i, int j)
{
    int min = 9999;
    int l;
    for (int m = r[i][j - 1]; m <= r[i + 1][j]; m++)
    {
        if (c[i][m - 1] + c[m][j] < min)
        {
            min = c[i][m - 1] + c[m][j];
            l = m;
        }
    }
    return l;
}

void printMatrix(int matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void OBST(int p[], int q[], int n)
{
    int w[MAX][MAX];
    int r[MAX][MAX];
    float c[MAX][MAX];

    for (int i = 0; i < n; i++)
    {
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0.0;
        // optimal trees with one node
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        r[i][i + 1] = i + 1;
        c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
    }

    w[n][n] = q[n];
    r[n][n] = 0;
    c[n][n] = 0.0;

    for (int m = 2; m <= n; m++)
    {
        for (int i = 0; i <= n - m; i++)
        {
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            int k = Find(c, r, i, j);
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            r[i][j] = k;
        }
    }

    // print c, w, r matrices

    printf("Cost Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f\t", c[i][j]);
        }
        printf("\n");
    }
    printf("\nWeight Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", w[i][j]);
        }
        printf("\n");
    }
    printf("\nRoot Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", r[i][j]);
        }
        printf("\n");
    }
}

