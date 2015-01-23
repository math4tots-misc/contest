import java.util.ArrayDeque;
import java.util.HashSet;

public class BreadthFirstSearch<Node extends AbstractBreadthFirstSearchNode<Node>> {
	public Node findGoal(Node node) {
		ArrayDeque<Node> queue = new ArrayDeque<Node>();
		HashSet<Object> seen = new HashSet<Object>();
		seen.add(node.getState());
		queue.addLast(node);
		while (queue.size() > 0) {
			node = queue.removeFirst();
			if (node.atGoal()) {
				return node;
			}
			for (Node neighbor : node.getNeighbors()) {
				if (!seen.contains(neighbor.getState())) {
					seen.add(neighbor);
					queue.addLast(neighbor);
				}
			}
		}
		return null;
	}
}
