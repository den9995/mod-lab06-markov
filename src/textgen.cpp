#include <iostream>
#include <fstream>
#include "textgen.h"

const int NPREF = 2;
const int MAXGEN = 1000;
typedef std::deque<std::string> prefix;
typedef std::map<prefix, std::vector<std::string>> st;

void readWords(const std::string& filename, std::vector<std::string>& words) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "Could not open file: " << filename << std::endl;
        return;
    }
    std::string word;
    while (inputFile >> word) {
        words.push_back(word);
    }
    inputFile.close();
}

void makeState(const std::vector<std::string>& words, st& state, int prefSize) {
    for (int i = 0; i < words.size() - prefSize; i++) {
        prefix  pref;
        for (int j = 0; j < prefSize; j++) {
            pref.push_back(words[j+i]);
        }
        state[pref].push_back(words[prefSize + i]);
    }
}

std::string getNext(st& state,prefix& pref) {
    std::string word;
    int size = state[pref].size();
    if(size!=0){
        word = state[pref][std::rand()%size];
        pref.push_back(word);
        pref.pop_front();
    }
    return word;
}
std::string generate(st& state,const std::vector<std::string>& words,int prefSize,int genSize){
    prefix  pref;
    int wSize = words.size();
    std::string generated;
    if(genSize <= prefSize){
        for (int i = 0; i < genSize; i++)
           generated+=words[std::rand()%wSize]+' '; 
    } else {
        for (int i = 0; i < prefSize; i++) 
            pref.push_back(words[std::rand()%wSize]);
        while(state[pref].size()==0){
            pref.push_back(words[std::rand()%wSize]);
            pref.pop_front();
        } //гарантия что хотя бы 1 токен сгенерируется
        for (int i = 0; i < prefSize; i++) 
            generated+=pref[i]+' ';
        for (int i = 0; i < genSize - prefSize; i++) {
            std::string next= getNext(state,pref);
            if (next == "") break;
            generated+=next+' ';
        }
    }
    return generated;
}

