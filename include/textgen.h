//Copyright 2023 den9995
#include <string>
#include <vector>
#include <deque>
#include <map>


#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_
typedef std::deque<std::string> prefix;
typedef std::map<prefix, std::vector<std::string>> st;

void readWords(const std::string& filename, std::vector<std::string>* words);
void makeState(const std::vector<std::string>& words, st* state, int prefSize);
std::string getNext(const st& state, prefix* pref);
std::string generate(const st& state, const std::vector<std::string>& words,
                                                  int prefSize, int genSize);
#endif  // INCLUDE_TEXTGEN_H_
