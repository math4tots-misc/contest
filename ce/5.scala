// DETECTING CYCLES
// CHALLENGE DESCRIPTION:
// Given a sequence, write a program to detect cycles within it.

object Main {

  def solve_one(line: String) {
    val numbers = line.split(" ").map(_.toInt)
    var map = scala.collection.mutable.Map[Integer, Integer]()
    for ((value, key) <- numbers.drop(1).zip(numbers)) {
      if (map.getOrElse(key, -1).equals(value)) {
        var x : Integer = key
        print(x)
        x = map.getOrElse(x, -1)
        while (!x.equals(key)) {
          print(" ")
          print(x)
          x = map.getOrElse(x, -1)
        }
        println()
        return
      }
      map.put(key, value)
    }
  }

  def main(args: Array[String]) {
    for (line <- scala.io.Source.fromFile(args(0)).getLines.filter(_.length > 0)) {
      solve_one(line)
    }
  }
}
