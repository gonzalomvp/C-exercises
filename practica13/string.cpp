#include "stdafx.h"
#include "string.h"

String::String(const char* str) {
	m_p = nullptr;
	Init(str);
}

String::String(const String& str) {
	m_p = nullptr;
	Init(str.ToCString());
}

String::~String() {
	if (m_p) {
		delete[] m_p;
	}
	m_p = nullptr;
}

void String::Init(const char *str)
{
	if (m_p) {
		delete[] m_p;
		m_p = nullptr;
	}
	m_length = 0;

	if (str) {
		m_length = strlen(str);
		char* pString = new char[m_length + 1];
		strcpy(pString, str);
		m_p = pString;
	}
}

bool String::operator==(const String& other) const {
	bool ret = false;
	if (m_length == other.m_length) {
		ret = true;
		for (unsigned int i = 0; i < m_length; i++)
		{
			if ((*this)[i] != other[i]) {
				ret = false;
				break;
			}
		}
	}
	return ret;
}

bool String::operator!=(const String& other) const {
	return !((*this) == other);
}

bool String::operator<(const String& other) const {
	bool ret = false;
	unsigned int lengthToCheck = other.m_length;

	if (m_length < other.m_length) {
		lengthToCheck = m_length;
		ret = true;
	}

	for (unsigned int i = 0; i < lengthToCheck; i++)
	{
		if ((*this)[i] < other[i]) {
			ret = true;
			break;
		}
		else if ((*this)[i] > other[i]) {
			ret = false;
			break;
		}
	}
	return ret;
}

bool String::operator>(const String& other) const {
	return other<*this;
}

String String::operator+(const String& other) const {
	
	char* buffer = new char[m_length + other.m_length + 1];

	for (unsigned int i = 0; i < m_length; i++)
	{
		buffer[i] = (*this)[i];
	}
	for (unsigned int i = 0; i < other.m_length; i++)
	{
		buffer[i + m_length] = other[i];
	}

	buffer[m_length + other.m_length] = '\0';
	String ret(buffer);
	delete[] buffer;

	return ret;
}

String String::operator+(char c) const {
	char* buffer = new char[m_length + 2];

	for (unsigned int i = 0; i < m_length; i++)
	{
		buffer[i] = (*this)[i];
	}

	buffer[m_length] = c;
	buffer[m_length + 1] = '\0';
	String ret(buffer);
	delete[] buffer;

	return ret;
}

String& String::operator=(const String& other) {
	Init(other.ToCString());
	return *this;
}

String& String::operator=(char c) {
	*this = String() + c;
	return *this;
}

String& String::operator+=(const String& other) {
	*this = *this + other;
	return *this;
}

String& String::operator+=(char c) {
	*this = *this + c;
	return *this;
}

char& String::operator[](unsigned int pos) {
	return reinterpret_cast<char*>(m_p)[pos];
}

const char& String::operator[](unsigned int pos) const{
	return reinterpret_cast<char*>(m_p)[pos];
}

int String::Length() const {
	return static_cast<int>(m_length);
}

String String::FromInt(int val) {
	char buffer[sizeof(int) * 8 + 1];
	itoa(val, buffer, 10);
	String ret(buffer);
	return ret;
}

String String::HexFromInt(int val) {
	char buffer[sizeof(int) * 8 + 1];
	itoa(val, buffer, 16);
	String ret(buffer);
	return ret;
}

String String::FromFloat(float val) {
	String ret;
	int size = snprintf(0, 0, "%f", val);
	if (size > 0) {
		unsigned int u_size = static_cast<unsigned int>(size);
		char* buffer = new char[u_size + 1];
		snprintf(buffer, u_size + 1, "%f", val);
		ret = String(buffer);
		delete[] buffer;
	}
	return ret;
}

int String::ToInt() const {
	return atoi(ToCString());
}

float String::ToFloat() const {
	return strtof(ToCString(), nullptr);
}

const char* String::ToCString() const {
	return reinterpret_cast<char*>(m_p);
}

String String::Left(int n) const {
	return Mid(0, n);
}

String String::Right(int n) const {
	return Mid(Length()-n, n);
}

