#include<bits/stdc++.h>
using namespace std;
void pushdown(int x){//�´���� 
	cov[ls[x]]+=cov[x];
	cov[rs[x]]+=cov[x];
	sum[ls[x]]+=cov[x]*num[ls[x]];
	sum[rs[x]]+=cov[x]*num[rs[x]];
	cov[x]=0;
}
void update(int x) {//�ϴ�ֵ 
	size[x]=size[ls[x]]+size[rs[x]]+1;
	sum[x]=sum[ls[x]]+sum[rs[x]];
}
int merge(int x,int y){
	if(!x||!y)return x|y;//������һ��Ϊ�� 
	if(ran[x]>ran[y]){//ran��ʾtreap�����Ȩֵ
		pushdown(x);
		rs[x]=merge(rs[x],y);
		update(x);
		return x;
	}else{
		pushdown(y);
		ls[y]=merge(x,ls[y]);
		update(y);
		return y;
	}
}
void split(int z,int &x,int &y,int k){//��z�ֳ�x��y������������k����x����k+1����y
	if(!z){x=0;y=0;return;}
	pushdown(z);
	if(size[ls[z]]>=k)y=z,split(ls[z],x,ls[y],k),update(y);//��k���������� 
	else x=z,split(rs[z],rs[x],y,k-size[ls[z]]-1,update(x);//��k����ڸ����Ҷ��� 
}
int main(){
	
}
