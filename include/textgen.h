#include <string>
#include <vector>
#include <deque>
#include <map>


typedef std::deque<std::string> prefix;
typedef std::map<prefix, std::vector<std::string>> st;

void readWords(const std::string& filename, std::vector<std::string>& words) ;
void makeState(const std::vector<std::string>& words, st& state, int prefSize) ;
std::string getNext(st& state,prefix& pref) ;
std::string generate(st& state,const std::vector<std::string>& words,int prefSize,int genSize);
