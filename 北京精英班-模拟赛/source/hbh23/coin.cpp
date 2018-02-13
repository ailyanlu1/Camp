#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100050
int n;double a[MAXN],b[MAXN];
double myabs(double h)
{
	if(h<0)h*=(-1);
	return h;
}
bool cmp(double a,double b)
{
	return a>b;
}
int main()
{	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
	{
	scanf("%lf%lf",&a[i],&b[i]);
	}
	sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);
	for(register int i=1;i<=n;i++)b[i]+=b[i-1];
	for(register int j=1;j<=n;j++)a[j]+=a[j-1];
	double hh=0;
	for(register int i=1;i<=n;i++)
	for(register int j=1;j<=n;j++)
	if(min(a[i]-i-j,b[j]-i-j)>hh)
	hh=min(a[i]-i-j,b[j]-i-j);
	printf("%.4lf\n",hh);
//	printf("%lf %lf",a[daa],b[daa]);
	return 0;
}
	
