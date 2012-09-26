//: C25:TypedBin.java
// Vector that knows how to grab the right type
package c16.doubledispatch;

import c16.trash.*;
import java.util.*;

public abstract class TypedBin {
    Vector v = new Vector();
    
    protected boolean addIt(Trash t) {
        v.addElement(t);
        return true;
    }

    public Enumeration elements() {
        return v.elements();
    }

    public boolean add(DDAluminum a) {
        return false;
    }

    public boolean add(DDPaper a) {
        return false;
    }

    public boolean add(DDGlass a) {
        return false;
    }

    public boolean add(DDCardboard a) {
        return false;
    }
}