#include <stdio.h>

long long int recFact(int n){
    if (n == 0) return 1;
    else return recFact(n-1) * n;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%lld", recFact(n));
    return 0;
}