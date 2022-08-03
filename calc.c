#include <stdio.h>
int main() {
int a, b;
    scanf("%d %d", &a, &b);
    char n;
    int res=0;
    n = scanf("%c", &n);
    switch (n)
    {
    case '+' :
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    default:
        break;
    }
    printf("\n%d\n", res);
}
