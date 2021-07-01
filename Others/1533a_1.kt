import kotlin.math.*
import java.util.*
import kotlin.collections.*
fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextStrings() = next().split(" ")
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

fun main() {
    var T: Int = nextInt()
    for (tt in 0 until T) {
        var (n, k) = nextLongs()
        var ans: Long = 0L;
        for (i in 0 until n) {
            var (l, r) = nextLongs()
            if (k >= l) {
                ans = maxOf(ans, 1+r-maxOf(l, k))
            }
        }
        println(ans)
    }
}