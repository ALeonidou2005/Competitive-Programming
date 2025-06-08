#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <string>
#include <fstream>

using namespace std;

#define ll long long
#define llu unsigned long long
#define ld long double
#define F first
#define S second
#define endl "\n"

#define sortVct(a) sort (a.begin(), a.end())
#define reverseVct(a) reverse (a.begin(), a.end())
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)(x).size()
#define ins insert
#define pb push_back

#define inf 1e9
#define INF 1e18
#define MOD 1000000007
#define MOD2 998244353

typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;
typedef set <ll> si;
typedef map <ll,ll> mi;

string printArr(ll *arr,ll l,ll m=0){if(m==1){for(ll i=0;i<l;i++)cout<<arr[i]<<" ";cout<<endl;}else{cout<<endl;for(ll i=0;i<l;i++)cout<<i<<": "<<arr[i]<<endl;}return "";}
string printVct(vi v,ll m=0){if(m==1){for(ll i=0;i<sz(v);i++)cout<<v[i]<<" ";cout<<endl;}else{cout<<endl;for(ll i=0; i<sz(v);i++)cout<<i<<": "<<v[i]<<endl;}return "";}
string printVct2D(vector<vi>v){cout<<endl;for(ll i=0;i<sz(v);i++){cout<<i<<": ";for(ll j=0;j<sz(v[i]);j++)cout<<v[i][j]<<" ";cout<<endl;}return "";}
string printVctPair(vii v,ll m=0){if(m==1){for(ll i=0;i<sz(v);i++)cout<<v[i].F<<":"<<v[i].S<<" ";cout<<endl;}else{cout<<endl;for(ll i=0;i<sz(v);i++)cout<<i<<":  "<<v[i].F<<" : "<<v[i].S<<endl;}return "";}
string printVctPair2D(vector<vii>v){cout<<endl;for(ll i=0;i<sz(v);i++){cout<<i<<": ";for(ll j=0;j<sz(v[i]);j++)cout<<v[i][j].F<<":"<<v[i][j].S<<" ";cout<<endl;}return "";}
void check(ll n){cout<<"CHECKPOINT "<<n<<"\n\n";}
#define dbg(x) cout<<#x<<":"<<x<<endl
#define dbg2(x,y) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<endl
#define dbg3(x,y,z) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<"  "<<#z<<":"<<z<<endl
#define dbg4(x,y,z,w) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<"  "<<#z<<":"<<z<<"  "<<#w<<":"<<w<<endl

const ll dx[8]={1,-1,0,0,1,1,-1,-1}, dy[8]={0,0,1,-1,1,-1,1,-1};

ll charToIntNum(char c){return (ll)c-48;} 
char intToCharNum(ll n){return (char)n+48;}
ll charToIntLower(char c){return (ll)c-97;}
char intToCharLower(ll n){return (char)n+97;}
ll charToIntUpper(char c){return (ll)c-65;}
char intToCharUpper(ll n){return (char)n+65;}

ll gcd(ll x,ll y){if(y==0)return x;return gcd(y,x%y);}
void yesno(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}

#define N 150
#define M 1000000

ll arr[N+1][M+1];
ll sumArr[M+1];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n,m;
	cin>>n>>m;
	for (ll i = 0; i<n; i++){
		for (ll j = 0; j<m; j++){
			cin>>arr[i][j];
			if (arr[i][j] == 0)
				arr[i][j]--;
		}
	}
	
	/*
	for(ll i = 0; i<n; i++){
		cout<<i<<": ";
		for (ll j = 0; j<m; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	*/

	ll posX_init, posX_last, posY_init, posY_last;
	ll ans = -1;
	for (ll i = 0; i<n; i++){
		for (ll j = 0; j<m; j++)
			sumArr[j] = 0;

		for (ll j = i; j<n; j++){
			for (ll k = 0; k<m; k++)
				sumArr[k] += arr[j][k];

			//kadane
			ll curPos_init = -1, nextPos_init = 0, curPos_last = -1;
			ll curAns = 0, curSum = 0;
			for (ll k = 0; k<m; k++){
				curSum += sumArr[k];
				if (curSum < 0){
					curSum = 0;
					nextPos_init = k+1;
				}
				if (curAns < curSum){
					curAns = curSum;
					curPos_init = nextPos_init;
					curPos_last = k;
				}
			}
			if (curAns > ans){
				ans = curAns;
				posY_init = i;
				posY_last = j;
				posX_init = curPos_init;
				posX_last = curPos_last;
			}
		}
	}

/*
	dbg(ans);
	dbg2(posX_init, posX_last);
	dbg2(posY_init, posY_last);
*/

	ll cost = 0;
	for (ll i = 0; i<n; i++){
		for (ll j = 0; j<m; j++){	
			if (posX_init <= j && posX_last >= j && posY_init <= i && posY_last >= i){
				//in selected area
				if (arr[i][j] == -1){
					cost++;
				}
			}
			else{
				//out of selected area
				if (arr[i][j] == 1)
					cost++;
			}
		}
	}
	
	cout<<cost<<endl;

	return 0;
}


/*
5 7
0 0 1 0 0 1 0
0 1 1 1 1 1 0
0 1 1 0 0 1 0
0 1 1 1 1 1 0
0 0 1 0 0 1 0

5 5
0 1 1 1 0
0 0 0 1 1
0 1 0 1 0
0 0 1 1 1
1 1 0 0 0

1 9
0 0 1 1 1 0 1 0 0
*/

































