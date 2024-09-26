#include <stdio.h>


void my_strcpy(char* dest, const char* src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; 
}


void my_strcat(char* dest, const char* src) {
    while (*dest)
        dest++; 
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; 
}


int my_strcmp(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);


    char str3[100];
    my_strcpy(str3, str1);
    printf("Copied string: %s\n", str3);


    my_strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);


    int result = my_strcmp(str1, str2);
    if (result == 0)
        printf("The strings are equal.\n");
    else if (result < 0)
        printf("String 1 is lexicographically smaller than String 2.\n");
    else
        printf("String 1 is lexicographically greater than String 2.\n");

    return 0;
}

