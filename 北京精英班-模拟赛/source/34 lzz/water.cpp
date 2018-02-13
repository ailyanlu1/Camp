#include<cstdio>
#include<algorithm>
using namespace std;
struct cup{
	int h,r;
}x[1010];
int s(const cup a,const cup b)
{
	if(a.r>b.r) return 1;
	return 0;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int k,i,j;
	int n;
	long long ans=0;
	int wh=0;
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		scanf("%d%d",&x[k].h,&x[k].r);
	}
	sort(x+0,x+n,s);
	//for(k=0;k<n;k++)printf("%d %d\n",x[k].h,x[k].r);
	for(k=0;k<n;k++)
	{
		ans+=x[k].r*x[k].r*(x[k].h-wh);
		wh=x[k].h;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
