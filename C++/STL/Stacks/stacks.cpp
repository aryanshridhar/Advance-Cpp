#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Learning STL stacks using parenthesis matching as stacks are really small!
string get_input() {
  string input;
  cin >> input;

  return input;
}

map<char, char> get_parenthesis_hashmap() {
  map<char, char> char_hashmap;

  char_hashmap.insert(pair<char, char>(')', '('));
  char_hashmap.insert(pair<char, char>('}', '{'));
  char_hashmap.insert(pair<char, char>(']', '['));

  return char_hashmap;
}

bool is_valid_parenthesis(stack<char> *stk, vector<char> char_vector) {

  map<char, char> char_hashmap = get_parenthesis_hashmap();

  for (int i = 0; i < char_vector.size(); i++) {
    if (char_vector[i] == '(' || char_vector[i] == '{' ||
        char_vector[i] == '[') {
      stk->push(char_vector[i]);
    } else if (char_vector[i] == ')' || char_vector[i] == '}' ||
               char_vector[i] == ']') {
      if (stk->empty()) {
        return false;
      } else {
        if (stk->top() == char_hashmap.find(char_vector[i])->second) {
          stk->pop();
        }
      }
    }
  }

  if (stk->empty()) {
    return true;
  }
  return false;
}

void populate_char_vector(vector<char> *ch, string s) {
  for (int i = 0; i < s.length(); i++) {
    ch->push_back(s[i]);
  }
}

int main() {

  stack<char> stack;
  vector<char> char_vector;

  string input = get_input();

  populate_char_vector(&char_vector, input);

  // At this point, all the string characters are within the stack.
  cout << is_valid_parenthesis(&stack, char_vector) << endl;
}