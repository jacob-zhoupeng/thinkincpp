//: C25:DynaTrash.java
// Using a Hashtable of Vectors and RTTI
// to automatically sort trash into
// vectors. This solution, despite the
// use of RTTI, is extensible.
package c16.dynatrash;

import c16.trash.*;
import java.util.*;

// Generic TypeMap works in any situation:
class TypeMap {
    private Hashtable t = new Hashtable();
    
    public void add(Object o) {
        Class type = o.getClass();
        if (t.containsKey(type)) {
            ((Vector)t.get(type)).addElement(0);
        } else {
            Vector v = new Vector();
            v.addElement(o);
            t.put(type, v);
        }
    }

    public Vector get(Class type) {
        return (Vector)t.get(type);
    }

    public Enumeration keys() {
        return t.keys();
    }

    // Returns handle to adapter class to allow
    // callbacks from ParseTrash.fillBin():
    public Fillable filler() {
        // Anonymous inner class:
        return new Fillable() {
            public void addTrash(Trash t) {
                add(t);
            }
        };
    }
}

public class DynaTrash {
    public static void main(String[] args) {
        TypeMap bin = new TypeMap();
        ParseTrash.fillBin("trash.dat", bin.filler());

        Enumeration<Class> keys = bin.keys();
        while (keys.hasMoreElements()) {
            Trash.sumValue(bin.get(keys.nextElement()));
        }
    }
} ///:~
