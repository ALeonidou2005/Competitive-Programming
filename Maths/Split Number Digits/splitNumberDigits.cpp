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

#define maxLength 18		//MAX LONG LONG ≈ 9 * 10^18 => maxLength = 18

ll pows[maxLength+1];		//for time optimization
ll digitLength(ll n){
    if (n == 1)
        return 1;
    ll f = pows[maxLength], c = maxLength;
    while (n%f == n){
        f /= 10;
        c--;
    }
    return c+1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll num;
	cin>>num;

	//initialising pow => O(log(maxLength))
	pows[0] = 1;
	for (ll i = 1; i<=maxLength; i++)
		pows[i] = pows[i-1] * 10;

	//finding number of digits of num => O(log(maxLength))
	ll l = digitLength(num);

	//splitting num digits => O(log(maxLength))
	ll d;
	for (ll i = l-1; i>=0; i--){
        d = ((ll)(num/pows[i]) % 10);
        cout<<d<<" ";
	}
	
	return 0;
}

//Total Time Complexity = O(log(maxLength))
//Total Space Complexity = O(log(maxLength))

































