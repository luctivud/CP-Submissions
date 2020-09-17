/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
   '          .       ,     神 | 光      .     '        .      , 
     .      '        Udit Gupta @luctivud         ,              
  ,    '   ELDIOS | LIGHT | GREED | CIPHER | XAYN | KIRA '    .  
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                **      **  *******  * *  ******
                **      **  **   **  ***    **
                **      **  **    *  * *    **
                ******* **  *******  * *    **
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~| WORSHIPPER OF GREED |~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <bits/stdc++.h>
using namespace std;
using llu = unsigned long long int;
typedef long long int ll;
typedef long double ldo;
const ll MODPRIME {1000000007};
#define FASTINPUTOUTPUTLIKELIGHT()          ios_base::sync_with_stdio(false);
#define TESTCASES()                         ll TestCases; cin>>TestCases; while(TestCases--)
#define mp                                  make_pair
#define pb                                  push_back
#define mems(arr,val)                       memset((arr), val, sizeof((arr)))
#define FOREACH(it, ___vect)                for (auto it = ___vect.begin(); it != ___vect.end(); it++)
#define endl                                "\n"

// ////////////////////////////////////////////////////////////////////////////////////////////

#define getx                                getchar_unlocked
#define putx                                putchar_unlocked
#define in(n)                               scanf("%d",&n)s
#define inl(n)                              scanf("%lld",&n)
#define out(n)                              printf("%d",n);
#define outl(n)                             printf("%lld",n);

inline int getint(){  // this getint() is even faster than scanf !!!!!
    // Use it as:
    // int x = getint();s
    char _c;
    int _x=0;
    _c=getx();
    while (_c<=' ') _c=getx();
    while (_c>='0'){ _x=10*_x+(_c-'0'); _c=getx();}
    return _x;
}
inline long long int getllint(){  // this getint() is even faster than scanf !!!!!
    // Use it as:
    // int x = getint();s
    char _c;
    long long int _x=0;
    _c=getx();
    while (_c<=' ') _c=getx();
    while (_c>='0'){ _x=10*_x+(_c-'0'); _c=getx();}
    return _x;
}
// ///////////////////////////////////////////////////////////////////////////////////////////////
#define MAXN 1000001

const int L=1e5+7;

// baseArray is the input array
// seg stores the values stored in nodes of segment trees
// pos_in_base stores the first occurrence of node in baseArray
// level stores the depth of node with respect to root
ll baseArray[L], seg[4*L], pos_in_base[L], level[L];
ll size_of_base, start_time = 1, number_of_nodes;
std::vector<ll> v[L];
// DFS function for creating the baseArray
void eulerTour(ll vertex, ll parent)
{
	// first occurrence of node in Euler Tour
	pos_in_base[vertex] = start_time;
	baseArray[start_time++] = vertex;
	// assigning level of vertex wrt root
	level[vertex] = level[parent] + 1;
	for(auto &x : v[vertex])
	{
		if(x != parent)
		{
			eulerTour(x, vertex);
		}
		baseArray[start_time++] = vertex;
	}
	return;
}
void build(ll start = 1, ll end = size_of_base, ll index = 1)
{
	// Leaf Node
	if( start == end )
	{
		seg[index] = baseArray[start];
		return;
	}
	ll mid = (start + end)/2;

	// Recursive calls for children
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);

	// current segtree node stores the node with minimum level in current range
	if(level[ seg[2*index] ] < level[ seg[2*index + 1] ])
	{
		seg[index] = seg[2*index];
	}
	else
	{
		seg[index] = seg[2*index + 1];
	}
	return;
}

// [l,r] represent the query range
ll query(ll l, ll r, ll start = 1, ll end = size_of_base, ll index = 1)
{
	// current range is outside the query range so return node initialised with 
	// very large level 
	if( start > r || end < l )return number_of_nodes + 1;

	// current range lies completely inside the query range so return value stored
	// in the segtree node
	if(start >= l && end <= r)
	{
		return seg[index];
	}

	ll mid = (start + end)/2, query_left, query_right;

	// query both children to find node with minimum level in the subtree
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	
	if(level[ query_left ] < level[ query_right ])
	{
		return query_left;
	}
	else
	{
		return query_right;
	}
}
// //////////////////////////////////////////////////////////////////
bool vis[L]; 
  
