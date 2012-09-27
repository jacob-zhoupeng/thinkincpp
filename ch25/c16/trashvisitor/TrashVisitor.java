//: C25:TrashVisitor.java
// The "visitor" pattern
package c16.trashvisitor;

import c16.trash.*;
import java.util.*;

// Specific group of algorithms packaged
// in each implementation of Visitor:
class PriceVisitor implements Visitor {
    public void visit(VAluminum al) {
        double v = al.weight() * al.value();
        System.out.println("value of Aluminum = " + v);
        alSum += v;
    }

    public void visit(VPaper p) {
        double v = p.weight() * p.value();
        System.out.println("value of Paper = " + v);
        pSum += v;
    }

    public void visit(VGlass g) {
        double v = g.weight() * g.value();
        System.out.println("value of Glass = " + v);
        gSum += v;
    }

    public void visit(VCardboard c) {
        double v = c.weight() * c.value();
        System.out.println("value of Cardboard = " + v);
        cSum += v;
    }

    void total() {
        System.out.println("Total Aluminum: $" + alSum + "\n"
            + "Total Paper: $" + pSum + "\n"
            + "Total Glass: $" + gSum + "\n"
            + "Total Cardboard: $" + cSum);
    }

    private double alSum; // Aluminum
    private double pSum; // Paper
    private double gSum; // Glass
    private double cSum; // Cardboard
}

class WeightVisitor implements Visitor {
    public void visit(VAluminum al) {
        alSum += al.weight();
        System.out.println("weight of Aluminum = " + al.weight());
    }

    public void visit(VPaper p) {
        pSum += p.weight();
        System.out.println("weight of Paper = " + p.weight());
    }

    public void visit(VGlass g) {
        gSum += g.weight();
        System.out.println("weight of Glass = " + g.weight());
    }

    public void visit(VCardboard c) {
        cSum += c.weight();
        System.out.println("weight of Cardboard = " + c.weight());
    }

    void total() {
        System.out.println("Total weight Aluminum: " + alSum);
        System.out.println("Total weight Paper: " + pSum);
        System.out.println("Total weight Glass: " + gSum);
        System.out.println("Total weight Cardboard: " + cSum);
    }
    
    private double alSum; // Aluminum
    private double pSum; // Paper
    private double gSum; // Glass
    private double cSum; // Cardboard
}

public class TrashVisitor {
    public static void main(String[] args) {
        Vector bin = new Vector();

        // ParseTrash still works, without changes:
        ParseTrash.fillBin("vtrash.dat", bin);

        // You could even iterate through
        // a list of visitors!
        PriceVisitor pv = new PriceVisitor();
        WeightVisitor wv = new WeightVisitor();
        Enumeration<Visitable> it = bin.elements();
        while (it.hasMoreElements()) {
            Visitable v = it.nextElement();
            v.accept(pv);
            v.accept(wv);
        }

        pv.total();
        wv.total();
    }
} ///:~
