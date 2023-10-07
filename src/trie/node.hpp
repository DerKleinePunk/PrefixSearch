#pragma once
#include <map>
#include <vector>
#include <string>


class node
{
private:
    /* data */
public:
    bool isEndOfWord;
    std::map<char,node*> children; 

    node();
    ~node();

    const std::vector<std::string> GetWords(const std::string& word);
};


