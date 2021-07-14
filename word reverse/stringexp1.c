#include<stdio.h>
#include<string.h>
#define MAX 2000
void main(){
    int dcount,i,flag[300],ln,j=0,k=0,m;
    char in[MAX],out[MAX];
    printf("Enter the string:\n");
    gets(in);
    ln=strlen(in);
    for(i=0;i<300;i++)
        flag[i]=0;
    for(i=ln-1;i>=0;i--)
        if(in[i]=='.'){
            flag[j]=i;
            j++;
        }
    for(i=0;i<=j;i++){
        if(flag[i]!=0){
            for(m=flag[i]+1;m<ln;m++,k++)
                out[k]=in[m];
            out[k]='.';
            k++;
            ln=flag[i];
        }
        else
            for(m=flag[i];m<ln;m++){
                out[k]=in[m];
                k++;
            }
    }
    printf(" Output:\n");
    puts(out);
    system("pause");
}
