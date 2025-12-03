import java.io.File

fun main() {
    val data = readDataFromFile("input")
    var sum = 0L

    println("Successfully parsed ${data.size} pairs:")
    data.forEachIndexed { index, pair ->
        println("Pair ${index + 1}: (${pair.first}, ${pair.second})")

        for (i in pair.first..pair.second) {
            sum += invalidIdV2(i)
        }
    }

    println("Result = ${sum}")
}

// Return 0 if valid
// return id if invalid
fun invalidId(id: Long): Long {
    return if (id.toString().isDigitCountEven() && id.toString().isRepeat()) {
        id
    } else {
        0L
    }
}

// Return 0 if valid
// return id if invalid
fun invalidIdV2(id: Long): Long {
    return if (id.toString().isRepeatV2()) {
        id
    } else {
        0L
    }
}

fun String.isDigitCountEven() = (this.length % 2 == 0)

fun String.isRepeat(): Boolean {
    if (this.length % 2 != 0) return false

    val mid = this.length / 2
    val firstHalf = this.substring(0, mid)
    val secondHalf = this.substring(mid)

    return firstHalf == secondHalf
}

// Split string by index from 1 to String length / 2 and store output to list
// if all element in list is the same return true else false
fun String.isRepeatV2(): Boolean {
    if (this.isEmpty()) return false

    val results = mutableListOf<Boolean>()

    for (splitIndex in 1..this.length / 2) {
        if (this.length % splitIndex != 0) continue

        val chunkSize = splitIndex
        val chunks = this.chunked(chunkSize)

        results.add(chunks.all { it == chunks.first() })
    }

    return results.any { it }
}

fun readDataFromFile(filename: String): List<Pair<Long, Long>> {
    val content = File(filename).readText().trim()

    return content.split(",").map { pairString ->
        val (first, second) = pairString.split("-").map { it.toLong() }
        Pair(first, second)
    }
}
