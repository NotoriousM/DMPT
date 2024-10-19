#include <stdio.h>

// Функция для подсчета количества неисправных катушек
int countFaultyCoils(int L1, int L2, int L3, int L4) {
    return L1 + L2 + L3 + L4;
}

int main() {
    int L1, L2, L3, L4;
    int green, yellow, red;
    
    // Заголовок таблицы истинности
    printf("  L1    L2    L3    L4 | Green Yellow Red\n");
    printf("--------------------------------------------\n");
    
    // Перебор всех возможных комбинаций состояний катушек
    for (L1 = 0; L1 <= 1; L1++) { // Инкрементируем coil1
        for (L2 = 0; L2 <= 1; L2++) {
            for (L3 = 0; L3 <= 1; L3++) {
                for (L4 = 0; L4 <= 1; L4++) {
                    
                    // Подсчет неисправных катушек
                    int faultyCoils = countFaultyCoils(L1, L2, L3, L4);
                    
                    // Логика индикации
                    if (faultyCoils == 0) {
                        green = 1;
                        yellow = 0;
                        red = 0;
                    } else if (faultyCoils == 1) {
                        green = 0;
                        yellow = 1;
                        red = 0;
                    } else if (faultyCoils == 2) {
                        green = 0;
                        yellow = 1;
                        red = 1;
                    } else {
                        green = 0;
                        yellow = 0;
                        red = 1;
                    }
                    
                    // Вывод текущей комбинации состояний катушек и индикации
                    printf("  %d     %d     %d     %d  |   %d     %d     %d\n", 
                            L1, L2, L3, L4, green, yellow, red);
                }
            }
        }
    }
    
    return 0;
}
