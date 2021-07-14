#include<stdio.h>
#include<string.h>
#define MAX 2000
char reverse(char in[]){
    int dcount,i,flag[300],ln,j=0,k=0,m;
    char out[MAX];
    //printf("Enter the string:\n");
    //gets(in);
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
   // printf(" Output:\n");
    puts(out);
    for(i=0;i<MAX;i++)
        out[i]='\0';
}
int main(){
    int T,i;
    printf("Enter no of input lines :\t ");
    scanf("%d",&T);
    char in[T][MAX],o;
    fflush(stdin);
    for(i=0;i<T;i++){
        printf("Enter the %d'th string:\n",i+1);
        gets(in[i]);
    }
    printf("\noutput strings :\n");
    for(i=0;i<T;i++){
        //puts(in[i]);
        o=reverse(in[i]);
      //  printf("\n");
    }
    system("pause");

}


