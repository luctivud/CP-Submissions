/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%O:,*..***%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%O. .:&Oo.,&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%O. .l%%%o..l*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%O*****************************************%%%%%&*olo*&%%<  .:***;  ,****&*%*&*************************************%%
%&<****************.  ..*****.   .****.  .**%%%%*..,:. .**o**.  .**.  ..**;&%&;*****.  .*.**.  .******.  ..**.   .**%%
%%%*%%%%%%%%%%%%%%%O* ;&%%%%%&o. <&%%%*. l*%%%%&; ,0%*. :%%**l .*%%O* ;&%%%%%%%%%%%*< .&%%%%*. <*%%%%%O* ;&%%0; *O%%%%
%%%%%%%%%%%%%%%%%%%0* :%%%%%%%*: .O%%%*. o%%%%%%*. *;. .*%%%%o .*%%0* :%%%%%%%%%%%%%l .O%%%%&. l%%%%%%0* ;*%%*: ,&%%%%
%%%%%%%%%&<<<<<<<<<;. :%%%%%%&*. :*%%%*. o%%%%%&o. .*,. .,l**; .*%%0* :%%%%%%%%%%%%%l .O%%%%&. l%%%%%%0* ;*%%*: ,0%%%%
%%%*&%%%%*<<,. .;<<;. :*%&,**..*l&%%%%*. o%%%*:. .lO%%&*l.     .*%%0* :%%%%%%%0:,o&O* ,&%%%%&. l%%%&o<,. .;::;. ,&%%%%
%%*<.l*%%%%%%*..*%%0* :%%0;  ;&*%%%%%%l  o%%&:.;**%%%%**:. ,<* .*%%0* :%%%%%%%&<. ...;&%%%%%&. l%%< .:;. .<l<:. ,&%%%%
%%%*. l*%%%%%&, l%%0* :%%%%**.,l***o<*   o%%%%&%%%%%0o* .:&%%o .*%%0* :%%%%%%%%%O;  ,O%%%%%%&. l%%* l**. l%%%*: ,&%%%%
%%%%&*.,*&%*0<..&%%0* :%%%%%%&l;,**,:l:  o%%%%%%%%%O* *l0%%%%o .*%%0* :%%%%%%%%%%%*. .o*%%%%&. l%%*.....;0%%%*: ,&%%%%
%%%%%&o*...*..:&%%%0* :%%%%%%%%%%%%%%%*. o%%%%%%%%%%O**%%%%%%o .*%%0* :%%%%%%%%%%%%&l. ,&%%%&. l%%%&&**0%%%%%*: ,&%%%%
%%%%%%%%0&*&0*%%%%%&l;*%%%%%%%%%%%%%%%0<;&%%%%%%%%%%%%%%%%%%%&;:O%%*l,*%%%%%%%%%%%%%%O; .*%%0<;&%%%%%%%%%%%%%%*,o*%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&*&%%%%%%%%%%%%%%%%%%%%%%%%%%*/
/* A l l ******** i s ******** O n e ******************&*************************************************************/
/******************************************************&************************* O n e ******** i s ******** A l l */

// l u c t i v u d   l i g h t 3 0 1   o m e g a 0 1 b o t   x a y n   c a r b o n \\\\  U   I
// n u m b   a b i l i t y   y u d i   g r e e d   m m m c d x c i i   x a r c o n ////    D   T

//             Author: Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)                  //


#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using PBSET = tree<lld, null_type, less<lld>, rb_tree_tag, tree_order_statistics_node_update>;

/*
    .insert(el) - set hai!
    .find_by_order(3) - returns an iterator to the k-th largest element (counting from zero)
    .order_of_key(6) - the number of items in a set that are strictly smaller than our item
*/




#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define          input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define        EACH(I7, A7)    for (auto& I7: A7)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  pb    push_back
#define         debspace(x)    cout << #x << " = "; println(x);
#define          debline(x)    cout << #x << " = "; print(x); cout << " ";
#define                  f1    first
#define                  s2    second



#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); huehue(_it, args); cout << "\n";}

void huehue(istream_iterator<string> it) {}
template<typename T, typename... Args>
void huehue(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << ", ";
	huehue(++it, args...);
}


template <class T> T inf() {
	return numeric_limits<T>::max();
}


void read() { return; }
void print() { return; }
void println() { cout << "\n"; return; }
template<class T> T read(T& x)   { cin >> x; return x; }
template<class T> void print(T a)   { cout << a; }
template<class T> void println(T a) { cout << a << "\n"; }

