#include <stdio.h>
#include <stdlib.h>

int recFigure(int** arr, int n, int m, int index1, int index2){
    if (arr[index1][index2] == 0) return 0;
    arr[index1][index2] = 0;
    int summ = 1;
    if (index1>0 && arr[index1-1][index2] == 1)
        summ = summ + recFigure(arr, n, m, index1-1, index2);
    if (index2+1<m && arr[index1][index2+1] == 1)
        summ = summ + recFigure(arr, n, m, index1, index2+1);
    if (index1+1<n && arr[index1+1][index2] == 1)
        summ = summ + recFigure(arr, n, m, index1+1, index2);
    if (index2>0 && arr[index1][index2-1] == 1)
        summ = summ + recFigure(arr, n, m, index1, index2-1);
    return summ;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int **arr = (int**) calloc(n, sizeof(int*));
    for (int i=0; i<n; i++){
        arr[i] = calloc(m, sizeof(int));
        for (int j=0; j<m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int max_summ = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int myau = recFigure(arr, n, m, i, j);
            if (myau >= max_summ) max_summ = myau;
        }
    }
    printf("%d", max_summ);
    return 0;
}