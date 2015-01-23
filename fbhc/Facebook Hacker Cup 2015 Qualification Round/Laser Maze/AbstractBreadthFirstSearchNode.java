import java.util.List;

abstract public class AbstractBreadthFirstSearchNode<
		N extends AbstractBreadthFirstSearchNode> {
	abstract public List<N> getNeighbors();
	abstract public boolean atGoal();
	abstract public Object getState();
}
