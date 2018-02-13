#include <cstdio>
#include <iostream>
#include <cstring>
#define N 1001
using namespace std ;
int n,m,x,y,z ;
int a[N][N];
int main()
{
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	scanf("%d%d",&n,&m) ;
     for(int i=1;i<=m;i++)
     {
     	int t1,t2,t3 ;
         scanf("%d %d %d",&t1,&t2,&t3);
         a[t1][t2]=t3;
         a[t2][t1]=t3 ;
     }                        
     for(int k=1;k<=n;k++)
         for(int i=1;i<=n;i++)
             for(int j=1;j<=n;j++)
                 if(a[i][j]>a[i][k]+a[k][j])
                     a[i][j]=a[i][k]+a[k][j];   
	 printf("%d",a[1][n]) ;                        
     return 0;
} 
