
/**
 * Red-Black Tree guided by CLRS 3rd edition.
 * 
 * In a Red-Black tree:
 * 1. Every node is either red or black.
 * 2. The root is black.
 * 3. Every leaf (NIL) is black.
 * 4. If a node is red, then both its children are black.
 * 5. For each node, all simple paths from the node to descendant leaves
 *    contain the same number of black nodes.
 * 
 * @author math4tots
 * 
 * @param <T>
 */
public class RedBlackTree<T extends Comparable<T>> {
	public static final boolean RED = true;
	public static final boolean BLACK = false;
	public static final boolean LEFT = true;
	public static final boolean RIGHT = false;
	
	public Node root, nil;
	
	public RedBlackTree() {
		root = nil = new Node();
		nil.p = nil.left = nil.right = nil;
	}
	
	public int compare(T a, T b) {
		return a.compareTo(b);
	}
	public void insert(T key) {
		new Node(RED,key).insert();
	}
	
	/**
	 * Even though all methods on Node are public,
	 * you really should figure out what you're doing before calling them.
	 * Many of them make assumptions about the state of the node/tree at
	 * the point of call. The methods on the tree itself should suffice for
	 * most people that just want a self balancing tree.
	 * @author math4tots
	 *
	 */
	public class Node {
		public boolean color;
		public T key;
		public Node left, right, p;
		
		public Node() {
			this(BLACK,null);
		}
		public Node(boolean color, T key) {
			this.color = color;
			this.key = key;
			left = right = p = nil;
		}
		
		public Node search(T k) {
			Node x = this;
			while (x != nil) {
				int comparison = compare(k,x.key);
				if (comparison == 0)
					break;
				else
					x = (comparison < 0) ? x.left : x.right;
			}
			return x;
		}
		public Node minimum() {
			Node x = this;
			while (x.left != nil)
				x = x.left;
			return x;
		}
		public Node maximum() {
			Node x = this;
			while (x.right != nil)
				x = x.right;
			return x;
		}
		public Node successor() {
			if (right != nil)
				return right.minimum();
			Node x = this, y = p;
			while (y != nil && x == y.right) {
				x = y;
				y = x.p;
			}
			return y;
		}
		public Node predecessor() {
			if (left != nil)
				return left.maximum();
			Node x = this, y = p;
			while (y != nil && x == y.left) {
				x = y;
				y = x.p;
			}
			return y;
		}
		public void transplant(Node v) {
			if (v != nil)
				v.p = p;
			if (p == nil)
				root = v;
			else if (this == p.left)
				p.left = v;
			else
				p.right = v;
		}
		/**
		 * Left rotation (x = this).
		 * 
		 *    x                  y 
		 *  *   y     ---->    x   *
		 *    *   *          *   *
		 * 
		 * (this) and (right) should not be nil.
		 * @param
		 */
		public void leftRotate() {
			Node x = this, y = right;
			
			x.transplant(y);
			
			x.right = y.left;
			if (x.right != nil)
				x.right.p = x;
			
			y.left = x;
			x.p = y;
		}
		/**
		 * Right rotation (y = this).
		 * 
		 *      y              x
		 *    x   *   ---->  *   y
		 *  *   *              *   *
		 * 
		 * (this) and (left) should not be nil.
		 * @param
		 */
		public void rightRotate() {
			Node y = this, x = left;
			y.transplant(x);
			
			y.left = x.right;
			if (y.left != nil)
				y.left.p = y;
			
			x.right = y;
			y.p = x;
		}
		/**
		 * Rotate (this)'s parent, so that (this) is the new parent
		 */
		public void rotate() {
			if (this == p.left)
				p.rightRotate();
			else
				p.leftRotate();
		}
		/**
		 * Inserts (this) into the nested RedBlackTree.
		 * (this) should not be nil.
		 * Also assumes color is RED.
		 */
		public void insert() {
			Node x = root, y = nil;
			while (x != nil) {
				y = x;
				x = (compare(key,x.key) < 0) ? x.left : x.right;
			}
			p = y;
			if (y == nil)
				root = this;
			else if (compare(key, y.key) < 0)
				y.left = this;
			else
				y.right = this;
			insertFixup();
		}
		/**
		 * Determines whether (this) is a left or right child.
		 * This method makes no sense if (this) is (nil) or (root).
		 * @return LEFT if (this) is a left child, otherwise RIGHT
		 */
		public boolean childType() {
			return p.left == this; 
		}
		/**
		 * Should only be called from insert().
		 * 
		 * The code is somewhat modified from CLRS in a way that I think
		 * is more intuitive, but is equivalent.
		 * 
		 * CLRS describes half the algorithm and just writes that the other 
		 * half is the same with left and right swapped. Doing it that way
		 * would probably generate faster code. However, I felt it was truer
		 * to the abstraction (and more intuitive and readable) to combine
		 * both cases into one.
		 * 
		 */
		public void insertFixup() {
			Node z = this;
			while (z.p.color == RED) {
				Node uncle = z.p.childType() == LEFT ? z.p.p.right : z.p.p.left;
				if (uncle.color == RED) {
					z.p.color = uncle.color = BLACK;
					z.p.p.color = RED;
					z = z.p.p;
				} else {
					if (z.childType() != z.p.childType()) {
						Node new_z = z.p;
						z.rotate();
						z = new_z;
					}
					z.p.color = BLACK;
					z.p.p.color = RED;
					z.p.rotate();
				}
			}
			root.color = BLACK;
		}
		
		/**
		 * For debugging.
		 */
		public void walkSubtree() {
			if (this != nil) {
				System.out.print("(");
				left.walkSubtree();
				System.out.print(key);
				right.walkSubtree();
				System.out.print(")");
			}
		}
	}
	
	/**
	 * For debugging
	 */
	public void walk() {
		System.out.println("walking...");
		root.walkSubtree();
		System.out.println();
	}
	
	public static void main(String[] args) {
//		System.out.println(new Integer(132).compareTo(44));
		RedBlackTree<Integer> tree = new RedBlackTree<Integer>();
//		for (int i = 0; i < 10; i++)
//			tree.insert(i);
//		tree.insert(1);
//		tree.insert(3);
//		tree.insert(2);
//		tree.walk();
		
		for (int i = 0; i < 10; i++) {
			tree.insert(i);
			tree.walk();
		}
	}
}
