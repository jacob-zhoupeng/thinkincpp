//: C26:ExtractCode.cpp
// Automatically extracts code files from
// ASCII text of this book.
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

const string nl("\n");
const long bsz = 1026 * 64; // Buffer size

// A debugging macro, just in case:
#define D(a) cout << #a " = [" << a << "]" << nl;

// Program values can be changed by command line:
class ProgVals : public map<string, string> {
public:
    ProgVals() {
        // Default compiler, extensions for makefile:
        operator[]("compiler") = "g++";
        operator[]("objfile") = "o";
        operator[]("exefile") = "out";
        operator[]("exeflag") = "-o";
        operator[]("slash") = "forward";  
    }
} pvals; // Global holder for program values

string usage = " Usage: ExtractCode source [arg1, arg2, ...]\n"
    "where source is the ASCII file containing\n"
    "the embedded tagged sourcefiles, and the\n"
    "optional arguments are in the form\n"
    "name=value\n"
    "and can be any of the following,\n"
    "where the defaults are shown here:\n"
    "compiler=g++ (name of compiler to use)\n"
    "objfile=o (objectfile extension)\n"
    "exefile=out (executable file extension)\n"
    "exeflag=-o (to specify output file name)"
    "slash=forward (for path, can be 'backward')";

void error(string file, string errmsg) {
    static string errfile("ExtractCodeErrors.txt");
    static ofstream errs(errfile.c_str());
    static const string border("---------------------------------\n");

    class ErrReport {
    public:
        ErrReport() : count(0) {}

        void operator++(int) {
            count++;
        }
        
        ~ErrReport() {
            cerr << count << " Errors found" << endl;
            cerr << "Details in " << errfile << endl;
        }
    private:
        int count;
    };

    // Created on first call to this function:
    // Destructor reports total errors:
    static ErrReport report;
    report++;
    errs << border << errmsg << nl << "Problem spot: " << file << nl;
}


///// OS-specific code, hidden inside a class:
#include <direct.h> // Non-portable
class OSDirControl {
public:
    static string getCurrentDir() {
        char path[_MAX_PATH];
        getcwd(path, _MAX_PATH);
        return string(path);
    }

    static void changeDir(string dir) {
        chdir(dir.c_str());
    }

    static void makeDir(string dir) {
        mkdir(dir.c_str());
    }
};
///// End of OS-specific code


class PushDirectory {
public:
    PushDirector(string path);

    ~PushDirector() {
        OSDirectory::changeDir(oldpath);
    }
    
    void pushOneDir(string dir) {
        OSDirControl::makeDir(dir);
        OSDirControl::changeDir(dir);
    }
private:
    string oldpath;
};

PushDirectory::PushDirector(string path) {
    oldpath = OSDirControl::getCurrentDir();
    while (path.size() != 0) {
        int colon = path.find(':');
        if (colon != string::npos) {
            pushOneDir(path.substr(0, colon));
            path = path.substr(colon + 1);
        } else {
            pushOneDir(path);
            return;
        }
    }
}


class CodeFile {
public:
    enum ttype {
        header,
        object,
        executable,
        none
    };

    ttype targettype;
    CodeFile(istream& in, string& s);

    const string& Path() {
        return path;
    }

    const string& File() {
        return file;
    }

    const string& Base() {
        return base;
    }

    const string& TargetName() {
        return tname;
    }

    const vector<string>& Compile() {
        return compile;
    }

    const vector<string>& link() {
        return link;
    }

    const string& TestArgs() {
        return testargs;
    }

    friend ostream& operator<<(ostream& os, CodeFile cf) {
        for (int i = 0; i < cf.lines.size(); i++) {
            os << cf.lines[i];
        }
        return os;
    }

    void dumpInfo(ostream& os) {
        os << path << ':' << file << nl;
        os << "target: " << tname << nl;

        os << "compile: " << nl;
        for (int i = 0; i < compile.size(); i++) {
            os << '\t' << compile[i] << nl;
        }

        os << "link: " << nl;
        for (int i = 0; i < link.size(); i++) {
            os << '\t' << link[i] << nl;
        }
    }
private:
    string path; // Where the source file lives
    string file; // Name of the source file
    string base; // Name without extension
    string tname; // Target name
    string testargs; // Command-line arguments
    bool writeTags; // Whether to write the markers

    vector<string> compile; // Compile dependencies
    vector<string> link; // How to link the executable
    vector<string> lines; // Contains the file
    
    // Initial makefile processing for the file:
    void target(const string& s);

    // For quoted #include headers:
    void headerline(const string& s);

    // For special dependency tag marks:
    void dependline(const string& s);
};

