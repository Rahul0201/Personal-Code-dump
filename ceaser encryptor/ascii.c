#include<stdio.h>
void main(){
    int i;
    unsigned char c;
    for(c=0;c<255;c++)
        printf("%3d\t%c\n",c,c);
}
