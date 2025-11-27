/* ========================================
            KAMEN - NUZKY - PAPIR
   ========================================
   Tento program vytvari klasickou hru Kamen-Nuzky-Papir.
   Muzete hrat bud ve dvou hracich nebo proti pocitaci (botovi).
   Hra se hraje na 3 kola, vyhrava ten, kdo ma vice bodu.
   Pokud po dvou kolech je vysledek nerozhodny nebo jedne z hracu ma uz 2 body hra konci predcasne.
   ======================================== */

#include <stdio.h>  // Standardni knihovna pro vstup/vystup (printf, scanf)
#include <stdlib.h> // Knihovna pro obecne funkce (srand, rand)
#include <time.h>   // Knihovna pro praci s casem (time, srand)

// === KONSTANTY PRO HODNOTY ===
int kamen = 1;    // Kamen ma hodnotu 1
int nuzky = 2;    // Nuzky maji hodnotu 2  
int papir = 3;    // Papir ma hodnotu 3

/* ========================================
   FUNKCE score()
   Ucel: Zobrazi aktualni skore obou hracu
   Parametry: 
   - skore_hrac1: pocet bodu prvniho hrace
   - skore_hrac2: pocet bodu druheho hrace
   ======================================== */
void score(int skore_hrac1, int skore_hrac2) {
    printf("Skore:\n");
    printf("Hrac 1: %d bodu\n", skore_hrac1);
    printf("Hrac 2: %d bodu\n", skore_hrac2);
}

/* ========================================
   FUNKCE prevod()
   Ucel: Prevede ciselnu hodnotu (1,2,3) na text ("Kamen", "Nuzky", "Papir")
   Parametry:
   - volba: ciselna hodnota (1,2,3)
   Navratova hodnota: textovy retezec s nazvem volby
   ======================================== */
const char *prevod(int volba) {
    switch (volba) {
        case 1:
            return "Kamen";
        case 2:
            return "Nuzky";
        case 3:
            return "Papir";
        default:    // Pro jakoukoliv neplatnou hodnotu
            return "Neplatna volba";
    }
}

void vyhodnotit(int skore_hrac1, int skore_hrac2) {
    printf("=== Konec hry ===\n");
    score(skore_hrac1, skore_hrac2);

    if (skore_hrac1 == skore_hrac2) {
        printf("Celkovy vysledek: Remiza!\n");
    }
    else if (skore_hrac1 > skore_hrac2) {
        printf("Celkovy vysledek: Hrac 1!\n");
    }
    else {
        printf("Celkovy vysledek: Hrac 2!\n");
    }
}

/* ========================================
   FUNKCE nacti_volbu_range()
   Ucel: Nacte volbu od uzivatele a zkontroluje, zda je v pozadovanem rozsahu
   Parametry:
   - prompt: text, ktery se zobrazi uzivateli
   - min: minimalni povolena hodnota
   - max: maximalni povolena hodnota
   Navratova hodnota: platna volba od uzivatele
   ======================================== */
int nacti_volbu_range(const char *prompt, int min, int max) {
    int volba;
    while (1) {  // Nekonecna smycka - opakuje se, dokud uzivatel nezada platne cislo
        printf("%s", prompt);  // Zobrazi vyzvu uzivateli
        
        // Kontrola, zda uzivatel zadal cislo
        if (scanf("%d", &volba) != 1) {
            printf("Zadali jste neplatny vstup. Zadejte cislo %d-%d.\n", min, max);
            
            // Vycisteni vstupniho bufferu - pokud uzivatel zadal text misto cisla
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;  // Vrat se na zacatek smycky
        }
        
        // BEZ této inicializace by bot vzdy hral stejne sekvence cisel.
        // Time(NULL) zajisti, ze kazdy beh programu ma jinou sekvenci nahodnych cisel.
        // Kontrola, zda cislo je v povolenem rozsahu.
        if (volba < min || volba > max) {
            printf("Cislo musi byt mezi %d a %d.\n", min, max);
            continue;  // Vrat se na zacatek smycky
        }
        
        // Vycisteni zbytku vstupu (pokud uzivatel zadal napr. "1abc")
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        
        return volba;  // Vrati platnou volbu
    }
}

/* ========================================
   FUNKCE nacti_volbu()
   Ucel: Nacte volbu pro hru KKamen-Nuzky-Papir (1-3)
   Parametry:
   - prompt: text, ktery se zobrazi uzivateli
   Navratova hodnota: ciselna volba (1, 2, nebo 3)
   ======================================== */
int nacti_volbu(const char *prompt) {
    return nacti_volbu_range(prompt, 1, 3);  // Pouziva obecnejsi funkci s rozsahem 1-3
}

/* ========================================
   HLAVNI FUNKCE PROGRAMU
   Zde zacina a konci beh programu
   ======================================== */
