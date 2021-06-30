/*
 * AUTHOR	: Hydrolyzed~
 * TASK		: Tension2
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

const int MxN = 500050;

int parent[MxN];
pair<int, int> id[MxN];
ll qs[MxN], a[MxN], b[MxN];

int root(int u){
	if(parent[u] == u){
		return u;
	}
	return parent[u] = root(parent[u]);
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q = 1;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		parent[i] = i;
		cin >> a[i] >> b[i];
		id[i] = make_pair(i, i);
	}
	for(int i=1, u ,v; i<=m; ++i){
		cin >> u >> v;
		parent[root(u)] = root(v);
	}
	for(int i=1; i<=n; ++i){
		id[i].first = root(parent[i]);
	} 
	sort(id + 1, id + n + 1);
	vector<ll> aa, bb;
	vector<ll> ans;
	for(int i=1; i<=n; ++i){
		aa.push_back(a[id[i].second]);
		bb.push_back(b[id[i].second]);
		// Generate Component
		if(id[i].first != id[i + 1].first){
			sort(all(aa), greater<ll>());
			sort(all(bb));
			ll sum = 0;
			for(int j=0; j<aa.size(); ++j){
				if(aa[j] - bb[j] > 0){
					sum += aa[j] - bb[j];
				}
				else{
					break;
				}
			}
			ans.push_back(sum);
			aa.clear(), bb.clear();
		}
	}
	ans.push_back(0);
	sort(all(ans));
	qs[1] = ans[0];
	for(int i=2; i<=ans.size(); ++i){
		qs[i] = qs[i - 1] + ans[i - 1];
	}
//	cout << endl;
//	for(int i=1; i<=10; ++i){
//		cout << parent[i] << " ";
//	}
//	cout << endl;
//	cout << "DBG : " ;
//	for(int i=1; i<=ans.size(); ++i){
//		cout << qs[i] << " " ;
//	}
//	cout << endl;

	while(q--){
		ll now, l;
		cin >> l;
		int idx = upper_bound(all(ans), l) - ans.begin();
		if(idx < ans.size()){
			now = qs[ans.size()] - qs[idx] - ((ans.size() - 1 - idx) * l);
		}
		else{
			now = ans[ans.size() - 1];
		}
		cout << max(ans[ans.size() - 1], now) << endl;
	}
	return 0;
}
