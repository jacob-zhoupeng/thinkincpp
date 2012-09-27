//: C25:Visitor.java
// The base interface for visitors
package c16.trashvisitor;

import c16.trash.*;

interface Visitor {
    void visit(VAluminum a);
    void visit(VPaper p);
    void visit(VGlass g);
    void visit(VCardboard c);
} ///:~