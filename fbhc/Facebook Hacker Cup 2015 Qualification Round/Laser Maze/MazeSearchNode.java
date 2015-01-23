import java.util.ArrayList;
import java.util.List;

public class MazeSearchNode
		extends AbstractBreadthFirstSearchNode<MazeSearchNode> {

	private final MazeState state;
	private final int depth;

	public MazeSearchNode(MazeState s, int d) {
		state = s;
		depth = d;
	}

	public int getDepth() {
		return depth;
	}

	@Override
	public List<MazeSearchNode> getNeighbors() {
		ArrayList<MazeSearchNode> neighbors = new ArrayList<MazeSearchNode>();
		for (MazeState neighbor_state : state.getNeighbors()) {
			neighbors.add(new MazeSearchNode(neighbor_state, depth+1));
		}
		return neighbors;
	}

	@Override
	public boolean atGoal() {
		return state.atGoal();
	}

	@Override
	public MazeState getState() {
		return state;
	}
}
