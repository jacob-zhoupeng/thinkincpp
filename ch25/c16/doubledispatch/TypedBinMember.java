//: C25:TypedBinMember.java
// An interface for adding the double dispatching
// member function to the trash hierarchy without
// modifying the original hierarchy.
package c16.doubledispatch;

interface TypedBinMember {
    // The new member function:
    boolean addToBin(TypedBin[] tb);
} ///:~