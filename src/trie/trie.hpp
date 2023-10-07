#pragma once
#include <string>

#include "node.hpp"

class trie
{
private:
    node root;
public:
    trie(/* args */);
    ~trie();

    void add(const std::string& word);
    std::vector<std::string> Search(const std::string& word);
};


