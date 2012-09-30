//: C26:Trace.h
// Creating a trace file
#ifndef TRACE_H_
#define TRACE_H_

#include <fstream>

#ifdef TRACEON
  ofstream TRACEFILE__("TRACE.OUT");   
  #define cout TRACEFILE__
#endif

#endif // TRACE_H ///:~