import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

data class Node(val x: Int, val y: Int)

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer(br.readLine())

    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()

    val map = Array(n) { br.readLine().toCharArray().map { it - '0' }.toIntArray() }
    val visited = Array(n) { IntArray(m) }

    val dx = intArrayOf(0, 1, 0, -1)  // 좌우상하
    val dy = intArrayOf(-1, 0, 1, 0)

    val queue: Queue<Node> = LinkedList()
    queue.add(Node(0, 0))
    visited[0][0] = 1

    while (queue.isNotEmpty()) {
        val (x, y) = queue.poll()
        for (i in 0 ..< 4) {
            val nx = x + dx[i]
            val ny = y + dy[i]

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue
            if (visited[nx][ny] == 0 && map[nx][ny] == 1) {
                visited[nx][ny] = visited[x][y] + 1
                queue.add(Node(nx, ny))
            }
        }
    }

    println(visited[n-1][m-1])
}