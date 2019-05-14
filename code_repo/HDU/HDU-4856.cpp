#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
typedef long long ll;

const int MAXN=20;
const int MAXM=(1<<16)+5;
const int INF=0x3f3f3f3f;

struct node{
    int x,y,step;
    node(int x=0,int y=0,int step=0):x(x),y(y),step(step){}
};

char g[MAXN][MAXN];
int n,m,X1[MAXN],Y1[MAXN],X2[MAXN],Y2[MAXN],dx[]={-1,1,0,0},dy[]={0,0,-1,1},dis[MAXN][MAXN],dp[MAXN][MAXM];
bool vis[MAXN][MAXN];
queue<node>q;

inline bool check(int x,int y){
    if(x<1||x>n||y<1||y>n)return 0;
    if(g[x][y]=='#'||vis[x][y])return 0;
    return 1;
}

void getDis(){
    memset(dis,0x3f,sizeof(dis));
    for(int i=0;i<m;i++)dis[i][i]=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            while(!q.empty())q.pop();
            memset(vis,0,sizeof(vis));
            q.push(node(X2[i],Y2[i],0));
            vis[X2[i]][Y2[i]]=1;
            while(!q.empty()){
                node now=q.front();q.pop();
                if(now.x==X1[j]&&now.y==Y1[j]){
                    dis[i][j]=now.step;
                    break;
                }
                for(int i=0;i<4;i++){
                    int tx=now.x+dx[i],ty=now.y+dy[i];
                    if(!check(tx,ty))continue;
                    q.push(node(tx,ty,now.step+1));
                    vis[tx][ty]=1;
                }
            }
        }
    }
}

int tsp(){
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<m;i++)dp[i][1<<i]=0;
    for(int i=0;i<1<<m;i++){
        for(int j=0;j<m;j++){
            if(!(i>>j&1))continue;
            int pre=i^(1<<j);
            for(int k=0;k<m;k++){
                if(!(pre>>k&1))continue;
                dp[j][i]=min(dp[j][i],dp[k][pre]+dis[k][j]);
            }
        }
    }
    int ans=INF;
    for(int i=0;i<m;i++)ans=min(ans,dp[i][(1<<m)-1]);
    return ans;
}

void solve(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++)scanf("%s",g[i]+1);
        for(int i=0;i<m;i++)scanf("%d%d%d%d",X1+i,Y1+i,X2+i,Y2+i);
        getDis();
        int ans=tsp();
        printf("%d\n",(ans>=INF)?(-1):ans);
    }
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}