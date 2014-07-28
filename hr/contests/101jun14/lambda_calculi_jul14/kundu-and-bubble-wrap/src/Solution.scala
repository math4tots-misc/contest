object Solution {
  def main(args: Array[String]): Unit = {
    val N = scala.io.StdIn.readLine.split(" ").map(_.toInt).product
    println((1 to N).map((i) => (N.toDouble/i.toDouble)).sum)
  }
}