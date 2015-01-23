/**
 * JUnit seemed a bit heavy-weight for a programming contest
 * (heck Java feels heavy-weight for a programming contest).
 * At the same time, when writing code in java, it's sometimes hard
 * to get visibility.
 * Hence tests.
 */

public class Test {
	public static void main(String[] args) {

		{
			Maze maze = Maze.from("3 4\n" +
				                  "....\n" +
				                  ".SG.\n" +
				                  "....\n");
			assert new Location(1, 1).equals(maze.getStartLocation());
			assert new Location(1, 2).equals(maze.getGoalLocation());
		}

		{
			Maze maze = Maze.from("3 4\n" +
				                  "<..^\n" +
				                  ".SG.\n" +
				                  "v..<\n");
			assert maze.occupiedAt(new Location(0, 0));
			assert maze.occupiedAt(new Location(0, 3));
			assert maze.occupiedAt(new Location(2, 0));
			assert maze.occupiedAt(new Location(2, 3));
			assert !maze.occupiedAt(new Location(0, 1));
			assert !maze.occupiedAt(new Location(1, 1));
			assert !maze.occupiedAt(new Location(1, 2));
		}

		{
			Maze maze = Maze.from("5 5\n" +
				                  ".....\n" +
				                  ".....\n" +
				                  "..>..\n" +
				                  ".....\n" +
				                  ".....\n");
			assert !maze.attackedAt(new Location(2, 3), 1);
			assert maze.attackedAt(new Location(2, 3), 0);
			assert !maze.attackedAt(new Location(4, 2), 0);
			assert maze.attackedAt(new Location(4, 2), 1);
			assert !maze.attackedAt(new Location(2, 0), 3);
			assert maze.attackedAt(new Location(2, 0), 2);
			assert !maze.attackedAt(new Location(0, 2), 0);
			assert maze.attackedAt(new Location(0, 2), 3);
		}

		{
			Maze maze = Maze.from("1 5\n" +
				                  ">.#..\n");
			assert maze.attackedAt(new Location(0, 1), 0);
			assert !maze.attackedAt(new Location(0, 3), 0);
		}

		{

			Maze maze = Maze.from("5 5\n" +
				                  "SG...\n" +
				                  ".....\n" +
				                  "..<..\n" +
				                  ".....\n" +
				                  ".....\n");

			assert maze.occupiedAt(new Location(2, 2));
			assert maze.attackedAt(new Location(0, 2), 1);

			{
				MazeState state = MazeState.from(maze);
				assert state.getNeighbors().size() == 2;
				assert state.getNeighbors().contains(
						new MazeState(maze, new Location(0, 1), 1));
				assert state.getNeighbors().contains(
						new MazeState(maze, new Location(1, 0), 1));
			}

			{
				MazeState state = new MazeState(maze, new Location(0, 1), 1);
				assert state.atGoal();
			}			

			{
				MazeState state = new MazeState(maze, new Location(1, 3), 0);
				assert state.getNeighbors().size() == 3;
				assert !state.getNeighbors().contains(
						new MazeState(maze, new Location(1, 2), 1));
				assert state.getNeighbors().contains(
						new MazeState(maze, new Location(2, 3), 1));
			}
		}

		{
			Maze maze = Maze.from("1 5\n" +
				                  "S...G\n");
			MazeSearchNode node = new MazeSearchNode(MazeState.from(maze), 0);
			BreadthFirstSearch<MazeSearchNode> search =
					new BreadthFirstSearch<MazeSearchNode>();
			assert search.findGoal(node).getDepth() == 4;
		}

		{
			Maze maze = Maze.from("1 5\n" +
				                  "S.#.G\n");
			MazeSearchNode node = new MazeSearchNode(MazeState.from(maze), 0);
			BreadthFirstSearch<MazeSearchNode> search =
					new BreadthFirstSearch<MazeSearchNode>();
			assert search.findGoal(node) == null;
		}

		{
			assert LaserMaze.solve(Maze.from("1 5\n" +
				                             "S...G\n")) == 4;
		}

		{
			assert LaserMaze.solve(Maze.from("1 5\n" +
				                             "S.#.G\n")) == null;
		}

		{
			assert LaserMaze.solve(Maze.from("1 5\n" +
				                             "S.#.G\n")) == null;
		}

		{
			assert LaserMaze.solve(Maze.from("5 5\n" +
											 "S....\n" +
											 ".....\n" +
											 ".>v..\n" +
											 ".^<..\n" +
											 "....G\n")) == 8;
		}

		System.out.println("All tests pass!");
	}
}
