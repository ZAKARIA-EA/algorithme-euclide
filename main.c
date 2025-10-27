#include <stdio.h>

int main() {
    int a, b, reste, temp;

    printf("Entrez le premier nombre : ");
    scanf("%d", &a);
    printf("Entrez le deuxieme nombre : ");
    scanf("%d", &b);
    printf("Calcul du PGCD de %d et %d\n", a, b);

    int a_initiale = a, b_initiale = b;

    while (b != 0) {
        reste = a % b;
        printf("%d = %d * (%d) + %d\n", a, b, a / b, reste);
        a = b;
        b = reste;
    }

    printf("Le PGCD de %d et %d est : %d\n", a_initiale, b_initiale, a);

    return 0;
}

