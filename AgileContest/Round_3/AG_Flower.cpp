/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Flower Bonquet
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	set<int> s;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		s.insert(x);
	}
	if(s.size() != n){
		return 0;
	}
	for(int i=1; i<=n; ++i){
		cout << n/i + (n % i != 0) << " ";
	}
	return 0;
}
