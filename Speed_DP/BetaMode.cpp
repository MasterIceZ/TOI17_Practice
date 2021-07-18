/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Beta Mode
 * ALGO		: Dynamic Programming
 * DATE		: 16 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

char s[10010], t[10010];
int dp[10010][10010];

void solve(){
	int nax = 0;
	cin >> (s+1) >> (t+1);
	int lens = strlen(s + 1), lent = strlen(t + 1);
	string ans, tmp;
	int pt;
	for(int i=1; i<=lens; ++i){
		for(int j=1; j<=lent; ++j){
			if(s[i] == t[j]){
				dp[i % 2][j] = dp[(i + 1) % 2][j-1] + 1;
				if(dp[i % 2][j] > nax){
					pt = i;
				}
				nax = max(dp[i % 2][j], nax);
			}
		}
	}
	stack<char> st;
	while(nax--){
		st.push(s[pt--]);
	}
	while(!st.empty()){
		cout << st.top();
		st.pop();
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
