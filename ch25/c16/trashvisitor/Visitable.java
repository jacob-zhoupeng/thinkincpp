//: C25:Visitable.java
// An interface to add visitor functionality to
// the Trash hierarchy without modifying the
// base class.
package c16.trashvisitor;

import c16.trash.*;

interface Visitable {
    // The new member function:
    void accept(Visitor v);
} ///:~