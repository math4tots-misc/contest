package math4tots;

public class Deque<T> extends RandomAccessContainer<T> {
	public List<T> list = new List<T>();
	public int lower_bound;
	
	public Deque() {
		list = new List<T>();
		lower_bound = 0;
	}
	
	public T get(int i) {
		return list.get(i + lower_bound);
	}
	
	public void set(int i, T t) {
		list.set(i + lower_bound, t);
	}
	
	public int size() {
		return list.size() - lower_bound;
	}
	
	public void push(T t) {
		list.push(t);
	}
	
	public T pop() {
		return list.pop();
	}
	
	public T peek() {
		return list.peek();
	}

	public void extend(Iterator<T> it) {
		list.extend(it);
	}
	
	public void pushLeft(T t) {
		if (lower_bound == 0)
			resetBuffer();
		lower_bound--;
		list.set(lower_bound, t);
	}
	
	public T popLeft() {
		T t = list.get(lower_bound);
		list.set(lower_bound++, null);
		if (size() < list.size()/8 - 10)
			resetBuffer();
		return t;
	}
	
	public T peekLeft() {
		return list.get(lower_bound);
	}
	
	public void extendLeft(Iterator<T> it) {
		while (it.hasNext())
			pushLeft(it.next());
	}
	
	public void resetBuffer() {
		List<T> old_list = list;
		list = new List<T>();
		lower_bound = list.size()+10;
		for (int i = lower_bound; i > 0; i--) {
			list.push(null);
		}
		list.extend(old_list.iterator());
	}
}
