#include "node.hpp"

node::node(/* args */)
{
    isEndOfWord = false;
}

node::~node()
{
}

const std::vector<std::string> node::GetWords(const std::string& word)
{
    std::vector<std::string> result;
    if(isEndOfWord) {
        result.push_back(word);
    }
    for(auto entry : children) {
        auto nextPrefix = word + entry.first;
		auto next = entry.second->GetWords(nextPrefix);
        result.insert(std::end(result), std::begin(next), std::end(next));
	}
    return result;
}