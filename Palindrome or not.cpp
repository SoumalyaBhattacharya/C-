#include <stdio.h>

// Function to check if a string is a palindrome
int isPalindrome(const char* str) {
    const char* start = str;
    const char* end = str + strlen(str) - 1;

    while (start < end) {
        if (*start != *end) {
            return 0; // Characters don't match, not a palindrome
        }
        start++;
        end--;
    }
    return 1; // If we reach here, it's a palindrome
}

int main() {
    char input[100]; // Assuming input string won't exceed 100 characters
    printf("Enter a string: ");
    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

