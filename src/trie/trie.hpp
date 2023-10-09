#pragma once
#include <string>

#include "trieNode.hpp"

class trie
{
private:
    trieNode* root{};
    static void findWordsFromNode(trieNode *node, std::string currentWord, std::vector<std::string> &result);
public:
    trie();
    ~trie();

    void add(const std::string& word) const;
    std::vector<std::string> Search(const std::string& word);
};


