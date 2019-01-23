#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=100;

bool bk[MAXN];
int ar[16];

void solve(){
    int a,cnt=0,p=0;
    while(1){
        scanf("%d",&a);
        if(a==-1)break;
        if(a==0){
            for(int i=0;i<p;i++)if(((ar[i]&1)==0)&&(bk[ar[i]>>1]))++cnt;
            printf("%d\n",cnt);
            memset(bk,0,sizeof(bk));
            cnt=p=0;
            continue;
        }
        bk[a]=1,ar[p++]=a;
    }
}

int main(){
    solve();
    return 0;
}