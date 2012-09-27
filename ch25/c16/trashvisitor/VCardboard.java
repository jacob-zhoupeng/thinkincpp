//: C25:VCardboard.java
// Cardboard for the visitor pattern
package c16.trashvisitor;

import c16.trash.*;

public class VCardboard extends Cardboard implements Visitable {
    public VCardboard(double wt) {
        super(wt);
    }

    public void accept(Visitor v) {
        v.visit(this);
    }
} ///:~