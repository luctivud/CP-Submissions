/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/

import java.lang.AssertionError
import kotlin.math.max
import kotlin.math.min
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun upp(arr: List<Int>, L: Int, R: Int, valu: Int) : Int {
    // return 0
    var l = L
    var r = R
    var value = valu
    var res: Int = r+1
    while (l <= r) {
        var mid : Int = (l + r) / 2;
        if (arr[mid] > value) {
            r = mid - 1
            res = mid
        } else {
            l = mid + 1
        }
    }

    return res
}

fun loo(arr: List<Int>, L: Int, R: Int, valu: Int) : Int {
    // return 0
    var l = L
    var r = R
    var value = valu
    var res: Int = r+1
    while (l <= r) {
        var mid : Int = (l + r) / 2;
        if (arr[mid] >= value) {
            r = mid - 1
            res = mid
        } else {
            l = mid + 1
        }
    }
    return res
}

fun solveEachTest(_TestCase : Int) {
    var (n, l, r) = readInts()
    var arr = readLine()!!.split(' ').map(String::toInt).sorted()
    var ans: Long = 0
    for (i in 0..(n-1)) {
        if (arr[i] > l) {
            break
        }
        var UU: Int = upp(arr, i+1, n-1, r-arr[i])
        var LL: Int = loo(arr, i+1, n-1, l-arr[i])
        // print(r-arr[i])
        // print(" ")
        // print(UU)
        // print(" ")
        // print(l-arr[i])
        // print(" ")
        // println(LL)
        ans += max(UU - LL, 0)
    }
    println(ans)
}

 
fun main(args: Array<String>) {
    var TT : Int = 1
    TT = readInt() 
    for (_TestCase : Int in 1..TT) {
        solveEachTest(_TestCase)
    }
}


