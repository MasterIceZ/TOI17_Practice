/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sieve of Eratosthenes
 * ALGO		: Math
 * DATE		: 27 Oct 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 1e7;
//bool visited[MxN + 10];
bitset<MxN> visited;

vector<int> sieve(){
	vector<int> prime ;
	for(int i=2; i<MxN; ++i){
		if(visited[i]){
			continue;
		}
		for(int j=i*2; j<MxN; j+=i){
			visited[j] = true;
		}
		prime.push_back(i);
//		cerr << i << "\n";
	}
	return prime;
}
/*
vector<int> sieve(){
	vector<int> prime;
	prime.push_back(2);
	for(int i=3; i*i<=MxN; i+=2){
		if(visited[i]){
			continue;
		}
		for(int j=i*i; j<=MxN; j+=i){
			visited[j] = true;
		}
	}
	for(int i=3; i<=MxN; i+=2){
		if(!visited[i]){
			prime.push_back(i);
		}
	}
	return prime;
}
*/

void solve(){
	auto res = sieve();
//	for(int i=0; i<10; ++i){
//		cout << res[i] << " ";
//	}
	int n;
	cin >> n;
	cout << res[n - 1];
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
