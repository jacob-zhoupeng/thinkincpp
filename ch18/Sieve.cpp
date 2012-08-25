//: C18:Sieve.cpp

#include <string>
#include <iostream>

using namespace std;

int main() {
    // Create a 50 char string and set each
    // element to 'p' for Prime
    string sieveChars(50, 'p');

    // By definition neither 0 nor 1 is prime.
    // Change these elements to "N" for Not Prime
    sieveChars.replace(0, 2, "NN");

    // Walk through the array:
    for (unsigned int i = 2; i <= (sieveChars.size()/2)-1; i++) {
        // Find all the factors:
        for (unsigned int factor = 2; factor*i < sieveChars.size();
                factor++) {
            sieveChars[factor*i] = 'N';
        }
    }

    cout << "Prime:" << endl;

    // Return the index of the first 'p' element:
    unsigned int i = sieveChars.find('p');

    // While not at the end of the string:
    while (i != sieveChars.npos) {
        // If the element is P, the index is a prime
        cout << i << " ";
        // Move past the last prime
        i++;
        // Find the next prime
        i = sieveChars.find('p', i);
    }
    cout << endl << "Not prime:" << endl;

    // Find the first element value not equal p:
    i = sieveChars.find_first_not_of('p');
    while (i != sieveChars.npos) {
        cout << i << " ";
        i++;
        i = sieveChars.find_first_not_of('p', i);
    }

    return 0;
} ///:~
