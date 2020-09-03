// Copyright 2020 ding liang
#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <string>
#include <vector>
#include <memory>

class Dictionary;
class DirectedAcyclicGraph;

class Tokenizer {
 public:
    explicit Tokenizer(const std::shared_ptr<Dictionary>& dict);
    virtual ~Tokenizer();
 public:
    void AddChar(char c);
    std::vector<std::string> GetTokens();
 private:
    std::string raw_input_;
    std::shared_ptr<Dictionary> dict_;
    std::unique_ptr<DirectedAcyclicGraph> dag_;
};
#endif  // TOKENIZER_H_
