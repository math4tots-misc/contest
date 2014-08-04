package math4tots;

final public class SliceIterator<T> extends Iterator<T> {
	public RandomAccessContainer<T> container;
	public int start, end;
	
	public SliceIterator(RandomAccessContainer<T> container, int start, int end) {
		int size = container.size();
		this.container = container;
		this.start = slice_index(start,size);
		this.end = slice_index(end,size);
	}

	@Override
	public T peek() {
		return container.get(start);
	}

	@Override
	public T next() {
		return container.get(start++);
	}

	@Override
	public boolean hasNext() {
		return start < end;
	}
}
