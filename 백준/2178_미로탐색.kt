import java.util.*;

var n : Int = 0
var m : Int = 0
var dr = arrayOf(-1, 0, 1, 0)
var dc = arrayOf(0, 1, 0, -1)
val check = Array(105){Array(105){ 0 } }
lateinit var graph : Array<Array<Int>>


fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var a : Int = 0

    n = nextInt()
    m = nextInt()

    graph = Array(n+5){Array(m+5){0} }

    for(i: Int in 1 .. n) {
        var line = next();
        for (j: Int in 0 until line.length) {
            graph[i][j+1] = line[j] - '0';
        }
    }
    bfs()

    System.out.println(check[n][m])
}

fun bfs() {
    val q = LinkedList<Pair<Int, Int>>()
    q.add(Pair(1, 1))
    check[1][1] = 1;
    while(!q.isEmpty()) {
        val here: Pair<Int, Int> = q.poll()
        val r = here.first
        val c = here.second
        for(i in 0..3) {
            val nr = r + dr[i];
            val nc = c + dc[i];
            if(nr<1 || nr>n || nc<1 || nc>m) continue
            if(check[nr][nc] == 0 && graph[nr][nc] == 1) {
                check[nr][nc] = check[r][c] + 1
                q.add(Pair(nr, nc))
            }
        }
    }
}