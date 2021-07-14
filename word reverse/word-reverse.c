#include<stdio.h>
#include<string.h>
#define MAX 2000
char reverse(char in[]){
    int dcount,i,flag[500],ln,j=0,k=0,m;
    char out[MAX];
    ln=strlen(in);
    for(i=0;i<500;i++)
        flag[i]=0;
    for(i=ln-1;i>=0;i--)
        if(in[i]==' '){
            flag[j]=i;
            j++;
        }
    for(i=0;i<=j;i++){
        if(flag[i]!=0){
            for(m=flag[i]+1;m<ln;m++,k++)
                out[k]=in[m];
            out[k]=' ';
            k++;
            ln=flag[i];
        }
        else
            for(m=flag[i];m<ln;m++){
                out[k]=in[m];
                k++;
            }
    }
    puts(out);
    for(i=0;i<MAX;i++)
        out[i]='\0';
}
int main(){
    int T,i;
    printf("Enter no of input lines :\t ");
    scanf("%d",&T);
    char in[T+1][MAX],o;
    printf("\ninput strings :\n");
    for(i=0;i<=T;i++){
        if(i!=0)
            printf("input %d:\t",i);
        gets(in[i]);
    }
    printf("\noutput strings :\n");
    for(i=1;i<=T;i++){
        printf("output %d :\t",i);
        o=reverse(in[i]);
    }
    system("pause");
}
