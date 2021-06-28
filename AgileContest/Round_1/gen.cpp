/*
 * AUTHOR	: Hydrolyzed~
 * TASK		:
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;

void solve(){
	int MxN = 1e3 + 1, i;
	set<int> s;
	for(int i=1; i * i<=MxN; ++i){
//		cout << i << endl;
		s.insert(i * i);
	}
	for(int i=1; 2 * (i * i) <= MxN; ++i){
		s.insert(2 * (i * i));
	}
	for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
		cout << *it << ", ";
	}
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
