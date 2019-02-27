/*
...
*/
#include<queue>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=10+5;
const int maxm=(1<<10)+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct node{
	int x,y,s,step;
	node(int x=0,int y=0,int s=0,int step=0):x(x),y(y),s(s),step(step){}
};

int n,m,p,k,s,key[maxn][maxn],bd[maxn][maxn][maxn][maxn],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
bool vis[maxn][maxn][maxm];
queue<node>q;

inline int getKeyState(int x,int y,int s){
	return s|(key[x][y]);
}

inline bool check(int sx,int sy,int tx,int ty,int state){
	if(tx<1||tx>n||ty<1||ty>m)return 0;
	int door=bd[sx][sy][tx][ty];
	if(door==-1||door>0&&((1<<door)&state)==0||vis[tx][ty][state])return 0;
	return 1;
}

int bfs(){
	node st(1,1,getKeyState(1,1,0),0);
	q.push(st);
	vis[1][1][st.s]=1;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		if(now.x==n&&now.y==m){
			return now.step;
		}
		for(int i=0;i<4;i++){
			int nx=now.x+dx[i],ny=now.y+dy[i];
			if(check(now.x,now.y,nx,ny,now.s)){
				int ns=getKeyState(nx,ny,now.s);
				vis[nx][ny][ns]=1;
				q.push(node(nx,ny,ns,now.step+1));
			}
		}
	}
	return -1;
}

void solve(){
	scanf("%d%d%d%d",&n,&m,&p,&k);
	for(int i=1;i<=k;i++){
		int x1,y1,x2,y2,g;
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);
		if(g==0)g=-1;
		bd[x1][y1][x2][y2]=bd[x2][y2][x1][y1]=g;
	}
	scanf("%d",&s);
	for(int i=1;i<=s;i++){
		int x,y,q;
		scanf("%d%d%d",&x,&y,&q);
		key[x][y]|=1<<q;
	}
	printf("%d",bfs());
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}