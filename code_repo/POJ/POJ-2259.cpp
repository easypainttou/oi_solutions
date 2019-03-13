/*
...
*/
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
const int maxn=1e3+5;
const int maxm=1e6+5;
const int inf=0x3f3f3f3f;
const double eps=1e-5;
typedef long long ll;

int mp[maxm];	//使用map会超时qwq

queue<int>q[maxn],mq;
int t,cnt;
char str[10];


//这个这里并没有什么用
int read(){
	int res=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())res=res*10+ch-'0';
	return res*f;
}


void solve(){
	while(1){
		t=read();
		if(t==0)break;
		memset(mp,0,sizeof(mp));
		if(!mq.empty())mq.pop();
		for(int i=1;i<=t;i++)while(!q[i].empty())q[i].pop();
		if(cnt)puts("");
		++cnt;
		printf("Scenario #%d\n",cnt);
		for(int i=1;i<=t;i++){
			int n;
			n=read();
			for(int j=1;j<=n;j++){
				int id;
				id=read();
				mp[id]=i;
			}
		}
		while(1){
			scanf("%s",str);
			if(str[0]=='E'){
				int id;
				id=read();
				int tid=mp[id];
				if(!q[tid].size())mq.push(tid);
				q[tid].push(id);
			}else if(str[0]=='D'){
				int tid=mq.front(),id=q[tid].front();
				printf("%d\n",id);
				q[tid].pop();
				if(!q[tid].size())mq.pop();
			}else if(str[0]=='S'){
				break;
			}
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}