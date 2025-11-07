#include <stdio.h>

//  Fonction pour calculer le PGCD et les coefficients de Bézout
int euclide_etendu(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int d = euclide_etendu(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return d;
}

int main() {
    int a, b, c;

    printf(" Algorithme d Euclide et Equation diophantienne ax + by = c\n");

    printf("Entrez a : ");
    scanf("%d", &a);
    printf("Entrez b : ");
    scanf("%d", &b);
    printf("Entrez c : ");
    scanf("%d", &c);

    int x0, y0;
    int d = euclide_etendu(a, b, &x0, &y0); // Calcul du PGCD et coefficients de Bézout

    printf("\nEtape 1  Calcul du PGCD :\n");
    printf("PGCD(%d, %d) = %d\n", a, b, d);

    // Vérification d’existence de solutions entieres
    if (c % d != 0) {
        printf("\nPas de solution entiere car %d ne divise pas %d.\n", d, c);
        return 0;
    }

    printf("\nEtape 2  Il existe des solutions entieres.\n");

    // Calcul d'une solution particulière
    int xp = x0 * (c / d);
    int yp = y0 * (c / d);

    // Coefficients de la solution générale
    int alpha = b / d;
    int beta = -a / d;

    printf("\nEtape 3  Solution particuliere :\n");
    printf("Une solution particuliere est : (x, y) = (%d, %d)\n", xp, yp);

    printf("\nEtape 4  Forme generale des solutions :\n");
    printf("x = %d + %d*k\n", xp, alpha);
    printf("y = %d + (%d)*k\n", yp, beta);
    printf("avec k appartient Z\n");

    printf("\nVerification : %d*(%d) + %d*(%d) = %d\n", a, xp, b, yp, a*xp + b*yp);

    return 0;
}
