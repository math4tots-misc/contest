// Fails two of the test cases.

// I just tried what I believed to be an equivalent solution in ruby
// and that one passed all test cases...
// Hmmm...

object Solution {
	
	def psum(N:Int) = (N*(N+1))/2
	
	def solve(N:Int) = psum(N/3) * 3 + psum(N/5) * 5 - psum(N/15) * 15
	
	def main(args:Array[String]) {
		val T = io.StdIn.readLine.toInt
		for (i <- 1 to T) {
			val N = io.StdIn.readLine.toInt
			println(solve(N-1))
		}
	}
}