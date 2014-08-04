package math4tots;

abstract public class Iterator<T> extends BaseObject {
	abstract public T peek();
	abstract public T next();
	abstract public boolean hasNext();
}
