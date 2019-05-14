/*

最长公共的s1的前缀和s2的后缀
只要连接在一起kmp获得next，再求使长度不越界的最长公共前缀和后缀 qwq

*/
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;

const int MAXN=5e4+5;
const int MAXM=(1<<16)+5;
const int INF=0x3f3f3f3f;

char s1[MAXN<<1],s2[MAXN];
int len1,len2,nxt[MAXN<<1];

void preKmp(){
    int j=nxt[1]=0;
    for(int i=1;i<len1+len2;i++){
        while(j>0&&s1[j+1]!=s1[i+1])j=nxt[j];
        if(s1[j+1]==s1[i+1])j++;
        nxt[i+1]=j;
    }
}

void solve(){
    while(~scanf("%s%s",s1+1,s2+1)){
        len1=strlen(s1+1),len2=strlen(s2+1);
        strcat(s1+1,s2+1);
        preKmp();
        int i;
        for(i=nxt[len1+len2];i;i=nxt[i]){
            if(i<=len1&&i<=len2){
                for(int j=1;j<=i;j++)printf("%c",s1[j]);
                printf(" ");
                break;
            }
        }
        printf("%d\n",i);
    }
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
