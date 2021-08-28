/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Peak TOI12
 * ALGO		: Implementation
 * DATE		: 28 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> peak, v(n);
	set<int>peaks;
	for(auto &x: v){
		cin >> x;
	}
	for(int i=0; i<n; ++i){
		if((i + 1 >= n || v[i] > v[i + 1]) && (i - 1 < 0 || v[i] > v[i - 1])){
			peaks.insert(v[i]);
		}
	}
	for(set<int>::iterator it=peaks.begin(); it!=peaks.end(); ++it){
		peak.push_back(*it);
	}
	reverse(all(peak));
	for(int i=0; i<min((int)peak.size(), k); ++i){
		cout << peak[i] << "\n";
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
