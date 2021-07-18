/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Ant Change Word
 * ALGO		: Dynamic Programming
 * DATE		: 16 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

char s[1010], t[1010];
int dp[1010][1010];

void solve(){
	cin >> (s + 1) >> (t + 1);
	int lens = strlen(s + 1), lent = strlen(t + 1);
	for(int i=1; i<=lens; ++i){
		dp[i][0] = i;
	}
	for(int i=1; i<=lent; ++i){
		dp[0][i] = i;
	}
	for(int i=1; i<=lens; ++i){
		for(int j=1; j<=lent; ++j){
			if(s[i] == t[j]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
			}
		}
	}
	cout << dp[lens][lent];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
