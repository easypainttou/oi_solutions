#include<cstdio>
#define f(x,y,z) for(int x=y;x<=z;x++)
using namespace std;
const int MAXN=280;
double len[MAXN];

void solve(){
	f(i,2,MAXN)len[i-1]=len[i-2]+1.0/i;
	while(1){
		double c;
		scanf("%lf",&c);
		if(c==0)break;
		
		int l=1,r=278;
		while(l<=r){
			int m=(l+r)>>1;
			if(len[m]>=c)r=m-1;
			else l=m+1;
		}
		printf("%d card(s)\n",r+1);
	}
}

int main(){
	solve();
	return 0;
}