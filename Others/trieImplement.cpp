#include <bits/stdc++.h>
using namespace std;

#define ALPHA_SIZE 26

class Trie {
public:
    bool isEnd = false;
    Trie *children[ALPHA_SIZE];
    
    void addWord(string word) {
        Trie *curr = this;
        for (auto i : word) {
            int pos = i - 'a';
            if (curr->children[pos] == NULL) {
                //create a new node
                curr->children[pos] = new Trie();

            }
            curr = curr->children[pos];
        }
        curr->isEnd = true;
    }
};

string s;

void traverse(Trie *t) {
    if (t->isEnd) cout << s << "\n";
    for (int i = 0; i < 26; i++) {
        if (t->children[i]) {
            s.push_back('a' + i);
            traverse(t->children[i]);
            s.pop_back();
        }
    }
}

int main() {
    Trie *t = new Trie();
    t->addWord("apple");
    traverse(t); cout << "\n";
    t->addWord("mango");
    traverse(t); cout << "\n";
    t->addWord("appy");
    traverse(t); cout << "\n";
    t->addWord("appler");
    traverse(t); cout << "\n";

    return 0;
}