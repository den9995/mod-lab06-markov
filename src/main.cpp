#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "textgen.h"
    
int main() {
    const int NPREF=2; // количество слов в префиксе
    const int MAXGEN=1000; //объем текста на выходе
    int seed = (int) std::time(nullptr);
    //int seed = 1682782617; сид, на котором сгенерирован пример
    std::srand(seed);
    std::cout<<"seed:"<<seed<<'\n';
    std::string filename = "sample.txt";
    std::vector<std::string> words;
    readWords(filename,words);
    st statetab;
    makeState(words,statetab,NPREF);
    std::ofstream out("output.txt"); 
    out<<generate(statetab, words, NPREF, MAXGEN);
    return 0;
}
