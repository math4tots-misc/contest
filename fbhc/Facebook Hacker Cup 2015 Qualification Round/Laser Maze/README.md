Laser Maze
==========

I picked Java for this problem because there were three problems and I figured
I might as well round out the trinity (C/C++, Python, Java), and I had already
used C and Python.

I probably super over-engineered this considering this is just a programming
contest problem, but at the same time I had fun using Java in what I feel is
a very Java-esque way.

The two mains are in

	LaserMaze.java
		This is the actual code that solves the problem.

	Test.java
		Some testing.

For actually doing things there are three executable bash scripts

	./run_example
		Runs the program on example input and diffs against the example output.

	./run_real
		Runs the program on the real input.
		The output is written to "laser_maze.out".

	./test
		Runs the tests I wrote to help with development.

I've only tested on my mac, but my guess is these would all run in any
reasonably modern *nix environment with bash and java on it.

I probably should've tested for performance, but I got kind of lazy...
Time expired ... 