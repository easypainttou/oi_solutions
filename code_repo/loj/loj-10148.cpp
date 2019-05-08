/*
...
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N=2e3+10;
const int M=40;
const int INF=0x3f3f3f3f;

int n,head[N],tail[N],dp[N][N],ans;

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",head+i),head[i+n]=head[i];
	for(int i=1;i<n<<1;i++)tail[i]=head[i+1];
	tail[n<<1]=head[1];
	for(int i=1;i<=n;i++){
		for(int j=1;j+i-1<=n<<1;j++){
			int L=j,R=j+i-1;
			for(int k=L;k+1<=R;k++){
				dp[L][R]=max(dp[L][R],dp[L][k]+dp[k+1][R]+head[L]*tail[k]*tail[R]);
			}
			if(i==n)ans=max(ans,dp[L][R]);
		}
	}
	printf("%d",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 