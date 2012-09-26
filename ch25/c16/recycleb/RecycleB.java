//: C25:RecycleB.java
// Adding more objects to the recycling problem
package c16.recycleb;

import c16.trash.*;
import java.util.*;

// A vector that admits only the right type:
class Tbin extends Vector {
    Class binType;
    
    Tbin(Class binType) {
        this.binType = binType;
    }

    boolean grab(Trash t) {
        // Comparing class types:
        if (t.getClass().equals(binType)) {
            addElement(t);
            return true; // Object grabbed
        }

        return false; // Object not grabbed
    }
}

class TbinList extends Vector { // (*1*)
    boolean sort(Trash t) {
        Enumeration e = elements();
        while (e.hasMoreElements()) {
            Tbin bin = (Tbin)e.nextElement();
            if (bin.grab(t)) {
                return true;
            }
        }
        return false; // bin not found for t
    }

    void sortBin(Tbin bin) { // (*2*)
        Enumeration e = bin.elements();
        while (e.hasMoreElements()) {
            if (!sort((Trash)e.nextElement())) {
                System.out.println("Bin not found");
            }
        }
    }
}

public class RecycleB {
    static Tbin bin = new Tbin(Trash.class);

    public static void main(String[] args) {
        // Fill up the Trash bin:
        ParseTrash.fillBin("trash.dat", bin);

        TbinList trashBins = new TbinList();

        trashBins.addElement(new Tbin(Aluminum.class));
        trashBins.addElement(new Tbin(Paper.class));
        trashBins.addElement(new Tbin(Glass.class));

        // Add one line here: (*3*)
        trashBins.addElement(new Tbin(Cardboard.class));

        Enumeration e = trashBins.elements();
        while (e.hasMoreElements()) {
            Tbin b = (Tbin)e.nextElement();
            Trash.sumValue(b);
        }
        Trash.sumValue(bin);
    }
} ///:~