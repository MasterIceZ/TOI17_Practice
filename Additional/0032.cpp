/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Numbers
 * ALGO		: Sortings
 * DATE		: 24 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x: v){
		cin >> x;
	}
	sort(all(v));
	int printed;
	for(auto x: v){
		if(x != 0){
			printed = x;
			break;
		}
	}
	cout << printed;
	for(auto x: v){
		if(x == printed){
			printed = -1;
			continue;
		}
		cout << x;
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
