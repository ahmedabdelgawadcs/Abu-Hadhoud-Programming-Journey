#include <iostream>
#include "clsString.h"
#include <vector>

using namespace std;

int main() {
	clsString str1, str2("Mohammed");

	str1.val = "Ahmed Ali";

	cout << "String1 = " << str1.val << endl;
	cout << "String2 = " << str2.val << endl;

	cout << "Number of words: " << str1.count_words() << endl;
	cout << "Number of words: " << str1.count_words("Fadi ahmed rateb omer", " ") << endl;
	cout << "Number of words: " << clsString::count_words("Mohammed Saqer Abu-Hadhoud", " ") << endl;

	//----------------------------------------

	clsString str3("hi how are you?");

	cout << "String 3 = " << str3.val << endl;
	cout << "String Length = " << str3.length << endl;

	str3.capitalize();
	cout << str3.val << endl;

	//----------------------------------------

	str3.lower_firsts();
	cout << str3.val << endl;

	//----------------------------------------

	str3.to_upper_case();
	cout << str3.val << endl;

	//----------------------------------------

	str3.to_lower_case();
	cout << str3.val << endl;

	//----------------------------------------

	cout << "After inverting a : " << clsString::invert_letter_case('a') << endl;
			
	//----------------------------------------
	
	str3.val = "AbCdEfg";

	str3.invert_letters_case();
	cout << str3.val << endl;

	str3.invert_letters_case();
	cout << str3.val << endl;

	//----------------------------------------

	cout << "Capital Letters count: " << clsString::count_letters("Mohammed Abu-Hadhoud", capital_letters) << '\n' << endl;

	str3.val = "Welcome to Jordan";
	cout << str3.val << endl;

	cout << "Capital Letters count: " << str3.count_capitals() << endl;
	
	//----------------------------------------
	
	cout << "Small Letters count: " << str3.count_smalls() << endl;
	
	//----------------------------------------

	cout << "vowels count: " << str3.count_vowels() << endl;

	//----------------------------------------

	cout << "letter E count: " << str3.freq_of('E', false) << endl;

	//----------------------------------------

	cout << "is letter u vowel? " << clsString::isvowel('u') << endl;
	
	//----------------------------------------

	cout << "Words Count: " << str3.count_words() << endl;

	//----------------------------------------

	vector<string> vWords;

	vWords = str3.split(' ');

	cout << "\nTokens = " << vWords.size() << endl;

	for (string& v : vWords)
		cout << v << endl;

	//----------------------------------------

	// Trims
	str3.val = "    Mohammed Abu-Hahdoud     ";
	cout << "\nString     = " << str3.val;

	str3.trim_left();
	cout << "\n\nTrim Left  = " << str3.val;

	//----------------------------------------

	str3.val = "    Mohammed Abu-Hahdoud     ";
	str3.trim_right();
	cout << "\nTrim Right = " << str3.val;

	//----------------------------------------

	str3.val = "    Mohammed Abu-Hahdoud     ";
	str3.trim();
	cout << "\nTrim       = " << str3.val << endl;

	//----------------------------------------

	// Joins
	vector<string> vWords1 = { "Mohammed","Faid","Ali","Maher" };
	cout << "\n\nJoin String From Vector: \n";
	cout << clsString::join(vWords1, ' ');

	string arr_str[] = { "Mohammed","Faid","Ali","Maher" };

	cout << "\n\nJoin String From array: \n";
	cout << clsString::join(arr_str, 4, ' ');

	//----------------------------------------

	str3.val = "Mohammed Saqer Abu-Hadhoud";
	cout << "\n\nString     = " << str3.val << endl;

	str3.reverse_words();
	cout << "\nReverse Words: " << str3.val;

	//----------------------------------------

	str3.val = "Mohammed Saqer Abu-Hadhoud";
	cout << "\nReplace: " << str3.replace_all("Mohammed", "Sari");
	
	//----------------------------------------

	str3.val = "This is: a sample text, with punctuations.";
	cout << "\n\nString     = " << str3.val;

	str3.remove_puncts();
	cout << "\nRemove Punctuations: " << str3.val << endl;

	//----------------------------------------
	
 	system("pause > 0");

	return 0;
}