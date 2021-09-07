/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Taep Foithong
 * ALGO		: Dynamic Programming
 * DATE		: 7 Sep 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 5e6 + 10;

ll power[11];
bool dp[MxN], mark [MxN];

bool divide(int now){
	if(mark[now]){
		return dp[now];
	}
	mark[now] = true;
	int tmp = now, num = 0;
	while(tmp > 0){
		num += power[tmp % 10];
		tmp /= 10;
	}
	if(now == num){
		return dp[now] = 1;
	}
	return dp[now] = divide(num);
}

void solve(){
	string s;
	cin >> s;
	ll now = 0;
	for(int i=0; i<s.size(); ++i){
		now += power[s[i] - '0'];
	}
	int tmp = 0;
	while(now > 0){
		tmp += power[now % 10];
		now /= 10;
	}
	cout << (divide(tmp) ? "Yes" : "No");
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1, k;
	cin >> q >> k;
	for(int i=0; i<=9; ++i){
		power[i] = 1;
		for(int j=1; j<=k; ++j){
			power[i] *= i;
		}
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
