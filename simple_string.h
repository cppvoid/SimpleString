#ifndef SIMPLE_SimpleString_H
#define SIMPLE_SimpleString_H

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <initializer_list>

class SimpleString
{
public:
    SimpleString();

    SimpleString( char c );

    SimpleString( const char* str );

    SimpleString( const SimpleString& sstring );

    SimpleString( SimpleString&& sstring );

    SimpleString( const std::initializer_list<char>& l );

    ~SimpleString();

    SimpleString& operator=( char c );

    SimpleString& operator=( const char* str );

    SimpleString& operator=( SimpleString sstring );

    SimpleString& operator=( SimpleString&& sstring );

    SimpleString& operator+( const SimpleString& sstring );

    SimpleString& operator+( char c );

    SimpleString& operator+( const char* str );

    SimpleString& operator+=( const SimpleString& sstring );

    SimpleString& operator+=( char c );

    SimpleString& operator+=( const char* str );

    char& operator[]( std::size_t pos );

    const char& operator[]( std::size_t pos ) const;

    void clear();

    bool empty() const;

    char* const cString() const;

    std::size_t length() const;

    friend void swap( SimpleString& lhs, SimpleString& rhs );

    friend std::ostream& operator<<( std::ostream& out, const SimpleString& sstring );

    friend std::istream& operator>>( std::istream& in, SimpleString& sstring );

private:
    std::size_t m_length;

    char* m_string;
};

bool operator==( const SimpleString& lhs, const SimpleString& rhs );
bool operator==( const char* lhs, const SimpleString& rhs );
bool operator==( const SimpleString& lhs, const char*   rhs );

bool operator!=( const SimpleString& lhs, const SimpleString& rhs );
bool operator!=( const char* lhs, const SimpleString& rhs );
bool operator!=( const SimpleString& lhs, const char*   rhs );

bool operator<( const SimpleString& lhs, const SimpleString& rhs );
bool operator<( const char* lhs, const SimpleString& rhs );
bool operator<( const SimpleString& lhs, const char*   rhs );

bool operator<=( const SimpleString& lhs, const SimpleString& rhs );
bool operator<=( const char* lhs, const SimpleString& rhs );
bool operator<=( const SimpleString& lhs, const char*   rhs );

bool operator>( const SimpleString& lhs, const SimpleString& rhs );
bool operator>( const char* lhs, const SimpleString& rhs );
bool operator>( const SimpleString& lhs, const char*   rhs );

bool operator>=( const SimpleString& lhs, const SimpleString& rhs );
bool operator>=( const char* lhs, const SimpleString& rhs );
bool operator>=( const SimpleString& lhs, const char* rhs );


#endif // SIMPLE_SimpleString_H
