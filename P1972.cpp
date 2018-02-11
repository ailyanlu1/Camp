#include<bits/stdc++.h>
#define N 1000010
using namespace std;
int n,i,x,f[N],a[N],ans[N],b[N],q,r,j;
struct abc{int l,r,z;}Q[N];
bool cmp(abc a,abc b){return a.r<b.r;}
void add(int x,int y){for(;x<=n;x+=x&-x)b[x]+=y;}
int ask(int x){int y=0;for(;x;x-=x&-x)y+=b[x];return y;}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		f[i]=a[x];//f[i]表示i之前最近的和i相等的数的位置 
		a[x]=i;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
		scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].z=i;//读入，记录每个询问初始位置 
	sort(Q+1,Q+q+1,cmp);//按照区间结尾排序 
	for(r=j=1;r<=n;r++){
		//printf("%d\n",f[r]);
		add(f[r]+1,1);//区间修改 
		add(r+1,-1);
		for(;Q[j].r==r;j++)//枚举以r为结尾的区间 
			ans[Q[j].z]=ask(Q[j].l);//保存答案 
	}
	for(i=1;i<=q;i++)
		printf("%d\n",ans[i]);
}
