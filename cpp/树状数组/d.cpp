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
