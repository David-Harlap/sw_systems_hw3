#include "txtfind.h"

#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

int getword(const char *l, char *w) {
    int i = 0;
    while (*(l + i) != '\n' && *(l + i) != '\t' && *(l + i) != ' ' && i < WORD) {
        *(w + i) = *(l + i);
        ++i;
    }
    *(w + i) = 0;
    return ++i;
}

int substring(char *str1, const char *str2) {
    int i = 0, ans = 0;

    while (i < strlen(str1)) {
        if (*(str1 + i) == str2[0]) {
            int j = 1;
            ans = 1;
            while (j < strlen(str2)) {
                if (*(str1 + i + j) != *(str2 + j)) {
                    ans = 0;
                }
                j++;
            }
            if (ans == 1) {
                return 1;
            }
        }
        i++;
    }
    return 0;
}

int similar(char *s, const char *t, int n) {
    int slen = strlen(s);
    int tlen = strlen(t);
    int count = 0, i = 0, j = 0;

    if (tlen > slen) {
        return 0;
    } else if ((slen == tlen) || (n == 0)) {
        if (strcmp(s, t) == 0) {
            return 1;
        } else {
            return 0;
        }
    } else if (tlen + n != slen) {
        return 0;
    } else {
        while (i < slen) {
            if (*(s + i) != *(t + j)) {
                count++;
            } else {
                j++;
            }
            i++;
        }
        if (count < n) {
            return 1;
        }
    }
    return 0;
}

void reset(char *s) {
    int i = 0;
    while (i < strlen(s)) {
        *(s + i) = '0';
        i++;
    }
}

void print_lines(const char *str) {
    char line[LINE];
    // char word[WORD];
    // char ch;
    // int count = 0;
    // size_t i = 0;

    while (fgets(line, LINE, stdin)) {
        if (substring(line, str)) {
            printf("%s", line);
        }
    }

    // while (ch != '\0') {
    //     while (ch != '\n' || ch != '\0') {
    //         line[count] = ch;
    //         count++;
    //         scanf(" %c", &ch);
    //     }
    //     if (substring(line, str)) {
    //         printf("%s", line);
    //     }
    //     reset(line, count);
    //     count = 0;
    // }
}

void print_similar_words(const char *str) {
    char word[WORD];
    char line[LINE];
    printf("enter print simular with the word '%s'\n", str);

    while (fgets(line, LINE, stdin)) {
        int i = 0;
        while (i < strlen(line))
        {
            i += getword(line + i, word);
            puts(word);
            if (similar(word, str, 1)) {
                printf("%s\n", word);
            }
            // reset(word);
        }
        // printf("\n");
    }
}

int main() {
    char firstLine[LINE];
    char str[WORD];
    char ch;
    int i = 0;

    fgets(firstLine, LINE, stdin);

    i = getword(firstLine, str);

    ch = *(firstLine + i);
    // puts(str);

    // printf("%d\n", i);

    // do {
    //     str[count++] = ch;
    //     scanf("%c", &ch);
    // } while (ch != ' ');

    // printf("%s", str);

    // // while (ch != ' ') {
    // //     str[count] = ch;
    // //     count++;
    // //     scanf(" %c", &ch);
    // // }
    // // scanf(" %c", &ch);
    if (ch == 'a' || ch == 'A') {
        print_lines(str);
    }
    if (ch == 'b' || ch == 'B') {
        print_similar_words(str);
    }
    return 0;
}
