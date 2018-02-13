#include<bits/stdc++.h>
using namespace std;
int n;
double a[100010],b[100010],ans=0,nn=0,xx=0,a1,a2,aa;
bool maxx(double x,double y)
{
	return x>y;
}
int main()
{
	int i,j;
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%lf%lf",&a[i],&b[i]);
	sort(a+1,a+n+1,maxx);
	sort(b+1,b+n+1,maxx);
	for(i=1;i<=n;i++)
	{
		nn+=a[i];
		for(j=1;j<=n;j++)
		{
			xx+=b[j];
			a1=nn-i-j;
			a2=xx-i-j;
			aa=min(a1,a2);
			if (ans<aa) ans=aa;
		}
		xx=0;
	}
	printf("%.4lf",ans);
	                                                                                                                                                                                                                                                                                                                                                                                     
return 0;
}

