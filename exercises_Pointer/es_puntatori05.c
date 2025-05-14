#include <stdio.h>
#include <math.h>

int contaInversioni(int* aPtr, int dim);

int main(void) {
    printf("Quanti elementi vuoi inserire?\n");
    int n;
    scanf("%d",&n);
    int a[n];
    
    for(int i=0;i<n;i++) {
        printf("Inserisci l'elemnto in posizione %d ", i);
        scanf("%d",&a[i]);
    }
    int c = contaInversioni(a, n);
    printf("Il numero di elementi maggiore del proprio successore e': %d\n", c);
}

int contaInversioni(int* aPtr, int dim) {
    int count=0;
    for(int i=0;i<dim-1;i++)
        if(*(aPtr+i)>*(aPtr+i+1))
            count++;
    return count;
}
