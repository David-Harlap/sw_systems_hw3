#ifndef _TXTFIND_H_
#define _TXTFIND_H_

void reset(char *s);

int getword(const char *l, char *w);

int substring(char *str1, const char *str2);

int similar(char *s, const char *t, int n);

void print_lines(const char *str);

void print_similar_words(const char *str);

#endif