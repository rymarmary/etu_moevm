#include <stdio.h>

int recSum(int arr[], int index){
    if (index == 99) return arr[99];
    else return recSum(arr, index+1) + arr[index];
}

int main() {
    // put your code here
    int arr[100];
    for (int i=0; i<100; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d", recSum(arr, 0));
    return 0;
}