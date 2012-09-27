//: C25:VAluminum.java
// Aluminum for the visitor pattern
package c16.trashvisitor;

import c16.trash.*;

public class VAluminum extends Aluminum implements Visitable {
    public VAluminum(double wt) {
        super(wt);
    }

    public void accept(Visitor v) {
        v.visit(this);
    }
} ///:~