#include<cstdio>
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

struct matrix{
	int r,c;
	matrix(int _r=0,int _c=0):r(_r),c(_c){}
}m[26];
char str[500];
int n,len,ans;
stack<matrix> s;

void solve(){
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		scanf("%d%d",&m[str[0]-'A'].r,&m[str[0]-'A'].c);
	}
	while(~scanf("%s",str)){
		len=strlen(str);
		ans=0;
		for(int i=0;i<len;i++){
			if(str[i]>='A'&&str[i]<='Z'){
				int od=str[i]-'A';
				s.push(m[od]);
			}else if(str[i]==')'){
				matrix tm1=s.top();s.pop();
				matrix tm2=s.top();s.pop();
				if(tm1.r!=tm2.c){
					printf("error\n");
					goto e;
				}
				ans+=tm2.r*tm1.r*tm1.c;
				s.push(matrix(tm2.r,tm1.c));
			}
			
		}
		printf("%d\n",ans);
		e:;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}