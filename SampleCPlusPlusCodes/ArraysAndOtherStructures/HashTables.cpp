// Hash tables are also known as dictionaries.
// See also http://www.cplusplus.com/reference/unordered_map/unordered_map/

#include "stdafx.h"
 
#include <iostream>
#include <map>
#include <unordered_map>

typedef std::map<std::string, int> dictionary;

using namespace std;

void addElements(dictionary& dict) {
	dict["Imam Khomeini"] = 5;
}

void removeElements(dictionary* const dict) {
	// Use constant where ever possible.
	dict->erase("Mas");
}

void UsingHashTables() {
	std::map<std::string, int> dict{ {"Naghi", 20} , {"Masoud", 10 },  {"Mas", 10 } };
	dict["Sefa"] = 20;

	addElements(dict);
	removeElements(&dict);

	for (auto key : dict) {
		cout << key.first << " and " << key.second << endl;
	}

	// Notice that an unordered_map object (i.e., the iterator of the dictionary class) makes no guarantees on which 
	// specific element is its first element.For example here Naghi is called third of course. 
	// But, in any case, the range that goes from its begin to its end covers all the elements in the container (or the bucket), 
	// until invalidated.
	for (auto it = dict.begin(); it != dict.end(); it++) {
		cout << "key is " << it->first << " and value is " << it->second << endl;
	}
}

