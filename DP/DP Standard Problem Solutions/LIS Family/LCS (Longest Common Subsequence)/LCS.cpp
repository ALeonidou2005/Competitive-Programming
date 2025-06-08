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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll arr1[N+1], arr2[N+1];
	ll dp[N+1][N+1];
	ll n1, n2;

	//initialisation
	for (ll i = 0; i<=N; i++){
		dp[0][i] = 0;
		dp[i][0] = 0;
	}

	//input
	cin>>n1>>n2;
	for (ll i = 1; i<=n1; i++)
		cin>>arr1[i];
	for (ll i = 1; i<=n2; i++)
		cin>>arr2[i];

	//process
	for (ll i = 1; i<=n1; i++){
		for (ll j = 1; j<=n2; j++){
			if (arr1[i] == arr2[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	vi list;
	ll i = n1, j = n2;
	while (i > 0){
		if (dp[i][j] == dp[i-1][j])
			i--;
		else if (dp[i][j] == dp[i][j-1])
			j--;
		else{
			list.pb(arr1[i]);
			j--;
			i--;
		}
	}
	reverseVct(list);

	//debug
	cout<<endl<<"DP: "<<endl;
	for (ll i = 0; i<=n1; i++){
		cout<<i<<": ";
		for (ll j = 0; j<=n2; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;


	//output
	cout<<dp[n1][n2];

	cout<<endl<<"Subsequence: ";
	for (llu i = 0; i<list.size(); i++)
		cout<<list[i]<<" ";
	
	return 0;
}

/*

Test Cases:

5 3
65 66 68 67 69
66 67 69
=> 3

6 5
1 2 3 4 1 6
1 3 2 3 6
=>4

15 10
3 5 7 1 9 2 6 2 7 8 1 9 2 3 4
7 5 6 8 2 3 4 1 5 2
=>6

*/




















