
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct node{
    int num;
    struct node * next;
};

void normal_multiplication(int a, int b){
    //displays normal division
    printf("Normal Multiplication:\n\n");

    //bigger number on top
    if (a < b){
        int temp = a;
        a = b;
        b = temp;
    }

    //first get the spacing needed for formatting
    int c = a;
    int d = b;
    int digits1 = 1;
    int digits2 = 1;
    c/=10;
    while (c != 0){
        c /= 10;
        digits1++;
    }
    d/=10;
    while (d != 0){
        d /= 10;
        digits2++;
    }
    int max_a = (pow(10, (digits1)) - 1);
    int max_b = (pow(10, (digits2)) - 1);
    int e = max_a * max_b;
    int digits = 1;
    e/=10;
    while (e != 0){
        e /= 10;
        digits++;
    }

    //now for the actual multiplication
    printf("%*d\n", digits, a);
    printf("%*d\n", digits, b);
    for (int i = 0; i < digits; i++){
        printf("-");
    }
    printf("\n");

    d = b;
    int zeros = 0;
    struct node * nums = NULL;
    struct node * current = nums;
    for (int i = 0; i < digits2; i++){
        int one = d % 10;
        d /= 10;
        int prod = one * a;
        printf("%*d", digits-zeros, prod);
        zeros++;
        printf("\n");

        struct node * temp = malloc(sizeof(struct node));
        temp->num = (prod*pow(10, i));
        temp->next = NULL;

        if (nums == NULL){
            nums = temp;
            current = nums;
        }
        else{
            current->next = temp;
            current = current->next;
        }
    }

    for (int i = 0; i < digits; i++){
        printf("-");
    }
    printf("\n");

    current = nums;
    int sum = 0;
    while (current != NULL){
        sum+=current->num;
        current = current->next;
    }
    printf("%*d\n", digits, sum);

    current = nums;
    while (current != NULL){
        struct node * temp = current;
        current = current->next;
        free(temp);
    }
}

void alkwarizmi (int a, int b){
    printf("Multiplication using Al Khwarizmi's method:\n\n");

    //move bigger number to right 
    if (a > b){
        int temp = b;
        b = a;
        a = temp;
    }

    //spacing
    int c = a;
    int d = b;
    int digits1 = 1;
    int digits2 = 1;
    c/=10;
    while (c != 0){
        c /= 10;
        digits1++;
    }
    d/=10;
    while (d != 0){
        d /= 10;
        digits2++;
    }

    //actual multiplication
    struct node * nums = NULL;
    struct node * current = nums;
    int digits3;
    while (a != 1){
        printf("%*d %*d", digits1, a, digits2, b);
        if (a % 2 == 0){
            printf(" (Strike Out)\n");
        }else{
            printf("\n");
            struct node * temp = malloc(sizeof(struct node));
            temp -> num = b;
            temp -> next = NULL;;

            if (nums == NULL){
                nums = temp;
                current = nums;
            }else{
                current -> next = temp;
                current = current -> next;
            }
        }
        a /= 2;
        b *= 2;
        if (a == 1){
            printf("%*d %*d\n", digits1, a, digits2, b);
            struct node * temp = malloc(sizeof(struct node));
            temp -> num = b;
            temp -> next = NULL;

            if (nums == NULL){
                nums = temp;
                current = nums;
            }else{
                current -> next = temp;
                current = current -> next;
            }
        }
        digits3 = 1;
        d = b;
        d/=10;
        while (d != 0){
            d /= 10;
            digits3++;
        }
    }

    for (int i = 0; i < digits1+1+digits3; i++){
        printf("-");
    }
    printf("\n");

    current = nums;
    int sum = 0;
    while (current != NULL){
        sum += (current -> num);
        current = current -> next;
    }
    printf("%*d\n", digits1+1+digits3, sum);
    current = nums;
    while (current!=NULL){
        struct node * temp = current;
        current = current -> next;
        free(temp);
    }
    printf("\n");
}

int main(){
    printf("This program displays the difference between normal multiplication and multiplication using the method discovered by Al Khwarizmi\n");
    printf("Enter two integers, separated by a space: ");
    int a, b;
    scanf("%d %d", &a, &b);
    normal_multiplication(a, b);
    printf("\n");
    alkwarizmi(a, b);
    return 0;
}