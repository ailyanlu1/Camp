#include<bits/stdc++.h> 
using namespace std;
void pushdown(int cur,int x){//�´���� 
	A[cur<<1]+=A[cur];
	B[cur<<1]+=B[cur];
	A[cur<<1|1]+=A[cur]+(x+1>>1)*B[cur];
	B[cur<<1|1]+=B[cur];
	sum[cur<<1]+=1ll*(A[cur]+A[cur]+1ll*B[cur]*(x-1>>1))*(x+1>>1)/2;
	sum[cur<<1|1]+=1ll*(A[cur]+1ll*B[cur]*(x+1>>1)+A[cur]+1ll*B[cur]*(x-1))*(x>>1)/2;
	A[cur]=B[cur]=0;
}
void update(int cur){
	sum[cur]=sum[cur<<1]+sum[cur<<1|1];
}
void add(int l,int r,int L,int R,int a,int b,int cur){//������[L,R]��������Ϊa����Ϊb������ 
	if(L<=l&&R>=r){//���䱻���� 
		A[cur]+=a+b*(l-L);
		//A[cur]��ʾ�������䱻�����������ΪA[cur],����ΪB[cur]�ĵȲ����� 
		//��L��Ϊa����ô��l��Ϊa+(l-L)*b
		B[cur]+=b;//�������b 
		sum[cur]=(sum[cur]+1ll*(a+1ll*b*(l-L)+a+1ll*b*(r-L))*(r-l+1)/2);
		//�Ȳ�������� 
		return;
	}
	pushdown(cur,r-l+1);//�´���� 
	int mid=l+r>>1;
	if(L<=mid)add(l,mid,L,R,a,b,cur<<1);
	if(R>mid)add(mid+1,r,L,R,a,b,cur<<1|1);
	update(cur);
}
int ask(int l,int r,int L,int R,int cur) {
	if(L<=l&&R>=r)return sum[cur];
	pushdown(cur,r-l+1);
	int ans=0,mid=l+r>>1;
	if(L<=mid)ans+=ask(l,mid,L,R,x,cur<<1);
	if(R>mid)ans+=ask(mid+1,r,L,R,x,cur<<1|1);
	return ans;
}
int main(){
	
}
