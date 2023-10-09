#pragma once
#include <string>

#include "node.hpp"

class trie
{
private:
    node* root;
    void findWordsFromNode(node *node, std::string currentWord, std::vector<std::string> &result);
public:
    trie();
    ~trie();

    void add(const std::string& word);
    std::vector<std::string> Search(const std::string& word);
};


