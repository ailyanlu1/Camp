#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define ll long long 
using namespace std;
const int maxn=1015;
struct Bot{
	
	ll h;
	ll r;
}bot[maxn];
ll ans=0;
int n;
bool cmp(Bot a,Bot b)
{
	return a.r>b.r; 
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	//+1s
	cin>>n;
	for(int i=1;i<=n;i++)
	{
      scanf("%lld %lld",&bot[i].h,&bot[i].r);//cin>>bot[i].h>>bot[i].r;	
	}
	sort(bot+1,bot+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		ans+=(bot[i].r*bot[i].r)*(bot[i].h-bot[i-1].h);
	}
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
