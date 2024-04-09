#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int **arr, int row, int col, char *name);
void add_matrix(int **arrA, int **arrB, int row, int col, int **arrC);
void subtract_matrix(int **arrA, int **arrB, int row, int col, int **arrC);
void transpose_matrix(int **arrA, int row, int col, int **arrC);
void multiply_matrix(int **arrA, int **arrB, int row, int col, int **arrC);

int main(){

    printf("[----- [송동선] [2023078041] -----]\n");

    // 행렬의 행과 열을 입력
    int row, col;
    printf("행: ");
    scanf("%d", &row);
    printf("열: ");
    scanf("%d", &col);
    
    // 행렬 A, B, C를 동적할당
    int **arrA = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++){
        arrA[i] = (int *)malloc(sizeof(int) * col);
    }
    int **arrB = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++){
        arrB[i] = (int *)malloc(sizeof(int) * col);
    }
    int **arrC = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++){
        arrC[i] = (int *)malloc(sizeof(int) * col);
    }

    // 행렬 A, B를 랜덤으로 초기화
    srand(time(NULL));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arrA[i][j] = rand() % 10;
            arrB[i][j] = rand() % 10;
        }
    }

    // 행렬 A, B 출력
    print_matrix(arrA, row, col, "행렬 A");
    print_matrix(arrB, row, col, "행렬 B");

    // 행렬 A, B의 합 출력
    add_matrix(arrA, arrB, row, col, arrC);
    print_matrix(arrC, row, col, "A + B");

    // 행렬 A, B의 차 출력 
    subtract_matrix(arrA, arrB, row, col, arrC);
    print_matrix(arrC, row, col, "A - B");

    // 행렬 A, B의 전치행렬 출력
    transpose_matrix(arrA, row, col, arrC);
    print_matrix(arrC, col, row, "A의 전치행렬");
    transpose_matrix(arrB, row, col, arrC);
    print_matrix(arrC, col, row, "B의 전치행렬");

    // 행렬 A, B의 곱 출력
    multiply_matrix(arrA, arrB, row, col, arrC);
    print_matrix(arrC, row, col, "A * B");

    // 동적할당 해제
    for(int i = 0; i < row; i++){
        free(arrA[i]);
        free(arrB[i]);
        free(arrC[i]);
    }
    free(arrA);
    free(arrB);
    free(arrC);
}
/*함수 출력*/
void print_matrix(int **arr, int row, int col, char *name){
    printf("\n%s\n", name);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
/*두 함수의 합*/
void add_matrix(int **arrA, int **arrB, int row, int col, int **arrC){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
}
/*두 함수의 차*/
void subtract_matrix(int **arrA, int **arrB, int row, int col, int **arrC){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arrC[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
}
/*전치행렬*/
void transpose_matrix(int **arrA, int row, int col, int **arrC){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arrC[j][i] = arrA[i][j];
        }
    }
}
/*두 함수의 곱*/
void multiply_matrix(int **arrA, int **arrB, int row, int col, int **arrC){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arrC[i][j] = 0;
            for(int k = 0; k < col; k++){
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
}