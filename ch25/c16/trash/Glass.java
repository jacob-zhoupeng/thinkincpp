//: C25:Glass.java
// The Glass class with prototyping
package c16.trash;

public class Glass extends Trash {
    private static double val = 0.23f;

    public Glass(double wt) {
        super(wt);
    }

    public double value() {
        return val;
    }

    public static void value(double newVal) {
        val = newVal;
    }
} ///:~