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
void rotate(int x)
{
    int y=dad[x],z=dad[y];
    bool f=s[1][y]==x;
    if(!is_root(y))s[s[1][z]==y][z]=x;
    s[f][y]=s[!f][x];s[!f][x]=y;
    dad[x]=z;dad[y]=x;dad[s[f][y]]=y;
    update(x);update(y);
}
void splay(int x)
{
    st[t=1]=x;
    for(int y=x;!is_root(y);st[++t]=y=dad[y]);
    for(;t;t--)if(rev[st[t]])reverse(st[t]);
    for(;!is_root(x);rotate(x))if(!is_root(dad[x]))
		s[0][dad[x]]==x^s[0][dad[dad[x]]]==dad[x]?rotate(x):rotate(dad[x]);
    update(x);
}
