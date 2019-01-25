#include<cstdio>
#include<cstring>
#define f(x,y,z) for(int x=y;x<=z;x++)
using namespace std;
const int M=20;

void solve(){
	int n,a,b,cnt,mcnt=0,ts,ms=0;
	char mn[M],tn[M];
	scanf("%d",&n);
	f(i,1,n){
		ts=cnt=0;
		scanf("%s",tn);
		f(j,1,4){
			scanf("%d%d",&a,&b);
			if(b==0)continue;
			cnt++;
			ts+=(a-1)*20+b;
		}
		if(cnt>mcnt||cnt==mcnt&&ts<ms)mcnt=cnt,ms=ts,strcpy(mn,tn);
	}
	printf("%s %d %d",mn,mcnt,ms);
}

int main(){
	solve();
	return 0;
}