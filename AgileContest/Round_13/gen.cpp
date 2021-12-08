#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n = 5, k = 6;
	srand(time(NULL));
	vector<int> v = {1, 2, 3, 4, 5};
	int x = rand() % 100;
	int cnt = 0;
	cout << n << " " << k << "\n";
	do{
		cnt++;
		if(cnt == x){
			break;
		}
	}while(next_permutation(v.begin(), v.end()));
	for(auto x: v){
		cout << x << "\n";
	}
	return 0;
}
