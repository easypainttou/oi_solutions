/*
使用栈的表达式转换 （WA到自闭QAQ。其实编译原理的表达式树更好理解qwq）


能过PTA 7-20 表达式转换
改一下就能过ch-1802

luogu P1175 暂时过不了
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=310;
const int maxm=7e6+5;
const int inf=0x3f3f3f3f;
const double eps=1e-5;
typedef long long ll;

int len,opnum,snum;
char str1[maxn],op[maxn],step[maxn];

int qPow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res*=a;
		a*=a,b>>=1;
	}
	return res;
}

inline int getPri(char ch){
	if(ch=='^')return 3;
	if(ch=='*'||ch=='/')return 2;
	if(ch=='+'||ch=='-')return 1;
	return 0;
}

inline void pop(){
	char ch=op[opnum];
	step[++snum]=ch,step[++snum]=' ',--opnum;
}

void solve(){
	scanf("%s",str1+1);
	len=strlen(str1+1);
	str1[0]='(',str1[len+1]=')';
	for(int i=0;i<=len+1;i++){
		if(isdigit(str1[i])){
			while(isdigit(str1[i])||str1[i]=='.')step[++snum]=str1[i++];
			step[++snum]=' ',--i;
		}else if(str1[i]=='('){
			op[++opnum]='(';
		}else if(str1[i]==')'){
			while(opnum>0&&op[opnum]!='(')pop();
			if(opnum>0)--opnum;
		}else{
			if((str1[i]=='-'||str1[i]=='+')&&str1[i-1]=='('){
				if(str1[i]=='-')step[++snum]='-';
				++i;
				while(isdigit(str1[i])||str1[i]=='.')step[++snum]=str1[i++];
				step[++snum]=' ',--i;
			}else{
				while(opnum>0&&getPri(op[opnum])>=getPri(str1[i]))pop();
				op[++opnum]=str1[i];
			}
		}
	}
	while(opnum>0){
		if(op[opnum]!='(')pop();
		else --opnum;
	}
	step[strlen(step+1)]=0;
	printf("%s",step+1);
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	solve();
	return 0;
}