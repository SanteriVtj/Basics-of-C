#include <stdio.h>
#include <math.h>

int main()
{
    return 0;
}

void simple_multiply(void)
{
    int a;
    int b;
    scanf("%d %d", &a, &b);
    int c = a * b;
    printf("%d * %d = %d\n", a, b, c);
}


void simple_math(void)
{
    float num1;
    char oper;
    float num2;
    scanf("%f %c %f", &num1, &oper, &num2);
    switch(oper)
    {
        case '+':
            printf("%.1f\n", (num1 + num2));
            break;
        case '-':
            printf("%.1f\n", (num1 - num2));
            break;
        case '/':
            printf("%.1f\n", (num1 / num2));
            break;
        case '*':
            printf("%.1f\n", (num1 * num2));
            break;
        default:
            printf("ERR\n");
            break;
    }
}




