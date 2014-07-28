import collection.immutable.TreeMap

object Solution {

  def main(args: Array[String]): Unit = {
    val N = scala.io.StdIn.readLine.toInt
    val a = scala.io.StdIn.readLine.split(" ").map(_.toInt).toVector
    
    var t = TreeMap[Int,Int]()
    
    val left = a.zipWithIndex.map((pair) => {
      var (x,i) = pair
      while (i >= 0 && x <= a(i)) { i -= 1 }
      i += 1
      i
    })
    
    val right = a.zipWithIndex.reverse.map((pair) => {
      var (x,i) = pair
      while (i < a.size && x <= a(i)) { i += 1 }
      i -= 1
      i
    }).reverse
    
    val areas = a.zipWithIndex.map((pair) => {
      var (x,i) = pair
      x * (right(i) - left(i) + 1)
    })
    println(areas.max)
  }
}