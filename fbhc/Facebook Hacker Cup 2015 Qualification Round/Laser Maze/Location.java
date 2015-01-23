/**
 * Your run of the mill convenience POD.
 */

import java.util.Objects;
import java.util.List;
import java.util.Arrays;

public class Location {
	private final int row, column;

	public Location(int r, int c) {
		row = r;
		column = c;
	}

	public int getRow() {
		return row;
	}

	public int getColumn() {
		return column;
	}

	public List<Location> getNeighbors() {
		return Arrays.asList(new Location[] {
			new Location(row+1, column),
			new Location(row-1, column),
			new Location(row, column+1),
			new Location(row, column-1),
		});
	}

	@Override
	public boolean equals(Object location) {
		return equals((Location) location);
	}

	public boolean equals(Location location) {
		return row    == location.row &&
		       column == location.column;
	}

	@Override
	public int hashCode() {
		return Objects.hash(row, column);
	}

	/* for debugging */
	@Override
	public String toString() {
		return "(" + Integer.toString(row) + ", " +
				Integer.toString(column) + ")";
	}
}
