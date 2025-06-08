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

ll isUgly(ll n){
	bool ans = 1;
	while (n!=1 && ans == 1){
		if (n%5 == 0)
			n/=5;
		else if (n%3 == 0)
			n/=3;
		else if (n%2 == 0)
			n/=2;
		else
			ans = 0;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;

	ll cur = 5, x = 5;
	while (x <= n){
		x += isUgly(cur);
		cur++;
	}
	
	cout<<n<<"th Ugly Number is: "<<cur-1;
	
	return 0;
}





















