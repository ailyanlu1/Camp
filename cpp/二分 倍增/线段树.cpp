#include <bits/stdc++.h>
using namespace std;

const int maxn=100000+15;
int n,m;
int sum[maxn*4],delta[maxn*4];
/*int change(int root,int l,int r,int x,int y)
{
	if (l>x || r<x) return 0;
	sum[root]+=y;
	if (l==r) return 0;
	int mid=(l+r)>>1;
	change(root<<1,l,mid,x,y);
	change(root<<1|1,mid+1,r,x,y);
	return 0;
}*/
int up(int root,int l,int r)
{
	sum[root]=sum[root<<1]+sum[root<<1|1];
	return 0;
}
int down(int root,int l,int r)
{
	if (delta[root]==0) return 0;
	int d=delta[root];
	delta[root]=0;
	int mid=(l+r)>>1;
	sum[root<<1]+=d*(mid-l+1);
	delta[root<<1]+=d;
	sum[root<<1|1]+=d*(r-mid);
	delta[root<<1|1]+=d;
	return 0;
}
int change2(int root,int l,int r,int x,int y,int z)
{
	if (x>r || y<l) return 0;
	if (x<=l && r<=y)
	{
		sum[root]+=z*(r-l+1);
		delta[root]+=z;
		return 0;
	}
	int mid=(l+r)>>1;
	down(root,l,r);
	change2(root<<1,l,mid,x,y,z);
	change2(root<<1|1,mid+1,r,x,y,z);
	up(root,l,r);
	return 0;
}
int foundsum(int root,int l,int r,int x,int y)
{
	if (l>y || r<x) return 0;
	if (x<=l && r<=y) return sum[root];
	down(root,l,r);
	int mid=(l+r)>>1;
	return foundsum(root<<1,l,mid,x,y)+foundsum(root<<1|1,mid+1,r,x,y);
}
int main()
{
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int od,x,y;
		scanf("%d%d%d",&od,&x,&y);
		if (od==1)
		{
			int z;
			scanf("%d",&z);
			change2(1,1,n,x,y,z);
		}
		else
		if (od==2)
		{
			printf("%d\n",foundsum(1,1,n,x,y));
		}
	}
	return 0;
 } 
