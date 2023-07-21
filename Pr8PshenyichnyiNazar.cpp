#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Рекурсивна функція для генерації анаграм
void generateAnagrams(char* word, int* count, int index) {
    // Базовий випадок: коли всі букви вже розміщені
    if (index == strlen(word)) {
        (*count)++;
        return;
    }

    // Генеруємо анаграми, міняючи букви місцями
    for (int i = index; i < strlen(word); i++) {
        // Міняємо місцями букви
        char temp = word[index];
        word[index] = word[i];
        word[i] = temp;

        // Рекурсивно генеруємо анаграми для решти букв
        generateAnagrams(word, count, index + 1);

        // Повертаємо букви на свої місця
        temp = word[index];
        word[index] = word[i];
        word[i] = temp;
    }
}

int main() {
    char word[15];
    printf("Введіть слово: ");
    scanf("%s", word);

    int count = 0;
    generateAnagrams(word, &count, 0);

    printf("Кількість анаграм: %d\n", count);

    return 0;
}
