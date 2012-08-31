//: C19:Fullwrap.h
// Completely hidden file IO
#ifndef FULLWRAP_H_INCLUDED
#define FULLWRAP_H_INCLUDED

class File {
public:
    File(); // Create object but don't open file
    File(const char* path, const char* mode = "r");
    ~File();
    int open(const char* path, const char* mode);
    int reopen(const char* path, const char* mode);
    int getc();
    int ungetc(int c);
    int putc(int c);
    int puts(const char* s);
    char* gets(char* s, int n);
    int printf(const char* format, ...);
    size_t read(void* ptr, size_t size, size_t n);
    size_t write(const void* ptr, size_t size, size_t n);
    int eof();
    int close();
    int flush();
    int seek(long offset, int whence);
    int getpos(fpos_t* pos);
    int setpos(const fpos_t* pos);
    int tell();
    void rewind();
    void set buf(char* buf);
    int setvbuf(char* buf, int type, size_t sz);
    int error();
    void Clearerr();
private:
    std::FILE* f;
    std::FILE* F(); // Produces checked pointer to f
};

#endif // FULLWRAP_H_INCLUDED
