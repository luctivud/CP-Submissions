// /*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
// /*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
// /*::::::::::::::::::::::::::::::::::::::::::::::::::::*/

import java.lang.AssertionError
import java.util.*
import kotlin.collections.*
import kotlin.math.*

typealias PII = Pair<Int, Int>
typealias PLL = Pair<Long, Long>
typealias PPII = Pair<Int, PII>
typealias APII = ArrayList<PII>
typealias APLL = ArrayList<PLL>
typealias AAPII = ArrayList<ArrayList<PII>>
typealias AAPLL = ArrayList<ArrayList<PLL>>

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextStrings() = next().split(" ")
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

val MX = 1000005
val MOD = 9998244353
val SZ = 1 shl 19 // shl == <<
val LG = 1 shr MOD
val INF = (1e9).toInt()

fun addMod(a: Int, b: Int) = (a + b) % MOD
fun subMod(a: Int, b: Int) = (a - b + MOD) % MOD
fun mulMod(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

private fun myAssert(x: Boolean) { if(!x){throw AssertionError()} }

fun solve() {
    // print("Case #$_TestCase: ")
    var n: Int = nextInt()
    var arr = arrayListOf<Long>()
    arr.addAll(nextLongs())
    var cntElem = HashMap<Long, Long>()
    var sumOfElem = 0L;
    for (i in 0 until n) {
        sumOfElem += arr[i];
        if (cntElem.containsKey(arr[i])) {
            cntElem[arr[i]] = cntElem[arr[i]]!! + 1;
        } else {
            cntElem.put(arr[i], 1)
        }
    }
    var ans = arrayListOf<Long>()
    for (i in 0 until n) {
        
        ans.add(i+1)
    }
    println(cntElem)

}


fun main() {
    val t0t4 = 1 
    // val t0t4 = nextInt() 
    for (i in 1..t0t4) {
        solve()
    }
}





// // Documentation of Template 

// var (n, b, c) = nextInts()
// var arr = nextInts().sorted()
// var sz = arr.count
// println("$n = $sz")

// arrayList.add(PPII(1, PII(1, 2)))
// val type1 = Array(n) { IntArray(n) }
// val type2 = Array(n, { IntArray(m) })
// val type3 = arrayOf(
//     intArrayOf(8, 9, 1, 13),
//     intArrayOf(3, 12, 7, 5),
//     intArrayOf(0, 2, 4, 11),
//     intArrayOf(6, 10, 15, 14)
// )
// class CustomComparator : Comparator<Pair<Int, Pair<Int, Int>>> {
//     override fun compare(o1: Pair<Int, Pair<Int, Int>>, o2: Pair<Int, Pair<Int, Int>>): Int {
//         return o1.first.compareTo(o2.first)
//     }
// }

// val arrayList = ArrayList<Pair<Int, Pair<Int, Int>>>()
// val sorted = arrayList.sortedWith(CustomComparator())
// val sorted2 = arrayList.sortedWith(compareBy({ -it.second }, { it.first }))
// HashMap
// val hashMap = HashMap<String, Int>()
// for (i in 0..n - 2) {
//     val w = s.substring(i, i + 2)
//     val c = hashMap.getOrElse(w) { 0 }
//     hashMap.put(w, c + 1)
// }
// if else
// val max = if (a > b) a else b
// Imports
// import kotlin.arrayOf as Arr
// import kotlin.intArrayOf as Iarr
// Printing
// println(" and ")
// Ranges
// // [ or ] => Inclusive | ( or ) => Exclusive
// for (i in 1..n) print(i) // [1, n]
// for (i in 1 until n) print(i) // [1, n)
// for (i in n  downTo 1) print(i) // [n, 1]
// for (i in 1..n step 2) print(i) // 1, 3, 5 , 7, 9 ...
// for (i in 8 downTo 1 step 2) print(i) // 8, 6, 4, 2
// Sorting
// val b = nextLongs().sorted() // a is mutable list
// val a = arrayListOf<Long>()
// a.addAll(nextLongs())
// a.sort()
// Swap Int
// var a = 10
// var b = 30
// a = b.also { b = a }
// Type Alias
// typealias PII = Pair<Int, Int>
// typealias PPII = Pair<Int, PII>  
