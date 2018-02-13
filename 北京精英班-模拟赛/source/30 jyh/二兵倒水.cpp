#include<bits/stdc++.h>
using namespace std;

#define maxn 1000+15
int n,tmp;
long long sum;
struct node{int h;int r;}z[maxn];
//bool cmp(node a,node b){a.h<b.h;}
inline int read_()
{
int x1=0,w1=1;register char ch1;
ch1=getchar();
while(ch1 < '0'||ch1 > '9'){if(ch1 == '-') w1=-1; ch1=getchar(); } 
while(ch1 >= '0'&&ch1 <= '9'){x1=(x1 << 3)+(x1 << 1)+ch1-'0';ch1=getchar();}
return x1*w1; 
}
void qsort(int l,int r)
{
	int x,y,mid,temp;
	x=l;y=r;mid=z[(l+r)/2].h;
	do{
		while(z[x].h<mid) x++;
		while(z[y].h>mid) y--;
		if(x<=y)
		{
			swap(z[x].h,z[y].h);
			swap(z[x].r,z[y].r);
			x++;y--;
		}
	}while(x<=y);
	if(x<r) qsort(x,r);
	if(l<y) qsort(l,y);
}
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
	n=read_();	
	for (int i=1;i<=n;i++)
	{z[i].h=read_();z[i].r=read_();}
	qsort(1,n);
	for (int i=1;i<=n;i++)
	{
		sum+=1ll*z[i].r*z[i].r*(z[i].h-tmp); 
	//	printf("%d %d %d\n",z[i].h,z[i].r,z[i].r*z[i].r*(z[i].h-tmp));
		tmp=z[i].h;
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
