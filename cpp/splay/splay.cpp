bool is_root(int x){return !dad[x];}
void reverse(int x)
{
    rev[x]^=1;swap(s[0][x],s[1][x]);
    rev[s[0][x]]^=1;rev[s[1][x]]^=1;
}
void update(int x)
{
    mx[x]=x;
    if(V[mx[s[0][x]]]>V[mx[x]])mx[x]=mx[s[0][x]];
    if(V[mx[s[1][x]]]>V[mx[x]])mx[x]=mx[s[1][x]];
}
//s[i][j]表示点j的第i(0,1)个儿子 
//dad[i]表示点i的父亲 
void rotate(int x)
{
    int y=dad[x],z=dad[y];//x的父亲和爷爷 
    bool f=s[1][y]==x;//f表示x是y的哪个儿子 s[f][y]==x 
    //s[s[1][z]==y][z]==y
    if(!is_root(y))s[s[1][z]==y][z]=x;
    //s[f][y]==x s[!f][x]==B
    s[f][y]=s[!f][x];s[!f][x]=y;
    //s[f][y]==B
    dad[x]=z;dad[y]=x;dad[s[f][y]]=y;
    update(x);update(y);
}
void splay(int x)
{
    st[t=1]=x;
    for(int y=x;!is_root(y);st[++t]=y=dad[y]);
    for(;t;t--)if(rev[st[t]])reverse(st[t]);
    for(;!is_root(x);rotate(x))if(!is_root(dad[x]))
		(s[0][dad[x]]==x)^(s[0][dad[dad[x]]]==dad[x])?rotate(x):rotate(dad[x]);
    update(x);
}
int find_kth(int x,int k){//sum表示节点的个数 
	if(sum[s[0][x]]>=k)return find_kth(s[0][x],k);
	if(sum[s[0][x]]+1==k)return x;
	return find_kth(s[1][x],k-sum[s[0][x]]-1);
}
int find_k(int x,int k){
	if(val[x]>k)return find_k(s[0][x],k);
	if(val[x]==k)return x;
	return find_k(s[1][x],k);
}
void insert(int &x,int k,int y){//插入节点 
	if(!x){
		x=++cnt;
		val[x]=k;
		dad[x]=y;
		splay(x);
		return;
	}
	if(val[x]>=k)insert(s[0][x],k,x);
	else insert(s[1][x],k,x);
}
int merge(int x,int y){//合并 
	splay(find_kth(y,1));
	s[0][y]=x;
}
int split(int x,int k){//分离 
	int t=find_kth(x,k);
	splay(t);
	y=s[1][t];
	dad[y]=0;
	s[1][t]=0;
}
