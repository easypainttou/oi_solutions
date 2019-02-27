/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=3e4+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

int n;
char str1[5],str2[205];
map<string,int>mp;

void solve(){
	scanf("%d",&n);
	while(n--){
		scanf("%s",str1),gets(str2);
		if(str1[0]=='a'){
			mp[str2]=1;
		}
		else{
			if(mp[str2])printf("yes\n");
			else printf("no\n");
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}