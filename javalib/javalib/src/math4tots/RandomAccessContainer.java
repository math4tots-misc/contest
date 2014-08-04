package math4tots;

abstract public class RandomAccessContainer<T> extends BoundedContainer<T> {
	abstract public void set(int i, T t);
	abstract public T get(int i);
	@Override
	abstract public int size();
	
	@Override
	public Iterator<T> iterator() {
		return new SliceIterator<T>(this,0,size());
	}
	
	public Iterator<T> slice(int start, int end) {
		return new SliceIterator<T>(this,start,end);
	}
}
