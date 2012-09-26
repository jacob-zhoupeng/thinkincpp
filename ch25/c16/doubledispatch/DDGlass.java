//: C25:DDGlass.java
// Glass for double dispatching
package c16.doubledispatch;

import c16.trash.*;

public class DDGlass extends Glass implements TypedBinMember {
    public DDGlass(double wt) {
        super(wt);
    }

    public boolean addToBin(TypedBin[] tb) {
        for (int i = 0; i < tb.length; i++) {
            if (tb[i].add(this)) {
                return true;
            }
        }
        return false;
    }
} ///:~