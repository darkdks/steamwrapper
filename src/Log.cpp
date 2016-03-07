#include "log.h"

#include <fstream>
#include <iostream>
#include <ctime>



Log::Log(char* filename) {
  m_stream.open(filename);
}

void Log::Write(char* logline){
	//m_stream << logline << endl;
	time_t now = time(0);
	struct tm* tm = localtime(&now);   
	m_stream << tm->tm_year+1900 << '/' << tm->tm_mon << '/' << tm->tm_mday
         << ' ' << tm->tm_hour << ':' << tm->tm_min << ':' << tm->tm_sec << ": ";
    m_stream << logline << "\n";
/*	time_t now = time(0);
    struct tm* tm = localtime(&now);    
    ofstream out( "logfile.txt",ios::ate);
    out << tm->tm_year << '/' << tm->tm_mon << '/' << tm->tm_mday
         << ' ' << tm->tm_hour << ':' << tm->tm_min << ':' << tm->tm_sec << ": ";
    out << logline << "\n";
    out.close(); */   
}

Log::~Log(){
  m_stream.close();
}


//Using the following modification to Write function, you can create a C++ variadic function. This should allow you to avoid using sprintf every time.
//
//#include <stdarg.h>
//
//void Log::Write(const char* logline, ...){
//  va_list argList;
//  char cbuffer[1024];
//  va_start(argList, logline);
//  vsnprintf(cbuffer, 1024, logline, argList);
//  va_end(argList);
//  m_stream << cbuffer << endl;
//}