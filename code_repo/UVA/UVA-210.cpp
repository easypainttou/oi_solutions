#include<cstdio>
#include<cstring>
//#include<iostream>
#include<queue>
using namespace std;

bool locked;
char pro[255][10];
int T,n,st[5],qt,var[26],p[10];
queue<int>bq;
deque<int>rq;

void run(int pid){
	int & l=p[pid],time=qt;
	while(time>0){
		switch(pro[l][2]){
			case '=':
			if(strlen(pro[l])==5)var[pro[l][0]-'a']=pro[l][4]-'0';
			else var[pro[l][0]-'a']=(pro[l][4]-'0')*10+pro[l][5]-'0';
			time-=st[0];
			break;
			
			case 'i':
			printf("%d: %d\n",pid+1,var[pro[l][6]-'a']);
			time-=st[1];
			break;
			
			case 'c':
			if(locked){bq.push(pid);return;}
			locked=1;
			time-=st[2];
			break;
			
			case 'l':
			locked=0;
			if(!bq.empty())rq.push_front(bq.front()),bq.pop();
			time-=st[3];
			break;
			
			case 'd':
			return;
			//time-=st[4];
			//break;
		}
		l++;
	}
	rq.push_back(pid);
}

void solve(){
	scanf("%d",&T);
	while(T--){
		memset(var,0,sizeof(var));
		scanf("%d%d%d%d%d%d%d",&n,&st[0],&st[1],&st[2],&st[3],&st[4],&qt);
		int l=0;
		for(int i=0;i<n;i++){
			gets(pro[l++]);
			p[i]=l-1;
			while(pro[l-1][2]!='d')gets(pro[l++]);
			rq.push_back(i);
		}
		locked=0;
		while(!rq.empty()){
			int pid=rq.front();
			//cout<<" qwq"<<pid<<endl;
			rq.pop_front();
			run(pid);
		}
		if(T)printf("\n");
	}
}

int main(){
	//freopen("out","w",stdout);
	solve();
	return 0;
}