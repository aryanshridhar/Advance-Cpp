#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int TRIE_SIZE = 26;

class Trie {
public:
  vector<Trie *> children;
  int nEoW; // number of end of words (Represents the number of strings that end
            // here).

  Trie() {
    nEoW = 0;
    for (int i = 0; i < TRIE_SIZE; i++) {
      children.push_back(NULL);
    }
  }
};

void insert(Trie *root, string s) {
  Trie *p = root;
  for (int i = 0; i < s.length(); i++) {
    int index = s[i] - 'a';

    if (p->children[index] == NULL) {
      p->children[index] = new Trie();
    }
    p = p->children[index];
  }

  p->nEoW++;
}

bool search(Trie *root, string s) {
  Trie *p = root;
  for (int i = 0; i < s.length(); i++) {
    int index = s[i] - 'a';
    if (p->children[index] == NULL) {
      return false;
    }
    p = p->children[index];
  }

  if (p != NULL && p->nEoW == 0) {
    return false;
  }
  return true;
}

bool delete_string(Trie *root, string s) {
  Trie *p = root;
  for (int i = 0; i < s.length(); i++) {
    int index = s[i] - 'a';
    if (p->children[index] == NULL) {
      return false;
    }
    p = p->children[index];
  }

  if (p != NULL && p->nEoW != 0) {
    // The string is actually present.
    p->nEoW--;
    return true;
  }
  return false;
}

int main() {
  Trie *root = new Trie();

  insert(root, "abcde");
  insert(root, "abcfg");
  insert(root, "akjl");
  insert(root, "kopl");

  cout << search(root, "abcde") << endl;

  delete_string(root, "abcde");

  cout << search(root, "abcde") << endl;

  return 0;
}