//: C25:DDCardboard.java
// Cardboard for double dispatching
package c16.doubledispatch;

import c16.trash.*;

public class DDCardboard extends Cardboard implements TypedBinMember {
    public DDCardboard(double wt) {
        super(wt);
    }

    public boolean addToBin(TypedBin[] tb){
        for (int i = 0; i < tb.length; i++) {
            if (tb[i].add(this)) {
                return true;
            }
        }
        return false;
    }
} ///:~