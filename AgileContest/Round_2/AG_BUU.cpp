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

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;
string a, b;

unordered_map<char, int> toA;
int v[4][100010], w[4][100010];

void solve(){
	int l, r;
	cin >> l >> r;
//	cout << r - l + 1;
	string s = a.substr(l, r-l+1);
	string t = b.substr(l, r-l+1);
//	cout << s << " " << t;
	for(int i=0; i<s.size(); ++i){
		v[toA[s[i]]][i]++, w[toA[t[i]]][i]++;
		
	}
	return ;
}

int32_t main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q = 1;
	toA['A'] = 0;
	toA['T'] = 1;
	toC['C'] = 2;
	cin >> n >> q;
	cin >> a >> b;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
