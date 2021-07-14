#include<stdio.h>
#include<stdlib.h>

#define MAXWL 15
#define IN 1
#define OUT 0
#define MAX_HEIGHT 35


void main(int argc, char *argv[]){
    FILE *input;
    int i,j;
    int state,count,buffer;
    int maxcount,len,x,y;
    char c;
    int wl[MAXWL+1],histogram[MAX_HEIGHT+2][MAXWL+2];
   
    if(argc!=2){
        printf("ERROR in arguments.");
        exit(1);
    }
    if((input=fopen(argv[1],"r"))==NULL)
        printf("ERROR in openning file");

    x=MAXWL+2;
    y=MAX_HEIGHT+2;
    state=OUT;
    count=0;
    buffer=0;
    for(i=0;i<=MAXWL;i++)
        wl[i]=0;
    //reading from file and counting lenghts
    do{
        c=fgetc(input);
        if( !((c>64 && c<91) || (c>96 && c<123)) ){
            if(count>0){
                if(count<=MAXWL)
                    wl[count]++;
                else
                    buffer++;
            }
            state=OUT;
            count=0;
        } else if (state==OUT){
            state=IN;
            count=1;
        } else
            count++;
    }while(c!=EOF);

    maxcount=0;
    for(i=0;i<=MAXWL;i++)
        if(wl[i]>maxcount)
            maxcount=wl[i];
    if(maxcount<buffer)
        maxcount=buffer;
    if(maxcount<MAX_HEIGHT)
        maxcount=MAX_HEIGHT;
    //Setting hist array to 0    
    for(i=0;i<y;i++)
        for(j=0;j<x;j++)
            histogram[i][j]=0;

    for(i=1;i<=MAXWL;i++){
        
        if(wl[i]>0){
            if((len= (wl[i]*MAX_HEIGHT)/maxcount)<=0)
                len=1;
        }else
            len=0;
        j=y-1;
        while(len>0){
            histogram[j][i]=1;
            len--;
            j--;
        }
        j--;
        histogram[j][i]=wl[i]+2;  
        j=y-1;  
    } 
    len=buffer;
    j=y-1;
    while(len>0){
            histogram[j][MAXWL+1]=1;
            len--;
            j--;
    }
    j--;
    histogram[j][MAXWL+1]=buffer+2;


    printf("\nHistogram of length of words in %s  :\t\n\n",argv[1]);
    printf("number of\n  words\n    ^\n"
            "\n    |"
            "\n    |\n");
    char bar = 219;
    for(i=0;i<y;i++){
        printf("    |");
        for(j=1;j<x;j++){
            if(histogram[i][j]==0)
                printf("      ");
            else if(histogram[i][j]==1)
                printf("     %c",bar);
            else
                printf("%6d",histogram[i][j]-2);
        }
        printf("\n");
    }
    printf("____|________________________________________________________________________________________________________>length\n    |");
    for(i=1;i<=MAXWL;i++)
        printf("%6d",i);
    printf("%6d<\n\n",MAXWL);
    




    fclose(input);
}