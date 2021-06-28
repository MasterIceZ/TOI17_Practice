/*
 * AUTHOR	: Hydrolyzed~
 * TASK		: Tension5
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()
vector<int> ls;

void solve(){
	int l, r;
	cin >> l >> r;
	cout << upper_bound(all(ls), r) - lower_bound(all(ls), l);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q = 1;
	
	int MxN = 1e9 + 1, i;
	
	for(int i=1; i * i<=MxN; ++i){
//		cout << i << endl;
		ls.push_back(i * i);
	}
	for(int i=1; 2 * (i * i) <= MxN; ++i){
		ls.push_back(2 * (i * i));
	}
	sort(all(ls));
	cin >> n >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
