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

fun solveEachTest(_TestCase : Int) {
    var n : Int = readInt()
    var arr = readInts()
    var netSum: Long = 0
    for (i : Int in 0..(n-1)) {
        netSum += arr[i]
    }

    //println(netSum)
    // arr.sort()
    if (netSum % n != 0L) {
        println("-1")
        return
    }

    netSum /= n
    var ans : Int = 0;
    for (i : Int in 0..(n-1)) {
        if (netSum < arr[i]) {
            // println("k")
            ans += 1;
        }
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


