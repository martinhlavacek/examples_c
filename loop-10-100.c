#include <stdio.h>
int main() {
    int i;

    // Cyklus for, který začíná od 10 a pokračuje dokud je 'i' menší nebo rovno 100
    // i += 10 znamená, že se 'i' zvyšuje o 10 v každé iteraci
    // a jedna se o zkraceny zapis pro i = i + 10
    for (i = 10; i <= 100; i += 10) {
        printf("%d\n", i); // Vypíše aktuální hodnotu 'i'
    }

    return 0;

}