#include<cstdio>
using namespace std;
void solve(){
	int n,cnt;
	scanf("%d",&n);
	cnt=((n>1)?(n-1):(1-n))+1;
	printf("%d",(1+n)*cnt/2);
	
}
int main(){
	solve();
	return 0;
}