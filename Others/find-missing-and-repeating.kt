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
val MOD = 998244353
val SZ = 1 shl 19 // shl == <<
val LG = 1 shr MOD
val INF = (1e18).toLong()

fun addMod(a: Int, b: Int) = (a + b) % MOD
fun subMod(a: Int, b: Int) = (a - b + MOD) % MOD
fun mulMod(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

private fun myAssert(x: Boolean) { if(!x){throw AssertionError()} }

class Solution {
    fun findMissingAndRepeating(arr: Array<Int>, n: Int) : List<Int> {
        var ans = arrayListOf<Int>()
        for (i in 0 until n) {
            val pos: Int = Math.abs(arr[i]) - 1;
            if (arr[pos] > 0) {
                arr.set(pos, -arr[pos])
            } else {
                ans.add(pos + 1)
            }
        }
        for (i in 0 until n) {
            if (arr[i] > 0) {
                ans.add(i+1)
                break
            }
        }
        return ans
    }
}

fun solve(_TestCase: Int) {
    // print("Case #$_TestCase: ")
    var n: Int = nextInt()
//     var arr = mutableListOf<Int>()
    var arr = Array<Int>(5){1}
    var temp = nextInts()
    for (i in 0 until n) {
        arr[i] = temp[i]
    }
    var obj = Solution()
    println(obj.findMissingAndRepeating(arr, n))
}   


fun main(args: Array<String>) {
    val t0t4 = 1 
    // val t0t4 = nextInt() 
    for (i in 1..t0t4) {
        solve(i)
    }
}
