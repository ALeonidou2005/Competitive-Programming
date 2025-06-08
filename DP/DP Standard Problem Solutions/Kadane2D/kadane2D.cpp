//Time Complexity: O(N^3)

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

#define N 101
#define M 101

ll sumArr[N+1];
ll kadane(int n){
	ll ans = 0, sum = 0;
	for (ll i = 0; i<n; i++){
		sum += sumArr[i];
		sum = max(sum,(ll)0);
		ans = max(ans,sum);
	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll arr[N+1][M+1];

	ll n,m;
	cin>>n>>m;
	for (ll i = 0; i<n; i++)
		for (ll j = 0; j<m; j++)
			cin>>arr[i][j];
	
	ll ans = 0;
	for (ll i = 0; i<n; i++){

		for (ll j = 0; j<m; j++)
			sumArr[j] = 0;

		for (ll j = i; j<n; j++){

			for (ll k = 0; k<m;k++)
				sumArr[k] += arr[j][k];
			ans = max(ans, kadane(m));
		}
	}
	
	cout<<ans;
	
	return 0;
}


/*
Sample Case:
4 4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
=> ANS: 15
*/




























