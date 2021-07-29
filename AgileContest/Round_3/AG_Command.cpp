#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

void calc(int& n, int i, vector<int>& v){
	while(n % i == 0){
		n /= i;
		v.push_back(i);
	}
}	

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t, n;
	cin >> t >> n;
	vector<int> v;
	calc(n, 4, v);
	calc(n, 6, v);
	for(int i=2; i<=sqrt(n); ++i){
		if(n % i == 0){
			calc(n, i, v);
		}
	}
	if(n != 1){
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for(auto x: v){
		cout << "AC";
		for(int i=1; i<=x; ++i){
			cout << "V";
		}
	}
	cout << "\n";
	return 0;
}
