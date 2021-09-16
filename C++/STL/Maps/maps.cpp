#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void show(map<string, string> m) {
  if (m.size() == 0) {
    cout << "Map contains no element" << endl;
  }
  for (map<string, string>::iterator iter = m.begin(); iter != m.end();
       iter++) {
    cout << "All names are - " << iter->first << " " << iter->second << endl;
  }
}

int main() {

  map<string, string> names;

  names.insert(pair<string, string>("Aryan", "Shridhar"));
  names.insert(pair<string, string>("Lionel", "Messi"));
  names.insert(pair<string, string>("Cristiano", "Ronaldo"));
  names.insert(pair<string, string>("Roger", "Federer"));

  // Retrieving specific values.
  cout << "Full name is Aryan " << names["Aryan"] << endl;
  cout << "Full name is Lionel " << names.find("Lionel")->second << endl;

  // Total size.
  cout << "Total values are " << names.size() << endl;

  // Displaying.
  show(names);

  // Modifying values.
  map<string, string>::iterator iter = names.find("Aryan");
  iter->second = "sHrIdHaR";

  cout << "Full name is Aryan " << names["Aryan"] << endl;

  // Deleting specific values.
  names.erase("Aryan");
  // OR
  map<string, string>::iterator iter1 = names.find("Lionel");
  names.erase(iter1);

  show(names);

  // Clearing all values.
  names.clear();

  show(names);
}