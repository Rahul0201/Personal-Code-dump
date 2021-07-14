#include<stdio.h>
#include<math.h>

float GJS(int n, float a[n][n+1]){
    int i,j,k;
     float x[n],c;
    //operation
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i!=j){
                c=a[j][i]/a[i][i];
                for(k=0;k<n+1;k++)
                    a[j][k]=a[j][k]-c*a[i][k];
            }
    //solution
    for(i=0;i<n;i++){
        x[i]=a[i][n]/a[i][i];
        printf("coefficient of x^%d = %f\n",i,x[i]);
    }
}
float main(){
    int ndeg,ndata,i,j,k;
    printf("enter no of data points : ");
    scanf("%d",&ndata);
    printf("enter degree of polynomial to fit :");
    scanf("%d",&ndeg);
    float X[ndata],Y[ndata],aug[ndeg+1][ndeg+2],op;
    printf("enter data points (x,f(x)):\n");
    for(i=0;i<ndata;i++)
        scanf("%f,%f",&X[i],&Y[i]);
    //initializing aug
    for(i=0;i<=ndeg;i++)
        for(j=0;j<=ndeg+1;j++)
            aug[i][j]=0;
    //reading aug
    for(i=0;i<=ndeg;i++)
        for(j=0;j<=ndeg;j++)
            for(k=0;k<ndata;k++)
                aug[i][j]+=pow(X[k],i+j);
    for(i=0;i<=ndeg;i++)
        for(k=0;k<ndata;k++)
            aug[i][ndeg+1]+=pow(X[k],i)*Y[k];
    //operation
    op=GJS(ndeg+1,aug);
    system("pause");
}
