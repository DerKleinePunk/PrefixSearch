#include "trie.hpp"

void trie::findWordsFromNode(trieNode* node, std::string currentWord, std::vector<std::string>& result)
{
    if(node->isEndOfWord) {
        result.push_back(currentWord);
    }
    for(const auto& pair : node->children) {
        findWordsFromNode(pair.second, currentWord + pair.first, result);
    }
}

trie::trie(/* args */)
{
    root = new trieNode();
}

trie::~trie()
= default;

void trie::add(const std::string& word) const
{
    auto currentNode = root;

    for(const auto buchstabe : word) {
        if(currentNode->children.find(buchstabe) == currentNode->children.end()) {
            currentNode->children.insert(std::pair(buchstabe, new trieNode()));
        }
        currentNode = currentNode->children[buchstabe];
    }
    currentNode->isEndOfWord = true;
}

std::vector<std::string> trie::Search(const std::string& word)
{
    const auto currentNode = root;
    for(const auto buchstabe : word) {
        if(currentNode->children.find(buchstabe) == currentNode->children.end()) {
            break;
        }
    }

    std::vector<std::string> result;
    findWordsFromNode(currentNode, word, result);
    //currentNode->GetWords(word, result);
    return result;
}