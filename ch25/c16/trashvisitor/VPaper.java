//: C25:VPaper.java
// Paper for the visitor pattern
package c16.trashvisitor;

import c16.trash.*;

public class VPaper extends Paper implements Visitable {
    public VPaper(double wt) {
        super(wt);
    }

    public void accept(Visitor v) {
        v.visit(this);
    }
} ///:~