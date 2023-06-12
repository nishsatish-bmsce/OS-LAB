#include <stdio.h>

void inputMatrix(int matrix[][10], int row, int column) {
   printf("\nEnter elements: \n");

   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("Enter a%d%d: ", i + 1, j + 1);
         scanf("%d", &matrix[i][j]);
      }
   }
}

void multiplyMatrices(int first[][10], int second[][10], int result[][10], int r1, int c1, int r2, int c2) {
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         result[i][j] = 0;
      }
   }

   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}

void addMatrices(int first[][10], int second[][10], int result[][10], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
          result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void transposeMatrices(int first[][10], int result[][10], int r1, int c1, int r2, int c2) {
    int a[10][10], temp[10][10];
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            temp[j][i] = a[i][j];
        }
    }
    result = temp;
}

void display(int result[][10], int row, int column) {
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("%d  ", result[i][j]);
         if (j == column - 1)
            printf("\n");
      }
   }
}

int main() {
   int first[10][10], second[10][10], result[10][10], r1, c1, r2, c2;
   printf("Enter rows and column for the first matrix: ");
   scanf("%d %d", &r1, &c1);
   printf("Enter rows and column for the second matrix: ");
   scanf("%d %d", &r2, &c2);

   // Taking input until
   // 1st matrix columns is not equal to 2nd matrix row
   while (c1 != r2) {
      printf("Error! Enter rows and columns again.\n");
      printf("Enter rows and columns for the first matrix: ");
      scanf("%d%d", &r1, &c1);
      printf("Enter rows and columns for the second matrix: ");
      scanf("%d%d", &r2, &c2);
   }

   inputMatrix(first, r1, c1);
   inputMatrix(second, r2, c2);

   multiplyMatrices(first, second, result, r1, c1, r2, c2);
   printf("\nMultiplied Matrix:\n");
   display(result, r1, c2);
   
   addMatrices(first, second, result, r1, c1, r2, c2);
   printf("\nAdded Matrix:\n");
   display(result, r1, c2);
   
   transposeMatrices(first, result, r1, c1, r2, c2);
   printf("\nSubtracted Matrix:\n");
   display(result, r1, c2);

   return 0;
}
