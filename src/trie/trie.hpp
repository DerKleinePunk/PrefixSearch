#pragma once
#include <string>

#include "trieNode.hpp"

class trie
{
private:
    trieNode* root{};
 public:
    trie();
    ~trie();

    void add(const std::string& word) const;
    std::vector<std::string> Search(const std::string& word);
};


