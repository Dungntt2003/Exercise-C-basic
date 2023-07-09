#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int isPalindrome(char *str) {
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;  // Not a palindrome
        }
    }

    return 1;  // Palindrome
}

int isDuplicate(char *str, char **palindromes, int numPalindromes) {
	int i;
    for ( i = 0; i < numPalindromes; i++) {
        if (strcmp(str, palindromes[i]) == 0) {
            return 1;  // Duplicate
        }
    }

    return 0;  // Not a duplicate
}

int main() {
	int i;
    char input[MAX_LENGTH];
    char *palindromes[MAX_LENGTH];
    int numPalindromes = 0;

    printf("Enter a text line: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline character

    if (isPalindrome(input)) {
        if (!isDuplicate(input, palindromes, numPalindromes)) {
            palindromes[numPalindromes] = strdup(input);
            numPalindromes++;
        }
        printf("'%s' is a palindrome.\n", input);
    } else {
        printf("'%s' is not a palindrome.\n", input);
    }

    printf("\nPalindromes entered:\n");
    for ( i = 0; i < numPalindromes; i++) {
        printf("%s\n", palindromes[i]);
    }

    return 0;
}

