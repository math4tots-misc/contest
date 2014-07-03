// https://www.hackerrank.com/challenges/solve-me-first

// this solution was already templated on the website.
// At least from it I get some idea of how scala does io
// (and what kind of classically 'functional' features I can expect).

object Solution {
	def main(args: Array[String]) {
		println(io.Source.stdin.getLines().take(2).map(_.toInt).sum)
	}
}
