#include<stdio.h>
#include<string.h>
#define MAX 2000
char reld(char ceasar[], int shift){       // right encrypt left decrypt
    int i,lim;
    lim=strlen(ceasar);
    for(i=0;i<lim;i++){
        if((ceasar[i]>=65 && ceasar[i]<=90-shift) || (ceasar[i]>=97 && ceasar[i]<=122-shift))
            ceasar[i]+=3;
        else if((ceasar[i]>90-shift && ceasar[i]<=90) || (ceasar[i]>=122-shift && ceasar[i]<=122))
            ceasar[i]-=26-shift;
    }
    puts(ceasar);
}
char lerd(char ceasar[], int shift){       // left encrypt right decrypt
    int i,lim;
    lim=strlen(ceasar);
    for(i=0;i<lim;i++){
        if((ceasar[i]>=65+shift && ceasar[i]<=90) || (ceasar[i]>=97+shift && ceasar[i]<=122))
            ceasar[i]-=3;
        else if((ceasar[i]>=65 && ceasar[i]<65+shift) || (ceasar[i]>=97 && ceasar[i]<97+shift))
            ceasar[i]+=26-shift;
    }
    puts(ceasar);
}
void main(){
    int shift,rl,ed;
    char ceasar[MAX],sol,c,s;
    printf("\t**  CEASAR CIPHER  **\nPress 'e' for encryption and 'd' for decryption :\t");
    scanf("%c",&c);
    if(c=='e')
        ed=0;
    else if(c=='d')
        ed=1;
    printf("Press 'r' for right shift and 'l' for left shift :");
    scanf("%c",&s);
    if(s=='r')
        rl=0;
    else if(s=='l')
        rl=1;
    printf("enter plain text:\n");
    gets(ceasar);


}
