#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
struct cup
{
	long long h,r;
}c[2000];
bool bijiao(cup a,cup b)
{
	return a.h>b.h;
}
long long n,ans;
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++){
	std::cin>>c[i].h>>c[i].r;
}
	std::sort(c+1,c+1+n,bijiao);
	ans+=c[1].r*c[1].r*c[1].h;
	for(int i=2;i<=n;i++){
	ans+=(c[i].r*c[i].r-c[i-1].r*c[i-1].r)*c[i].h;
}
	std::cout<<ans;
	return 0;
}
