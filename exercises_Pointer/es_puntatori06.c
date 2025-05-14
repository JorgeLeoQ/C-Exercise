#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r = 3;
    int c = 4;

    int ** matrice = (int **)malloc(r*sizeof(int*));
    for(int i=0; i<r; i++) {
        matrice[i] = malloc(c*sizeof(int));
    }

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            matrice[i][j] = i * c + j;
        }
    }
    for (int i = 0; i < r; i++){
        free(matrice[i]);
    }
    free(matrice);
    
    return 0;
}