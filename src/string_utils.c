#include <stdio.h>
#include <string.h>
#include <ctype.h> 
int my_strlen(const char* s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}


char* my_strcpy(char* dest ,const char* src){
    int i=0;
    while(src[i] !='\0'){
        dest[i]=src[i];
        i++;
    }
    dest[i]='\0';
    return dest;
}


char* my_strncpy(char* dest,const char* src,int n){
    int i=0; 
    for(i = 0; i < n; i++){
        if(src[i] !='\0'){
            dest[i]=src[i];
        }else{
            dest[i]='\0';
        }
    }
    dest[i]='\0';
    return dest;
}


char* my_strcat(char* dest,const char* src){
    int i=0;
    int j=0;
    while(dest[i] !='\0'){
        i++;
    }
    while(src[j] !='\0'){
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}


int my_strcmp(const char* a,const char* b){
    int i=0;
    while(a[i] !='\0'&& b[i] !='\0' && a[i]==b[i]){
        i++;
    }
    return a[i]-b[i];
}


int my_strncmp(const char* a,const char* b,int n){
    int i=0;
    while( i<n && a[i] !='\0'&& b[i] !='\0' && a[i]==b[i]){
        i++;
    }
    if(i==n){return 0;}
    return a[i]-b[i];
}


void toUpperCase(char* s){
    while(*s !='\0'){
        if(*s >= 'a'&& *s <= 'z'){
            *s=*s-32;
        }
        s++;
    }
}


void toLowerCase(char* s){
    while(*s !='\0'){
        if(*s >= 'A'&& *s <= 'Z'){
            *s=*s+32;
        }
        s++;
    }
}
// reverseString
void reverseString(char* s){
    int i = 0, j = strlen(s) - 1;
    while(i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

// countVowels
int countVowels(const char* s){
    int count = 0;
    for(int i = 0; s[i] != '\0'; i++){
        char c = tolower(s[i]);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            count++;
    }
    return count;
}
// countConsonants
int countConsonants(const char* s){
    int count = 0;
    for(int i = 0; s[i] != '\0'; i++){
        char c = tolower(s[i]);
        if(isalpha(c)){
            if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u')
                count++;
        }
    }
    return count;
}

//count words
int countWords(const char* s){
    int count = 0, inWord = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] != ' ' && !inWord){
            inWord = 1;
            count++;
        } else if(s[i] == ' '){
            inWord = 0;
        }
    }
    return count;
}
