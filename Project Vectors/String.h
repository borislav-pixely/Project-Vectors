#ifndef _STRING_H
#define _STRING_H

#include <iostream>

class String {

public:
	String(char* = ".");
	String(String&);
	~String();

	String& operator = (const String&);
	String& operator += (const String&);
	String& operator += (int);
	String operator + (const String&) const;
	String operator + (int) const;

	int set_string(char*);
	int set_length(size_t);
	char* get_string() const;
	size_t get_length() const;

private:
	size_t length;
	char* string;

};

std::ostream& operator << (std::ostream&, const String&);
std::istream& operator >> (std::istream&, String&);

#endif