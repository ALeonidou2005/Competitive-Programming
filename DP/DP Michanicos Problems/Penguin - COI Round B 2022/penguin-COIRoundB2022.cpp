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

#define N 5000000

ll s, p, m, n;
ll dp[N+1];
ll arr[N+1];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>s>>p>>m>>n;

	for (ll i = 0; i<n; i++)
		cin>>arr[i];

	ll dif, ptr= 0;
	dp[0] = s;
	for (ll i = 1; i<n; i++){
		
		while (arr[ptr] < arr[i] - m + 1)
			ptr++;

		if (ptr == 0)
			dif = 0;
		else
			dif = dp[ptr-1];

		dp[i] = min(s + dp[i-1], p + dif);
	}

	cout<<dp[n-1];
	
	return 0;
}


/*

10 25 30 6
0 1 2 30 30 32

=>45

*/



























