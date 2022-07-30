#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool recLabirinth(int** arr, int n, int m, int index1, int index2){
    arr[index1][index2] = 1;
    if (index1 == n-1 && index2 == m-1) return true;
    if (index1>0 && arr[index1-1][index2] == 0 && recLabirinth(arr, n, m, index1-1, index2))
        return true;
    if (index2+1<m && arr[index1][index2+1] == 0 && recLabirinth(arr, n, m, index1, index2+1))
        return true;
    if (index1+1<n && arr[index1+1][index2] == 0 && recLabirinth(arr, n, m, index1+1, index2))
        return true;
    if (index2>0 && arr[index1][index2-1] == 0 && recLabirinth(arr, n, m, index1, index2-1))
        return true;
    return false;
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
    if (recLabirinth(arr, n, m, 0, 0)) puts("exists");
    else puts("doesn't exist");
    return 0;
}