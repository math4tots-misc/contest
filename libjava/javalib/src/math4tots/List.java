package math4tots;

public class List<T> extends RandomAccessContainer<T> {
	public java.util.ArrayList<T> list = new java.util.ArrayList<T>();
	
	public List() {
	}
	
	public List(Iterator<T> t) {
		extend(t);
	}
	
	@Override
	public T get(int i) {
		return list.get(i);
	}
	
	@Override
	public void set(int i, T t) {
		list.set(i, t);
	}
	
	@Override
	public int size() {
		return list.size();
	}
	
	public void push(T t) {
		list.add(t);
	}
	
	public T pop() {
		return list.remove(list.size()-1);
	}
	
	public T peek() {
		return list.get(list.size()-1);
	}

	public void extend(Iterator<T> it) {
		while (it.hasNext())
			list.add(it.next());
	}
}
