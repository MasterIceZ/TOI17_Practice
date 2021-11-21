/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Math Power
 * ALGO		: Math [Fermat Last Theorm]
 * DATE		: 21 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	ll a, b, c;
	cin >> a >> b >> c;
	if(a * a + b * b ==  c * c){
		cout << 2;
	}
	else if(a + b == c){
		cout << 1;
	}
	else{
		cout << "NO";
	}
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
