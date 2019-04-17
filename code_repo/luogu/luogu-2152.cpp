/*
高精度gcd
更相减损术
*/
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

typedef long long ll;

const int maxn=1e4+10;
const int maxm=62;
const int inf=0x3f3f3f3f;

struct hP{
	int num[maxn],len;
	
	hP(){memset(num,0,sizeof(num)),len=0;}
	
	bool operator<(const hP&a){
		if(len<a.len)return 1;
		if(len>a.len)return 0;
		for(int i=len-1;i>=0;i--){
			if(num[i]<a.num[i])return 1;
			if(num[i]>a.num[i])return 0;
		}
		return 0;
	}
	
	hP operator-(const hP&a){
		hP res;
		for(int i=0;i<len;i++){
			res.num[i]+=num[i]-a.num[i];
			if(res.num[i]<0){
				res.num[i]+=10,--res.num[i+1];
			}
		}
		for(int i=len-1;i>=0;i--){
			if(res.num[i]){
				res.len=i+1;
				break;
			}
		}
		return res;
	}
	
	void mul2(){
		hP res;
		res.len=len;
		for(int i=0;i<res.len;i++){
			res.num[i]+=num[i]<<1;
			res.num[i+1]+=res.num[i]/10;
			res.num[i]%=10;
			if(res.num[res.len])++res.len;
		}
		*this=res;
	}
	
	void div2(){
		for(int i=len-1;i>=0;i--){
			if(i)num[i-1]+=(num[i]&1)*10;
			num[i]=num[i]>>1;
		}
		for(int i=len-1;i>=0;i--){
			if(num[i]){
				len=i+1;
				return;
			}
		}
		len=0;
	}
	
	void output(){
		for(int i=len-1;i>=0;i--)printf("%d",num[i]);
		puts("");
	}
}A,B,ans;
char sa[maxn],sb[maxn];
int cnt;

void solve(){
	scanf("%s%s",sa,sb);
	A.len=strlen(sa),B.len=strlen(sb);
	for(int i=0;i<A.len;i++)A.num[A.len-1-i]=sa[i]-'0';
	for(int i=0;i<B.len;i++)B.num[B.len-1-i]=sb[i]-'0';
	while(1){	
		if(A.len==0||B.len==0)break;
		if(A.num[0]&1&&B.num[0]&1){
			if(A<B){
				ans=B-A;
				B=ans;
			}else{
				ans=A-B;
				A=ans;
			}
		}else if(!(A.num[0]&1)&&B.num[0]&1){
			A.div2();
		}else if(A.num[0]&1&&!(B.num[0]&1)){
			B.div2();
		}else{
			A.div2(),B.div2(),++cnt;
		}
	}
	if(A.len){
		ans=A;
	}else{
		ans=B;
	}
	while(cnt--)ans.mul2();
	for(int i=ans.len-1;i>=0;i--)printf("%d",ans.num[i]);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}