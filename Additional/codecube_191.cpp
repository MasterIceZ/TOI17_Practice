/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Anagram
 * ALGO		: Hash
 * DATE		: 12 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	s = " " + s;
	t = " " + t;
	unordered_map<string, bool> mp;
	for(int i=1; i<=min(n, m); ++i){
		for(int j=1; i+j<=min(n, m); ++j){
			mp[s.substr(j, i)] = true;
		}
	}
	for(auto x: mp){
		cout << x.first << "\n";
	}
	for(int i=min(n, m); i>=1; --i){
		for(int j=1; j+i<=min(n, m); ++j){
			if(mp[t.substr(j, i)]){
				cout << i;
				return ;
			}
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
