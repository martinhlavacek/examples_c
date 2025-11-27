#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int kamen = 1;
int nuzky = 2;
int papir = 3;

void score(int skore_hrac1, int skore_hrac2) {
    printf("Skore:\n");
    printf("Hrac 1: %d bodu\n", skore_hrac1);
    printf("Hrac 2: %d bodu\n", skore_hrac2);
}


const char *prevod(int volba) {
    switch (volba) {
        case 1:
            return "Kamen";
        case 2:
            return "Nuzky";
        case 3:
            return "Papir";
        default:
            return "Neplatna volba";
    }
}

int nacti_volbu_range(const char *prompt, int min, int max) {
    int volba;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &volba) != 1) {
            printf("Zadali jste neplatny vstup. Zadejte cislo %d-%d.\n", min, max);
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        if (volba < min || volba > max) {
            printf("Cislo musi byt mezi %d a %d.\n", min, max);
            continue;
        }
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        return volba;
    }
}

int nacti_volbu(const char *prompt) {
    return nacti_volbu_range(prompt, 1, 3);
}

int main()
{
    
    

    int hrac1;
    int hrac2;
    int vysledek[4];
    int mod;

    int skore_hrac1 = 0;
    int skore_hrac2 = 0;


    printf("Hra Kamen, Nuzky, Papir\n");
    printf("Vyberte mod hry:\n");
    printf("1) 2 hraci\n");
    printf("2) 1 hrac a bot\n");
    mod = nacti_volbu_range("Volba: ", 1, 2);
    printf("Zadejte: 1 = Kamen, 2 = Nuzky, 3 = Papir\n\n");

    if (mod == 2)
    {
        srand((unsigned) time(NULL));
    }

    for (int i = 1; i <=3; i++)
    {

        printf("Kolo %d\n", i);
        hrac1 = nacti_volbu("Hrac 1 zadejte volbu: ");
        if (mod == 1)
        {
            hrac2 = nacti_volbu("Hrac 2 zadejte volbu: ");
        }
        else
        {
            hrac2 = rand() % 3 + 1;
        }
        printf("Hrac 1: %s | Hrac 2: %s\n", prevod(hrac1), prevod(hrac2));
        
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
            if (skore_hrac1 == skore_hrac2)
            {
                printf("Celkovy vysledek: Remiza!\n");
            }
            else if (skore_hrac1 > skore_hrac2)
            {
                printf("Celkovy vysledek:Hrac 1!\n");
            }
            else
            {
                printf("Celkovy vysledek:Hrac 2!\n");
            }
        }
    }
    
    return 0;
}