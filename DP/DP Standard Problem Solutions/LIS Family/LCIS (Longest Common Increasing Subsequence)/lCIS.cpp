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
	ll n, m;
	ll dp[N+1];

	//input
	cin>>n>>m;
	for (ll i = 0; i<n; i++)
		cin>>arr1[i];
	for (ll i = 0; i<m; i++)
		cin>>arr2[i];
 
    //process
    for (ll i = 0; i<m; i++)
        dp[i] = 0;

 	ll cur;
    for (ll i = 0; i<n; i++){

        cur = 0;
        for (ll j=0; j<m; j++){

            if (arr1[i] == arr2[j])
                dp[j] = max(dp[j], cur + 1);
 
            if (arr1[i] > arr2[j])
                cur = max(cur, dp[j]);


        }

        //debug
        /*
        cout<<endl<<"DP:  i:"<<i<<"  cur:"<<cur<<"  ";
		for (ll i = 0; i<m; i++)
			cout<<dp[i]<<" ";
		*/
    }
 
    ll ans = 0;
    for (ll i = 0; i<m; i++)
        if (dp[i] > ans)
           ans = dp[i];

 	//output
    cout<<endl<<"LCIS Length: "<<ans;

	return 0;
}


/*

Test Cases:

4 7
3 4 9 1
5 3 8 9 10 2 1
=> 2

6 9
4 9 0 2 5 1
5 8 4 0 9 3 2 1 5
=> 3

*/































