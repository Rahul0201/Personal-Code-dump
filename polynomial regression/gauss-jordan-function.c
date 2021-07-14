#include<stdio.h>
float GJS(int n, float a[n][n+1]){
    int i,j,k;
     float x[n],c;
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
float main(){
    //declaration
    int n,i,j;
    printf("enter no of variables:  ");
    scanf("%d",&n);
    float a[n][n+1],s;
    printf("enter augmented matrix:\n");
    //reading augmented
    for(i=0;i<n;i++)
        for(j=0;j<n+1;j++)
            scanf("%f",&a[i][j]);
    //solution
    s=GJS(n,a);

}
