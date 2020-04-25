/*
...
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 + 5;

int s1, s2;
vector<bool> score;

void solve() {
    char tmp;
    while (1) {
        cin >> tmp;
        if (tmp == 'E') break;
        if (tmp == 'W') {
            score.push_back(0);
        } else {
            score.push_back(1);
        }
    }
    s1 = s2 = 0;
    for (int i = 0; i < score.size(); ++i) {
        if (score[i] == 0) {
            ++s1;
        } else {
            ++s2;
        }
        if (s1 >= 11 || s2 >= 11) {
            if (s1 - s2 > 1 || s2 - s1 > 1) {
                cout << s1 << ":" << s2 << endl;
                s1 = s2 = 0;
            }
        }
    }
    cout << s1 << ":" << s2 << endl;
    cout << endl;
    s1 = s2 = 0;
    for (int i = 0; i < score.size(); ++i) {
        if (score[i] == 0) {
            ++s1;
        } else {
            ++s2;
        }
        if (s1 >= 21 || s2 >= 21) {
            if (s1 - s2 > 1 || s2 - s1 > 1) {
                cout << s1 << ":" << s2 << endl;
                s1 = s2 = 0;
            }
        }
    }
    cout << s1 << ":" << s2 << endl;
}

int main() {
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
