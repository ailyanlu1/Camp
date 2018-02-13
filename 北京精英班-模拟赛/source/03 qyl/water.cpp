#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define ll long long

using namespace std;

struct node{
	int h;
	int r;
}a[10005];

ll ans;
int n;
int maxh;

void qsort(int left, int right)
{
	int i,j,t,temp;
	if(left>right)
		return;
	temp=a[left].r;
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j].r<=temp&&i<j)
			j--;
		while(a[i].r>=temp&&i<j)
			i++;
		if(i<j)
		{
			swap(a[i],a[j]);
		}
	}
	a[left].r=a[i].r;
	a[i].r=temp;
	qsort(left,i-1);
	qsort(i+1,right);
}

ll dmath(int i)
{
	int j=pow(a[i].r,2);
	int j2;
	if(i==1)
	{
		return j*a[i].h;		
	}
	else
	{
		j2=a[i].h-a[i-1].h;
		if(j2>0)
		{
			return j*j2;		
		}
		else
			return 0;
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i].h,&a[i].r);
	
	qsort(1,n);
	
	for(int i=n; i>=1; --i)
		ans+=dmath(i);
	
	printf("%lld\n",ans);
	
	return 0;
}
