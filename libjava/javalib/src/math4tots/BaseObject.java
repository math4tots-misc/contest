package math4tots;

public abstract class BaseObject {
	public static int slice_index(int index, int size) {
		return
				index < 0    ? index % size + size :
				index > size ? index % size        :
					           index               ;
	}
}
