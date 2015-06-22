#pragma once

#include <string>
#include <exception>

class IndexSearchException: public std::exception {
    public:
        IndexSearchException(const char* msg) : mMsg(msg) {}
        virtual ~IndexSearchException() throw() {}
        const char* what() const throw()  {return mMsg.c_str();}
    protected:
        std::string mMsg;
};
