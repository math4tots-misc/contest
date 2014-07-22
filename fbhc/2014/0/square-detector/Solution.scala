// https://www.facebook.com/hackercup/problems.php?pid=318555664954399&round=598486203541358

// Unfortunately, the facebook hacker cup judge doesn't seem to be available after the contest
// as far as I can tell.

object Solution {
	def main(args : Array[String]) {
		val T = scala.io.StdIn.readInt()
		for (t <- 1 to T) {
			val N = scala.io.StdIn.readInt()
			val ar = (1 to N).map((i:Int) => scala.io.StdIn.readLine())
			
			val left =
				(0 until N).map((row:Int) =>
					(0 until N).map((col:Int) =>
						if (ar(row)(col) == '#') col else N).min).min
			
			val right =
				(0 until N).map((row:Int) =>
					(0 until N).map((col:Int) =>
						if (ar(row)(col) == '#') col else 0).max).max
			
			val down =
				(0 until N).map((row:Int) =>
					(0 until N).map((col:Int) =>
						if (ar(row)(col) == '#') row else 0).max).max
			
			val up =
				(0 until N).map((row:Int) =>
					(0 until N).map((col:Int) =>
						if (ar(row)(col) == '#') row else N).min).min
			
			val answer =
				if (left != N && (right-left) == (down-up) &&
					(up to down).forall((row:Int) =>
						(left to right).forall((col:Int) => ar(row)(col) == '#')))
					"YES"
				else
					"NO"
			
			println("Case #" + t + ": " + answer)
		}
	}
}
