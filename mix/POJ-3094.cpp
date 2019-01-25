#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=300;

char str[MAXN];

void solve(){
	int s,len;
	while(1){
		gets(str);
		if(str[0]=='#')break;
		s=0,len=strlen(str);
		for(int i=0;i<len;i++){
			if(str[i]==' ')continue;
			s+=(int(str[i]-'A')+1)*(i+1);
		}
		printf("%d\n",s);
	}
}

int main(){
	solve();
	return 0;
}