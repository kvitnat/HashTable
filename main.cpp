#include <fstream>
#include <iostream>
#include <vector>
bool isRight(std::string& w, std::vector<std::string> & dict);

int main() {
    std::vector<std::string> dictionary;
    std::ifstream dictFile("../dictionary.txt");
    std::string word;

    if(!dictFile.is_open()){
        std::cout << "Error! File wasn't open\n";
        return 0;
    }
    while(dictFile >> word){
        dictionary.push_back(word);
    }
    dictFile.close();


    std::ifstream text("../texts/alice.txt");
    std::ofstream wrongWords("../texts/aliceWrongWords.txt");

    if(!text.is_open()){
        std::cout << "Error! Text wasn't open\n";
        return 0;
    }

    char x ;
    while (!text.eof())
    {
        x = text.get();
        while (x != ' ' && x != '-' && !text.eof())
        {
            word = word + x;
            x = text.get();
        }
        if (!isRight(word, dictionary) && word != "")
            wrongWords << word << '\n';
        word.clear();

    }

    wrongWords.close();

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
bool isRight(std::string& w, std::vector<std::string> & dict)
{
    fixWord(w);
    for(const auto & i : dict)
        if(w == i)
            return true;
    return false;
}