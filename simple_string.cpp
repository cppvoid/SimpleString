#include "simple_string.h"

SimpleString::SimpleString()
    : m_length( 0 ),
      m_string( new char[ m_length + 1 ] )
{
    m_string[ m_length - 1 ] = '\0';
}

SimpleString::SimpleString( char c )
    : m_length( 1 ),
      m_string( new char[ m_length + 1 ] )
{
    m_string[0] = c;
    m_string[1] = '\0';
}

SimpleString::SimpleString( const char* str )
    : m_length( 0 ),
      m_string( nullptr )
{
    /* We have to test whether str is not NULL before
     * we use the function strlen()
     */

    if( str == nullptr )
        throw std::invalid_argument("str is NULL");

    m_length = std::strlen( str );
    m_string = new char[ m_length + 1 ];

    std::strncpy( m_string, str, m_length );
}

SimpleString::SimpleString( const SimpleString& sstring )
    : m_length( sstring.length() ), m_string( new char[ m_length + 1 ] )
{
    std::strncpy( m_string, sstring.cString(), m_length );
}

SimpleString::SimpleString( SimpleString&& sstring )
    : m_length( 0 ), m_string( new char[1] )
{
    m_string[0] = '\0';
    swap( *this, sstring );
}

SimpleString::SimpleString( const std::initializer_list<char>& l )
{
    if( l.size() > 0 )
    {
        m_length = l.size();
        m_string = new char[ l.size() + 1 ];

        std::size_t counter = 0;
        for( const auto& iter : l )
        {
            m_string[counter] = iter;
            ++counter;
        }

        m_string[ m_length + 1 ] = '\0';
    }
    else
    {
        m_length = 0;
        m_string = new char[ m_length + 1 ];
        m_string[0] = '\0';
    }
}

SimpleString::~SimpleString()
{
    delete[] m_string;
}

SimpleString& SimpleString::operator=( char c )
{
    delete[] m_string;

    m_length = 1;
    m_string = new char[ m_length + 1 ];
    m_string[0] = c;
    m_string[1] = '\0';

    return *this;
}

SimpleString& SimpleString::operator=( const char* str )
{
    if( str == nullptr )
        throw std::invalid_argument("str is NULL");

    m_length = std::strlen( str );
    delete[] m_string;

    m_string = new char[ m_length + 1 ];
    std::strncpy( m_string, str, m_length );

    return *this;
}

SimpleString& SimpleString::operator=( SimpleString sstring )
{
    swap( *this, sstring );
    return *this;
}

SimpleString& SimpleString::operator=( SimpleString&& sstring )
{
    if( this != &sstring )
    {
        clear();
        swap( *this, sstring );
    }
    return *this;
}

SimpleString& SimpleString::operator+( const SimpleString& sstring )
{
    m_length += sstring.length();
    std::strcat( m_string, sstring.cString() );
    return *this;
}

SimpleString& SimpleString::operator+( char c )
{
    char str[2] = { c, '\0' };
    m_length++;
    std::strcat( m_string, str );

    return *this;
}

SimpleString& SimpleString::operator+( const char* str )
{
    if( str == nullptr )
        throw std::invalid_argument("str is NULL");

    m_length += std::strlen( str );

    std::strcat( m_string, str );
    return *this;
}

SimpleString& SimpleString::operator+=( const SimpleString& sstring )
{
    m_length += sstring.length();
    std::strcat( m_string, sstring.cString() );
    return *this;
}

SimpleString& SimpleString::operator+=( char c )
{
    m_length++;
    char str[2] = { c, '\0' };
    std::strcat( m_string, str );

    return *this;
}

SimpleString& SimpleString::operator+=( const char* str )
{
    if( str == nullptr )
        throw std::invalid_argument("str is NULL");

    m_length += std::strlen( str );
    std::strcat( m_string, str );
    return *this;
}

char& SimpleString::operator[]( std::size_t pos )
{
    if( pos > m_length )
        throw std::range_error( "pos < length" );

    return m_string[pos];
}

