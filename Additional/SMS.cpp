/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Cell{
	char c;
	int v;
	bool operator < (const Cell& o) const{
		return v > o.v;
	}
};

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	set<char> don;
	unordered_map<char, int> sum;
	while(1){
		string s;
		cin >> s;
		unoredered_map<char, int> sc;
		if(s == "!"){
			break;
		}
		else{
			for(int i=0; i<s.size(); ++i){
				if(!don.count(s[i])){
					sc[s[i]]++;
					sum[s[i]]++;
				}
			}
			int nin = 0;
			bool ok = true;
			char l;
			for(int i='A'; i<='G'; ++i){
				char cc = (char) i;
				if(sc[cc] == nin){
					ok = false;
					break;
				}
				if(sc[cc] < nin){
					nin = sc[cc];
					l = cc;
				}
			}
			if(ok){
				don.insert(l);
			}
		}
	}
	vector<Cell> v;
	for(auto x: sum){
		if(!don.count(
	}	
	return 0;
}
