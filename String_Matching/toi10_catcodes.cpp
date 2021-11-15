/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi10_catcodes
 * ALGO		: Rabin Karp
 * DATE		: 14 Nov 2021
 * */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mem[100100], cut, ha;
int m, sz;

char s[1000100];

const int HSH = 1e6 + 3;

struct HSH_Table{
	int mp[HSH], real[HSH];

	void add(ll key, int val){
		ll use = key % HSH;
		while(mp[use]){
			use = (use + 1) % HSH;
		}
		mp[use] = val;
		real[use] = key;
	}

	int read(ll key){
		ll use = key % HSH;
		while(mp[use]){
			if(real[use] == key){
				return mp[use];
			}
			use = (use + 1) % HSH;
		}
		return 0;
	}
} mp;

// unordered_map<ll, int> mp;
bool visited[100100];

void solve(){
	int n, q;
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; ++i){
		gets(s);
		ll now = 0;
		for(int i=0; i<m; ++i){
			now <<= 1;
			now |= (s[i] - '0');
		}
//		mem[i] = now;
//		mp[now] = i;
		mp.add(now, i);
	}
	cut = 1 << (m - 1);
	scanf("%d", &q);
	while(q--){
		scanf("%d ", &sz);
		gets(s);
		ha = 0;
		for(int i=0; i<m; ++i){
			ha = (ha << 1) | (s[i] - '0');
		}
		for(int i=0; i<=sz-m; ++i){
//			visited[mp[ha]] = 1;
			visited[mp.read(ha)] = 1;
			ha -= ((s[i] - '0') * cut);
			ha = (ha << 1) | (s[i + m] - '0');
		}
		bool ok = false;
		for(int i=1; i<=n; ++i){
			if(visited[i]){
				printf("%d ", i);
				ok = true;
			}
			visited[i] = false;
		}
		if(!ok){
			printf("OK");
		}
		printf("\n");
	}
	return ;
}

int main(){
	int q = 1;
	while(q--){
		solve();
	}
	return 0;
}
