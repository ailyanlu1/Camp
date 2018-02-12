#include <bits/stdc++.h>
using namespace std;

const int maxn=100000+15;
int n,L,a[maxn],b[maxn];
double c[maxn],pre[maxn];
bool check(double ans)
{
	for (int i=1;i<=n;i++) c[i]=a[i]-ans*b[i];  //更新权值 
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+c[i]; //维护前缀和 
	double pree=0;
	for (int i=L;i<=n;i++)
	{
		if (pre[i]>pree) return true;   //判断存不存在一个权值和非负的子序列 
		pree=min(pree,pre[i-L+1]); //维护最小的pre[l-1](l<=r-L+1) 
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&L);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	double l=0,r=9999999999,midd;
	while (l+(1e-5)<r)   //二分的最小精度 
	{
		midd=(l+r)/2;
		if (check(midd)) l=midd;
		 else r=midd; 
	}
	printf("%.1lf\n",l);
	return 0;
}
