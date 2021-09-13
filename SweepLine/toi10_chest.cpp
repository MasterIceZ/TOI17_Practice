#include<bits/stdc++.h>
using namespace std;

using ll = long long;

unordered_map<ll, ll> mp;

void create(ll now, bool sign = false){
	switch(now){
		case 2:
			mp[2] += 1 * (sign ? -1: 1);
			break;
		case 3:
			mp[3] += 1 * (sign ? -1: 1);
			break;
		case 4:
			mp[2] += 2 * (sign ? -1: 1);
			break;
		case 5:
			mp[5] += 1 * (sign ? -1: 1);
			break;
		case 6:
			mp[3] += 1 * (sign ? -1: 1);
			mp[2] += 1 * (sign ? -1: 1);
			break;
		case 7:
			mp[7] += 1 * (sign ? -1: 1);
			break;
		case 8:
			mp[2] += 3 * (sign ? -1: 1);
			break;
		case 9:
			mp[3] += 2 * (sign ? -1: 1);
			break;
		default:
			mp[2] += 1 * (sign ? -1: 1);
			mp[5] += 1 * (sign ? -1: 1);
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> line;
	ll v, l, r;
	for(int i=1; i<=n; ++i){
		cin >> v >> l >> r;
		line.emplace_back(l, v);
		line.emplace_back(r + 1, -v);
	}
	sort(line.begin(), line.end());
	ll last = -1, nax = -1, cou = 0;
	for(auto x: line){
		if(x.second > 0){
			create(x.second);
			last = x.first;
		}
		else{
			ll now = (mp[2] + 1) * (mp[3] + 1) * (mp[5] + 1) * (mp[7] + 1);
			if(now == nax){
				cou += x.first - last;
			}	
			else if(now > nax){
				nax = now;
				cou = x.first - last;
			}
			create(x.second * -1, 1);
		}
	}
	cout << nax << " " << cou << "\n";
	return 0;
}
