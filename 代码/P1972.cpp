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
		f[i]=a[x];//f[i]��ʾi֮ǰ����ĺ�i��ȵ�����λ�� 
		a[x]=i;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
		scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].z=i;//���룬��¼ÿ��ѯ�ʳ�ʼλ�� 
	sort(Q+1,Q+q+1,cmp);//���������β���� 
	for(r=j=1;r<=n;r++){
		//printf("%d\n",f[r]);
		add(f[r]+1,1);//�����޸� 
		add(r+1,-1);
		for(;Q[j].r==r;j++)//ö����rΪ��β������ 
			ans[Q[j].z]=ask(Q[j].l);//����� 
	}
	for(i=1;i<=q;i++)
		printf("%d\n",ans[i]);
}
