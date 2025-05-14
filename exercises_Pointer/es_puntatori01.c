#include <stdio.h>
#include <math.h>

int findSolutions(double a, double b, double c, 
    double * ptrx1, double * ptrx2);

int main(void) {
    printf("Inserisci i tre coefficienti dell'equazione\n");
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double x1, x2;
    if(findSolutions(a, b, c, &x1, &x2)) {
        printf("Le soluzioni reali dell'equazione sono: %f e %f.\n", x1, x2);
    }
    else {
        printf("L'equazione non ha soluzioni reali.\n");
    }
    return 0;
}

int findSolutions(double a, double b, double c, double * ptrx1, double * ptrx2) {
    double delta = b*b - 4*a*c;
    if (delta >= 0) {
        *ptrx1 = (-b-sqrt(delta))/(2*a);
        *ptrx2 = (-b+sqrt(delta))/(2*a);
        return 1;
    }
    return 0;
}
