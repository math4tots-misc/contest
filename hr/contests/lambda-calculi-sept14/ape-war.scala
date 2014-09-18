// .... There are some strange
// performance issues ...
// A Binary search is throwing solution over limit
// on the larger cases ...

import scala.collection.immutable.TreeSet

object Solution {
def main(args : Array[String]) : Unit = {

val Array(n,m) = scala.io.StdIn.readLine.split("\\s+").map(_.toInt)
val parents = Array(0) ++ scala.io.StdIn.
    readLine.
    split("\\s+").
    map(_.toInt - 1)

class Node(val id : Int) {
    var p : Node = null           // parent
    var a : Vector[Node] = null   // ancestors (including this)
    var l : Int = -1              // level
    var s : TreeSet[Int] = null   // ids in ancestor (excluding this)
    
    def ca : Vector[Node] = {
        if (a == null)
            if (id == 0) a = Vector(this)
            else         a = p.ca :+ this
        a
    }
    
    def cl : Int = {
        if (l == -1)
            if (id == 0) l = 0
            else         l = p.l + 1
        l
    }
    
    def cs : TreeSet[Int] = {
        if (s == null)
            if (id == 0) s = TreeSet[Int]()
            else         s = p.cs + p.id
        s
    }
    
    def cc : Unit = { ca; cl; cs }
    
    override def toString : String = id.toString
    
    // find lowest common ancestor
    def c(n : Node) : Node = {
        var x = 0
        var y = Math.min(a.length, n.a.length)
        
        while (x + 1 < y) {
            val z = (x+y) / 2
            if (a(z) == n.a(z)) x = z
            else                y = z
        }
        
        a(x)
    }
    
    // find number of elements from this to n
    // with id's within the range [l, r]
    def solve(n : Node, l : Int, r : Int) : Int = {
        val m = c(n)
        
        // Let's see what performance is if we leave these out.
        val s1 = (s + id).range(l, r+1)
        val s2 = (n.s + n.id).range(l, r+1)
        val s3 = m.s.range(l, r+1)
        
        s1.size + s2.size - 2 * s3.size - (if (s1.contains(m.id)) 1 else 0)
    }
}

val nodes = (for (i <- 0 until n) yield new Node(i))
for (i <- 0 until n) nodes(i).p = nodes(parents(i))
for (node <- nodes) { node.cc }

for (i <- 0 until m) {
    val Array(x,y,l,r) = scala.io.StdIn.
        readLine.
        split("\\s+").
        map(_.toInt - 1)
    
    println(nodes(x).solve(nodes(y), l, r))
}

}}
