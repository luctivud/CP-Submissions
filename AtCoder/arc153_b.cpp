/*          J  A  I   S  H  R  E  E   R  A  M          */
#ifdef LUCTIVUD
    #include "mydebug.h"
    pprint:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #include "bits/stdc++.h"
    using namespace std;
    #define _____error_____(...)
#endif


// #pragma GCC optimize("O3,unroll-loops,trapv")
// #pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
// #pragma GCC optimize "trapv"



typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = 
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};





const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;




struct Node{
	int cnt,val,prior;
	Node* par;
	Node* l, * r;
	bool is_rev;
	~Node(){
		delete l;
		delete r;
	}
	Node():cnt(1),val(-1),prior(rand()%1000000007),par(0),l(0),r(0),is_rev(0){}
	Node(int val):cnt(1),val(val),prior(rand()%1000000007),par(0),l(0),r(0),is_rev(0){}
};


void prob(Node * root){
	if(root && root->is_rev){
		root->is_rev =0;
		swap(root->l,root->r);
		if(root->l)root->l->is_rev ^=1;
		if(root->r)root->r->is_rev ^= 1;
	}
}
int get_new_cnt(Node * root){
	int ans = 1;
	if(root->l)ans+=root->l->cnt;
	if(root->r)ans+=root->r->cnt;
	return ans;
}

void split(Node* root,int index, Node* &l, Node* &r, Node* lpar=0, Node*rpar=0){
	prob(root);
	if(!root)
		l = r = 0;
	else {
		int cnt;
		if(!root->l)cnt = 0;
		else cnt = root->l->cnt;

		if(cnt < index){
			l = root;
			split(root->r,index-cnt-1,l->r,r,l,rpar);
			l->cnt = get_new_cnt(l);
			l->par = lpar;
		}else {
			r = root;
			split(root->l,index,l,r->l,lpar,r);
			r->cnt = get_new_cnt(r);
			r->par = rpar;
		}
	}
}



void insert(Node * &root, Node * new_node, int index){
	prob(root);
	if(!root){
		root = new_node;
		return;
	}
	if(root->prior <= new_node->prior){
		new_node->par = root->par;
		split(root,index,new_node->l,new_node->r);
		root = new_node;
		if(root->l)root->l->par = root;
		if(root->r)root->r->par = root;
		root->cnt = get_new_cnt(root);
	}else {
		int cnt;
		if(!root->l)cnt = 0;
		else cnt = root->l->cnt;
		new_node->par = root;
		if(index <= cnt){
			insert(root->l,new_node,index);
		}else{
			insert(root->r,new_node,index-cnt-1);
		}
		root->cnt = get_new_cnt(root);
	}
}
void merge(Node * &root, Node *l, Node *r, Node * par=0){
	if(!l || !r){
		if(l)root = l;
		else root = r;
	}else{
		prob(l);
		prob(r);
		if(l->prior > r->prior){
			root = l;
			merge(root->r,l->r,r,root);
		}else{
			root = r;
			merge(root->l,l,r->l,root);
		}
	}
	if(root)root->par = par;
	if(root)root->cnt = get_new_cnt(root);
	prob(root);
}


void reverse_segment(Node * &root, int l,int r){
	Node *part1, *part2, *rem,*tmp;
	split(root,l,part1,rem);
	root = rem;
	rem = 0;
	split(root,r-l+1,part2,rem);
	part2->is_rev ^= 1;
	merge(root,part1,part2);
	tmp = root;
	root = 0;
	merge(root,tmp,rem);
}



int get_by_index(Node*root, int index){
	prob(root);
	if(!root)return -1;
	int cnt;
	if(!root->l)cnt=0;
	else cnt = root->l->cnt;
	if(cnt == index)return root->val;
	if(cnt < index){
		return get_by_index(root->r,index-cnt-1);
	}
	return get_by_index(root->l,index);
}


/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/


void reverseoo(lld st, lld ed, Node * arr) {
    // reverse(arr.begin()+st, arr.begin()+ed);
    reverse_segment(arr, st, ed);
}

void doOp(lld x, Node* arr, lld sz) {
    // assert((lld)arr.size() == sz);
    //0 to x
    reverseoo(0, x-1, arr);
    //x to sz
    reverseoo(x, sz-1, arr);
}




void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, m; cin >> n >> m;
    vector<string> matr(n);
    forn(i, n) {
        cin >> matr[i];
    }

    // vector<lld>rows(n);
    // vector<lld>cols(m);
    // iota(all(rows), 0ll);
    // iota(all(cols), 0ll);

    // _____error_____(rows, cols);

    Node* rows = new Node(0);
    forn(i, n-1) {
        insert(rows, new Node(i+1), i+1);
    }

    Node* cols = new Node(0);
    forn(i, m-1) {
        insert(cols, new Node(i+1), i+1);
    }

    // forn(i, n) {
    //     cout << get_by_index(tree, i) << " ";
    // }

    lld q; cin >> q;
    forn(qq, q) {
        lld a, b; cin >> a >> b;
        doOp(a, rows, n);
        doOp(b, cols, m);
    }

    forn(i, n) {
        forn(j, m) {
            lld x = get_by_index(rows, i);
            lld y = get_by_index(cols, j);
			// _____error_____(x, y);
            cout << matr[x][y];
        }
        cout << "\n";
    }
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    cin.tie(0)->sync_with_stdio(0);
    cout.precision(10); cout << fixed;

    srand(time(0));

    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/Users/luctivud/CPPrc/Zinput.txt", "r", stdin);
        freopen("/Users/luctivud/CPPrc/Zoutput.txt", "w", stdout);
    #endif


    int __NTestCases = 1;

    #ifdef LUCTIVUD
    cin >> __NTestCases; 
    #endif 

    for (int _TestCase = 1; _TestCase <= __NTestCases; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n";
    }


    #ifdef LUCTIVUD
        // auto end_time = std::chrono::high_resolution_clock::now();
        // std::chrono::duration<double> diff = end_time - start_time;
        // cerr << "Finished in : " << diff.count() << "\n";
    #endif


    return 0; 
}




/*  ~~
    .?.?.?.
*/
