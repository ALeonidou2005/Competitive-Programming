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
#define V 1000

void debugDP(ll v, ll dp[2][V+1]){
	cout<<endl<<"Printing DP: "<<endl;
	for (ll i = 0; i<2; i++){
		cout<<i<<": ";
		for (ll j = 0; j<=v; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll dp[2][V+1];
	ii items[N+1];

	ll n,v;
	cin>>v>>n;

	ll a,b;
	for (ll i = 1; i<=n; i++){
		cin>>a>>b;
		items[i] = ii(a,b);
	}

	for (ll i = 0; i<=2; i++)
		dp[i][0] = 0;
	for (ll i = 0; i<=v; i++)
		dp[0][i] = 0;

	ll tmp;
	for (ll i = 1; i<=n; i++){
		for (ll j = 1; j<=v; j++){
			tmp = (i+1)%2;
			if (items[i].S > j)
				dp[i%2][j] = dp[tmp][j];
			else
				dp[i%2][j] = max(dp[tmp][j], items[i].F + dp[tmp][j-items[i].S]);
		}
	}

	debugDP(v, dp);
	cout<<dp[n%2][v];
	
	return 0;
}


/*

10 4
10 5 40 4 30 6 50 3

*/































