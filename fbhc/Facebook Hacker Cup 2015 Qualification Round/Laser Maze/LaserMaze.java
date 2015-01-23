import java.util.Scanner;
import java.util.Deque;

public class LaserMaze {

	public static Integer solve(Maze maze) {
		MazeSearchNode node = new MazeSearchNode(MazeState.from(maze), 0);
		BreadthFirstSearch<MazeSearchNode> search =
				new BreadthFirstSearch<MazeSearchNode>();
		MazeSearchNode goalNode = search.findGoal(node);
		if (goalNode == null) {
			return null;
		}
		return goalNode.getDepth();
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for (int t = 1; t <= T; t++) {

			Integer answer = solve(Maze.from(scanner));

			System.out.print("Case #");
			System.out.print(t);
			System.out.print(": ");
			if (answer == null) {
				System.out.println("impossible");
			} else {
				System.out.println(answer);
			}
		}
	}

}
