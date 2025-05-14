#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int main(void) {
    int (*operation)(int, int);
    int a = 10;
    int b = 5;

    char operator;
    printf("Inserisci un'operazione (+, -): ");
    scanf(" %c", &operator);

    switch (operator)
    {
    case '+':
        operation = add;
        break;
    case '-':
        operation = subtract;
        break;
    
    default:
        printf("Operatore non valido\n");
        return -1;
    }

    printf("Risultato: %d\n", operation(a, b));
    return 0;
}
