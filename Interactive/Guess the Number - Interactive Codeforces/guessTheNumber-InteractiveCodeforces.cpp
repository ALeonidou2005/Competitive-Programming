#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

#define ll long long
#define llu unsigned long long
#define F first
#define S second

#define sortVct(a) sort (a.begin(), a.end())
#define reverseVct(a) reverse (a.begin(), a.end())
#define pb push_back

#define inf 1e6
#define INF 1e9
#define MOD 1000000007

typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll l = 1, r = 1000000, c;
	string s;
	
	while (l < r){
		c = l + (r-l+1)/2;
		cout<<c<<endl;
		cin>>s;

		if (s == ">=")
			l = c;
		else
			r = c - 1;
	}
	
	cout<<"! "<<l<<endl;
	
	return 0;
}

































