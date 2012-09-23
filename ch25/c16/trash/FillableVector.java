//: C25:FillableVector.java
// Adapter that makes a Vector Fillable
package c16.trash;

import java.util.*;

public class FillableVector implements Fillable {
    private Vector v;

    public FillableVector(Vector vv) {
        v = vv;
    }

    public void addTrash(Trash t) {
        v.addElement(t);
    }
} ///:~