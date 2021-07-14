#include<stdio.h>
float main(){
    //declaration
    int i,j,k,n;
    printf("enter no of variables:  ");
    scanf("%d",&n);
    float a[n][n+1],x[n],c;
    printf("enter augmented matrix:\n");
    //reading augmented
    for(i=0;i<n;i++)
        for(j=0;j<n+1;j++)
            scanf("%f",&a[i][j]);
    //operation
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i!=j){
                c=a[j][i]/a[i][i];
                for(k=0;k<n+1;k++)
                    a[j][k]=a[j][k]-c*a[i][k
                    ];
            }
    //solution
    for(i=0;i<n;i++){
        x[i]=a[i][n]/a[i][i];
        printf("soluion %d = %f\n",i+1,x[i]);
    }
}
