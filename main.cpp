#include <fstream>
#include <vector>
#include <chrono>
#include "checker/VectorChecker.h"
#include "checker/TreeChecker.h"
#include "checker/HashChecker.h"
#include "checker/MyHashChecker.h"
#include "checker/TrieChecker.h"
#include "classes/Trie.h"

using namespace std::chrono;

const int N = 5;

void checkingTexts(Checker& checker, std::vector<std::string> dictionaryVector,
                   std::ifstream text[N], std::string msg);

int main() {
    std::vector<std::string> wrongWordsVector;
    std::ifstream dictFile("../dictionary.txt");
    std::vector<std::string> dictionaryVector;
    std::string word;

    //opening files with texts
    std::ifstream text[N];
    std::ofstream wrongWords[N];
    text[0].open("../texts/alice.txt");
    wrongWords[0].open("../texts/aliceWrongWords.txt");
    text[1].open("../texts/dracula.txt");
    wrongWords[1].open("../texts/draculaWrongWords.txt");
    text[2].open("../texts/holmes.txt");
    wrongWords[2].open("../texts/holmesWrongWords.txt");
    text[3].open("../texts/sherlock.txt");
    wrongWords[3].open("../texts/sherlockWrongWords.txt");
    text[4].open("../texts/tolstoy.txt");
    wrongWords[4].open("../texts/tolstoyWrongWords.txt");



    //reading dictionary from file into vector
    if(!dictFile.is_open()){
        std::cout << "Error! File wasn't open\n";
        return 0;
    }
    while(dictFile >> word){
        dictionaryVector.push_back(word);
    }
    dictFile.close();


    // std::vector writing into file
    VectorChecker vectorCheckerWrite;
    for(const std::string & w : dictionaryVector)
        vectorCheckerWrite.add(w);

    for(int i = 0; i < N; i++)
    {
        if(!text[i].is_open()){
            std::cout << "Error! Text wasn't open\n";
            return 0;
        }

        while ((text[i]) >> word)
            if (!vectorCheckerWrite.check(word))
                wrongWords[i] << word << '\n';

        wrongWords[i].close();
        text[i].close();
        text[i].clear();
    }



    VectorChecker vectorChecker;
    checkingTexts(vectorChecker, dictionaryVector, text, "stdvector  ");

    TreeChecker treeChecker;
    checkingTexts(treeChecker, dictionaryVector, text, "binarytree ");

    HashChecker hashChecker;
    checkingTexts(hashChecker, dictionaryVector, text, "unordrdset ");

    MyHashChecker myHashChecker;
    checkingTexts(myHashChecker, dictionaryVector, text, "hashtable  ");
    //std::cout << "collisions = " << myHashChecker.collisions() << '\n';

    TrieChecker trieChecker;
    checkingTexts(trieChecker, dictionaryVector, text, "trie struct  ");


    return 0;
}


void checkingTexts(Checker& checker, std::vector<std::string> dictionaryVector,
                   std::ifstream text[N], std::string msg)
{
    int countWords = 0;
    int countWrongWords = 0;
    std::string word;

    //reopening the files
    text[0].open("../texts/alice.txt");
    text[1].open("../texts/dracula.txt");
    text[2].open("../texts/holmes.txt");
    text[3].open("../texts/sherlock.txt");
    text[4].open("../texts/tolstoy.txt");

    //reading dictionary from vector into tree
    auto start = steady_clock::now();
    checker.create(0, dictionaryVector.size() - 1, dictionaryVector);
    auto end = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(end - start);
    std::cout << msg << elapsed.count() << ' ';

    elapsed = duration_cast<milliseconds>(start - start);   //zero

    for(int i = 0; i < N; i++)
    {
        start = steady_clock::now();
        while ((text[i]) >> word)
        {
            countWords++;
            if (!checker.check(word)) {
                countWrongWords++;
            }
        }
        end = steady_clock::now();
        elapsed += duration_cast<milliseconds>(end - start);

        text[i].close();
        text[i].clear();
    }
    std::cout << elapsed.count() << ' ' << countWords << ' ' << countWrongWords << '\n';

}