#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>

using namespace std;
typedef long long ll;

const int MAXN=1e6+5;
const int MAXM=(1<<16)+5;
const int INF=0x3f3f3f3f;
const int MOD=10007;

char s[MAXN],tmp[MAXN];
int n,len;
string tmps;
set<string>st;

int minPre(){
	len=strlen(s+1);
	for(int i=1;i<=len;i++)s[len+i]=s[i];
	int i=1,j=2,k;
	while(i<=len&&j<=len){
		for(k=0;k<len&&s[i+k]==s[j+k];k++);
		if(k==len)break;
		if(s[i+k]<s[j+k]){
			j=j+k+1;
			if(i==j)j++;
		}else{
			i=i+k+1;
			if(i==j)i++;
		}
	}
	return min(i,j);
}

void solve(){
	while(~scanf("%d",&n)){
		st.clear();
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			int pos=minPre();
			for(int j=pos,k=1;k<=len;j++,k++)tmp[k]=s[j];
			tmp[len+1]=0;
			tmps=tmp+1;
			st.insert(tmps);
		}
		printf("%d\n",st.size());
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
