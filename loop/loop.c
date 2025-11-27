#include <stdio.h>

int main() {
    int cislo;
    int i;

    // 1. Validace vstupu pomocí nekonečného cyklu while
    while (1) {
        printf("Zadej zaporne cislo: ");
        scanf("%d", &cislo);

        // Zkontrolujeme, zda je číslo menší než 0 (tedy záporné)
        if (cislo < 0) {
            break; // Pokud je podmínka splněna, vyskočíme z cyklu ven
        }

        // Pokud kód dojde až sem, znamená to, že 'break' se neprovedl
        printf("Chyba: Zadal jsi kladne cislo nebo nulu. Zkus to znovu.\n");
    }

    printf("\nVypis cisel od 0 do %d:\n", cislo);

    // Jdeme od 0 směrem dolů (i--) dokud je 'i' větší nebo rovno zadanému číslu
    for (i = 0; i >= cislo; i--) {
        printf("%d\n", i);
    }

    return 0;
}
