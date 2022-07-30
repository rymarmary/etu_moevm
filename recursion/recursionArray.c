#include <stdio.h>

void recArr(int n){
    int num;
    if (n==0) return;
    else{
        scanf("%d", &num);
        recArr(n-1);
        printf("%d ", num);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    recArr(n);
    return 0;
}