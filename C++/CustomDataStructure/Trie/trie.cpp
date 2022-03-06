#include <fstream>
#include <iostream>

using namespace std;

struct Node {
  Node *link[26];
  bool flag = false;

  bool containerChar(char ch) { return link[ch - 'a'] != NULL; }

  void put(char ch, Node *node) { link[ch - 'a'] = node; }

  Node *get(char ch) { return link[ch - 'a']; }

  void setFlag(bool b) { flag = b; }

  bool getFlag() { return flag; }
};

class Trie {
private:
  Node *root;

public:
  Trie() { root = new Node(); }

  void insert(string word) {
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containerChar(word[i])) {
        node->put(word[i], new Node());
      }

      node = node->get(word[i]);
    }

    node->setFlag(true);
  }

  bool search(string word) {
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containerChar(word[i])) {
        return false;
      }

      node = node->get(word[i]);
    }

    if (node->getFlag()) {
      return true;
    }

    return false;
  }

  void erase(string word) {
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containerChar(word[i])) {
        return;
      }

      node = node->get(word[i]);
    }

    node->setFlag(false);
  }

  bool startsWith(string word) {
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containerChar(word[i])) {
        return false;
      }

      node = node->get(word[i]);
    }

    return true;
  }
};