import java.util.Scanner;

public class Maze {
	private final int height, width;
	private final char[] data;
	private final int[] attackTable;
	private final Location start, goal;

	/* For testing */
	public static Maze from(String string) {
		return from(new Scanner(string));
	}

	public static Maze from(Scanner scanner) {
		int height = scanner.nextInt(), width = scanner.nextInt();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < height; i++) {
			sb.append(scanner.next());
		}
		assert sb.length() == width * height;
		return new Maze(height, width, sb.toString().toCharArray());
	}

	public Maze(int h, int w, char[] d) {
		height = h;
		width = w;
		data = d;
		attackTable = calculateAttackTable();
		Location s = null, g = null;
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				if (characterAt(new Location(r, c)) == 'S') {
					s = new Location(r, c);
				} else if (characterAt(new Location(r, c)) == 'G') {
					g = new Location(r, c);
				}
			}
		}
		start = s;
		goal = g;
	}

	public Location getStartLocation() {
		return start;
	}

	public Location getGoalLocation() {
		return goal;
	}

	public boolean attackedAt(Location location, int time) {
		assert time >= 0 && time < 4;
		return (attackTable[getIndex(location)] & (1 << time)) != 0;
	}

	public boolean occupiedAt(Location location) {
		return characterAt(location) == '#' ||
			   characterAt(location) == '^' ||
			   characterAt(location) == '>' ||
			   characterAt(location) == 'v' ||
			   characterAt(location) == '<';
	}

	public boolean includes(Location location) {
		return location.getRow()    >= 0 &&
			   location.getRow()    <  height &&
			   location.getColumn() >= 0 &&
			   location.getColumn() <  width;
	}

	/* -- only private methods beyond this point -- */

	private int getIndex(Location location) {
		return location.getRow() * width + location.getColumn();
	}

	private char characterAt(Location location) {
		return data[getIndex(location)];
	}

	private int[] calculateAttackTable() {
		int[] attackTable = new int[width * height];
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				attackTable[getIndex(new Location(r, c))] = 0;
			}
		}

		/*
		 * Some metaprogramming/macros could feel really good here.
		 * But in Java, I'm afraid that sort of thinking may just
		 * lead to an even uglier mess.
		 * At least the code here is pretty easy to read.
		 */

		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				int base;
				if (characterAt(new Location(r, c)) == '^') {
					base = 0;
				} else if (characterAt(new Location(r, c)) == '<') {
					base = 1;
				} else if (characterAt(new Location(r, c)) == 'v') {
					base = 2;
				} else if (characterAt(new Location(r, c)) == '>') {
					base = 3;
				} else {
					continue;
				}
				for (int dr = -1;
						r+dr >= 0 && !occupiedAt(new Location(r+dr, c));
						dr--) {
					attackTable[getIndex(new Location(r+dr, c))] |=
						1 << ((base+0)%4);
				}
				for (int dc = 1;
						c+dc < width && !occupiedAt(new Location(r, c+dc));
						dc++) {
					attackTable[getIndex(new Location(r, c+dc))] |=
						1 << ((base+1)%4);
				}
				for (int dr = 1;
						r+dr < height && !occupiedAt(new Location(r+dr, c));
						dr++) {
					attackTable[getIndex(new Location(r+dr, c))] |=
						1 << ((base+2)%4);
				}
				for (int dc = -1;
						c+dc >= 0 && !occupiedAt(new Location(r, c+dc));
						dc--) {
					attackTable[getIndex(new Location(r, c+dc))] |=
						1 << ((base+3)%4);
				}
			}
		}
		return attackTable;
	}
}
