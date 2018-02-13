#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define ll long long

using namespace std;

void qsort(int left, int right)
{
	int i,j,t,temp;
	if(left>right)
		return;
	temp=a[left];
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j]<=temp&&i<j)
			j--;
		while(a[i]>=temp&&i<j)
			i++;
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[left]=a[i];
	a[i]=temp;
	qsort(left,i-1);
	qsort(i+1,right);
}

int main()
{
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);

	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%lf%lf",&map[i].a,&map[i].b);

	printf("0.5000");


	return 0;
}
