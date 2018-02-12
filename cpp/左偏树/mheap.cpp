#include<bits/stdc++.h> 
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(heap[x]>heap[y])swap(x,y);
	rs[x]=merge(rs[x],y);
	if(dist[rs[x]]>dist[ls[x]])swap(ls[x],rs[x]);
	dist[x]=dist[rs[x]]+1;
	return x;
}
void add(int x){
	heap[++n]=x;
	ls[n]=rs[n]=0;
	merge(root,n);
}
void del(){
	root=merge(ls[root],rs[root]);
}
