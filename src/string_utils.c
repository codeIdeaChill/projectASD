#include <stdio.h>

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


int main(){
    int x = my_strlen("spider man");
    printf("the size is :%d\n",x);


    char dest[40];
    printf("%s",my_strcpy(dest,"hello world"));

    return 0;
}