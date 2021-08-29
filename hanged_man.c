#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int read_text(char string[], int size, int flag) {
    int len;
    if (fgets(string, size, stdin) == NULL) {
        printf("error : fgets() failed\n");
        exit(EXIT_FAILURE);
    }
    len = strlen(string);
    if (len > 0) {
        if (flag && (string[len - 1] == '\n')) {
            string[len - 1] = '\0';
            len--;
        }
    } else {
        printf("error : no input\n");
        exit(EXIT_FAILURE);
    }
    return len;
}

int main() {
    char ch, secret[30], hide[30] = {0};
    int i, found, len, error, correct;

    printf("enter secret word : ");
    len = read_text(secret, sizeof(secret), 1);

    for (i = 0; i < len; i++) {
        hide[i] = '_';
    }
    error = correct = 0;
    while (error < 7) {
        printf("enter character : ");
        ch = getchar();
        found = 0;
        for (i = 0; i < len; i++) {
            if (secret[i] == ch) {
                hide[i] = ch;
                found = 1;
                correct++;
                if (correct == len) {
                    printf("secret word is found!!!\n");
                    return 0;
                }
            }
        }
        if (found == 0) {
            error++;
            printf("error , %c does not exist . You've got %d more attempts\n", ch, 7 - error);
        } else {
            printf("%s/n", hide);
        }
        getchar();
    }
    printf("sorry,the secret word was %s\n", secret);
    return 0;
}

