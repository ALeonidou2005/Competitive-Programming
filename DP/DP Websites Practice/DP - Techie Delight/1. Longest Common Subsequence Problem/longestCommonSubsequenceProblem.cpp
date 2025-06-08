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
#define endl "\n"

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

#define N 1000

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll dp[N+1][N+1];

	string x,y;
	cin>>x>>y;

	ll n = x.size(), m = y.size();

	for (ll i = 0; i<=n; i++)
		dp[i][0] = 0;
	for (ll i = 0; i<=m; i++)
		dp[0][i] = 0;
	
	for (ll i = 1; i<=n; i++){
		for (ll j = 1; j<=m; j++){
			if (x[i-1] != y[j-1])
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			else
				dp[i][j] = dp[i-1][j-1] + 1;
		}
	}
	
	cout<<dp[n][m];
	
	
	return 0;
}



/*
ABCBDAB
BDCABA
*/






























