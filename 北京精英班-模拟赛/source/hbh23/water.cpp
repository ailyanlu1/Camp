#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 2005
int n;
struct DD
{
	long long h,r;
}bei[MAXN];
bool cmp(DD a,DD b)
{
	return a.h<b.h;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	long long ans=0;
	for(register int i=1;i<=n;i++)
	scanf("%lld%lld",&bei[i].h,&bei[i].r);
	long long delth=0;
	sort(bei+1,bei+n+1,cmp);
	for(register int i=1;i<=n;i++)
	{
		ans+=(bei[i].h-delth)*bei[i].r*bei[i].r;
		delth=bei[i].h;
	}
	printf("%lld\n",ans);
	return 0;
}
