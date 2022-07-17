#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct Node{
    int x; int y; float r;
    struct Node* next;
};

int main(){
    struct Node* p1 = (struct Node*) malloc(sizeof(struct Node));
    struct Node* p2 = (struct Node*) malloc(sizeof(struct Node));

    p1->x = 2;
    p1->y = 2;
    p1->r = 2.5;

    p2->x = 5;
    p2->y = 5;
    p2->r = 5.5;

    p1->next = p2;
    p2->next = NULL;

    int answer1 = p1->next->x;
    printf("%d\n", answer1);

    int answer2 = p2->x;
    printf("%d\n", answer2);

    float answer3 = p1->next->r;
    printf("%f\n", answer3);

    free(p1);
    free(p2);

    return 0;
}