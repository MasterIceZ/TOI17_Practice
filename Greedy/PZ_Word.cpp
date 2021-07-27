/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Word
 * ALGO		: Greedy
 * DATE		: 21 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	unordered_map<char ,int> mp;
	string s;
	cin >> s;
	for(int i=0; i<s.size(); ++i){
		mp[s[i]] += 1;
	}
	for(int i=0; i<s.size(); ++i){
		if(mp[s[i]] == 1){
			cout << s[i];
		}
		else{
			mp[s[i]] -= 1;
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
