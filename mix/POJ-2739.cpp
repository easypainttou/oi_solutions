#include<cstdio>
#define f(x,y,z) for(int x=y;x<=z;x++)
using namespace std;

const int MAXN=1e4+10;

int pri[MAXN],bk[MAXN],pc;

void getPrime(){
    for(int i=2;i<MAXN;i++){
        if(!bk[i])pri[pc++]=i;
        for(int j=0;j<pc;j++){
            if(i*pri[j]>=MAXN)break;
            bk[i*pri[j]]=1;
            if(i%pri[j]==0)break;
        }
    }
}

void solve(){
    int n,cnt,ans;
    getPrime();
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        ans=0;
        for(int i=0;pri[i]<=n;i++){
            cnt=0;
            f(j,i,pc-1){
                cnt+=pri[j];
                if(cnt>=n)break;
            }
            if(cnt==n)ans++;
        }
        printf("%d\n",ans);
    }

}

int main(){
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}