template<class T> void read(vector<T> &arr)   { EACH(i, arr) cin >> (i); }
template<class T> void print(vector<T> arr)   { EACH(i, arr) {cout << i << " ";} }
template<class T> void println(vector<T> arr) { EACH(i, arr) {cout << i << " ";} cout << "\n"; }

template<class T> void read(vector<vector<T>> &arr)   { EACH(i, arr) read(i); }
template<class T> void print(vector<vector<T>> arr)   { EACH(i, arr) println(i); }
template<class T> void println(vector<vector<T>> arr) { EACH(i, arr) println(i); }

template<typename T, typename... Args> void read(vector<T> &arr, Args &... args)   { read(arr); read(args...);}
template<typename T, typename... Args> void read(vector<vector<T>> &arr, Args &... args)   { read(arr); read(args...);}
template<typename T, typename... Args> void read(T &a, Args &... args) { cin >> (a); read(args...); }
template<typename T, typename... Args> void print(vector<T> &arr, Args &... args)   { print(arr); print(args...);}
template<typename T, typename... Args> void print(T a, Args... args) { cout << a << " "; print(args...); };
template<typename T, typename... Args> void println(vector<T> &arr, Args &... args)   { print(arr); println(args...);}
template<typename T, typename... Args> void println(T a, Args... args) { cout << a << " "; println(args...); };


const lld d4i[4] = { -1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const lld d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct Parenting {
	lld u;
	lld v;
	lld h;
};


// if u<u′, then r<r′
// if u>u′, then r>r′
// if u=u′, find the distances of nodes v and v′ from the root and denote them by h and h′ respectively
// if u=u′ and h<h′, then r<r′
// if u=u′ and h>h′, then r>r′
// if u=u′, h=h′ and v<v′, then r<r′
// if u=u′, h=h′ and v>v′, then r>r′

bool cmp (const Parenting &a, const Parenting &b) {
	if (a.u < b.u) {
		return true;
	} else if (a.u == b.u) {
		if (a.h < b.h) {
			return true;
		} else if (a.h == b.h) {
			return (a.v < b.v);
		} else {
			return false;
		}
	} else {
		return false;
	}
}


void UtilPrintMyBaby(vector<Parenting> hairu) {
	EACH(it, hairu) {
		println("u", it.u, "v", it.v, "h", it.h);
	}
}


const lld MOD = (lld)(1e9) + 7ll;


lld power(lld x, lld y) {
	lld res = 1;

	x = x % MOD;

	if (x == 0) return 0;

	while (y > 0)  {
		if (y & 1)
			res = (res * x) % MOD;

		y = y >> 1;
		x = (x * x) % MOD;
	}
	return res;
}







// void UDdfs(lld node, lld par, vector<lld> &depth, vector<lld> adj[], lld d = 0ll) {
// 	depth[node] = d;
// 	for (auto n: adj[node]) {
// 		if (n != par) {
// 			dfs(n, node, depth, adj, d+1);
// 		}
// 	}
// }





const lld MAXN = (lld)(1e3) + 5ll;
const lld level = 18ll;



void dfs(lld cur, lld prev, vector<lld> &depth, vector<lld> adj[], vector<vector<lld>> &parent, vector<lld> &children) {
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	children[cur] = 1;
	EACH(i, adj[cur]) {
		if (i != prev) {
			dfs(i, cur, depth, adj, parent, children);
			children[cur] += children[i];
		}
	}
}


void precomputeSparseMatrix(lld n, vector<vector<lld>> &parent) {
	for (lld i = 1; i < level; i++) {
		for (lld node = 1; node <= n; node++) {
			if (parent[node][i - 1] != -1)
				parent[node][i] = parent[parent[node][i - 1]][i - 1];
		}
	}
}


lld lca(lld u, lld v, vector<lld> &depth, vector<vector<lld>> &parent) {
	if (depth[v] < depth[u])
		swap(u, v);

	lld diff = depth[v] - depth[u];

	for (lld i = 0; i < level; i++)
		if ((diff >> i) & 1)
			v = parent[v][i];

	if (u == v)
		return u;

	for (lld i = level - 1; i >= 0; i--)
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}

	return parent[u][0];
}



void findPosOfV() {

}

 