// Array of vector where ith index 
// stores the path from the root 
// node to the ith node 
vector<ll> path[L]; 
void bfs(ll node) 
{ 
  
    // Create a queue of {child, parent} 
    queue<pair<ll, ll> > qu; 
  
    // Push root node in the front of 
    // the queue and mark as visited 
    qu.push({ node, -1 }); 
    vis[node] = true; 
  
    while (!qu.empty()) { 
        pair<ll, ll> p = qu.front(); 
  
        // Dequeue a vertex from queue 
        qu.pop(); 
        vis[p.first] = true; 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If any adjacent has not 
        // been visited then enqueue it 
  
        for (ll child : v[p.first]) { 
            if (!vis[child]) { 
                qu.push({ child, p.first }); 
  
                // Path from the root to this vertex is 
                // the path from root to the parent 
                // of this vertex followed by the 
                // parent itself 
                path[child] = path[p.first]; 
                path[child].push_back(p.first); 
            } 
        } 
    } 
} 

// ll getCount(ll node, ll LCA, ll a[], bool includeLCA) 
// { 
//     ll count = 0;
//     bool found = false;
//     vector<ll> ans = path[node]; 
//     for (ll k : ans) { 
//         // cout << k << " ";
//         if (found){
//             count+=1;
//         }
//         if (k == LCA){
//             found = true;
//         }
//     }
//     if (includeLCA){
//         count+=1;
//     }
//     // cout << node << '\n'; 
//     return count;
// } 

char prime[1000000]={0};
// int a[11];
ll P[1000000];
// ll P[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
ll k;

void sieve()
{
	
	P[k++]=2;

	for(int i=3;i*i<1000000;i+=2)
	{
		if(!prime[i])
		{
			P[k++]=i;
			for(int j=i*i;j<1000000;j+=i+i)
				prime[j] = 1;
		}
	}

	for(int i=1001;i<1000000;i+=2)
		if(!prime[i])
			P[k++]=i;
}

// //////////////////////////////////////////////////////////////////

