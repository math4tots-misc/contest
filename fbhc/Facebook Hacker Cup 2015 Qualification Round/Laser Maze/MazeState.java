import java.util.Objects;
import java.util.List;
import java.util.ArrayList;

public class MazeState {
	private final Maze maze;
	private final Location location;
	private final int time;

	/**
	 * Return MazeState representative of the starting state of given maze.
	 */
	public static MazeState from(Maze maze) {
		return new MazeState(maze, maze.getStartLocation(), 0);
	}

	public MazeState(Maze m, Location loc, int t) {
		maze = m;
		location = loc;
		time = t;
		assert t >= 0 && t < 4;
	}

	public List<MazeState> getNeighbors() {

		/* A filter and then a map here would feel really good. */
		List<MazeState> neighbors = new ArrayList<MazeState>();

		for (Location loc : location.getNeighbors()) {
			if (maze.includes(loc) && !maze.occupiedAt(loc) &&
					!maze.attackedAt(loc, (time+1)%4)) {
				neighbors.add(new MazeState(maze, loc, (time+1)%4));
			}
		}

		return neighbors;
	}

	public boolean atGoal() {
		return location.equals(maze.getGoalLocation());
	}

	@Override
	public int hashCode() {
		return Objects.hash(maze, location, time);
	}

	@Override
	public boolean equals(Object state) {
		return equals((MazeState) state);
	}

	public boolean equals(MazeState state) {
		return maze.equals(state.maze) &&
			   location.equals(state.location) &&
		       time == state.time;
	}

	/* for debugging */
	@Override
	public String toString() {
		return  "(" + location.toString() + ", " + Integer.toString(time) + ")";
	}
}
