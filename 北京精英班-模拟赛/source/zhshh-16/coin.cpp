#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define LL long long
#define MAX 100010
using namespace std;
float a[MAX],b[MAX]; 
struct node{
	double a,b;
}edge[MAX];
bool cmp1(const node a,const node b){//首先排序，猜大获奖最多的 
	return a.a<b.a;
}
int n;
double maxa=0x3f3f3f3f,maxb=0x3f3f3f3f,mx;
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>edge[i].a>>edge[i].b;
		maxa=max(maxa,edge[i].a);
		maxb=max(maxb,edge[i].b);
	}
	//mx=ceil(max(maxa,maxb));
}
double ans=0;
int use=0;
int cnt=0;
double ma=0,mb=0;//投结果大/小的时候，所得的的收益 
void DFS(){
	if(min(ma-use,mb-use)>ans)ans=min(ma-use,mb-use); 
	if(cnt==n+1)return ;
	cnt++;
	//单注 大 
	ma+=edge[cnt].a;
	use++;
	DFS();
	ma-=edge[cnt].a;
	use--;
	//单注 小 
	mb+=edge[cnt].b;
	use++;
	DFS();
	mb-=edge[cnt].b; 
	use--;
	//双注 
	ma+=edge[cnt].a;
	mb+=edge[cnt].b;
	use+=2;
	DFS();
	ma-=edge[cnt].a;
	mb-=edge[cnt].b;
	use-=2;
	//不投注 
	DFS();
	cnt--;
}
void work(){
//	sort(a+1,a+n+1);
//	sort(b+1,b+n+1);
//	int mx=ceil(min(a[1],b[1])-1);//最多的可以有多少人 
	DFS();
	printf("%.4f",ans);
}
int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	
	init();
	
	work();
	
	return 0;
}
