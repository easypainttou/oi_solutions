/*
分数 转 连分数
连分数 转 分数
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
const int maxm=105;
const int inf=0x3f3f3f3f;

int a[maxm],tot;
char str[maxn];

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

void solve(){
	while(~scanf("%s",str)){
		tot=0;
		if(isdigit(str[0])){
			int nume=0,deno=0,pos=0;
			for(;str[pos];pos++){
				if(str[pos]=='/')break;
				nume=nume*10+str[pos]-'0';
			}
			++pos;
			for(;str[pos];pos++){
				deno=deno*10+str[pos]-'0';
			}
			while(1){
				int quot=nume/deno;
				a[++tot]=quot;
				nume=nume%deno;
				if(nume==0)break;
				swap(nume,deno);
			}
			printf("[");
			int cnt=0;
			while(cnt!=tot-1){
				printf("%d",a[cnt+1]);
				if(cnt)printf(",");
				else printf(";");
				++cnt;
			}
			printf("%d]",a[tot]);
		}else{
			int cnt=1,num=0;
			while(str[cnt]){
				if(isdigit(str[cnt]))num=num*10+str[cnt]-'0';
				else a[++tot]=num,num=0;
				++cnt;
			}
			int nume=a[tot],deno=1;
			for(int i=tot-1;i>=1;i--){
				swap(nume,deno);
				nume+=deno*a[i];
				int d=gcd(nume,deno);
				nume/=d,deno/=d;
			}
			if(deno==1)printf("%d",nume);
			else printf("%d/%d",nume,deno);
		}
		puts("");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}