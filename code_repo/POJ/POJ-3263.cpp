/*
...
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e4+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const int mod=9901;
typedef long long ll;

int N,I,H,R,b[maxn],bk[maxn][maxn];

void solve(){
	scanf("%d%d%d%d",&N,&I,&H,&R);
	int A,B;
	for(int i=1;i<=R;i++){
		scanf("%d%d",&A,&B);
		if(A>B)swap(A,B);	//设A要在B前面
		if(bk[A][B])continue;	//会有重复的关系qwq
		--b[A+1],++b[B];
		bk[A][B]=1;
	}
	for(int i=1;i<=N;i++){
		b[i]+=b[i-1];
		printf("%d\n",H+b[i]);
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}