#include <stdio.h>
#include <math.h>

int findSolutions (double a, double b, double c,
    double* re1, double* im1, double* re2, double* im2);

int main(void) {
    printf("Inserisci i tre coefficienti dell'equazione\n");
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double re1, im1, re2, im2;
    if(findSolutions(a, b, c, &re1, &im1, &re2, &im2)) {
        printf("Le soluzioni reali dell'equazione sono: %g e %g.\n", re1, re2);
    }
    else {
        printf("L'equazione complesse dell'equazione sono: %g + j %g e %g + j %g.\n", re1, im1, re2, im2);
    }
    return 0;
}

int findSolutions(double a, double b, double c,
    double* re1, double* im1, double* re2, double* im2) {
    double delta = b*b - 4*a*c;
    if (delta >= 0) {
        *re1 = (-b-sqrt(delta))/(2*a);
        *re2 = (-b+sqrt(delta))/(2*a);
        *im1 = 0;
        *im2 = 0;
        return 1;
    }
    else {
        *re1 = -b/(2*a);
        *re2 = *re1;
        *im1 = sqrt(-delta)/(2*a);
        *im2 = -*im1;
        return 0;        
    }
}
