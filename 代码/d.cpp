#include<bits/stdc++.h> 
void add(int x,int y){//��� 
	for(;x<=n;x+=x&-x)
		a[x]+=y;
}
int ask(int x){//ѯ��ǰ׺�� 
	int y=0;
	for(;x;x-=x&-x)
		y+=a[x];
	return y;
}
for(int i=n;i>=1;i--){
	add(b[i],1);
	ans+=ask(b[i]-1);
}
