#ifndef UGINE_STRING_H
#define UGINE_STRING_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class String {
public:
    String(const char* str = "");
    String(const String& str);
    ~String();

    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    bool operator<(const String& other) const;
    bool operator>(const String& other) const;
    String operator+(const String& other) const;
    String operator+(char c) const;
    String& operator=(const String& other);
    String& operator=(char c);
    String& operator+=(const String& other);
    String& operator+=(char c);
    char& operator[](unsigned int pos);
    const char& operator[](unsigned int pos) const;

    int Length() const;

    static String FromInt(int val);
    static String HexFromInt(int val);
    static String FromFloat(float val);

    int ToInt() const;
    float ToFloat() const;
    const char* ToCString() const;

    String Left(int n) const;
    String Right(int n) const;
    String Mid(int ofs, int n) const;
    String Replace(const String& find, const String& rep) const;
    int Find(const String& str, int ofs) const;

    String ToUpper() const;
    String ToLower() const;
    String LTrim() const;
    String RTrim() const;
    String Trim() const;
    String LSet(int len, char c) const;
    String RSet(int len, char c) const;

    String StripExt() const;
    String StripDir() const;
    String ExtractExt() const;
    String ExtractDir() const;
    //String RealPath() const;

    static String Read(const String& filename);
    void Write(const String& filename, bool append = true) const;

private:
	void *m_p;
	unsigned int m_length;

	void Init(const char *str);
};

String operator+(const char* str, const String& other);

#endif