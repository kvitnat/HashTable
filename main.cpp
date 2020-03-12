#include <fstream>
#include <vector>
#include <chrono>
//#include "Tree.h"
#include "VectorChecker.h"

using namespace std::chrono;
//void func(int n1, int n2, Tree& tree, std::vector<std::string> & vect);
void fixWord(std::string& w);


int main() {
    std::vector<std::string> wrongWordsVector;
    std::ifstream dictFile("../dictionary.txt");

    //opening files with texts
    const int N = 5;
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

    int countWords = 0;
    int countWrongWords = 0;
    std::string word;


    VectorChecker vectorChecker;

    auto start = steady_clock::now();
    //reading dictionary from file into vector
    if(!dictFile.is_open()){
        std::cout << "Error! File wasn't open\n";
        return 0;
    }

    while(dictFile >> word){
        fixWord(word);
        vectorChecker.add(word);
    }
    auto end = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(end - start);
    dictFile.close();

    std::cout << "stdvector " << elapsed.count() << ' ';

    elapsed = duration_cast<milliseconds>(start - start);   //zero


    // std::vector
    for(int i = 0; i < N; i++)
    {
        if(!text[i].is_open()){
            std::cout << "Error! Text wasn't open\n";
            return 0;
        }

        start = steady_clock::now();
        while ((text[i]) >> word)
        {
            countWords++;
            if (!vectorChecker.check(word)) {
                wrongWordsVector.push_back(word);
                countWrongWords++;
            }
        }
        end = steady_clock::now();
        elapsed += duration_cast<milliseconds>(end - start);

        for(const std::string& w : wrongWordsVector)
            wrongWords[i] << w << '\n';

        wrongWordsVector.clear();
        wrongWords[i].close();
    }

    std::cout << elapsed.count() << ' ' << countWords << ' ' << countWrongWords << '\n';



    //binary search tree
    //---------------------------------------------------------
    //dictFile.clear();
    //dictFile.open("../dictionary.txt");
//    Tree dictionaryTree;
//    start = steady_clock::now();
//
//    //reading dictionary from vector into tree
//    func(0, dictionaryVector.size() - 1, dictionaryTree, dictionaryVector);
//    end = steady_clock::now();
//    elapsed = duration_cast<milliseconds>(end - start);
//    //dictFile.close();
//    std::cout << "binsearchtree " << elapsed.count() << '\n';
    return 0;
}

void fixWord(std::string& w)
{
    std::string fixedWord;
    for(int i = 0; i < w.length(); ++i)
    {
        if((w[i] >= 'a' && w[i] <= 'z') ||
           (w[i] == '\'' && i != 0 && i != w.length() - 1))
            fixedWord += w[i];
        if(w[i] >= 'A' && w[i] <= 'Z')
            fixedWord += (w[i] + ('a' - 'A'));
    }
    w.assign(fixedWord);
}


//void func(int n1, int n2, Tree& tree, std::vector<std::string> & vect)
//{
//    int i = (n1 + n2)/2;
//    tree.add(vect[i]);
//    if(n1 <= n2)
//    {
//        func(i + 1, n2, tree, vect);
//        func(n1, i - 1, tree, vect);
//    }
//}