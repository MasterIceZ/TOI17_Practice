/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi6_tree
 * ALGO		: Sorting
 * DATE		: 25 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	vector<pair<int, int>> tree1, tree2;
	int n, u, v;
	cin >> n;
	for(int i=1; i<n; ++i){
		cin >> u >> v;
		tree1.emplace_back(max(u, v), min(u, v));
	}
	for(int i=1; i<n; ++i){
		cin >> u >> v;
		tree2.emplace_back(max(u, v), min(u, v));
	}
	sort(tree1.begin(), tree1.end());
	sort(tree2.begin(), tree2.end());
	for(int i=0; i<n - 1; ++i){
		if(tree1[i] != tree2[i]){
			cout << "N";
			return ;
		}
	}
	cout << "Y";
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 5;
//	cin >> q;
	while(q--){
		solve();
	}
	cout << "\n";
	return 0;
}
