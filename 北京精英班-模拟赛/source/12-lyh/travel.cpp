#include <cstdio>
#include <cstring>

using namespace std;

int n, m;

int nodes[505];
bool vis[505];

int fr[2005];
int to[2005];
int tm[2005];

int nexptr = 1;
int nex[2005];
int toid[2005];

bool time[505][2005];//true��ʾ��ռ�ã�false��ʾû��ռ�� 

void addpath(int node, int path){
	//printf("Add: %d %d\n", fr[path], to[path]);
	if(nodes[node] == 0){
		nodes[node] = nexptr;
	}else{
		int cur = nodes[node];
		while(nex[cur] != 0){
			cur = nex[cur];
		}
		nex[cur] = nexptr;
	}
	toid[nexptr] = path;
	nexptr++;
}
int ans = -1;
int space = 0;
void dfs(int city, int _time){
	/*static int callt = 0;
	callt++;
	if(callt > 10000) return; */
	//printf("%d\n", ans);
	
	//space++;
	//for(int i = 0; i <= space; ++i)printf(" ");
	//printf("Dfs(%d, %d)\n", city, _time);
	if(city == n){
		if(ans == -1){
			ans = _time;
		}else{
			ans = ans < _time ? ans : _time; 
		}
		//space--;
		return;
	}
	for(int i = nodes[city]; i != 0; i = nex[i]){
		int id = toid[i];
		int ffr, tto;
		if(city = fr[id]){
			ffr = fr[id];
			tto = to[id];
		}else{
			ffr = to[id];
			tto = fr[id];
		}
		if(!vis[tto]){
			if(tto == n || !time[tto][_time + tm[id]]){
				vis[tto] = true;
				dfs(tto, _time + tm[id]);
				//printf("%d set to false by %d\n", tto, ffr);
				vis[tto] = false;
			}
		}
	}
	//space--;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	memset(nex, 0, sizeof(nex));
	memset(nodes, 0, sizeof(nodes));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){//���������ÿ�����������������ѭ���������档�������ֻ��һ�� 
		scanf("%d%d%d", fr + i, to + i, tm + i);
		addpath(fr[i], i);
		addpath(to[i], i);
	}
	memset(time, false, sizeof(time));
	int cnt = 0;
	int cur;
	for(int i = 1; i <= n ; ++i){
		scanf("%d", &cnt);
		if(cnt == 0) continue;
		for(int j = 1; j <= cnt; ++j){
			//printf("okay!");
			scanf("%d", &cur);
			time[i][cur] = true;
		}
	}
	memset(vis, false, sizeof(vis));
	vis[1] = true;
	dfs(1, 0);
	//printf("%d\n", time[3][3]);
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
