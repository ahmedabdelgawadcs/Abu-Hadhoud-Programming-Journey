#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

enum enCharsType {small_letters, capital_letters, all};

const char VOWELS[5] = { 'a', 'e', 'o', 'i', 'u' };

class clsString {
	string _str;
	int _length = 0;

public:
	clsString(string str = "") {
		_str = str;
		_length = str.length();
	}

	void set_str(string str) {
		_str = str;
		_length = str.length();
	}

	string get_str() {
		return _str;
	}

	__declspec(property(put = set_str, get = get_str)) string val;

	int get_length() {
		return _length;
	}
	
	__declspec(property(get = get_length)) int length;

	static int count_words(string str, string delim = " ") {
		int counter = 0;
		short pos = 0;
		string word;

		while ((pos = str.find(delim)) != string::npos) {
			word = str.substr(0, pos);

			if (word != "")
				counter++;

			str.erase(0, pos + delim.length());
		}

		if (str != "")
			counter++;

		return counter;
	}

	int count_words(string delim = " ") {
		return count_words(_str, delim);
	}

	static vector<string> split(string str, string delim) {
		string word;
		vector<string> vWords;
		short pos = 0;

		while ((pos = str.find(delim)) != string::npos) {
			word = str.substr(0, pos);

			if (word != "")
				vWords.push_back(word);

			str.erase(0, pos + delim.length());
		}

		if (str != "")
			vWords.push_back(str);

		return vWords;
	}

	static vector<string> split(string str, char delim) {
		return split(str, to_string(delim));
	}

	vector<string> split(string delim) {
		return split(_str, delim);
	}

	vector<string> split(char delim) {
		return split(_str, delim);
	}

	static string join(const vector<string>& vWords, string delim) {
		if (vWords.empty())
			return "";
		
		string str;

		for (const string& v : vWords)
			str += v + delim;

		str.erase(str.length() - delim.length());

		return str;
	}

	static string join(const string words[], int length, string delim) {
		if (length == 0)
			return "";
		
		string str;

		for (int i = 0; i < length; i++)
			str += words[i] + delim;

		str.erase(str.length() - delim.length());

		return str;
	}

	static string join(const vector<string>& vWords, char delim) {
		return join(vWords, to_string(delim));
	}

	static string join(const string words[], int length, char delim) {
		return join(words, length, to_string(delim));
	}

	static string to_upper_case(string &str) {
		string uppered;

		for (char& s : str)
			uppered += toupper(s);

		return str = uppered;
	}

	string to_upper_case() {
		return to_upper_case(_str);
	}

	static string to_lower_case(string &str) {
		string lowered;

		for (char& s : str)
			lowered += tolower(s);

		return str = lowered;
	}

	string to_lower_case() {
		return to_lower_case(_str);
	}

	static string trim_left(string &str) {
		for (short i = 0; i < str.length(); i++)
			if (str[i] != ' ')
				return str = str.substr(i);

		return str;
	}

	string trim_left() {
		return trim_left(_str);
	}

	static string trim_right(string &str) {
		for (short i = str.length() - 1; i >= 0; i--)
			if (str[i] != ' ')
				return str = str.substr(0, ++i);

		return str;
	}

	string trim_right() {
		return trim_right(_str);
	}

	static string trim(string &str) {
		trim_left(str);
		return trim_right(str);
	}

	string trim() {
		return trim(_str);
	}

	static string reverse_str(string &str) {
		string reversed;
		
		for (short i = str.length() - 1; i >= 0; i--)
			reversed += str[i];

		return str = reversed;
	}

	string reverse_str() {
		return reverse_str(_str);
	}

	static string reverse_words(string &str, string delim) {
		vector<string> vWords = split(str, delim);
		vector<string>::iterator iter = vWords.end() - 1;
		string reversed;

		for (; iter > vWords.begin(); iter--)
			reversed += *iter + delim;

		return str = reversed.substr(0, reversed.length()) + delim + *iter;
	}

	string reverse_words(string delim) {
		return reverse_words(_str, delim);
	}

	string reverse_words(char delim = ' ') {
		return reverse_words(_str, to_string(delim));
	}

	static string replace_all(string &str, string search_val, string replace_val) {
		short pos;

		while ((pos = str.find(search_val)) != string::npos)
			str.replace(pos, search_val.length(), replace_val);

		return str;
	}

	string replace_all(string search_val, string replace_val) {
		return replace_all(_str, search_val, replace_val);
	}

	static void first_letters(string str) {
		vector<string> vWords = split(str, ' ');

		for (string& v : vWords)
			cout << v[0] << ' ';
	}

	void first_letters() {
		first_letters(_str);
	}

	static string capitalize(string &str) {
		vector<string> vWords = split(str, ' ');
		
		for (string& v : vWords)
			v = char(toupper(v[0])) + v.substr(1);

		return str = join(vWords, ' ');
	}

	string capitalize() {
		return capitalize(_str);
	}

	static string lower_firsts(string &str) {
		vector<string> vWords = split(str, ' ');

		for (string& v : vWords)
			v = char(tolower(v[0])) + v.substr(1);
		
		return str = join(vWords, ' ');
	}

	string lower_firsts() {
		return lower_firsts(_str);
	}

	static int count_capitals(string str) {
		int counter = 0;

		for (char s : str)
			if (isupper(s))
				counter++;

		return counter;
	}

	int count_capitals() {
		return count_capitals(_str);
	}

	static int count_smalls(string str) {
		int counter = 0;

		for (char s : str)
			if (islower(s))
				counter++;

		return counter;
	}

	int count_smalls() {
		return count_smalls(_str);
	}

	static int freq_of(string str, char ch, bool match_case = true) {
		int counter = 0;

		for (char s : str)
			if (!match_case && tolower(s) == tolower(ch) || match_case && s == ch)
				counter++;

		return counter;
	}

	int freq_of(char ch, bool match_case) {
		return freq_of(_str, ch, match_case);
	}

	static bool isvowel(char ch) {
		ch = tolower(ch);
		
		for (const char v : VOWELS)
			if (v == ch)
				return true;

		return false;
	}

	static int count_vowels(string str) {
		int counter = 0;
		
		for (char s : str)
			if (isvowel(s))
				counter++;

		return counter;
	}

	int count_vowels() {
		return count_vowels(_str);
	}

	static int count_letters(string str, enCharsType chars_type) {
		switch (chars_type) {
		case small_letters:
			return count_smalls(str);
		case capital_letters:
			return count_capitals(str);
		}

		return str.length();
	}

	int count_letters(enCharsType chars_type) {
		return count_letters(_str, chars_type);
	}

	static string invert_letters_case(string &str) {
		string converted;

		for (char s : str)
			converted += islower(s) ? char(toupper(s)) : char(tolower(s));

		return str = converted;
	}

	string invert_letters_case() {
		return invert_letters_case(_str);
	}

	static char invert_letter_case(char ch) {
		return islower(ch) ? toupper(ch) : tolower(ch);
	}

	static char invert_letter_case(char &ch) {
		return ch = islower(ch) ? toupper(ch) : tolower(ch);
	}

	static string remove_puncts(string &str) {
		string new_str;

		for (char s : str)
			if (!ispunct(s))
				new_str += s;

		return str = new_str;
	}

	string remove_puncts() {
		return remove_puncts(_str);
	}
};