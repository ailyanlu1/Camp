#include<bits/stdc++.h> 
void update(int x){
	if(dist[rs[x]]>dist[ls[x]])swap(ls[x],rs[x]);
	dist[x]=dist[rs[x]]+1;
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(heap[x]>heap[y])swap(x,y);
	rs[x]=merge(rs[x],y);
	update(x);
	return x;
}
void add(int x,int y){
	heap[++n]=x;
	ls[n]=rs[n]=0;
	root[y]=merge(root[y],n);
}
void del(int x){
	root[x]=merge(ls[root[x]],rs[root[x]]);
}