void solve(){
    ll queries, v1, v2, LCA;
	cin >> number_of_nodes;
    baseArray[L], seg[4*L], pos_in_base[L], level[L];
    mems(baseArray, 0); mems(seg, 0); mems(pos_in_base, 0); mems(level, 0);
    mems(v,NULL); mems(path, NULL); mems(vis, NULL);
    start_time = 1;
	// Building the tree
	for (ll i = 0; i < number_of_nodes-1; ++i)
	{
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	// Assuming 1 is the root of the tree
	eulerTour(1,-1);
	// dummy node, not part of original tree
	level[number_of_nodes + 1] = INT_MAX; 
	size_of_base = start_time - 1;
	build();
    // Store the array a[]
    ll li[number_of_nodes];
    for (ll i=0; i<number_of_nodes; ++i){
        cin>>li[i];
        // cout<<a[i]<<" ";
    }

    bfs(1); 

	cin >> queries;

	while( queries-- )
	{
        // ll a[number_of_nodes];
        // for (ll i=0; i<number_of_nodes; i++){
        //     a[i] = li[i];
        // }
		cin >> v1 >> v2;
        // ll ans = 0;
		// node which occurs 1st in the baseArray must be v1
		// if it is not so then swap v1, v2	
		if(pos_in_base[v1] > pos_in_base[v2])
		{
			swap(v1, v2);
		}
		// pos_in_base stores the first occurrence of node in baseArray
		LCA = query(pos_in_base[v1], pos_in_base[v2]);
        map<int,int> m;
        set<ll>checkNodes;
        checkNodes.clear(); m.clear();
        // cout<<k<<"k";
        bool found = false;
        for(vector<ll>::iterator it = path[v1].begin(); it!=path[v1].end(); it++){ 
            ll currNode = *it;
                // cout<<currNode<<"cn";
            if (found){
                // cout <<currNode<<" "<<currNode-1<<" "<< temp << endl;
                checkNodes.insert(currNode);
            }
            if (currNode == LCA){
                found = true;
            }
        }
        // // cout<<endl;
        found = false;
        for(vector<ll>::iterator it = path[v2].begin(); it!=path[v2].end(); it++){ 
            ll currNode = *it;
            if (found){
                // cout << *it<<"it"<<temp << " ";
                // cout<<currNode<<"cn";
                checkNodes.insert(currNode);
            }
            if (currNode == LCA){
                found = true;
            }
        }
        checkNodes.insert(v1);
        checkNodes.insert(v2);
        checkNodes.insert(LCA);
        // {v1, v2, LCA};
        // cout<< v1<< " "<< v2<< " "<< LCA ;
        for (set<ll>::iterator it = checkNodes.begin(); it!=checkNodes.end(); it++){
            ll currentCheckingNode = (*it);
            ll temp = li[currentCheckingNode-1];
            // cout<<temp<<"-"<<currentCheckingNode<<" ";
            ll temp2 = temp;
            // cout<<temp<<"c"<<queries<<"q ";
            for(ll j=0; j<min((ll)floor(sqrt(temp2))+1LL,k); j++){
            // for(ll j=0; j<k; j++){
                while(temp>1 && temp%P[j]==0) {
                    // cout<<temp<<" ";
                    temp/=P[j];
                    if(m.find(P[j])!=m.end())
                        m[P[j]]++;
                    else
                        m.insert(mp(P[j],1));
                } 
                // cout<<temp<<"temp"<<endl;
            }
            if (temp>1){
                if(m.find(temp)!=m.end())
                    m[temp]++;
                else
                    m.insert(mp( temp, 1 ));
            }
        }
        // // for (ll i=0; i<number_of_nodes; i++){
        // //     cout<<a[i]<<" ";
        // // }
		// // cout << "LCA of "<< v1 <<" and "<< v2 <<" is "<< LCA <<endl;
        // // cout<<"Path of v1, v2, lca"<<endl;
        // // ans += getCount(v1, LCA, a, true);
        // // ans += getCount(v1, LCA, a, false);
        // // getCount(v2);
        // // getCount(LCA);
        // cout<<endl<<"fctrs";
        map<int,int>::iterator it;
		llu ans=1;
		for(it=m.begin();it!=m.end();++it){
			ans*= (((*it).second+1LL) % MODPRIME) ;
            ans = ans % MODPRIME;
            // cout<<(*it).first<<"^"<<(*it).second<<" ";
        } 
		cout<< ans % MODPRIME;
        cout<<endl;
	}
    // ll n; cin>>n;
    // // vector<vector<ll>> adjli;
    // for (ll i=1; i<n; i++){
    //     ll v1,v2;
    //     cin >> v1 >> v2;
	// 	v[v1].push_back(v2);
	// 	v[v2].push_back(v1);
    // }
    // ll a[n];
    // for (ll i=0; i<n; ++i){
    //     cin>>a[i];
    // }
    // eulerTour(1,-1);
	// // dummy node, not part of original tree
	// level[number_of_nodes + 1] = INT_MAX; 
	// size_of_base = start_time - 1;
	// build();
    // // LCA lc(adjli, n, 0);
    // bfs(1); 
    // ll q; cin>>q;
    // for (ll i=0; i<q; i++){
    //     ll v1,v2;
    //     cin >> v1 >> v2;
    //     if(pos_in_base[v1] > pos_in_base[v2])
	// 	{
	// 		swap(v1, v2);
	// 	}
	// 	// pos_in_base stores the first occurrence of node in baseArray
	// 	ll LCA = query(pos_in_base[v1], pos_in_base[v2]);
	// 	cout << "LCA of "<< v1 <<" and "<< v2 <<" is "<< LCA <<endl;
    //     // cout<<LCA<<endl;
    //     cout<<"Path of v1, v2, lca"<<endl;
    //     displayPath(v1);
    //     displayPath(v2);
    //     displayPath(LCA);
    // }
    /////////////// // / / / //
    return;
}

signed main(){
    sieve();
    FASTINPUTOUTPUTLIKELIGHT()
    TESTCASES()
        solve();
    return 0;
}
/*
THE APPROACH AND LOGIC WAS MINE. @luctivud
SOME PART OF THE CODE HAS BEEN TAKEN FROM THE BELOW SITES. PLEASE DO NOT PLAGIARIZE.
geeksforgeeks.org
https://cp-algorithms.com/graph/lca.html
https://github.com/sahilbansal17/Competitive_Coding/blob/2a401f54b0cdf8bb684546a6e0225be6995b155a/Data%20Structures/Trees/LCA/RMQ.cpp

SAMPLE TEST CASES::
2
9
1 2
1 3
2 5
5 6
6 7
6 8
3 4
4 9
14 37 18 16 12 9 1 4 289
10
6 4
6 3
9 6
7 8
6 8
9 9
5 7
3 6
2 3
7 1
5
1 2
1 3
2 4
2 5
2 6 4 3 5
4
5 4
3 4
1 4
2 2
*/