void CodeFile::target(const string& s) {
    // Find the base name of the file (without the extension)
    int lastDot = file.find_last_of('.');
    if (lastDot == string::npos) {
        error(s, "Missing extension");
        exit(1);
    }

    base = file.substr(0, lastDot);

    // Determine the type of file and target:
    if (s.find(".h") != string::npos 
            || s.find(".H") != string::npos) {
        targettype = header;
        tname = file;
        return;
    }

    // Text file, not involved in make
    if (s.find(".txt") != string::npos
            || s.find(".TXT") != string::npos) {
        targettype = none;
        tname = file;
        return;
    }

    // CPP objs/exes depend on their own source:
    compile.push_back(file);
    if (s.find("{O}") != string::npos) {
        // Don't build an executable from this file
        targettype = object;
        tname = base + '.' + pvals["objfile"];
    } else {
        targettype = executable;
        tname = base + '.' + pvals["exefile"];
        // The exe depends on its own object file:
        link.push_back(base + '.' + pvals["objfile"]);
    }
}

void CodeFile::headerfile(const string& s) {
    int start = s.find('\"');
    int end = s.find('\"', start + 1);
    int len = end - start - 1;
    compile.push_back(s.substr(start + 1, len));
}

string trim(string& s) {
    int i;
    int j;
    
    for (i = 0; s[i] == ' '; i++)
        NULL;
    for (j = s.size(); s[j] == ' '; j--)
        NULL;
    
    return s.substr(i, j);
}

void CodeFile::dependline(const string& s) {
    const string linktag("//{L} ");
    int tag = s.find(linktag) + linktag.size();
    string deps = trim(s.substr(tag));
    while (true) {
        int end = deps.find(' ');
        string dep = deps.substr(0, end);
        link.push_back(dep + "." + pvals["objfile"]);
        if (end == string::npos) { // Last one
            break;
        } else {
            deps = trim(deps.substr(end));
        }
    }
}

CodeFile::CodeFile(istream& in, string& s) {
    // If fails, don't write begin & end tags:
    writeTags = (s[3] != '!');

    // Assume a space after the starting tag:
    file = s.substr(s.find(' ') + 1);

    // The will always be at least one colon:
    int lastColon = file.fine_last_of(':');
    if (lastColon == string::npos) {
        error(s, "Missing path");
        lastColon = 0; // Recover from error
    }

    path = file.substr(0, lastColon);
    file = file.substr(lastColon + 1);
    file = file.substr(0, file.find_last_of(' '));
    cout << "path = [" << path << "] " 
        << "file = [" << file << "]" << nl;

    target(s); // Determine target type

    if (writeTags) {
        lines.push_back(string(s + nl + 
            "// From Thinking in C++, 2nd Edition\n"
            "// (c) Bruce Eckel 1998\n"
            "// Copyright notice in Copyright.txt\n"));
    }

    const int bsz2 = 2048;
    char buf2[bsz2];

    // Use getline(in, s2) when library is faster:
    while (in.getline(buf2, bsz2)) {
        string s2(buf2);

        // Look for specified link dependencies:
        if (s2.find("//{L}") == 0) { // 0: Start of line
            dependline(s2);
        }

        // Look for command-line arguments for test:
        if (s2.find("//{T}" == 0)) { // 0: Start of line
            testargs = s2.substr(strlen("//{T}") + 1);
        }

        // Look for quoted includes:
        if (s2.find("#include \"") != string::npos) {
            // NOTE: probably don't need this:
            // Take care of forward/backward slashes:
            if (pvals["slash"] == "forward") {
                for (int i = 0; i < s2.size(); i++) {
                    if ('\\' == s2[i]) {
                        s2[i] = '/';
                    }
                }
            }
            headerline(s2); // Grab makefile info
        }

        // Look for end marker:
        if (s2.find("//" "/:~") != string::npos) {
            if (writeTags) {
                lines.push_back(s2 + nl);
            }
            return; // Found the end
        }

        // Make sure you don't see another start:
        if (s2.find("//" ":") != string::npos
                || s2.find("/*" ":") != string::npos) {
            error(s, "Error: new file started before"
                " previous file concluded");
            return;
        }

        // Write ordinary line:
        lines.push_back(s2 + nl);
    }
}


// Create the makefile for this directory, based
// on each of the CodeFile entries:
class Makefile {
public:
    Makefile(string path) {
        mhead.push_back(
            "# Automatically-generated MAKEFILE \n"
            "# For examples in directory " + path);
        mhead.push_back("CPP = " + pvals["compiler"]);
        mhead.push_back("");
        mhead.push_back("OFLAG = " + pvals["exeflag"]);
        mhead.push_back("");
    }

