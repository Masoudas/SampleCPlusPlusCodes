/**
* Question: Break down a string into substring separated by white space or " "?
* 
* Note: We're not using regex here.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void break_down_string_from_whitespace(string str) {
	vector<string> sub_strs{};

	size_t last_pos = 0;
	for (size_t pos = str.find(' '); pos < str.length() && last_pos - 1 != pos; pos = str.rfind(' ')) {
		cout << pos << endl;
		sub_strs.push_back(str.substr(last_pos, pos));
		last_pos = pos + 1;
		
	}

	vector<string>::iterator begin = sub_strs.begin();
	vector<string>::iterator end = sub_strs.end();
	for (; begin != end; begin++)
	{
		cout << *begin << endl;
	}
}

//int main() {
//	string str{ "A B C D E F G, How I Wonder What You Are." };
//
//	break_down_string_from_whitespace(str);
//}