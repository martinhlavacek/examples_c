#include <stdio.h>
#include <stdlib.h>


void score(int skore_hrac1, int skore_hrac2) {
    printf("Skore:\n");
    printf("Hrac 1: %d bodu\n", skore_hrac1);
    printf("Hrac 2: %d bodu\n", skore_hrac2);
}





int main()
{
    int kamen = 1;
    int nuzky = 2;
    int papir = 3;
    

    int hrac1;
    int hrac2;
    int vysledek[3];
    int skore_hrac1 = 0;
    int skore_hrac2 = 0;


    printf("Hra Kamen, Nuzky, Papir (2 hraci)\n");
    printf("Zadejte: 1 = Kamen, 2 = Nuzky, 3 = Papir\n\n");

    for (int i = 1; i <=3; i++)
    {

        printf("Kolo %d\n", i);
        printf("Hrac 1 zadejte volbu: ");
        scanf("%d", &hrac1);
        printf("Hrac 2 zadejte volbu: ");
        scanf("%d", &hrac2);
        printf("Hrac 1: %d | Hrac 2: %d\n", hrac1, hrac2);
        
        if (hrac1 == hrac2)
        {
            printf("Remiza!\n\n");
            vysledek[i] = 0;
            //continue;
        }
        else if ((hrac1 == kamen && hrac2 == nuzky) ||
                 (hrac1 == nuzky && hrac2 == papir) ||
                 (hrac1 == papir && hrac2 == kamen))
        {
            printf("Hrac 1 vyhrava!\n\n");
            vysledek[i] = 1;
            skore_hrac1 = skore_hrac1 + 1;
        }
        else
        {
            printf("Hrac 2 vyhrava!\n\n");
            vysledek[i] = 2;
            skore_hrac2 = skore_hrac2 + 1;
        }
        
        if (i ==2 && vysledek[1] == 0 && vysledek[2] == 0)
        {
            printf("Dve remizy po sobe! Hra se ukoncuje predcasne.\n=== Konec hry ===\n");
            score(skore_hrac1, skore_hrac2);
            break;
        }
        if (i ==3)
        {
            printf("=== Konec hry ===\n");
            score(skore_hrac1, skore_hrac2);
        }
    }
    
    return 0;
}