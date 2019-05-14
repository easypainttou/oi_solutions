/*

一个重要的性质len-next[i]为此字符串的最小循环节长度(i为字符串的结尾)，
另外如果len%(len-next[i])==0,循环节就是周期出现的，出现次数就为len/(len-next[i])

HUST-1010 求最小循环节长度
POJ-2406 最小循环节周期出现的次数

qwq
*/
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;

const int MAXN=1e5+5;
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
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);
        n=strlen(s+1);
        preKmp();
        if(!nxt[n])printf("%d\n",n);
        else{
            int t=n-nxt[n];
            printf("%d\n",(n%t==0)?0:(t-n%t));
        }
    }
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
