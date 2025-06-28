import java.io.*
import java.util.*

private fun dfs(n: Int, graph: Array<IntArray>, visited: BooleanArray) {
    visited[n] = true
    print("$n ")

    for (i in 1..< graph[n].size) {
        if (!visited[i] && graph[n][i] == 1) {
            dfs(i, graph, visited)
        }
    }
}

private fun bfs(start: Int, graph: Array<IntArray>, visited: BooleanArray) {
    val queue: Queue<Int> = LinkedList()
    queue.add(start)
    visited[start] = true

    while (queue.isNotEmpty()) {
        val n = queue.poll()
        print("$n ")

        for (i in 1..< graph[n].size) {
            if (!visited[i] && graph[n][i] == 1) {
                visited[i] = true
                queue.add(i)
            }
        }
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer(br.readLine())

    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    val v = st.nextToken().toInt()

    val graph = Array(n + 1) { IntArray(n + 1) }
    val visited = BooleanArray(n + 1)

    repeat(m) {
        st = StringTokenizer(br.readLine())
        val a = st.nextToken().toInt()
        val b = st.nextToken().toInt()
        graph[a][b] = 1
        graph[b][a] = 1
    }

    dfs(v, graph, visited)
    println()
    visited.fill(false)
    bfs(v, graph, visited)
}