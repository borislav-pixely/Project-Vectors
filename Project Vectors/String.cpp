#include "String.h"

String::String(char* string) {
	if (string == ".") {
		length = 0;
	} else {
		try {
			length = strlen(string);
			this->string = new char[length + 1];
			for (size_t i = 0; i < length; i++)
				this->string[i] = string[i];
			this->string[length] = '\0';
		} catch (...) {
			length = 5;
			this->string = "Error";
		}
		
	}
}

String::String(String& right) {
	length = right.length;
	string = new char[length + 1];
	for (size_t i = 0; i < length; i++)
		string[i] = right.string[i];
	string[length] = '\0';
}

String::~String() {
	if (length != 0)
		delete[] string;
}

String& String::operator = (const String& right) {
	if (this != &right) {
		length = right.length;
		delete[] string;
		string = new char[length + 1];
		for (size_t i = 0; i < length; i++)
			string[i] = right.string[i];
		string[length] = '\0';
	}
	return *this;
}

String& String::operator += (const String& right) {
	char* temp = new char[length + right.length + 1];
	for (size_t i = 0; i < length; i++)
		temp[i] = string[i];
	for (size_t i = 0, j = length; i < right.length; i++)
		temp[j++] = right.string[i];
	length += right.length;
	temp[length] = '\0';
	delete[] string;
	string = new char[length + 1];
	for (size_t i = 0; i < length; i++)
		string[i] = temp[i];
	string[length] = '\0';
	delete[] temp;
	return *this;
}

String& String::operator += (int value) {
	size_t size = 0;
	size_t tempValue = value;
	for (; tempValue > 10; tempValue /= 10, size++);
	char* temp = new char[size + 2];
	for (int i = size; i >= 0; i--) {
		temp[i] = '0' + (value % 10);
		value /= 10;
	}
	temp[size + 1] = '\0';
	String TMP(temp);
	TMP.set_length(size + 4);
	delete[] temp;
	*this += TMP;
	return *this;
}

String String::operator + (const String& right) const {
	char* temp = new char[length + right.length + 1];
	for (size_t i = 0; i < length; i++)
		temp[i] = string[i];
	for (size_t i = 0, j = length; i < right.length; i++)
		temp[j++] = right.string[i];
	temp[length + right.length] = '\0';
	String TMP(temp);
	delete[] temp;
	return TMP;
}

String String::operator + (int value) const {
	size_t size = 0;
	size_t tempValue = value;
	while (tempValue > 10) {
		tempValue /= 10;
		size++;
	}
	char* temp = new char[size + 2];
	for (int i = size; i >= 0; i--) {
		temp[i] = '0' + (value % 10);
		value /= 10;
	}
	temp[size + 1] = '\0';
	String TMP_R(temp);
	TMP_R.set_length(size + 4);
	delete[] temp;
	String TMP(this->get_string());
	TMP += TMP_R;
	return TMP;
}

int String::set_string(char* string) {
	this->length = strlen(string);
	delete[] this->string;
	this->string = new char[length + 1];
	for (size_t i = 0; i < length; i++)
		this->string[i] = string[i];
	this->string[length] = '\0';
	return 0;
}

int String::set_length(size_t length) {
	this->length = length;
	return 0;
}

char* String::get_string() const {
	return string;
}

size_t String::get_length() const {
	return length;
}

std::ostream& operator << (std::ostream& out, const String& object) {
	out << object.get_string();
	return out;
}

std::istream& operator >> (std::istream& in, String& object) {
	char* temp = new char[1024];
	in >> temp;
	object.set_string(temp);
	delete[] temp;
	return in;
}