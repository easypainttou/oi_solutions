/*
...
*/
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

const int MAXN=1e6+105;

int pri[MAXN],cnt,phi[MAXN],mp[MAXN];
bool vis[MAXN];

void getPrime(){
    phi[1]=0; //phi[1]=1 这题是0 qwq？
    for(int i=2;i<=MAXN-5;i++){
        if(!vis[i])pri[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt;j++){
            if(i*pri[j]>MAXN-5)break;
            vis[i*pri[j]]=1;
            if(i%pri[j]){
                phi[i*pri[j]]=phi[i]*(pri[j]-1);
            }else{
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
        }
    }
}

void debug(){
    for(int i=1;i<=MAXN-5;i++)printf("%d:%d\n",i,phi[i]);
}

void solve(){
    getPrime();
   // debug();
    for(int i=1;i<=MAXN-5;i++){
        for(int j=min(phi[i],1000000);j>=0&&!mp[j];j--){
            mp[j]=i;
        }
    }
    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++){
        int n,tmp;
        ll ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&tmp),ans+=mp[tmp];
        printf("Case %d: %lld Xukha\n",j,ans);
    }
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
