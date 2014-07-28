import collection.immutable.TreeMap

object Solution {

  def main(args: Array[String]): Unit = {
    val N = scala.io.StdIn.readLine.toInt
    val a = scala.io.StdIn.readLine.split(" ").map(_.toInt).toVector
    var t = new TreeMap[Int,Int]
    val left = a.zipWithIndex.map((pair) => {
      val (v,i) = pair
      val leftmost = if (t.from(v).isEmpty) i else t.from(v).head._2
      t = (new TreeMap[Int,Int] + (v->i)) ++ t.to(v)
      leftmost
    })
    t = new TreeMap[Int,Int]
    val right = a.zipWithIndex.reverse.map((pair) => {
      val (v,i) = pair
      val rightmost = if (t.from(v).isEmpty) i else t.from(v).head._2
      t = (new TreeMap[Int,Int] + (v->i)) ++ t.to(v)
      rightmost
    }).reverse
    val answer = a.zipWithIndex.map((pair) => {
      val (v,i) = pair
      v * (right(i) - left(i) + 1)
    }).max
    println(answer)
  }
}