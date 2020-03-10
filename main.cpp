#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;
bool isRight(std::string& w, const std::vector<std::string> & dict);

int main() {
    std::vector<std::string> dictionaryVector;
    std::vector<std::string> wrongWordsVector;
    std::ifstream dictFile("../dictionary.txt");
    std::string word;

    int countWords = 0;
    int countWrongWords = 0;


    auto start = steady_clock::now();
    //reading dictionary from file into vector
    if(!dictFile.is_open()){
        std::cout << "Error! File wasn't open\n";
        return 0;
    }
    while(dictFile >> word){
        dictionaryVector.push_back(word);
    }
    auto end = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(end - start);
    dictFile.close();

    std::cout << "stdvector " << elapsed.count() << ' ';

    elapsed = duration_cast<milliseconds>(start - start);

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
            if (!isRight(word, dictionaryVector)) {
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
bool isRight(std::string& w, const std::vector<std::string> & dict)
{

    fixWord(w);
    if(w.empty())
        return true;
    long N1 = 0;
    long N2 = dict.size() - 1;

    while(N1 <= N2)
    {
        if(w == dict[int((N2 + N1)/2)])
            return true;
        if(w < dict[int((N2 + N1)/2)])
            N2 = int((N2 + N1)/2) - 1;
        else
            N1 = int((N2 + N1)/2) + 1;
    }

    return false;
}