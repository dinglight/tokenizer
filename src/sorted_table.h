// Copyright 2020 ding liang
#ifndef _SORTED_TABLE_H_
#define _SORTED_TABLE_H_

#include "dictionary.h"

class SortedTable : public Dictionary {
public:
    SortedTable();
    virtual ~SortedTable();
    bool Load(const std::string & file_path) override;
    MatchType Match(const std::string & key) const override;
    size_t GetMaxKeyLength() const override;

    void Add(const std::string & key);
    std::string GetMaxKey() const;
private:
    size_t max_key_length_;
    std::vector<std::string> keys_;
};

#endif  // _SORTED_TABLE_H_
