// Source: https://www.geeksforgeeks.org/prefix-infix-conversion/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

bool checkOperator(char op){
	switch(op){
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
	}
	return false;
}

string Prefix2Infix(string str){
	stack<string> s;
	int n = str.length();
	fr(i,0,n-1){
		if (!checkOperator(str[n-1-i])){
			s.push(string(1,str[n-1-i]));
		}
		else{
			string opn1 = s.top();
			s.pop();
			string opn2 = s.top();
			s.pop();

			string t = "(" + opn1 + str[n-1-i] + opn2 + ")";
			s.push(t);
		}
	}
	return s.top();
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		cout << Prefix2Infix(s) << endl;
	}
}