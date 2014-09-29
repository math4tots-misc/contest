object Solution {
    val memo = new scala.collection.mutable.HashMap[(Int,Int,Int), Int]()
    var digits : Vector[Int] = null
    
    def cost(left : Int, right : Int, level : Int) : Int = {
        val key = (left, right, level)
        if (!memo.contains(key)) {
            if (level == digits.length) {
                memo.put(key, 0)
            }
            else {
                val digit = digits(level)
                memo.put(key, 1 + scala.math.min(
                    (left  - digit).abs + cost(digit, right, level+1),
                    (right - digit).abs + cost(left,  digit, level+1)))
            }
        }
        
        return memo.getOrElse(key, 0)
    }
    
    def main(args : Array[String]) : Unit = {
        scala.io.StdIn.readLine
        digits = scala.io.StdIn.readLine.
            split("\\s+").
            map(_.toInt).
            map((digit) => if (digit == 0) 10 else digit).
            toVector
        
        println((for (left <- 1 to 10; right <- 1 to 10) yield cost(left, right, 0)).min)
    }
}
