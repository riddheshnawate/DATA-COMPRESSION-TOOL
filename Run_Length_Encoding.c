#include <stdio.h>
#include <string.h>

int main() {
    char str[100], encoded[200];
    int count, i, j = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        count = 1;
        while (str[i] == str[i + 1]) {
            count++;
            i++;
        }
        encoded[j++] = str[i];
        encoded[j++] = count + '0';
    }

    encoded[j] = '\0';

    printf("Encoded string: %s\n", encoded);

    return 0;
}

