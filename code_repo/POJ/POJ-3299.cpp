#include<cstdio>
#include<cmath>
using namespace std;

char ch,bk;
double tmp,t,d,h;

inline void ipt(){
	if(ch=='T')t=tmp,bk|=(1<<0);
	if(ch=='D')d=tmp,bk|=(1<<1);
	if(ch=='H')h=tmp,bk|=(1<<2);
}

inline void cal(){
	if(bk==3)h=t+0.5555*(6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10);
	if(bk==5)d=1/(1/273.16-log(((h-t)/0.5555+10)/6.11)/5417.7530)-273.16;
	if(bk==6)t=h-0.5555*(6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10);
}

void solve(){
	while(1){
		scanf("%c",&ch);
		if(ch=='E')break;
		bk=0;
		scanf("%lf",&tmp);
		ipt(),getchar();
		scanf("%c%lf",&ch,&tmp);
		ipt(),getchar();
		cal();
		printf("T %.1f D %.1f H %.1f\n",t,d,h);
	}
}

int main(){
	solve();
	return 0;
}