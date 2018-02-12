void find(int x){
	return dad[x]==x?x:dad[x]=find(dad[x]);
}
dad[find(x)]=find(y);
