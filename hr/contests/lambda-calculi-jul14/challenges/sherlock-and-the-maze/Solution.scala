/*
It does seem a tad bit cheap to use mutable values in a functional programming contest,
but technically speaking, even in Haskell you can use stateful monads to do this sort of
thing.
*/

object Solution {

	// precompute
	val a = scala.collection.mutable.ArrayBuffer.fill(101*101*101*2){0}
	val b = scala.collection.mutable.ArrayBuffer.fill(101*101*101*2){false}
	
	def combine(n:Int,m:Int,k:Int,d:Int) : Int = n+101*(m+101*(k+101*d))
	
	def main(args: Array[String]) {
		val N = scala.io.StdIn.readLine.toInt
		for (n <- 1.to(N)) {
			val Array(n,m,k) = scala.io.StdIn.readLine.split(" ").map(_.toInt)
			println(solve(n,m,k))
		}
	}
	
	def solve(n:Int,m:Int,k:Int,d:Int) : Int = {
		val x = combine(n,m,k,d)
		
		if (!b(x)) {
			if (n == 1)
				if (m == 1)
					a(x) = 1											// already at destination
				else
					a(x) = if (d == 0 || k > 0) 1 else 0				// only need to move right
			else
				if (m == 1)
					a(x) = if (d == 1 || k > 0) 1 else 0				// only need to move down
				else
					if (k == 0)
						a(x) = 0										// no turns left but not on edge
					else
						if (d == 1)
							a(x) = (solve(n-1,m,k,d) + solve(n,m-1,k-1,1-d)) % 1000000007
						else
							a(x) = (solve(n,m-1,k,d) + solve(n-1,m,k-1,1-d)) % 1000000007
			b(x) = true
		}
		return a(x)
	}
	
	def solve(n:Int,m:Int,k:Int) : Int = {
		return if (n == 1 || m == 1) 1 else (solve(n-1,m,k,1) + solve(n,m-1,k,0)) % 1000000007
	}
}