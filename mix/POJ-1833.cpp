#include<cstdio>
#include<algorithm>
using namespace std;

int input(){
	int num=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';)ch=getchar();
	for(;ch>='0'&&ch<='9';)num=num*10+ch-'0',ch=getchar();
	return num;
}

void output(int a){
    if(a>=10)output(a/10);
    putchar(a%10+'0');
}  

int main(){
	int t,n,k,a[1050],i;
	scanf("%d",&t);
	while(t--){
		n=input(),k=input();
		for(i=0;i<n;i++)a[i]=input();
		while(k--)next_permutation(a,a+n);
		for(i=0;i<n-1;i++)
			output(a[i]),putchar(' ');
		output(a[n-1]),putchar('\n');
	}
	return 0;
}