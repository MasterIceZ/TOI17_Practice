/*
 * AUTHOR	: Hydrolyzed~
 * TASK		: Tension5
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;

vector<int> ls = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912};
vector<int> can;

void solve(){
	int l, r;
	cin >> l >> r;
	cout << upper_bound(all(can), r) - lower_bound(all(can), l);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q = 1;
	cin >> n >> q;
	int bound = upper_bound(all(ls), n) - ls.begin();
	int NaX = bound - 1;
	for(int i=0; i<=NaX; ++i){
		can.push_back(ls[i]);
//		cout << ls[i] << " ";
	}
//	cout << endl;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
