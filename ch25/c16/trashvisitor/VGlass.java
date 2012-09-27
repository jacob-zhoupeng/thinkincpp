//: C25:VGlass.java
// Glass for the visitor pattern
package c16.trashvisitor;

import c16.trash.*;

public class VGlass extends Glass implements Visitable {
    public VGlass(double wt) {
        super(wt);
    }

    public void accept(Visitor v) {
        v.visit(this);
    }
} ///:~