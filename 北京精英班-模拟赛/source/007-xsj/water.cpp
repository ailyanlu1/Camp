#include<bits/stdc++.h>
using namespace std;
struct cup
{
	int r,h;
	cup(int h=0,int r=0):h(h),r(r){}
}p[1010];
int mh;
int cnt;
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n;
	scanf("%d",&n);
	int m=n;
	while(n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		p[cnt].h=a,p[cnt].r=b;
		cnt++;
	}
	sort(p,p+m,[](cup a,cup b){return a.h<b.h;});
	long long ans=0;
	for(int i=0;i<m;i++)
	{
		ans+=p[i].r*p[i].r*(p[i].h-mh);
		mh=p[i].h;
	}
	cout<<ans<<endl;
	return 0;
}