int main()
{
    // === PROMENNE ===
    //   Promenne pro ukladani dat behem hry
    int hrac1;       // Volba prvniho hrace
    int hrac2;       // Volba druheho hrace/bota
    int vysledek[4]; // Pole pro ukladani vysledku jednotlivych kol (index 0 se nepouziva)
    int mod;         // Herni mod: 1 = 2 hraci, 2 = hrac/bot

    int skore_hrac1 = 0;  // Skore prvniho hrace (zacina na 0)
    int skore_hrac2 = 0;  // Skore druheho hrace/bota (zacina na 0)

    printf("Hra Kamen, Nuzky, Papir\n");
    printf("Vyberte mod hry:\n");
    printf("1) 2 hraci\n");
    printf("2) 1 hrac a bot\n");
    
    // Nacte herni mod od uzivatele
    mod = nacti_volbu_range("Volba: ", 1, 2);
    printf("Zadejte: 1 = Kamen, 2 = Nuzky, 3 = Papir\n\n");

    // === NASTAVENI GENERATORU NAHODNYCH CISEL ===
    //   Potrebujeme jen pro herni mod 2
    if (mod == 2) {
        // srand() inicializuje generator nahodnych cisel
        // time(NULL) vraci aktualni cas jako seed
        srand((unsigned) time(NULL));
    }

    // === HLAVNI HERNI SMYCKA ===
    //   Hraje se maximalne 3 kola
    for (int i = 1; i <= 3; i++) {
        printf("Kolo %d\n", i);
        
        // Nacte volbu prvniho hrace
        hrac1 = nacti_volbu("Hrac 1 zadejte volbu: ");
        
        // === NACTENI VOLBY DRUHEHO HRACE/BOTA ===
        //   Podle zvoleneho modu se nacte bud volba od druheho hrace nebo se vygeneruje nahodna volba bota
        if (mod == 1) {
            // Herni mod 2 hracu - nacte volbu od druheho hrace
            hrac2 = nacti_volbu("Hrac 2 zadejte volbu: ");
        } else {
            // Herni mod hrac vs bot - vygeneruje nahodnou volbu
            // rand() % 3 vytvori cislo 0, 1, nebo 2
            // + 1 z nej udela 1, 2, nebo 3
            hrac2 = rand() % 3 + 1;
        }
        
        // Zobrazi volby obou hracu
        printf("Hrac 1: %s | Hrac 2: %s\n", prevod(hrac1), prevod(hrac2));
        
        // === URCENI VITEZE ===
        //   Porovnani voleb a urceni vysledku kola
        if (hrac1 == hrac2) {
            // Stejne volby = remiza
            printf("Remiza!\n\n");
            vysledek[i] = 0;  // Ulozi vysledek kola (0 = remiza)
        }
        else if ((hrac1 == kamen && hrac2 == nuzky) ||    // Kamen porazi nuzky
                 (hrac1 == nuzky && hrac2 == papir) ||    // Nuzky porazi papir
                 (hrac1 == papir && hrac2 == kamen)) {    // Papir porazi kamen
            // Prvni hrac vyhrava
            printf("Hrac 1 vyhrava!\n\n");
            vysledek[i] = 1;  // Ulozi vysledek kola (1 = vyhra hrace 1)
            skore_hrac1 = skore_hrac1 + 1;  // Prida bod prvnimu hraci
        }
        else {
            // Druhy hrac vyhrava
            printf("Hrac 2 vyhrava!\n\n");
            vysledek[i] = 2;  // Ulozi vysledek kola (2 = vyhra hrace 2)
            skore_hrac2 = skore_hrac2 + 1;  // Prida bod druhemu hraci
        }
        
        // === SPECIALNI KONEC HRY - DVA REMIZY ===
        //   Pokud jsou prvni dve kola remizy, hra muze skoncit predcasne 
        if (i == 2 && vysledek[1] == 0 && vysledek[2] == 0) {
            printf("Dve remizy po sobe! Hra se ukoncuje predcasne.\n");
            vyhodnotit(skore_hrac1, skore_hrac2);
            break; 
        }
        
        // === DRUHY SPECIALNI KONEC HRY ===
        //   Pokud po druhem kole ma nektery hrac dva body, hra konci
        if (i == 2 && (skore_hrac1 == 2 || skore_hrac2 == 2)) {
            int vedouci = (skore_hrac1 > skore_hrac2) ? 1 : 2;
            printf("Hrac %d ma dva body po dvou kolech! Hra se ukoncuje predcasne.\n", vedouci);
            vyhodnotit(skore_hrac1, skore_hrac2);
            break;
        }

        // === FINALNI VYHODNOCENI HRY ===
        //   Po dokonceni vsech kol se urci celkovy vitez
        if (i == 3) {
            vyhodnotit(skore_hrac1, skore_hrac2);
        }
    }
    
    return 0;
}