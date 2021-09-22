#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

ll tree[200200], n;

void update(int idx, ll val){
	for(; idx<=n; idx+=idx&-idx){
		tree[idx] += val;
	}
}

ll query(int idx){
	ll res = 0;
	for(; idx; idx-=idx&-idx){
		res += tree[idx];
	}
	return res;
}

ll a[200200], b[200200];
unordered_map<int, ll> mp;
pair<ll, ll> cnt[200200];
vector<pair<ll, ll>> pwd;

void solve(){
	memset(cnt, 0, sizeof cnt);
	memset(tree, 0, sizeof tree);
//	ll k;
	long long k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		mp[a[i]] = 1;
		b[i] = a[i];
		cnt[i].first = a[i];
	}
	sort(b + 1, b + n + 1);
	int it = 0;
	for(int i=1; i<=n; ++i){
		mp[b[i]] = i;
	}
	for(int i=n; i>=1; --i){
		update(mp[a[i]], 1);
		cnt[mp[a[i]]].second += query(mp[a[i]] - 1);
	}
//	pwd.clear();
//	for(int i=1; i<=n; ++i){
//		pwd.emplace_back(cnt[i].first, cnt[mp[cnt[i].first]].second);
//	}
//	ll sum = 0;
//	sort(all(pwd));
	ll last = 0, sum = 0;
	for(int i=1; i<=n; ++i){
		sum += cnt[mp[b[i]]].second;
		if(sum >= k){
			it = i;
			last = k - (sum - cnt[mp[b[i]]].second);
			break;
		}
	}
	if(sum < k){
		cout << -1;
		return ;
	}
	int it2 = 0;
	for(int i=1; i<=n; ++i){
		if(a[i] == b[it]){
			it2 = i;
			break;
		}
	}
	vector<ll> v;
	for(int i=it2; i<=n; ++i){
		if(a[i] < b[it]){
			v.push_back(a[i]);
		}
	}
	sort(all(v));
	cout << b[it] << " " << v[last - 1];
	mp.clear();
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
