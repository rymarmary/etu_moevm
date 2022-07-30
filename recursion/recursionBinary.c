#include <stdio.h>
#include <string.h>

void recDecToBin(int n, char* result){
    if (n==0) return;
    else {
        if (n%2 == 1){
            recDecToBin(n/2, result);
            result[strlen(result)] = '1';
        }
        else{
            recDecToBin(n/2,result);
            result[strlen(result)] = '0';
        }
    }
}


int main(){
    int n;
    char result[30]="";
    scanf("%d", &n);
    // вызов функции recDecToBin
    recDecToBin(n, result);
    puts(result);
    return 0;
}