#include<stdio.h>
#include<stlib>

int main(){

  FILE *fp=fopen("stydebts.ext","w");

  if(fp==NULL){

    perror("error opening file");
    exit(1);
  }
fprint(fp,"%-20s %5s\n","Name","grad");
fprint(fp,"%-20s %5s \n","Ali",  15);
fprint(fp,"%-20s %5s\n",,"Sara"   17);
fprint(fp,"%-20s %5s\n",,"Mohamed"   12);

fclose(fp);
printf("[ok]File 'students.txt'created.\n");

fp=fopen("students.txt", "r");
if(fp==NUUL){perror("error");exit(1);}
char line[100];
printf("\n---content of students.txt ---\n");
while(fgets(line,sizeof(line),fp)!=NULL){
    printf("%s",line);  
}
fclose(fp;)
printf(fp,"%-20s %5")
}