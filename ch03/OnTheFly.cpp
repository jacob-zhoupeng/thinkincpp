//: C03:OneTheFly.cpp
// On-the-fly data definition

int main() {
    //..
    { // Begin a new scope
        int q = 0; // Plain C requires definitions here
        // ..
        for (int i = 0; i < 100; i++) { // Define at point of use
            q++;
            // Notice q comes from a larger scope
            int p = 12; // Definition at the end of the scope
        }

        int p = 1; // A defferent p
    } // End scope containing q & outer p

    return 0;
} ///:~
