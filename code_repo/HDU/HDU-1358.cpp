#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;

const int MAXN=1e6+5;
const int MAXM=(1<<16)+5;
const int INF=0x3f3f3f3f;

char s[MAXN];
int n,nxt[MAXN];

void preKmp(){
    int j=nxt[1]=0;
    for(int i=1;i<n;i++){
        while(j>0&&s[j+1]!=s[i+1])j=nxt[j];
        if(s[j+1]==s[i+1])j++;
        nxt[i+1]=j;
    }
}

void solve(){
    int kase=0;
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        ++kase;
        printf("Test case #%d\n",kase);
        scanf("%s",s+1);
        preKmp();
        for(int i=1;i<=n;i++){
            int t=i-nxt[i];
            if(nxt[i]&&i%t==0){
                printf("%d %d\n",i,i/t);
            }
        }puts("");
    }
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
