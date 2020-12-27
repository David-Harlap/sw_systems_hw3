#ifndef _TXTFINDER_H_
#define _TXTFINDER_H_

void reset(char *s,int count);

/*int getline(char s[]);

int getword(char w[]);*/
int substring( char * str1, char * str2);

int similar (char *s, char *t, int n);

void print_lines(char * str);

void print_similar_words(char * str);

#endif