#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;
const int N=1000+5;
bool f;
int n,a,b,ar[N];
stack<int>s;


int main(){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		while(1){
			scanf("%d",&ar[1]);
			if(ar[1]==0)break;
			for(int i=2;i<=n;i++){
				scanf("%d",&ar[i]);
			}
			a=b=0,f=1;
			while(!s.empty())s.pop();
			while(b<n){
				if(a<n&&ar[b+1]==a+1)++a,++b;
				else if(!s.empty()&&ar[b+1]==s.top())++b,s.pop();
				else if(a<n)++a,s.push(a);
				else{f=0;break;}
			}
			if(f)printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
	return 0;
}