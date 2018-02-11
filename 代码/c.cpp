#include<bits/stdc++.h> 
using namespace std;
int find(int x){
	return dad[x]==x?x:find(dad[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(dep[x]>dep[y])swap(x,y);
	dad[x]=y;
	dep[y]=max(dep[y],dep[x]+1); 
}
int main(){
	
}
