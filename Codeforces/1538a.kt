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
    // println(n)
    var arr = IntArray(n) {getNextInt()}
    var zeke = ArrayList<Int>()
    for (i : Int in 0..(n-1)) {
        if (arr[i] == 1 || arr[i] == n) {
            zeke.add(i)
        }
    }
    zeke.sort()
    var a: Int = zeke[0]+1;
    var b: Int = zeke[1]+1
    // println(zeke.size)
    println(min(min(b, n-a+1), a + n - b + 1))
}

 
fun main(args: Array<String>) {
    // var TT : Int = 1
    var TT = readInt() 
    for (_TestCase : Int in 1..TT) {
        solveEachTest(_TestCase)
    }
}


