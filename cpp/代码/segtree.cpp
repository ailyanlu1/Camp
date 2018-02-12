#include<bits/stdc++.h>
using namespace std;
void pushdown(int cur,int x){
	if(cov[cur]){
		cov[cur<<1]=cov[cur<<1|1]=1;
		sum[cur<<1]=sum[cur<<1|1]=0;
		cov[cur]=0;
	}
}
void update(int cur){
	sum[cur]=sum[cur<<1]+sum[cur<<1|1];
}
void add(int l,int r,int L,int R,int x,int cur){
//[l,r]Ϊ�߶����ڵ�cur��Ӧ������
//Ҫ������[L,R]����x��Ȩֵ 
//���1	l<L R<r ->���1 O(log (n/2)) ->���2+���3 O(log n) 
//���2	L<=l R<r ->���2+���4 ->���2 O(log n) 
//���3	l<L R>=r ->���3+���4 ->���3 O(log n) 
//���4	L<=l R>=r O(1)
	if(L<=l&&R>=r){//[l,r]Ϊ[L,R]�������� 
		cov[cur]=1;//���������x��lazy��� 
		sum[cur]=0;//��������� 
		return;
	}
	pushdown(cur,r-l+1);//�´���� 
	int mid=l+r>>1;//�����м�� 
	if(L<=mid)add(l,mid,L,R,x,cur<<1);//��������� 
	if(R>mid)add(mid+1,r,L,R,x,cur<<1|1);//�����Ҷ��� 
	update(cur);//�ϴ�ֵ 
}
int ask(int l,int r,int L,int R,int cur) {
	if(L<=l&&R>=r)return sum[cur];
	pushdown(cur,r-l+1);
	int ans=0,mid=l+r>>1;
	if(L<=mid)ans+=ask(l,mid,L,R,x,cur<<1);
	if(R>mid)ans+=ask(mid+1,r,L,R,x,cur<<1|1);
	return ans;
}
void build(int l,int r,int cur){
	if(l==r){sum[cur]=a[l];return;}
	int mid=l+r>>1;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
	update(cur);
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&t,&l,&r);
		if(t==1){
			add(r,1,0);
			add(l,1,1);
		}else
		{
			printf("%d\n",ask(1,l-1,0)+ask2(r+1,n,1));
		}
	}
}
