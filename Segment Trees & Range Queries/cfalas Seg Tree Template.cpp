#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define INF 10000000
#define MOD 1000000007
#define MID (l+r)/2
#define HASHMOD 2305843009213693951
#define ll long long
#define ull unsigned long long
#define F first
#define S second
typedef pair<ll, ll> ii;
typedef pair<ii, int> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef map<int, int> mii;

#define EPS 1e-6
#define FOR(i,n) for(int i=0;i<((int)(n));i++)
#define FORi(i,a,b) for(int i=((int)(a));i<((int)(b));i++)
#define FOA(v, a) for(auto v : a)

int t, n;
vi a, b;

template<typename T>
struct seg_tree{
	struct node{
		T val;
		T laz;
		node* left=NULL;
		node* right=NULL;
		node() {val=0, laz=0, left=NULL, right=NULL;}
		node(T v) {val=v, laz=0, right=NULL, left=NULL;}
	};
	static inline node *root=NULL;
	static inline int N;
	const int RAND_VALUE=0;
	seg_tree(int n){N=n, root = new node();}

	inline void merge(node *par){
		par->val = par->left->val + par->right->val;
	}

	inline void update_node(node* ind, int val, int l, int r){
		ind->val = val * (r-l+1);
		ind->laz = val;
	}

	inline void down(node *par, int l, int r){
		par->left->val += par->laz * (MID-l+1);
		par->right->val += par->laz * (r-MID);

		par->left->laz = par->laz;
		par->right->laz = par->laz;

		par->laz = 0;
	}

	void build(vector<T>& arr, int l=0, int r=N-1, node *ind=root){
		if(l==r) ind->val = arr[l];
		else{
			if(ind->left==NULL) ind->left = new node();
			if(ind->right==NULL) ind->right = new node();
			build(arr,l,MID,ind->left);
			build(arr,MID+1,r,ind->right);

			merge(ind);
		}
	}

	void update(int rl, int rr, int val, int l=0, int r=N-1, node* ind=root){
		if(rl<=l && r<=rr) update_node(ind, val,l,r);
		else if(rr<l || r<rl) return;
		else{
			if(ind->left==NULL) ind->left = new node();
			if(ind->right==NULL) ind->right = new node();
			down(ind,l,r);
			update(rl,rr,val,l,MID,ind->left);
			update(rl,rr,val,MID+1,r,ind->right);
			merge(ind);
		}
	}

	T query(int rl, int rr, int l=0, int r=N-1, node* ind=root){
		if(rl<=l && r<=rr) return ind->val;
		else if(rl>r || l>rr) return RAND_VALUE;
		else{
			if(ind->left==NULL) ind->left = new node();
			if(ind->right==NULL) ind->right = new node();
			down(ind,l,r);

			T ret=0;
			ret += query(rl,rr,l,MID,ind->left);
			ret += query(rl,rr,MID+1,r,ind->right);
			return ret;
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>n>>q;
	seg_tree<ll> tr(n);
	a.resize(n);
	FOR(i,n) cin>>a[i];
	tr.build(a);
	while(q--){
		int t,a,b;
		cin>>t>>a>>b;
		if(t==1) tr.update(a-1,a-1,b);
		else cout<<tr.query(a-1,b-1)<<endl;
	}
}
