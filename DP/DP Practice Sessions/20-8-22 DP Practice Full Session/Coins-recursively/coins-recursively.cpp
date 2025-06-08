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
#define V 100

ll items[N+1];
ll dp[V+1];

ll n, v;

ll solve(ll cv){

	if (cv == 0)
		return 0;

	if (dp[cv] == INF){
		ll dif;
		for (ll i = 0; i<n; i++){
			dif = cv - items[i];
			if (dif >= 0)
				dp[cv] = min(dp[cv], solve(dif) + 1);
		}
	}

	return dp[cv];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (ll i = 0; i<=V; i++)
		dp[i] = INF;

	cin>>v>>n;

	for (ll i = 0; i<n; i++)
		cin>>items[i];

	cout<<solve(v);

	return 0;
}


// 10 2 1 5































