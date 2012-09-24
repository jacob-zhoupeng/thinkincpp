//: C25:Trash.java
// Base class for Trash recycling examples
package c16.trash;

import java.util.*;
import java.lang.reflect.*;

public abstract class Trash {
    private double weight;

    Trash(double wt) {
        weight = wt;
    }

    Trash() {}

    public abstract double value();

    public double weight() {
        return weight;
    }

    // Sums the value of Trash in a bin:
    public static void sumValue(Vector bin) {
        Enumeration e = bin.elements();
        double val = 0.0f;

        while (e.hasMoreElements()) {
            // One kind of RTTI:
            // A dynamically-checked cast
            Trash t = (Trash)e.nextElement();
            val += t.weight() * t.value();
            System.out.println(
                "weight of " +
                // Using RTTI to get type
                // information about the class:
                t.getClass().getName() +
                " = " + t.weight());
        }
        System.out.println("Total value = " + val);
    }

    // Remainder of class provides support for
    // prototyping:
    public static class PrototypeNotFoundException extends Exception {};
    public static class CannotCreateTrashException extends Exception {};

    private static Vector trashTypes = new Vector();

    public static Trash factory(Info info) throws PrototypeNotFoundException, 
            CannotCreateTrashException {
        for (int i = 0; i < trashTypes.size(); i++) {
            // Somehow determine the new type
            // to create, and create one:
            Class tc = (Class)trashTypes.elementAt(i);

            if (tc.getName().indexOf(info.id) != -1) {
                try {
                    // Get the dynamic constructor member function
                    // that takes a double argument:
                    Constructor ctor = tc.getConstructor(new Class[] { double.class });

                    // Call the constructor to create a 
                    // new object:
                    return (Trash)ctor.newInstance(new Object[] { new Double(info.data) });
                } catch (Exception ex) {
                    ex.printStackTrace();
                    throw new CannotCreateTrashException();
                }
            }
        }

        // Class wast not in the list. Try to load it,
        // but it must be in your class path!
        try {
            System.out.println("Loading " + info.id);
            trashTypes.addElement(Class.forName(info.id));
        } catch (Exception e) {
            e.printStackTrace();
            throw new PrototypeNotFoundException();
        }

        // Loaded successfully, Recursive call should work this time:
        return factory(info);
    }

    public static class Info {
        public String id;
        public double data;

        public Info(String name, double data) {
            id = name;
            this.data = data;
        }
    }
} ///:~
