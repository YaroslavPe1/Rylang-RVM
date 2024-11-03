#include <stdio.h>
#include "core.h"

int main() {
    VM vm;
    initVM(&vm);

    int code[] = {
        PUSH, 5,      // Поместить 5 в стек
        PUSH, 3,      // Поместить 3 в стек
        SWAP,         // Обменять 5 и 3 местами
        PRINT,        // Должно напечатать 5
        PUSH, 4,
        OVER,         // Копирует 3 (находится под 4)
        PRINT,        // Должно напечатать 3
        AND,          // Побитовое И между 4 и 3 (результат 0)
        PRINT,        // Должно напечатать 0
        PUSH, 2,
        DUPN, 1,      // Копирует 4 (на позиции -1 от вершины)
        PRINT,        // Должно напечатать 4
        LT,           // Сравнение 2 < 4 (результат 1)
        PRINT,        // Должно напечатать 1
        HALT
    };

    run(&vm, code);
    return 0;
}