#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

bitset<1000100> p;
vector<int> prime;

void solve(){
	prime.push_back(2);
	for(int i=3; i*i<=1000000; i+=2){
		if(p[i]){
			continue;
		}
		for(int j=i*i; j<=1000000; j+=i){
			p[j] = true;
		}
	}
	for(int i=3; i<=1000000; i+=2){
		if(!p[i]){
			prime.push_back(i);
		}
	}
	int l, r;
	cin >> l >> r;
	cout << upper_bound(prime.begin(), prime.end(), r) - lower_bound(prime.begin(), prime.end(), l - 1);
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
