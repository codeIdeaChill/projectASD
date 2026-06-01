#include<stdio.h>

//strlen():
int my_strlen(const char* s);
//strcpy():
char* my_strcpy(char* dest ,const char* src);
//strncpy():
char* my_strncpy(char* dest,const char* src,int n);
//strcat():
char* my_strcat(char* dest,const char* src);
//strcmp():
int my_strcmp(const char* a,const char* b);
//strncmp():
int my_strncmp(const char* a,const char* b,int n);
//toupper():
void toUpperCase(char* s);
//tolower():
void toLowerCase(char* s);
//isPalindrome
int isPalindrome(const char* s);
// removeChar
void removeChar(char* s, char c);
//removeSpaces
void removeSpaces(char* s);
//compareIgnoreCase
int compareIgnoreCase(const char* a, const char* b);