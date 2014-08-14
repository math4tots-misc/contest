object Main {
	def main(args:Array[String]) {
		for (line <- scala.io.Source.fromFile(args(0)).getLines()) {
			if (line.size != 0) {
				val Array(a,b,n) = line.split("\\s").map(_.toInt)
				val c = a * b
				for (n <- 1 to n) {
					if (n  % c == 0) {
						print("FB")
					} else if (n % a == 0) {
						print("F")
					} else if (n % b == 0) {
						print("B")
					} else {
						print(n)
					}
					print(" ")
				}
				println
			}
		}
	}
}