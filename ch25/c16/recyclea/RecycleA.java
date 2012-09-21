//: C25:RecycleA.java
// Recycling with RTTI
package c16.recyclea;

import java.util.*;
import java.io.*;

abstract class Trash {
    private double weight;

    Trash(double wt) {
        weight = wt;
    }

    abstract double value();

    double weight() {
        return weight;
    }

    // Sums the value of Trash in a bin:
    static void sumValue(Vector bin) {
        Enumeration e = bin.elements();
        double val = 0.0f;
        while (e.hasMoreElements()) {
            // One kind of RTTI:
            // A dynamically-checked cast
            Trash t = (Trash)e.nextElement();

            // Polymorphism in action:
            val += t.weight() * t.value();
            System.out.println(
                "weight of " +
                // Using RTTI to get type
                // information about the class:
                t.getClass().getName() +
                " = " + t.weight());
        }
        System.out.println("Total value = " + val);   
    }
}

class Aluminum extends Trash {
    static double val = 1.67f;

    Aluminum(double wt) {
        super(wt);
    }

    double value() {
        return val;
    }

    static void value(double newval) {
        val = newval;
    }
}

class Paper extends Trash {
    static double val = 0.10f;

    Paper(double wt) {
        super(wt);
    }

    double value() {
        return val;
    }

    static void value(double newval) {
        val = newval;
    }
}

class Glass extends Trash {
    static double val = 0.23f;

    Glass(double wt) {
        super(wt);
    }

    double value() {
        return val;
    }

    static void value(double newval) {
        val = newval;
    }
}

public class RecycleA {
    public static void main(String[] args) {
        Vector bin = new Vector();

        // Fill up the Trash bin:
        for (int i = 0; i < 30; i++) {
            switch((int)(Math.random() * 3)) {
                case 0 :
                    bin.addElement(new Aluminum(Math.random() * 100));
                    break;
                case 1 :
                    bin.addElement(new Paper(Math.random() * 100));
                    break;
                case 2 :
                    bin.addElement(new Glass(Math.random() * 100));
                    break;
            }
        }

        Vector glassBin = new Vector();
        Vector paperBin = new Vector();
        Vector alBin = new Vector();

        Enumeration sorter = bin.elements();

        // Sort the Trash:
        while (sorter.hasMoreElements()) {
            Object t = sorter.nextElement();

            // RTTI to show class membership:
            if (t instanceof Aluminum) {
                alBin.addElement(t);
            }

            if (t instanceof Paper) {
                paperBin.addElement(t);
            }
            
            if (t instanceof Glass) {
                glassBin.addElement(t);
            }
        }

        Trash.sumValue(alBin);
        Trash.sumValue(paperBin);
        Trash.sumValue(glassBin);
        Trash.sumValue(bin);
    }
}