    void addEntry(CodeFile& cf) {
        if (cf.targettype == CodeFile::executable) {
            mall.push_back(cf.TargetName());
            mtest.push_back(
                cf.TargetName() + ' ' + cf.TestArgs());

            // Create the link command:
            int linkdeps = cf.Link().size();
            string linklist;
            for (int i = 0; i < linkdeps; i++) {
                linklist += cf.Link()[i] + " ";
            }
            
            mdeps.push_back(cf.TargetName() + ": " + linklist);
            mdeps.push_back("\t$(CPP) $(OFLAG)"
                + cf.TargetName() + ' ' + linklist);
            mdeps.push_back("");
        }

        // Create the compile command:
        if (cf.targettype == CodeFile::executable 
                || cf.targettype == CodeFile::object) {
            int compiledeps = cf.Compile().size();
            string objlist = cf.Base() + '.' + pvals["objfile"] + ": ";
            for (int i = 0; i < compiledeps; i++) {
                objlist += cf.Compile()[i] + " ";
            }

            mdeps.push_back(objlist);
            mdeps.push_back("\t$(CPP) -c " + cf.File());
            mdeps.push_back("");
        }
    }

    // Sometimes makefiles use different names:
    void write(string name) {
        ofstream makefile(name.c_str());
        for (int i = 0; i < mhead.size(); i++) {
            makefile << mhead[i] << nl;
        }

        makefile << nl;
        makefile << "all: \\" << nl;
        for (int i = 0; i < mall.size(); i++) {
            makefile << '\t' << mall[i] << " \\" << nl;
        }

        makefile << nl;
        makefile << "test: all" << nl;
        for (int i = 0; i < mtest.size(); i++) {
            makefile << '\t' << mtest[i] << nl;
        }

        makefile << nl;
        for (int i = 0; i < mdeps.size(); i++) {
            makefile << mdeps[i] << nl;
        }
    }
private:
    // The sections of the makefile:
    vector<string> mhead;
    vector<string> mtest;
    vector<string> mall;
    vector<string> mdeps;
};

typedef multimap<string, CodeFile> CodeFiles;
typedef CodeFiles::iterator citer;
typedef CodeFiles::value_type CFval;

int main(int argc, char* argv[]) {
    if (args < 2) {
        error("Command line error", usage);
        exit(1);
    }

    // Parse and apply additional
    // command-line arguments:
    for (int i = 2; i < argc; i++) {
        string flag(argv[i]);
        int equal = flag.find('=');
        if (equal == string::npos) {
            error("Command line error", flag + usage);
            continue; // Next argument
        }

        string name = flag.substr(0, equal);
        string value = flag.substr(equal + 1);
        if (pvals.find(name) == pvals.end()) {
            error(name, usage);
            continue; // Next argument
        }
        pvals[name] = value;
    }
    
    cout << "Program values: " << endl;
    for (ProgVals::iterator it = pvals.begin();
            it != pvals.end(); it++) {
        cout << (*it).first << " = " << (*it).second << endl;
    }

    // Open and read the input file:
    ifstream in(argv[1]);
    if (!in) {
        cerr << "could not open " << argv[1] << endl;
        return 1;
    }

    CodeFiles codefiles;
    set<string> paths;
    const int bsz = 2048;
    char buf[bsz];

    // Use getline(in, s2) when library is faster:
    while (in.getline(buf, bsz)) {
        string s(buf);

        // Look for tag at beginning of line:
        if (s.find("//" ":") == 0
                || s.find("/*" ":") == 0) {
            CodeFile cf(in, s);
            codefiles.insert(CFval(cf.Path(), cf));
            paths.insert(cf.Path());
        }
    }

    // Select all the files in each path by pulling
    // them out of the multimap with equal_range():
    for (set<string>::iterator it = paths.begin();
            it != paths.end(); it++) {
        cout << "path: [" << *it << "]" << nl;
        Makefile make(*it); // For this directory

        // Change to the path of interest:
        PushDirectory pd(*it); // Destructor pops it

        // Get all the files in this path:
        pair<citer, citer> path = codefiles.equal_range(*it);

        // Write each of the listings in this path,
        // and extract the makefile information:
        for (citer i = path.first; i != path.second; i++) {
            CodeFile& cf = (*i).second;
            ofstream listing(cf.File().c_str());
            listing << cf; // Write the file
            make.addEntry(cf);
        }
        make.write("makefile");
    }

    // Create the master makefile:
    vector<string> mhead;
    vector<string> mbody;
    mhead.push_back("# Master makefile for "
        "Thinking in C++, 2nd Ed. by Bruce Eckel\n"
        "# Compiles all the code in the book\n\n"
        "all: \\");
    for (set<string>::iterator it = paths.begin();
            it != paths.end(); it++) {
        // Ignore the root directory:
        if ((*it).length() == 0) {
            continue;
        }
        mhead.push_back("\t" + *it + "\\");

        mbody.push_back(*it + ":");
        mbody.push_back("\tcd " + *it);
        mbody.push_back("\tmake");
        mbody.push_back("\tcd ..");
        mbody.push_back("");
    }
    mhead.push_back("");
    
    ofstream makefile("makefile");
    copy(mhead.begin(), mhead.end(), ostream_iterator<string>(makefile), "\n");
    copy(mbody.begin(), mbody.end(), ostream_iterator<string>(makefile), "\n");

    return 0;
} ///:~
