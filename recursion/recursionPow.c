#include <stdio.h>

double recPow(int n, int pow){
    if (n == 0) return 0;
    if (pow == 0) return 1;
    if (pow < 0) return 1/recPow(n, -pow);
    else{
        if (pow%2 == 0) return recPow(n, pow/2) * recPow(n, pow/2);
        else return recPow(n, pow-1) * n;
    }
}

int main(){
    int n; int pow;
    scanf("%d %d", &n, &pow);
    printf("%f", recPow(n, pow));
    return 0;
}