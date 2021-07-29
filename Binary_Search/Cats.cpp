/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Cats TOI13
 * ALGO		: Math
 * DATE		: 29 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int n, x, ans, prev;
	cin >> n;
	ans = prev = 0;
	for(int i=1; i<=n; ++i){
		cin >> x;
		if(x <= ans){
			continue ;
		}
		if(prev == 0){
			prev = x;
		}
		else{
			if(x == prev){
				prev = 0;
			}
			else if(x < prev){
				ans = x;
			}
			else{
				ans = max(ans, prev);
				prev = x;
			}
		}
	}
	cout << ans;
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
