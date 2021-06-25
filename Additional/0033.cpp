/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Looblike
 * ALGO		: Data Structure
 * DATE		: 24 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int mp[10010];

void solve(){
	int nax = 0, n;
	cin >> n;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		mp[x]++;
		nax = max(nax, mp[x]);
	}
	for(int i=1; i<=10000; ++i){
		if(mp[i] == nax){
			cout << i << " " ;
		}
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
