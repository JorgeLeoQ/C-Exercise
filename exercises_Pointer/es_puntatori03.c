#include <stdio.h>
#include <math.h>

void retta(double x1, double y1, double x2, double y2, double * m, double * q);

int main(void) {
    printf("Inserisci le coordinate di un punto nel piano\n");
    double x1, y1;
    scanf("%lf%lf", &x1, &y1);
    printf("Inserisci le coordinate di un secondo punto\n");
    double x2, y2;
    scanf("%lf%lf", &x2, &y2);
    double m, q;
    retta(x1, y1, x2, y2, &m, &q);
    printf("L'equazione della retta per i due punti dati e'\n");
    if (m==INFINITY)
        printf("x=%g\n",q);
    else if(m==0)
        printf("y=%g\n",q);
    else
        printf("y=%g x + %g\n", m, q);
}

void retta(double x1, double y1, double x2, double y2, double * m, double * q) {
    if(x1==x2) {
        //retta verticale
        *m = INFINITY;
        *q = x1;
    }
    else {
        *m = (y2-y1)/(x2-x1);
        *q = -(*m)*x2+y2;
    }
}
