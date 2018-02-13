#include<bits/stdc++.h>
using namespace std;
int N;
long long S;
struct glass{
	int h,r;
}g[1005];
bool cmp(glass a,glass b)
{
	return a.h<b.h;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++)
	scanf("%d%d",&g[i].h,&g[i].r);
	sort(g+1,g+1+N,cmp);
	for(int i=N;i>1;i--)
	{
		g[i].h-=g[i-1].h;
		S+=g[i].h*g[i].r*g[i].r;
	}
	S+=g[1].h*g[1].r*g[1].r;
	cout<<S;
	return 0;
}
