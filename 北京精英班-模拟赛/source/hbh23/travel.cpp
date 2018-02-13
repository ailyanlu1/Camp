#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=10000+5;
int u[2050],v[2050],w[2050],first[2050],_next[2500],d[1010];
bool used[maxn];
priority_queue<pii,vector<pii>,greater<pii> > q;int n,m,x;pii h;
//int lujin[maxn];
int t[505][105],k[505];
int find(int jiedian,int mytime)
{
	int left=1,right=k[jiedian];
	int mid;
	while(left<right) 
	{
		mid=(left+right)>>1;
		if(t[jiedian][mid]>=mytime)right=mid;
		else left=mid+1;
	}
	if(t[jiedian][left]!=mytime)return 0;
	int kk=0;
	while(left<=k[jiedian]&&t[jiedian][left]==mytime+kk)
	{
		kk++;left++;
	}
	return kk;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
scanf("%d%d",&n,&m);
memset(first,-1,sizeof(first));//memset(used,false,sizeof(used));
for(int i=1;i<=2*m;i++)
{
	scanf("%d%d%d",&u[i],&v[i],&w[i]);
_next[i]=first[u[i]];first[u[i]]=i;
i++;
u[i]=v[i-1];v[i]=u[i-1];w[i]=w[i-1];_next[i]=first[u[i]];first[u[i]]=i;
}
for(register int i=1;i<=n;i++)
{
	scanf("%d",&k[i]);
	for(register int j=1;j<=k[i];j++)scanf("%d",&t[i][j]);
	sort(t[i]+1,t[i]+k[i]+1);
}
for(int i=0;i<=n;i++)
	d[i]=1<<28;
    d[1]=0;
q.push(make_pair(0,1));
while(!q.empty())
{
    h=q.top();q.pop();
    x=h.second;
    if(used[x])continue;
    used[x]=true;
    for(int e=first[x];e!=-1;e=_next[e])
    {
        if(d[v[e]]>d[x]+w[e]+find(v[e],d[x]+w[e]))
            {d[v[e]]=d[x]+w[e]+find(v[e],d[x]+w[e]);
            //lujin[v[e]]=e;
            q.push(make_pair(d[v[e]],v[e]));
    }
}
}
        printf("%d\n",d[n]);
//		getchar();getchar();
return 0;
}


