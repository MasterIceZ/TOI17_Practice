/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

set<int> s;

void rec(vector<ll> v){
	ll sum = 0;
	for(auto x: v){
		sum *= 10;
		sum += x;
	}
	s.insert(sum);
	for(int i = v.back() + 1; i < 10; ++i){
		v.back() = i;
		rec(v);
		if(i + 1 <= 9){
			v.push_back(i+1);
			rec(v);
		}
	}
}

void solve(){
	for(int i=0; i<10; ++i){
		vector<ll> v = {i};
		rec(v);
	}
	cout << "{";
	for(auto it = s.begin(); it != s.end(); ++it){
		cout << *it << ", ";
	}
	cout << "}";
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	freopen("gen.out", "w", stdout);
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
