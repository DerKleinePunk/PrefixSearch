#include "trieNode.hpp"

trieNode::trieNode(/* args */)
{
    isEndOfWord = false;
}

trieNode::~trieNode()
{
    for(auto entry : children) {
        delete entry.second;
    }

    children.clear();
}

void trieNode::GetWords(const std::string& word, std::vector<std::string>& result)
{
    if(isEndOfWord) {
        result.push_back(word);
    }

    for(const auto &entry : children) {
        auto nextPrefix = word + entry.first;
		entry.second->GetWords(nextPrefix, result);
	}
}