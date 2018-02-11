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
for(int i=n;i>=1;i--){
	add(b[i],1);
	ans+=ask(b[i]-1);
}
