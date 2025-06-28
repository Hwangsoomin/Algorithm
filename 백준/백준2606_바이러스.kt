import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

var n: Int = 0; var m: Int = 0; var answer: Int = -1

private fun dfs(here: Int, graph: Array<IntArray>, visited: BooleanArray) {
    visited[here] = true
    answer += 1

    for (i in 1 ..n ) {
        if (!visited[i] && graph[here][i] == 1) {
            dfs(i, graph, visited)
        }
    }

}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    n = br.readLine().toInt()
    m = br.readLine().toInt()

    val graph = Array(n + 1) { IntArray(n + 1) }
    val visited = BooleanArray(n + 1)

    repeat(m) {
        val st = StringTokenizer(br.readLine())
        val a = st.nextToken().toInt()
        val b = st.nextToken().toInt()
        graph[a][b] = 1
        graph[b][a] = 1
    }

    dfs(1, graph, visited)
    println(answer)

}