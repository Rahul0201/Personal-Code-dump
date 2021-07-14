#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2000
char reld(char ceasar[], int shift){       // right encrypt left decrypt
    int i,lim;
    shift%=26;
    lim=strlen(ceasar);
    for(i=0;i<lim;i++){
        if((ceasar[i]>=65 && ceasar[i]<=90-shift) || (ceasar[i]>=97 && ceasar[i]<=122-shift))
            ceasar[i]+=shift;
        else if((ceasar[i]>90-shift && ceasar[i]<=90) || (ceasar[i]>=122-shift && ceasar[i]<=122))
            ceasar[i]-=26-shift;
    }
    puts(ceasar);
}
char lerd(char ceasar[], int shift){       // left encrypt right decrypt
    int i,lim;
    shift%=26;
    lim=strlen(ceasar);
    for(i=0;i<lim;i++){
        if((ceasar[i]>=65+shift && ceasar[i]<=90) || (ceasar[i]>=97+shift && ceasar[i]<=122))
            ceasar[i]-=shift;
        else if((ceasar[i]>=65 && ceasar[i]<65+shift) || (ceasar[i]>=97 && ceasar[i]<97+shift))
            ceasar[i]+=26-shift;
    }
    puts(ceasar);
}
void main(){
    int shift,ed,rl,fn;
    char ceasar[MAX],sol;
    printf("\t**  CEASAR CIPHER  **\nPress '0' for encryption and '1' for decryption :\t");
    scanf("%d",&ed);
    printf("Press '0' for right shift and '1' for left shift :\t");
    scanf("%d",&rl);
    fn=ed^rl;
    fflush(stdin);
    system("cls");
    if(ed==0)
        printf("\n\tEnter plain text:\n");
    else if(ed==1)
        printf("\n\tEnter cipher text:\n");
    else{
        printf("\n\tERROR IN INPUT !!!");
        exit(1);
    }
    gets(ceasar);
    printf("enter shift:\t");
    scanf("%d",&shift);
    if(ed==0)
        printf("Cipher text:\n");
    else if(ed==1)
        printf("Plain text:\n");
    if(fn==0)
        sol=reld(ceasar,shift);
    else if (fn==1)
        sol=lerd(ceasar,shift);
    system("pause");
}
