// Copyright 2020 ding liang
#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <string>
#include <vector>

enum class MatchType {
    EXACT,
    PARTIAL,
    NOMATCH
};

class Dictionary {
 public:
    virtual bool Load(const std::string & file_path) = 0;
    virtual MatchType Match(const std::string & key) const = 0;
    virtual size_t GetMaxKeyLength() const = 0;
};

#endif  // DICTIONARY_H_
