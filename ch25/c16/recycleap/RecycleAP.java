//: C25:RecycleAP.java
// Recycling with RTTI and Prototypes
package c16.recycleap;

import java.util.*;
import c16.trash.*;

public class RecycleAP {
    public static void main(String[] args) {
        Vector bin = new Vector();
        
        // Fill up the Trash bin:
        ParseTrash.fillBin("Trash.dat", bin);
        Vector glassBin = new Vector();
        Vector paperBin = new Vector();
        Vector alBin = new Vector();

        Enumeration sorter = bin.elements();

        // Sort the Trash:
        while (sorter.hasMoreElements()) {
            Object t = sorter.nextElement();

            // RTTI to show class membership:
            if (t instanceof Aluminum) {
                alBin.addElement(t);
            }

            if (t instanceof Paper) {
                paperBin.addElement(t);
            }

            if (t instanceof Glass) {
                glassBin.addElement(t);
            }
        }

        Trash.sumValue(alBin);
        Trash.sumValue(paperBin);
        Trash.sumValue(glassBin);
        Trash.sumValue(bin);
    }
}
