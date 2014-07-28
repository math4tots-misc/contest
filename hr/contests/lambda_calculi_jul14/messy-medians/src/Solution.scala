import collection.immutable.TreeSet

object Solution {
  def main(args: Array[String]): Unit = {
    val T = scala.io.StdIn.readLine.toInt
    val a = (1 to T).map((i) => scala.io.StdIn.readLine.toInt)
    val m = Array.ofDim[Int](T) // medians
    val s = Array.ofDim[TreeSet[(Int,Int)]](T) // (multi)sets used to calculate medians
    val h = Array.ofDim[(Int,Int)](T) // keys used
    
    m(0) = a(0)
    s(0) = TreeSet[(Int,Int)]((a(0),0))
    
    for (i <- 1 until T) {
      if (a(i) < 0) {         // go back in time!
        m(i) = m(i+a(i))
        s(i) = s(i+a(i))
      } else {
        s(i) = s(i-1).insert((a(i),i)) // insert the new element into the new set
        m(i) = s(i).slice((s(i).size-1)/2, (s(i).size-1)/2 + 1).head._1
      }
    }
    
    for (median <- m) {
      println(median)
    }
  }
}