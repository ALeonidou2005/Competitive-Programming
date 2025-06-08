#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

#define ll long long
#define llu unsigned long long
#define F first
#define S second
#define endl "\n"

#define sortVct(a) sort (a.begin(), a.end())
#define reverseVct(a) reverse (a.begin(), a.end())
#define pb push_back

#define printVct(v) for(llu i = 0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl
#define printPair(x) cout<<x.first<<" "<<x.second<<endl
#define printArr(arr,s,e) for(int J=s; J<=e; J++) cout<<arr[J]<<" "; cout<<endl

#define inf 1e6
#define INF 1e9
#define MOD 1000000007

//Types: 
typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;

#define N 100
#define K 100

ll dp[N+1][K+1];

ll solve(ll n, ll k){

	if (k == 1)
		return 1;

	if (dp[n][k] == -1){
		dp[n][k] = 0;
		for (ll i = 0; i<=n; i++)
			dp[n][k] += solve(n-i, k-1);
	}

	return dp[n][k]; 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (ll i = 0; i<N; i++)
		for (ll j = 0; j<K; j++)
			dp[i][j] = -1;

	ll n,k;
	cin>>n>>k;

	cout<<solve(n, k);	
	
	return 0;
}




// 5 2 => 6


























