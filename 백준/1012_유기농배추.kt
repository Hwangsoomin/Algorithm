import java.util.*;

var n: Int = 0
var m: Int = 0
var k: Int = 0
var graph: Array<Array<Int>> = Array(55){Array(55){ 0 } }
var check: Array<Array<Boolean>> = Array(55){ Array(55){ false } }
var dr = arrayOf(-1, 0, 1, 0)
var dc = arrayOf(0, 1, 0, -1)

fun bfs(x: Int, y: Int) {
    var q: Queue<Pair<Int, Int>> = LinkedList<Pair<Int, Int>>()
    q.add(Pair(x, y))
    while(!q.isEmpty()) {
        var here: Pair<Int, Int> = q.poll()
        var r: Int = here.first
        var c: Int = here.second
        check[r][c] = true
        for(i: Int in 0 until 4) {
            var nr: Int = r + dr[i]
            var nc: Int = c + dc[i]
            if(nr<0 || nr>=m || nc<0 || nc>=n) continue
            if(!check[nr][nc] && graph[nr][nc] == 1) {
                check[nr][nc] = true
                q.add(Pair(nr, nc))
            }
        }
    }
}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var t: Int = 0
    var a: Int = 0
    var b: Int = 0
    var answer: Int = 0

    t = nextInt()

    while(t > 0) {
        t -= 1

        m = nextInt()
        n = nextInt()
        k = nextInt()

        graph = Array(55){Array(55){ 0 } }
        check = Array(55){Array(55){ false } }
        answer = 0

        for (i: Int in 1..k) {
            a = nextInt()
            b = nextInt()
            graph[a][b] = 1
        }

        for (i: Int in 0 until m) {
            for (j: Int in 0 until n) {
                if (!check[i][j] && graph[i][j] == 1) {
                    answer += 1
                    bfs(i, j)
                }
            }
        }

        println(answer)
    }
}