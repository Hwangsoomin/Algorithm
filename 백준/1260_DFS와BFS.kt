import java.util.*;

var n : Int = 0
var m : Int = 0
var v : Int = 0
val graph = Array(1005) { mutableListOf<Int>() }
val check = Array(1005) { false }
val answer = mutableListOf<Int>()

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var a : Int
    var b : Int

    n = nextInt()
    m = nextInt()
    v = nextInt()

    for(i: Int in 1..m) { // 그래프 생성
        a = nextInt()
        b = nextInt()

        graph[a].add(b)
        graph[b].add(a)
        graph[a].sort()
        graph[b].sort()
    }

    dfs(v);
    for(i: Int in 0 until answer.size) {
        System.out.print(answer[i])
        System.out.print(" ")
    }
    System.out.println()
    answer.clear()
    for(i in 0 until check.size) {
        check[i] = false
    }
    bfs()
    for(i: Int in 0 until answer.size) {
        System.out.print(answer[i])
        System.out.print(" ")
    }
}

fun dfs(here : Int) {
    answer.add(here)
    check[here] = true
    for(i : Int in 0 until  graph[here].size) {
        val next : Int = graph[here][i]
        if(!check[next]) {
            check[next] = true
            dfs(next)
        }
    }
}

fun bfs() {
    val queue: Queue<Int> = LinkedList<Int>()
    queue.add(v)
    while(!queue.isEmpty()) {
        val here = queue.poll()
        answer.add(here)
        check[here] = true
        for(i in 0 until graph[here].size) {
            val next = graph[here][i]
            if(!check[next]) {
                check[next] = true
                queue.add(next)
            }
        }
    }
}