const char& SimpleString::operator[]( std::size_t pos ) const
{
    if( pos > m_length )
        throw std::range_error( "pos < length" );

    return m_string[pos];
}

void SimpleString::clear()
{
    m_length = 0;
    delete[] m_string;

    m_string = new char[ m_length + 1 ];
    m_string[0] = '\0';
}

bool SimpleString::empty() const
{
    return m_string[0] == '\0';
}

void swap( SimpleString& lhs, SimpleString& rhs )
{
    std::swap( lhs.m_length, rhs.m_length );
    std::swap( lhs.m_string, rhs.m_string );
}

char* const SimpleString::cString() const
{
    return m_string;
}

std::size_t SimpleString::length() const
{
    return m_length;
}

std::ostream& operator<<( std::ostream& out, const SimpleString& sstring )
{
    out << sstring.m_string;
    return out;
}

std::istream& operator>>( std::istream& in, SimpleString& sstring )
{
    in >> sstring.m_string;
    return in;
}

bool operator==( const SimpleString& lhs, const SimpleString& rhs )
{
    return std::strcmp( lhs.cString(), rhs.cString() );
}

bool operator==( const char* lhs, const SimpleString& rhs )
{
    return std::strcmp( lhs, rhs.cString() );
}

bool operator==( const SimpleString& lhs, const char* rhs )
{
    return std::strcmp( lhs.cString(), rhs );
}

bool operator!=( const SimpleString& lhs, const SimpleString& rhs )
{
    return !( lhs == rhs );
}

bool operator!=( const char* lhs, const SimpleString& rhs )
{
    return !( lhs == rhs );
}

bool operator!=( const SimpleString& lhs, const char* rhs )
{
    return !( lhs == rhs );
}

bool operator<( const SimpleString& lhs, const SimpleString& rhs )
{
    return lhs.length() < rhs.length();
}

bool operator<(const char* lhs, const SimpleString& rhs )
{
    if( lhs == nullptr )
        throw std::invalid_argument("lhs is NULL");

    return std::strlen( lhs ) < rhs.length();
}

bool operator<( const SimpleString& lhs, const char* rhs )
{
    if( rhs == nullptr )
        throw std::invalid_argument("rhs is NULL");

    return lhs.length() < std::strlen( rhs );
}

bool operator<=( const SimpleString& lhs, const SimpleString& rhs )
{
    return lhs.length() <= rhs.length();
}

bool operator<=( const char* lhs, const SimpleString& rhs )
{
    if( lhs == nullptr )
        throw std::invalid_argument("lhs is NULL");

    return std::strlen( lhs ) <= rhs.length();
}

bool operator<=( const SimpleString& lhs, const char* rhs )
{
    if( rhs == nullptr )
        throw std::invalid_argument("rhs is NULL");

    return lhs.length() <= std::strlen( rhs );
}

bool operator>( const SimpleString& lhs, const SimpleString& rhs )
{
    return lhs.length() > rhs.length();
}

bool operator>( const char* lhs, const SimpleString& rhs )
{
    if( lhs == nullptr )
        throw std::invalid_argument("lhs is NULL");

    return std::strlen( lhs ) > rhs.length();
}

bool operator>( const SimpleString& lhs, const char* rhs )
{
    if( rhs == nullptr )
        throw std::invalid_argument("rhs is NULL");

    return lhs.length() > std::strlen( rhs );
}

bool operator>= (const SimpleString& lhs, const SimpleString& rhs)
{
    return lhs.length() >= rhs.length();
}

bool operator>= (const char*   lhs, const SimpleString& rhs)
{
    if( lhs == nullptr )
        throw std::invalid_argument("lhs is NULL");

    return std::strlen( lhs ) >= rhs.length();
}

bool operator>= (const SimpleString& lhs, const char*   rhs)
{
    if( rhs == nullptr )
        throw std::invalid_argument("rhs is NULL");

    return lhs.length() >= std::strlen( rhs );
}
