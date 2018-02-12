#include<bits/stdc++.h> 
void add(int x,int y){//添加 
	for(;x<=n;x+=x&-x)
		a[x]+=y;
}
int ask(int x){//询问前缀和 
	int y=0;
	for(;x;x-=x&-x)
		y+=a[x];
	return y;
}
