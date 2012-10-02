//: C26:CGI_GET.cpp
// Tests CGImap by extracting the information
// from a CGI GET submitted by an HTML Web page.
#include "CGImap.h"

int main(int argc, char* argv[]) {
    // You MUST print this out, otherwise the
    // server will not send the response:
    cout << "Content-type: text/plain\n" << endl;

    // For a CGI "GET," the server puts the data
    // in the environment variable QUERY_STRING:
    CGImap query(getenv("QUERY_STRING"));

    // Test: dump all names and values
    for (CGImap::iterator it = query.begin(); it != query.end(); it++) {
        cout << (*it).first << " = " << (*it).second << endl;
    }

    return 0;
} ///:~