/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Funny Tile
 * ALGO		: Divide and Conquer
 * DATE		: 18 Aug 2021
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

vector<tuple<int, int, int>> ans;

void divide(int n, int midi, int midj, pair<int, int> hole){
	int type;
	if(hole.first < midi && hole.second < midj){
		type = 0;
	}
	else if(hole.first < midi && hole.second >= midj){
		type = 1;
	}
	else if(hole.first >= midi && hole.second < midj){
		type = 2;
	}
	else{
		type = 3;
	}
	dbg(type, midj - 1, midi - 1);
	ans.emplace_back(type, midj - 1, midi - 1);
	if(n <= 2){
		return ;
	}
	// Type => 0
	if(type == 0){
		divide(n/2, midi-n/4, midj-n/4, hole);
	}
	else{
		divide(n/2, midi-n/4, midj-n/4, make_pair(midi - 1, midj - 1));
	}
	// Type => 1
	if(type == 1){
		divide(n/2, midi-n/4, midj+n/4, hole);
	}
	else{
		divide(n/2, midi-n/4, midj+n/4, make_pair(midi - 1, midj));
	}
	// Type => 2
	if(type == 2){
		divide(n/2, midi+n/4, midj-n/4, hole);
	}
	else{
		divide(n/2, midi+n/4, midj-n/4, make_pair(midi, midj - 1));
	}
	// Type => 3
	if(type == 3){
		divide(n/2, midi+n/4, midj+n/4, hole);
	}
	else{
		divide(n/2, midi+n/4, midj+n/4, make_pair(midi, midj));
	}		
}

void solve(){
	int n, x, y;
	cin >> n >> x >> y;
	divide(n, n/2, n/2, make_pair(y, x));
	sort(all(ans));
	cout << ans.size() << "\n";
	for(auto x: ans){
		cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
//		cout << endl;
	}
	return 0;
}
