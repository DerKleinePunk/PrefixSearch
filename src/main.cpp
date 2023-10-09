#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

#include "trie/trieNode.hpp"

/*int main(int, char**){
    std::cout << "Hello, from prefixSearch!\n";

    std::string line;
    std::vector<std::string> wortlist;

    std::ifstream myfile ("wortliste.txt");
    if (myfile.is_open()) {
        while ( getline (myfile,line) )
        {
            //std::cout << line << std::endl;
            wortlist.push_back(line);
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
        return 99;
    }

    std::cout << wortlist.size() << " words loaded" << std::endl;

    trie testTrie;
    for(auto word : wortlist) {
        testTrie.add(word);
    }

    std::cout << "trie erstellt" << std::endl;

    const auto start_time = std::chrono::high_resolution_clock::now();
    auto result = testTrie.Search("Text");
    const auto end_time = std::chrono::high_resolution_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << "[us]" << std::endl;

    /*
    for(auto entry : result) {
        std::cout << entry << std::endl;
    }
}*/


class PrefixTrie
{
public:
    trieNode *root;

    PrefixTrie()
    {
        root = new trieNode();
    }

    void insert(const std::string &word)
    {
        trieNode *current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
            {
                current->children[c] = new trieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    std::vector<std::string> search(const std::string &prefix)
    {
        std::vector<std::string> result;
        trieNode *current = root;
        for (char c : prefix)
        {
            if (current->children.find(c) == current->children.end())
            {
                return result; // Prefix not found
            }
            current = current->children[c];
        }
        findWordsFromNode(current, prefix, result);
        return result;
    }

private:
    void findWordsFromNode(trieNode *node, const std::string& currentWord, std::vector<std::string> &result)
    {
        if (node->isEndOfWord)
        {
            result.push_back(currentWord);
        }
        for (const auto &pair : node->children)
        {
            findWordsFromNode(pair.second, currentWord + pair.first, result);
        }
    }
};

int main(int, char**)
{
    PrefixTrie trie;
    std::cout << "Hello, from prefixSearch!\n";

    std::string line;
    std::vector<std::string> wortlist;

    std::ifstream myfile("wortliste.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            wortlist.push_back(line);
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
        return 99;
    }

    std::cout << wortlist.size() << " words loaded" << std::endl;

    for (auto word : wortlist)
    {
        trie.insert(word);
    }

    std::cout << "trie erstellt" << std::endl;

    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<std::string> result = trie.search("Text");
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Zeit für die Suche: " << elapsed_time.count() << " Mikrosekunden" << std::endl;
    for (const std::string &word : result)
    {
        std::cout << word << std::endl;
    }

    return 0;
}