String String::Mid(int ofs, int n) const {
	
	String ret;
	if (ofs < Length()) {
		unsigned int u_ofs = static_cast<unsigned int>(ofs);
		unsigned int u_n = static_cast<unsigned int>(n);

		if (ofs < 0) u_ofs = 0;
		if (n < 0) u_n = 0;
		if (u_ofs + u_n > m_length) u_n = m_length - u_ofs;

		for (unsigned int i = 0; i < u_n; i++)
		{
			ret += (*this)[i + u_ofs];
		}
	}

	return ret;
}

String String::Replace(const String& find, const String& rep) const {
	String ret;
	int offset = 0;
	int index = Find(find, offset);
	while (index != -1) {
		ret += Mid(offset, index - offset) + rep;
		offset = index + find.Length();
		index = Find(find, offset);
	}
	ret += Right(Length() - offset);

	return ret;
}

int String::Find(const String& str, int ofs) const {
	int ret = -1;
	for (int i = ofs; i <= Length() - str.Length(); i++)
	{
		if (Mid(i, str.Length()) == str) {
			ret = i;
			break;
		}
	}
	return ret;
}


String String::ToUpper() const {
	String ret;
	for (unsigned int i = 0; i <= m_length; i++)
	{
		char c = (*this)[i];
		ret += (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c ;
	}
	return ret;
}

String String::ToLower() const {
	String ret;
	for (unsigned int i = 0; i <= m_length; i++)
	{
		char c = (*this)[i];
		ret += (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
	}
	return ret;
}

String String::LTrim() const {
	String ret;
	bool trim = true;
	for (unsigned int i = 0; i < m_length; i++)
	{
		if (!trim || (*this)[i] != ' ') {
			ret += (*this)[i];
			trim = false;
		}
	}
	return ret;
}

String String::RTrim() const {
	String ret;
	bool trim = true;
	for (unsigned int i = 1; i <= m_length; i++)
	{
		if (!trim || (*this)[m_length -i] != ' ') {
			ret = String("") + (*this)[m_length - i] + ret;
			trim = false;
		}
	}
	return ret;
}

String String::Trim() const {
	return LTrim().RTrim();
}

String String::LSet(int len, char c) const {
	String ret;
	for (unsigned int i = 0; i < len - m_length; i++)
	{
		ret += c;
	}
	ret += *this;
	return ret;
}

String String::RSet(int len, char c) const {
	String ret = *this;
	for (unsigned int i = 0; i < len - m_length; i++)
	{
		ret += c;
	}
	return ret;
}

String String::StripExt() const {
	int lastIndex = -1;
	int offset = 0;

	do {
		offset = lastIndex;
		lastIndex = Find(".", offset + 1);
	} while (lastIndex != -1);
	
	return Left(offset);
}

String String::StripDir() const {
	int lastIndex = -1;
	int offset = 0;

	do {
		offset = lastIndex;
		lastIndex = Find("\\", offset + 1);
	} while (lastIndex != -1);

	return Right(Length() - offset - 1);
}

String String::ExtractExt() const {
	int lastIndex = -1;
	int offset = 0;

	do {
		offset = lastIndex;
		lastIndex = Find(".", offset + 1);
	} while (lastIndex != -1);

	return Right(Length() - offset);
}

String String::ExtractDir() const {
	int lastIndex = -1;
	int offset = 0;

	do {
		offset = lastIndex;
		lastIndex = Find("\\", offset + 1);
	} while (lastIndex != -1);

	return Left(offset);
}

String String::Read(const String& filename) {
	String ret;
	FILE* file = fopen(filename.ToCString(), "r");
	if (file) {
		fseek(file, 0, SEEK_END);
		int file_size = ftell(file);
		if (file_size > 0) {
			unsigned int size = static_cast<unsigned int>(file_size);
			fseek(file, 0, SEEK_SET);
			char* buffer = new char[size + 1];
			unsigned int readBytes = fread(buffer, sizeof(char), size, file);
			buffer[readBytes] = '\0';
			ret = String(buffer);
			delete[] buffer;
		}
		fclose(file);
	}
	return ret;
}

void String::Write(const String& filename, bool append) const {
	char* mode = "w";
	if (append) mode = "a";

	FILE* file = fopen(filename.ToCString(), mode);
	if (file) {
		fwrite(this->ToCString(), sizeof(char), m_length, file);
		fclose(file);
	}
}


String operator+(const char* str, const String& other) {
	return String(str) + other;
}