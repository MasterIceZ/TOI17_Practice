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

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> student_class(10010, 0);
	for(int i=1, a, b; i<=m; ++i){
		cin >> a >> b;
		student_class[b] = a;
	}
	queue<int> row;
	vector<queue<int>> student(11);
	while(1){
		char x;
		cin >> x;
		if(x == 'X'){
			cout << "0";
			break;
		}
		else if(x == 'E'){
			int a;
			cin >> a;
			if(student[student_class[a]].empty()){
				row.push(student_class[a]);
			}
			student[student_class[a]].push(a);
		}
		else{
			if(row.empty()){
				cout << "empty" << endl;
			}
			else{
				cout << student[row.front()].front() << endl;
				student[row.front()].pop();
				if(student[row.front()].empty()){
					row.pop();
				}
			}
		}
	}
	cout << endl;
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
