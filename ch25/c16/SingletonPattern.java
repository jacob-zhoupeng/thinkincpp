//: C25:SingletonPattern.java
// The Singleton design pattern: you can
// never instantiate more than one.
package c16;

// Since this isn't inherited from a Cloneable
// base class and cloneability isn't added,
// making it final prevents cloneability from
// being added in any derived classes:
final class Singleton {
	public static Singleton getHandle() {
		return s;
	}

	public int getValue() {
		return i;
	}

	public void setValue(int x) {
		i = x;
	}

	private static Singleton s = new Singleton(47);
	private int i;

	//! 防止类在外部实例化
	private Singleton(int x) {
		i = x;
	}
}

public class SingletonPattern {
	public static void main(String[] args) {
		Singleton s = Singleton.getHandle();
		System.out.println(s.getValue());

		Singleton s2 = Singleton.getHandle();
		s2.setValue(9);
		System.out.println(s.getValue());

		try {
			// Can't do this: compile-time error.
			// Singleton s3 = (Singleton)s2.clone();
		} catch (Exception e) {}
	}
} ///:~
