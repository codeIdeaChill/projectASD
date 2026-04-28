#include <stdio.h>

int my_strlen(const char* s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}


int main(){
    int x = my_strlen("spider man");
    printf("the size is :%d",x);
    
    return 0;
}