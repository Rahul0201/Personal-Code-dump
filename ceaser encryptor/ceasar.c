#include<stdio.h>
#include<string.h>
#define MAX 2000
void main(){
    int i,lim,shift;
    char ceasar[MAX];
    printf("enter plain text:\n");
    gets(ceasar);
    printf("enter  right shift:\t");
    scanf("%d",&shift);
    lim=strlen(ceasar);
    for(i=0;i<lim;i++){
        if((ceasar[i]>=65 && ceasar[i]<=90-shift) || (ceasar[i]>=97 && ceasar[i]<=122-shift))
            ceasar[i]+=3;
        else if((ceasar[i]>90-shift && ceasar[i]<=90) || (ceasar[i]>=122-shift && ceasar[i]<=122))
            ceasar[i]-=26-shift;
    }
    puts(ceasar);

}
