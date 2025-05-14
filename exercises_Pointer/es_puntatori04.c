#include <stdio.h>
#include <math.h>

int contaPositivi(int* aPtr, int dim);

int main(void){
    printf("Quanti elementi vuoi inserire?\n");
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) {
        printf("Inserisci l'elemnto in posizione %d ", i);
        scanf("%d",&a[i]);
    }
    int c = contaPositivi(a, n);
    printf("Il numero di elementi positivi inseriti e': %d\n", c);
}

int contaPositivi(int* aPtr, int dim){
    int count=0;
    for(int i=0;i<dim;i++)
        if(*(aPtr+i)>0)
            count++;
    return count;
}
