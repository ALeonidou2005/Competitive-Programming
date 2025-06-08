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

#define N 1000

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll dp[N+1][N+1];
	ll len;
	string s, tmp;
	cin>>s;

	tmp = s;
	reverseVct(tmp);

	for (ll i = 0; i<N; i++){
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	len = s.size();
	for (llu i = 1; i<=len; i++){
		for (llu j = 1; j<=len; j++){
			if (s[i-1] == tmp[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	for (llu i = 1; i<=len; i++){
		cout<<i<<": ";
		for (llu j = 1; j<=len; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}

	vector<char> list;
	ll i = len,j = len;
	while(i > 0){
		if (dp[i][j] == dp[i-1][j])
			i--;
		else if (dp[i][j] == dp[i][j-1])
			j--;
		else{
			i--;
			j--;
			list.pb(s[i]);
		}
	}

	cout<<endl<<"ANS - Length: "<<dp[len][len];

	cout<<endl<<"Subsequence: ";
	for (ll i = 0; i<list.size(); i++)
		cout<<list[i];
	
	return 0;
}


































