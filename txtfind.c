#include "txtfind.h"
#include <stdio.h>
#include "string.h"

#define LINE 256
#define WORD 30

/*int getline(char s[]){
    char ch;
    int count=0;
    scanf( "%c" ,ch);
    while (ch != '\n')
    {
        s[count]=ch;
        count++;
        scanf("%c",ch);
    }
    s[count]='\0';
    return count;
}

int getword(char w[]){
    char ch;
    int count=0;
    scanf( "%c" ,ch);
    while (ch != '\n' || ch!='\t'|| ch!=' ')
    {
        w[count]=ch;
        count++;
        scanf("%c",ch);
    }
    w[count]='\0';
    return count;
}*/

int substring( char * str1, char * str2){
    int i = 0,ans=0;

    while(i<strlen(str1)){
        if( *(str1+i) == str2[0]){
            int j=1;
            ans=1;
            while(j<strlen(str2)){
                if(*(str1+i+j) != *(str2+j)){
                    ans=0;
                }
                j++;
            }
            if (ans==1){
                return 1;
            }
        }
        i++;
    }
    return 0;
}

int similar (char *s, char *t, int n){
    int slen = strlen(s);
    int tlen = strlen(t);
    int count= 0, i=0,j=0;

    if(tlen>slen){
        return 0;
        }
    else if((slen==tlen)||(n==0)){
        if(strcmp(s,t)==0){
            return 1;}
        else
            {return 0;}  
        }
    else if (tlen + n != slen){
        return 0;
        }
    else {
        while(i<slen){
            if(*(s+i) != *(t+j)){
                count++; 
            }
            else {
                j++;
            }
            i++;
        }
        if(count<n){
            return 1;
        }
    }
        
    return 0;
}


void reset(char *s,int count){
    int i = 0;
    while(i<count){
        *(s+i)= '0';
        i++;
    }
}

void print_lines(char * str){
    char s[LINE];
    char ch;
    int count=0;
    scanf( "%c" ,&ch);

    while (ch != '\0'){
        while (ch != '\n'|| ch != '\0'){
            s[count]=ch;
            count++;
            scanf("%c",&ch);
        }
        if(substring(&s,str)){
            printf("%s", s);
        }
        reset(&s , count);
        count=0;
    }
}

void print_similar_words(char * str){
    char w[LINE];
    char ch;
    int count=0;
    scanf( "%c" ,&ch);

    while (ch != '\0'){
        while (ch != '\n'|| ch != '\0' || ch!='\t'|| ch!=' '){
            w[count]=ch;
            count++;
            scanf("%c",&ch);
        }
        if(similar(&w,str,1)){
            printf("%s", w);
        }
        reset(&w , count);
        count=0;
    }
}

int main(){
    char str[WORD];
    char ch;
    int count = 0;
    scanf( "%c" ,&ch);

    while (ch != ' '){
        str[count] = ch;
        count++;
        scanf("%c",&ch);
    }
    scanf("%c",&ch);
    if(ch == 'a'|| ch=='A'){
        print_lines(str);
    }
    if(ch == 'b'|| ch=='B'){
        print_similar_words(str);
    }
    return 0;
}






