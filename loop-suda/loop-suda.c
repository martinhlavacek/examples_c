#include <stdio.h>
int main() {
    int i;

    // Cyklus je potreba nastavit tak aby prosel vsechny cisla od 0 do 100
    // vytisknu cisla ktera jsou suda ale nejsou delitelna deseti
    // je potreba vyresit cislo 0, protoze to je sude ale delitelne deseti
    for (i = 0; i <= 100; i++) {
       if (i == 0) {
            continue; // Přeskočí iteraci, pokud je 'i' rovno 0
        }
        

        switch (i) {
            case 10:
                continue;
            case 20:
                continue;
            case 30:
                continue;
            case 40:
                continue;
            case 50:
                continue;   
            case 60:
                continue;
            case 70:
                continue;
            case 80:
                continue;
            case 90:
                continue;
            case 100:
                continue;
        }
        
        if (i % 2 == 0) { 
            printf("%d\n", i); // Vypíše aktuální hodnotu 'i'
        }

        // LEPSI ZAPIS
        // Kontrola, zda je 'i' sudé a zároveň není dělitelné deseti
        // Použití logického AND (&&) pro obě podmínky
        // suda cisla jsou delitelna 2 beze zbytku tudiz i % 2 == 0 kdy % je operator pro zbytek po deleni
        // cisla delitelna deseti jsou ta ktera maji zbytek po deleni deseti ruzny od nuly tedy i % 10 != 0

        // if ((i % 2 == 0) && (i % 10 != 0)) { 
        //     printf("%d\n", i); // Vypíše aktuální hodnotu 'i'
        // } 
    }

    return 0;

}