package math4tots;

abstract public class BoundedContainer<T> extends BaseObject {
	abstract int size();
	abstract Iterator<T> iterator();
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder("{");
		Iterator<T> it = iterator();
		
		if (it.hasNext()) {
			sb.append(it.next());
			while (it.hasNext()) {
				sb.append(", ");
				sb.append(it.next());
			}
		}
		
		sb.append("}");
		
		return sb.toString();
	}
	
	public static void main(String[] args) {
		Deque<Integer> list = new Deque<Integer>();
		System.out.println(list);
		list.push(12);
		System.out.println(list);
		list.push(44);
		System.out.println(list);
		list.pushLeft(45);
		System.out.println(list);
//		
//		BinarySearchTree<Integer> tree = new BinarySearchTree<Integer>(new Comparator<Integer>() {
//
//			@Override
//			public int compare(Integer a, Integer b) {
//				// TODO Auto-generated method stub
//				return a - b;
//			}
//			
//		});
//		
//		System.out.println(tree);
//		tree.insert(12);
//		System.out.println(tree);
//		tree.insert(44);
//		System.out.println(tree);
//		tree.insert(44);
//		System.out.println(tree);
//		tree.insert(1);
//		System.out.println(tree);
//		tree.remove(12);
//		System.out.println(tree);
	}
}
