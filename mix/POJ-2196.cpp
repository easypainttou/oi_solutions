#include<cstdio>
#define f(x,y,z) for(int x=y;x<=z;x++)
using namespace std;

int cs(int x,int b){
	int s=0;
	while(x){
		s+=(x%b);
		x=x/b;
	}
	return s;
}

void solve(){
	f(i,1000,9999){
		int ds=cs(i,10);
		if(ds!=cs(i,12))continue;
		if(ds!=cs(i,16))continue;
		printf("%d\n",i);
	}
}
int main(){
	solve();
	return 0;
}