#include <iostream>
#include <cstdio>
#define N 100001
using namespace std ;
struct node{
	int a[4],b[4] ;
}t[100000];
double a[N],b[N] ;
double tmp1=0,tmp2=0 ;
double ans=0.0 ;
int n ;
void dfs(int k)
{
	if (k==n)
	{
		ans=max(ans,min(tmp1,tmp2)) ;
		return ;
	}
	for (int i=1;i<=4;i++)
	{
		tmp1+=t[i].a[i] ;
		tmp2+=t[i].b[i] ;
		dfs(k+1) ;
		tmp1-=t[i].a[i] ;
		tmp2-=t[i].b[i] ;
	}
}
int main()
{
	scanf("%d",&n) ;
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a[i],&b[i]) ;//²Â´ó ²ÂÐ¡ 
	}
	if (n==1) 
	{
		printf("0.0000") ;
		return 0 ;
	}
	for (int i=1;i<=n;i++)
	{
		t[i].a[1]=a[i]-1.0 ;
		t[i].b[1]=b[i]-1.0 ;
		t[i].a[2]=a[i]-2.0 ;
		t[i].b[2]=b[i]-2.0 ;
		t[i].a[3]=a[i] ;
		t[i].b[3]=b[i] ;
		t[i].a[4]=0.0 ;
		t[i].b[4]=0.0 ;
	}
	dfs(0) ;
	printf("%.4f",ans) ;
}
