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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll items[N+1];
	ll dp[N+1];

	ll v,n;
	cin>>v>>n;
	for (ll i = 0; i<n; i++)
		cin>>items[i];
	
	ll dif;
	dp[0] = 0;
	for (ll i = 1; i<=v; i++){
		dp[i] = INF;
		for (ll j = 0; j<n; j++){
			dif = i - items[j];
			if (dif >= 0)
				dp[i] = min(dp[i], 1 + dp[dif]);
		}
	}
	
	for (ll i = 0; i<=v; i++)
		cout<<i<<": "<<dp[i]<<endl;

	cout<<dp[v];
	
	return 0;
}


//7 4 1 3 4 5 































