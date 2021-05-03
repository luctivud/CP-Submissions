// ************************.- J A I  S H R E E  R A M -.*************************


/* 
      ::: All is One ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

          Author   :  Udit "luctivud" Gupta 

          linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
          github   :  https://github.com/luctivud

      :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: One is All :::
*/


#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
#pragma GCC optimize ("Ofast")
// #pragma GCC target ("fpmath=sse,sse2")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")


using namespace std;



typedef long long int lld;
typedef unsigned long long int llu;
// #define int lld

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define          input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        EACH(I7, A7)    for (auto& I7: A7)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  pb    push_back
#define         debhairu(x)    cout << #x << " = "; println(x);
#define         debspace(x)    cout << #x << " = "; print(x); cout << " ";
#define                  f1    first
#define                  s2    second
#define           PLEASE_AC    return



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


const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};



const auto start_time = std::chrono::high_resolution_clock::now();

signed light() {

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    return 0; 
}


signed luctivud() {

    #ifdef LUCTIVUD
      auto end_time = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> diff = end_time - start_time;
      cerr << "Finished in : " << diff.count() << "\n";
    #endif

  return 0; 
}



const lld MOD = lld(1e9) + 7ll;
const lld mod = MOD;


const long double EPS = 1e-6;

const lld INFll = inf<lld>();
const int INFi = inf<int>();


void add_undirected_edge(lld a, lld b, vector<lld> adj[]) {
    adj[a].pb(b);
    adj[b].pb(a);
    return;
}



/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/






void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, l, r;
    read(n, l, r);

    vector<lld> left, right;

    forn(i, l) {
    	left.pb(read(_TestCase));
    }

    forn(i, r) {
    	right.pb(read(_TestCase));
    }


    sort(all(left));
    sort(all(right));


    lld i = 0ll, j = 0ll;

    vector<lld> left_rem, right_rem;

    while (i < l and j < r) {
    	if (left[i] == right[j]) {
    		i++; j++;
    	} else if (left[i] < right[j]) {
    		left_rem.pb(left[i]);
    		i++;
    	} else {
    		right_rem.pb(right[j]);
    		j++;
    	}
    }	

    while (i < l) {
    	left_rem.pb(left[i++]);
    }

    while (j < r) {
    	right_rem.pb(right[j++]);
    }

    l = len(left_rem);
    r = len(right_rem);

    lld ans = 0ll;

    // debhairu(left_rem);
    // debhairu(right_rem);
    vector<lld> lefty, righty, left_same, right_same;

  	i = 1ll;	
    lld prev = l > 0 ? left_rem[0] : -1;
    lld cnt = l > 0 ? 1 : 0;
    while (i < l) {
    	// error(i);
    	if (prev == left_rem[i]) {
    		cnt++;
    	} else {
    		if (cnt & 1) {
    			lefty.pb(prev);
    		}
    		forn(xx, (cnt/2)* 2) {
    			left_same.pb(prev);
    		}
    		prev = left_rem[i];
    		cnt = 1;
    	}
		i++;
    }

    if (cnt & 1) {
    	lefty.pb(prev);
    }
    forn(xx, (cnt/2)* 2) {
		left_same.pb(prev);
	}



    i = 1ll;
    prev = r > 0 ? right_rem[0] : -1;
    cnt = r > 0 ? 1 : 0;
    
    while (i < r) {
    	if (prev == right_rem[i]) {
    		cnt++;
    	} else {
    		if (cnt & 1) {
    			righty.pb(prev);
    		}
    		forn(xx, (cnt/2)*2ll) {
    			right_same.pb(prev);
    		}
    		prev = right_rem[i];
    		cnt = 1;
    	}
		i++;
    }

    if (cnt & 1) {
    	righty.pb(prev);
    }
    forn(xx, (cnt/2)*2ll) {
		right_same.pb(prev);
	}

    for (auto val: left_same) {
    	lefty.pb(val);
    }

    for (auto val : right_same) {
    	righty.pb(val);
    }

    // debhairu(left_same);
    // debhairu(right_same);
    // debhairu(lefty);
    // debhairu(righty);

    l = len(lefty);
    r = len(righty);
    lld mn = min(l, r);
    ans += mn;

    if (l - mn > 0) {
    	i = mn+1;
		prev = l-mn > 0 ? lefty[mn] : -1;
		cnt = l-mn > 0 ? 1 : 0;
    	lld res = 0ll;
    	while (i < l) {
	    	if (prev == lefty[i]) {
	    		cnt++;
	    	} else {
	    		if (cnt & 1) {
	    			res++;
	    		}
	    		ans += cnt / 2;
	    		prev = lefty[i];
	    		cnt = 1;
	    	}
			i++;
	    }

	    if (cnt & 1) {
	    	res++;
	    }
	    ans += cnt / 2;
	    ans += res;
    } else if (r - mn > 0) {
    	i = mn+1;
		prev = r-mn > 0 ? righty[mn] : -1;
		cnt = r-mn > 0 ? 1 : 0;
    	lld res = 0ll;
    	while (i < r) {
    		// error(i, cnt, prev);
	    	if (prev == righty[i]) {
	    		cnt++;
	    	} else {
	    		if (cnt & 1) {
	    			res++;
	    		}
	    		ans += cnt / 2;
	    		prev = righty[i];
	    		cnt = 1;
	    	}
			i++;
	    }

	    // error(cnt, ans);

	    if (cnt & 1) {
	    	res++;
	    }
	    ans += cnt / 2;
	    ans += res;
    }

    println(ans);


    // cout << "\n"; 
    return;
}


signed main() {
    light(); int T3X0 = 0, T353 = 1;
    TESTCASES() 
        solveEachTest(T353 - T3X0);
    PLEASE_AC luctivud(); 
}

/*        0.2s   Domain Expansion:  
                              MALEVOLENT SHRINE     */

  //   i = 1ll;
  //   lld prev = l >= 0 ? left_rem[0] : -1;
  //   lld cnt = l >= 0 ? 1 : 0;
  //   while (i < l) {
  //   	if (prev == left_rem[i]) {
  //   		cnt++;
  //   	} else {
  //   		if (cnt & 1) {
  //   			lefty.pb(prev);
  //   		}
  //   		ans += cnt / 2;
  //   		prev = left_rem[i];
  //   		cnt = 1;
  //   	}
		// i++;
  //   }

  //   if (cnt & 1) {
  //   	lefty.pb(prev);
  //   }
  //   ans += cnt / 2;



  //   i = 1ll;
  //   prev = r >= 0 ? left_rem[0] : -1;
  //   cnt = r >= 0 ? 1 : 0;
    
  //   while (i < r) {
  //   	if (prev == right_rem[i]) {
  //   		cnt++;
  //   	} else {
  //   		if (cnt & 1) {
  //   			righty.pb(prev);
  //   		}
  //   		ans += cnt / 2;
  //   		prev = right_rem[i];
  //   		cnt = 1;
  //   	}
		// i++;
  //   }

  //   if (cnt & 1) {
  //   	righty.pb(prev);
  //   }
  //   ans += cnt / 2;