void findPosOfU(lld &thisU, lld &thisV, lld pos, vector<lld> prefixSumChildren, vector<bool> &visited, map<lld, vector<Parenting> > &possibleParenting, lld n, vector<lld> &depth, vector<vector<lld>> &parent) {
	thisU = (lower_bound(all(prefixSumChildren), pos) - prefixSumChildren.begin());
	lld offsetForV = pos - prefixSumChildren[thisU-1];
	// error(pos, thisU, offsetForV);
	if (!visited[thisU]) {
		visited[thisU] = true;
		for4(i, 1, n+1, 1) {
			if (lca(thisU, i, depth, parent) != thisU) {
				Parenting temp;
				temp.u = thisU;
				temp.v = i;
				temp.h = depth[i]-1;
				possibleParenting[thisU].pb(temp);
			}
		}
		sort(all(possibleParenting[thisU]), cmp);
	}
	// UtilPrintMyBaby(possibleParenting[thisU]);
	// thisV = 4;
	thisV = possibleParenting[thisU][offsetForV-1].v;
}






void solveEachTest(lld _TestCase) {
	// cout << "Case#" << _TestCase << ": ";
	lld n; read(n);
	vector<lld> adj[n + 1];

	vector<lld> depth(n + 1, 0ll);
	vector<vector<lld>> parent(n + 1, vector<lld>(level, 0)) ;
	// int parent[MAXN][level] = {0};

	forn(i, n - 1) {
		lld a, b; read(a, b);
		adj[a].pb(b);
		adj[b].pb(a);
	}



	// UDdfs(1, -1, depth, adj);



	// find all the valid parents.  [LCA (a, b) != a] for a->b valid
	vector<lld> children(n+1, 0ll);
	dfs(1ll, 0ll, depth, adj, parent, children);
	// debspace(depth);

	precomputeSparseMatrix(n, parent);

	// println(lca(4, 5, depth, parent));


	// create a list with details of each valid parenting : u, v, depth and sort afterwards;

	// vector<Parenting> hairu;


	// instead of this make  a prefix sum on number of children of each node and then
	// gget the v for each u on demand using a visited tag. 
	// Assumed time complexity: N * Q * log(N); 

	vector<lld> prefixSumChildren(n+1, 0ll);

	for4(i, 2ll, n+1ll, 1) {
		prefixSumChildren[i] += (n - children[i]) + prefixSumChildren[i-1];
	}

	vector<bool> visited(n+1, false);

	map<lld, vector<Parenting> > possibleParenting;

	// for4(i, 2ll, n + 1ll, 1ll) {
	// 	vector<Parenting> temp;
	// 	for4(j, 1ll, (n + 1ll), 1ll) {
	// 		if (i == j) {
	// 			continue;
	// 		}
	// 		if (lca(i, j, depth, parent) != i) {
	// 			Parenting baby;
	// 			baby.u = i;
	// 			baby.v = j;
	// 			baby.h = depth[j] - 1ll;
	// 			temp.pb(baby);
	// 		}
	// 	}

	// 	sort(all(temp), cmp);
	// 	// reserve() is optional - just to improve performance
	// 	hairu.reserve(hairu.size() + distance(temp.begin(), temp.end()));
	// 	hairu.insert(hairu.end(), temp.begin(), temp.end());
	// }

	// sort(all(hairu), cmp);
	// UtilPrintMyBaby(hairu);


	// create pbds to store the indices in order to find c.i in O(log n)

	PBSET indices;

	// debspace(prefixSumChildren);
	forn(i, prefixSumChildren[n]) {
		indices.insert(i + 1);
	}



	// QUERY PART
	lld q; read(q);

	lld d = 0ll;

	lld prev2 = 1, prev3 = 1;
	forn(qq, q) {
		lld e; read(e);
		prev2 *= 2;
		prev2 %= MOD;
		prev3 *= 3;
		prev3 %= MOD;
		lld c = e ^ d;
		auto posu = indices.find_by_order(c - 1);
		lld pos = *(posu);
		indices.erase(posu);
		lld thisU, thisV;

		findPosOfU(thisU, thisV, pos, prefixSumChildren, visited, possibleParenting, n, depth, parent);

		d = (d % MOD) + ((prev2 * thisU) % MOD) + ((prev3 * thisV) % MOD);

		d %= MOD;

		// println(pos);

	}

	println(d);

	// cout << "\n";
	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 

	lld T3X0 = 0, T353 = 1;

	TESTCASES()
	solveEachTest(T353 - T3X0);
	return 0;
}
// Random Thought :  null
// Message : If you get the anime reference in this code, we're friends and we can talk about LIFE.