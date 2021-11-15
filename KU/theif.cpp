/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: theif
 * ALGO		: Implementation
 * DATE		: 13 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	int n, k, t;
	cin >> n >> k >> t;
	int current = 1 + k;
	set<int> s;
	s.insert(1);
	s.insert(current);
	while(current != (t % n) && current != 1){
		current += k;
		current %= n;
		s.insert(current);
	}	
	cout << s.size();
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
