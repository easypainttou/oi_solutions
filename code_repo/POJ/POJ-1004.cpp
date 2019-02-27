#include<cstdio>

using namespace std;

void solve(){
    double s,ave=0;
    for(int i=0;i<12;i++)scanf("%lf",&s),ave+=s;
    printf("$%.2f\n",ave/12);
}

int main(){
    solve();
    return 0;
}