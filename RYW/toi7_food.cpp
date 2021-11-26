/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi7_food
 * ALGO		: Brute Force
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

bool forbidden[10];

void solve(){
	int n, m, x;
	vector<int> food;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		food.push_back(i);
	}
	while(m--){
		cin >> x;
		forbidden[x] = true;
	}
	do{
		if(forbidden[food[0]]){
			continue;
		}
		for(auto x: food){
			cout << x << " ";
		}
		cout << "\n";
	}while(next_permutation(food.begin(), food.end()));
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
