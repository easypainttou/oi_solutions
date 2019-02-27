#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=(1<<8)+15;
int bk[maxn],val[maxn],l[maxn],r[maxn],cnt,rt;
char str[maxn];
bool flag;
queue<int>q;
vector<int>bfsans;

void addnode(int v,char * s){
	int len=strlen(s),crt=rt;
	for(int i=0;i<len;i++){
		if(s[i]=='L'){
			if(!l[crt])l[crt]=++cnt;
			crt=l[crt];
		}else if(s[i]=='R'){
			if(!r[crt])r[crt]=++cnt;
			crt=r[crt];
		}
	}
	if(bk[crt]){
		flag=0;
		return;
	}
	bk[crt]=1,val[crt]=v;
}

void bfs(){
	bfsans.clear();
	if(!q.empty())q.pop();
	q.push(rt);
	while(!q.empty()){
		int crt=q.front();
		q.pop();
		if(!bk[crt]){
			flag=0;
			return;
		}
		bfsans.push_back(val[crt]);
		if(l[crt])q.push(l[crt]);
		if(r[crt])q.push(r[crt]);
	}
}

void solve(){
	flag=rt=cnt=1;
	while(~scanf("%s",str)){
		//cout<<str;
		if(str[0]=='('&&str[1]==')'){
			if(!flag){
				printf("not complete");
			}else{
				bfs();
				if(!flag){printf("not complete");}
				else {
					for(int i=0;i<bfsans.size();i++){
						if(i)printf(" ");
						printf("%d",bfsans[i]);
						//cout<<"qwq";
					}
				}
			}
			printf("\n");
			flag=rt=cnt=1;
			memset(l,0,sizeof(l));
			memset(r,0,sizeof(r));
			memset(bk,0,sizeof(bk));
			continue;
		}
		int tv;
		sscanf(str+1,"%d",&tv);
		addnode(tv,strchr(str,',')+1);
		//if(!flag)continue;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}