#include<bits/stdc++.h>
using namespace std;

#define maxn 10000+15 
int n;
double ans;
int f[maxn][maxn];
struct node{double a;double b;}jia[maxn];
void dfs(int x,double mo1,double mo2)
{	
    if (x==n+1) {
		ans=max(ans,min(mo1,mo2));
		return;
	}
	for (int i=0;i<4;i++)
	{
	//  if (mo1<0||mo2<0) return;
		if (i==0) dfs(x+1,mo1,mo2);
		if (i==1) dfs(x+1,mo1+jia[x].a-1,mo2-1);
		if (i==2) dfs(x+1,mo1-1,mo2+jia[x].b-1);
		if (i==3) dfs(x+1,mo1+jia[x].a-2,mo2+jia[x].b-2);
	}
}
int main()
{
	freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	scanf("%lf%lf",&jia[i].a,&jia[i].b);
		ans=-1;
		dfs(1,0,0);
		printf("%.4lf",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
