#pragma once
#include <map>
#include <vector>
#include <string>
#include <unordered_map>


class trieNode
{
private:
    /* data */
public:
    bool isEndOfWord;
    //std::map<char,node*> children; 
    std::unordered_map<char,trieNode*> children;

    trieNode();
    ~trieNode();

    void trieNode::GetWords(const std::string& word, std::vector<std::string>& result);
};


