#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <math.h>


void DrawMatrix(int,int,double **);
double** newMatrix(int,int);
int solve(int,int,double**);
void normalize(int,int,int rows,int cols,double**,int);
int findMax(int x, int y,int rows,int cols, double **matrix);

int main()
{
    int n = 3,m = 4;
    char input = 'y';

    do
    {
        printf("\nENTER N ");
        scanf("%i",&n);
        printf("ENTER M ");
        scanf("%i",&m);

        if(n < m - 1)
        {
            printf(" N < M");
            continue;
        }

        double **matrix = newMatrix(n,m);
        double *ans = malloc((m-1)*sizeof(double));;

        /*
        matrix[0][0] = 2;
        matrix[0][1] = 4;
        matrix[0][2] = 1;
        matrix[0][3] = 36;

        matrix[1][0] = 5;
        matrix[1][1] = 2;
        matrix[1][2] = 1;
        matrix[1][3] = 47;
        
        matrix[2][0] = 2;
        matrix[2][1] = 3;
        matrix[2][2] = 4;
        matrix[2][3] = 37;

        //(2,5,7)
        */ 

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                printf("Matrix[%i][%i] = ",i,j);
                scanf("%lf",&matrix[i][j]);
            }
        }

        DrawMatrix(n,m,matrix);

        if(solve(n,m,matrix) == 0) {
            printf("ERROR\n");
        }
        else {
            DrawMatrix(n,m,matrix);
            int p = 0; 

             for (size_t j = 0; j < n; j++)
             {
                ans[p]  = matrix[n - j - 1][m - 1];

                for (size_t i = 0; i < j; i++)
                {
                    ans[p] -= matrix[n - j - 1][m - i -2] * ans[i];
                }
                p++;
             }

             printf("\n ANSWER = ( ");
             for (size_t i = 0; i < p; i++)
             {
                printf("%lf ",ans[i]);
             }
             printf(")");
        }

        free(ans);
        for (size_t i = 0; i < n; i++) free(matrix[i]);
        free(matrix);
        
        printf("\nwould you like to continue? Y/N\n");
        getchar();
        scanf("%c",&input);

    }while(input == 'y' || input == 'Y');

    return 0 ;
}

void DrawMatrix(int n,int m, double **matrix)
{
    printf("-------------------------------\n");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j  < m; j++)
        {
            printf("%lf ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------");
}


double** newMatrix(int n,int m)
{
    double **A = (double **)malloc(n*sizeof(double *));

    for(int i = 0; i < n; i++) {
        A[i] = (double *)malloc(m*sizeof(double));
        for(int j = 0;j < m; j++) A[i][j] = 0;
    }

    return A;
}

int solve(int rows,int cols,double** matrix)
{
    for (size_t n= 0; n < cols - 1; n++)
    {
        if(findMax(n,n,rows,cols,matrix) == 0) return 0;
        normalize(n,n,rows,cols,matrix,n);

        for (size_t i = n + 1; i < rows; i++)
        for (size_t j = 0; j < cols; j++) matrix[i][j] -= matrix[n][j];
    }

    return 1;
}

int findMax(int x, int y,int rows,int cols, double **matrix)
{
    const double EPS = 0.00001;
    double max;

    for (size_t i = 0; i < rows; i++)
    {
        max = fabs(matrix[x][y]);
        int maxRow = x;

        for (size_t j = x; j < rows; j++)
        {
            if(fabs(matrix[j][y]) > max)
            {
                max = matrix[j][y];

                double *tmp = matrix[j];
                matrix[j] = matrix[maxRow];
                matrix[maxRow] = tmp;

                maxRow = j;
            }
        }
    }

    if(max  < EPS) return 0;
    return 1;
}

void normalize(int x,int y,int rows,int cols,double** matrix,int indx)
{
    for(int i = x;i < rows; i ++)
    {
         double a = matrix[i][indx];
         for(int j = y;j < cols; j ++) matrix[i][j] /= a;
    }
}
