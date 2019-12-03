#ifndef LOGSTREAM_H
#define LOGSTREAM_H

#include <iostream>
#include <string>

namespace J
{

enum Severity { NONE, INFO, WARNING, ERROR, FATAL };

class LogStream
{
public:
    LogStream() {}
    virtual ~LogStream()
    {
        std::cerr << std::endl;
    }
};

inline const LogStream& operator<<(const LogStream& stream, const char* value)
{
    std::cerr << value;
    return stream;
}

inline const LogStream& operator<<(const LogStream& stream, std::string value)
{
    std::cerr << value;
    return stream;
}   

const LogStream& operator<<(const LogStream& stream, bool value)
{
    std::cerr << (value ? "true " : "false ");
    return stream;
}

const LogStream& operator<<(const LogStream& stream, int value)
{
    std::cerr << value;
    return stream;
}

const LogStream& operator<<(const LogStream& stream, unsigned int value)
{
    std::cerr << value;
    return stream;
}

LogStream dbg(Severity s = NONE)
{
    LogStream stream;
    std::string msg;
    switch (s)
    {
    case INFO:
        msg = "[INFO] ";
        break;
    case WARNING:
        msg = "[WARNING] ";
        break;
    case ERROR:
        msg = "[ERROR] ";
        break;
    case FATAL:
        msg = "[FATAL] ";
        break;
    case NONE:
    default:
        msg = "";
    }
    stream << msg;
    return stream; 
}

}

#endif // LogStream.h
