#include <stdio.h>

int main() {
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString); 

    int vowels = 0;
    int consonants = 0;

    for (int i = 0; inputString[i] != '\0'; i++) {
        char ch = inputString[i]; 

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            switch (ch) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    vowels++;
                    break;
                default:
                    consonants++;
            }
        }
    }

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}

