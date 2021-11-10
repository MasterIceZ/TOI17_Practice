#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using ll = long long;
struct A{
	int val, idx;
	bool operator < (const A& o) const{
		if(val != o.val){
			return val < o.val;
		}
		return idx > o.idx;
	}
};
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> v, w, a(n + 3);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		if(a[i] > a[i - 1] && a[i] > a[i + 1]){
			v.push_back(a[i]);
		}
	}
	sort(all(v));
	v.push_back(-1);
	for(int i=0; i<v.size() - 1; ++i){
		if(v[i] != v[i + 1]){
			w.push_back(v[i]);
			cout << v[i] << ", " << i << "\n";
		}
	}
	if(w.size() == 0){
		cout << -1 << "\n";
		return ;
	}
	int mnt = min(k, (int)w.size());
	while(mnt--){
		cout << w.back() << "\n";
		w.pop_back();
	}
	return ;
}
int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
