// ************************.- J A I  S H R E E  R A M -.*************************


/* 
      ::: ---------- ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

          Author   :  Udit "luctivud" Gupta 

          linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
          github   :  https://github.com/luctivud

      :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ---------- :::
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


#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second



#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); huehue(_it, args); cout << "\n";}

void huehue(istream_iterator<string> it) {}
template<typename T, typename... Args>
void huehue(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << ", ";
    huehue(++it, args...);
}

const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


const lld MOD = lld(1e9) + 7ll;
const lld mod = MOD;

lld TempVar;

const long double EPS = 1e-6;

/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/
void printTreeEdges(int prufer[], int m)
{
	int vertices = m + 2;
	int vertex_set[vertices];

	// Initialize the array of vertices
	for (int i = 0; i < vertices; i++)
		vertex_set[i] = 0;

	// Number of occurrences of vertex in code
	for (int i = 0; i < vertices - 2; i++)
		vertex_set[prufer[i] - 1] += 1;

	// cout << m << "\n";

	int j = 0;

	// Find the smallest label not present in
	// prufer[].
	for (int i = 0; i < vertices - 2; i++)
	{
		for (j = 0; j < vertices; j++)
		{

			// If j+1 is not present in prufer set
			if (vertex_set[j] == 0)
			{

				// Remove from Prufer set and print
				// pair.
				vertex_set[j] = -1;
				cout << (j + 1) << " " << prufer[i] << "\n";

				vertex_set[prufer[i] - 1]--;

				break;
			}
		}
	}

	j = 0;

	// For the last element
	for (int i = 0; i < vertices; i++)
	{
		if (vertex_set[i] == 0 && j == 0)
		{

			cout << (i + 1) << " ";
			j++;
		}
		else if (vertex_set[i] == 0 && j == 1)
			cout << (i + 1) << "\n";
	}
}

// generate random numbers in between l an r
int ran(int l, int r)
{
	return l + (rand() % (r - l + 1));
}

// Function to Generate Random Tree
void generateRandomTree(int n)
{

	int length = n - 2;
	int arr[length];

	// Loop to Generate Random Array
	for (int i = 0; i < length; i++)
	{
		arr[i] = ran(0, length + 1) + 1;
	}
	printTreeEdges(arr, length);
}

// Driver Code

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zinput.txt", "w", stdout);
    #endif


    srand((unsigned)time(0));
	int n = 17;
	// cout << "1\n";
	cout << n << "\n";
	generateRandomTree(n);


    #ifdef LUCTIVUD
      // auto end_time = std::chrono::high_resolution_clock::now();
      // std::chrono::duration<double> diff = end_time - start_time;
      // cerr << "Finished in : " << diff.count() << "\n";
    #endif

    return 0; 
}

/*        0.2s   Ryoki Tenkai:  
                                  Jihei Endonka     */
