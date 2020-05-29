#include <stdio.h> 
#include <stdlib.h>
  
const int MAX = 100; 
  
// Funcion para imprimir la matriz
void impMatriz(int M[][MAX], int fila, int columna) 
{ 
    for (int i = 0; i < fila; i++) { 
        for (int j = 0; j < columna; j++) 
            printf("%d ", M[i][j]); 
  
        printf("\n"); 
    } 
} 
  
// Funcion para multiplicar dos matrices A[][] and B[][] 
void multMatriz(int fil1, int col1, int A[][MAX], 
                    int fil2, int col2, int B[][MAX]) 
{ 
    int i, j, k; 
  
    // Matriz que almacena el resultado
    int C[MAX][MAX]; 
  
    // Revisa si la multiplicacion es posible 
    if (fil2 != col1) { 
        printf("Multiplicacion de matrices no es posible\n"); 
        return; 
    } 
  
    // Multiplica las dos matrices
    for (i = 0; i < fil1; i++) { 
        for (j = 0; j < col2; j++) { 
            C[i][j] = 0; 
            for (k = 0; k < fil2; k++) 
                C[i][j] += A[i][k] * B[k][j]; 
        } 
    } 
  
    // Imprime el resultado
    printf("\nMatriz Resultado: \n"); 
    impMatriz(C, fil1, col2); 
} 
  
// Programa principal
int main() 
{ 
    int fil1, col1, fil2, col2, i, j; 
    int A[MAX][MAX], B[MAX][MAX]; 
  
    // Se define el tamaño de la matriz  A 
    fil1=3;
    col1=3;
  
    // Lee los elementos de la Matriz A desde el archivo m1.txt 
    
    FILE *myFile;
    myFile = fopen("m1.txt", "r");
    
    if (myFile == NULL){
        printf("Error de lectura en archivo\n");
        exit (0);
        }
    
    for (i = 0; i < fil1; i++) { 
        for (j = 0; j < col1; j++) { 
          fscanf(myFile, "%d,", &A[i][j]);

        } 
    } 
  
    // Se define el tamaño de la matriz  B 
    
    fil2=3;
    col2=3;
  
    // Lee los elementos de la Matriz B desde el archivo m2.txt 
    
    FILE *myFile2;
    myFile2 = fopen("m2.txt", "r");
    
    if (myFile2 == NULL){
        printf("Error Reading File\n");
        exit (0);
        }
        
    for (i = 0; i < fil2; i++) { 
        for (j = 0; j < col2; j++) { 
            fscanf(myFile2, "%d,", &B[i][j]); 
        /*    scanf("%d", &B[i][j]); 
            printf("%d", B[i][j]); */
        } 
    } 
  
    // Impresion en pantalla de la Matriz A 
    printf("\n\nMatriz A: \n"); 
    impMatriz(A, fil1, col1); 
  
    // Impresion en pantalla de la Matriz B 
    printf("\nMatriz B: \n"); 
    impMatriz(B, fil2, col2); 
  
    // Producro de las 2 matrices  3x3
    multMatriz(fil1, col1, A, fil2, col2, B); 
  
    return 0; 
} 
