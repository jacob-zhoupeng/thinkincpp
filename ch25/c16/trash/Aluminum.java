//: C25:Aluminum.java
// The Aluminum class with prototyping
package c16.trash;

public class Aluminum extends Trash {
    private static double val = 1.67f;
    
    public Aluminum(double wt) {
        super(wt);
    }

    public double value() {
        return val;
    }

    public static void value(double newVal) {
        val = newVal;
    }
} ///:~