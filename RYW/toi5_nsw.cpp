/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi5_nsw
 * ALGO		: Brute Force
 * DATE		: 17 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void up(vector<int>& v, int n){
	for(int i=1; i<=n; ++i){
		v.push_back(v[0]);
		v.erase(v.begin());
	}
}

void down(vector<int>& v, int n){
	while(n--){
		v.insert(v.begin(), v.back());
		v.pop_back();
	}	
}

void solve(){
	vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> b = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	string key, w;
	cin >> key >> w;
	
	up(a, key[0] - '0' - 1);
	up(b, key[1] - '0' - 1);
	up(c, key[2] - '0' - 1);

	for(int i=0; i<w.size(); ++i){
		cout << c[b[a[w[i] - '0' - 1] - 1] - 1];
		up(a, key[0] - '0');
		down(b, 1);
		up(c, key[2] - '0');
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
