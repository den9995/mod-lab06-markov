// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"
TEST(Test1, prefixGen) {
    std::string filename = "test.txt";
    std::vector<std::string> words;
    readWords(filename,words);
    st statetab;
    makeState(words,statetab,2);
    for (std::pair<prefix, std::vector<std::string>> valFromTab: statetab) {
        EXPECT_EQ(2, valFromTab.first.size());
    }
}
TEST(Test2, tableGen) {
    std::string filename = "test.txt";
    std::vector<std::string> words;
    readWords(filename,words);
    st statetab;
    makeState(words,statetab,2);
    prefix pref;
    pref.push_back("to");
    pref.push_back("perform");
    EXPECT_EQ(statetab[pref].size(), 2);
}
TEST(Test3, noChoiseSuffix) {
    std::string filename = "test.txt";
    std::vector<std::string> words;
    readWords(filename,words);
    st statetab;
    makeState(words,statetab,2);
    prefix pref;
    pref.push_back("perform");
    pref.push_back("something");
    EXPECT_EQ(getNext(statetab,pref), "worth");
}
TEST(Test4, ChoiseSuffix) {
    std::srand(2);
    std::string filename = "test.txt";
    std::vector<std::string> words;
    readWords(filename,words);
    st statetab;
    makeState(words,statetab,2);
    prefix pref;
    pref.push_back("to");
    pref.push_back("perform");
    EXPECT_EQ(getNext(statetab,pref), "something");
    pref.pop_back();
    pref.push_front("to");
    EXPECT_EQ(getNext(statetab,pref), "grouth");
}
TEST(Test5, genWords) {
    std::srand(0);
    std::string filename = "test.txt";
    std::vector<std::string> words;
    readWords(filename,words);
    st statetab;
    makeState(words,statetab,2);
    EXPECT_EQ(generate(statetab,words,2,9), "perform something worth resulting in a future payout. Therefore, ");
}
    
