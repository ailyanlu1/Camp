#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct qaq
{
    int h,r;
}qwq[1001];
bool cmp(qaq a,qaq b)
{
	return a.h<b.h;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
    int n;
    long long sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&qwq[i].h,&qwq[i].r);
    sort(qwq+1,qwq+n+1,cmp);
    for(int i=1;i<=n;i++)
        sum+=qwq[i].h*qwq[i].r*qwq[i].r;
	for(int i=2;i<=n;i++)
        sum-=qwq[i].r*qwq[i].r*qwq[i-1].h;
    printf("%lld",sum);
    return 0;
}       