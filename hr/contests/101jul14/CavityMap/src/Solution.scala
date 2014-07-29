object Solution {
  def main(args: Array[String]): Unit = {
    val n = io.StdIn.readLine.toInt;
    val map = (0 until n).map(i => io.StdIn.readLine.map(_.toString.toInt));
    val marked_map = (0 until n).map(row => (0 until n).map(col =>
      if (row == 0 || row == n-1 || col == 0 || col == n-1 ||
          Array((-1,0),(0,-1),(0,1),(1,0)).exists(
              {case (dr,dc) => map(row+dr)(col+dc) >= map(row)(col)} ))
        map(row)(col).toString else "X"));
    println(marked_map.map(_.mkString("")).mkString("\n"))
  }

}
