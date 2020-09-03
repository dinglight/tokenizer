// Copyright 2020 ding liang
#include "sorted_table.h"
#include <fstream>
#include <algorithm>
#include "util.h"

SortedTable::SortedTable()
:max_key_length_(0)
{

}
SortedTable::~SortedTable()
{

}

bool SortedTable::Load(const std::string & file_path)
{
    std::ifstream ifs(file_path);
    if (!ifs) {
        return false;
    }

    std::string line;
    while (std::getline(ifs, line)) {
        util::StringUtil::Trim(line);
        keys_.push_back(line);
        if (max_key_length_ < line.length()) {
            max_key_length_ = line.length();
        }
    }
    ifs.close();

    std::sort(keys_.begin(), keys_.end());

    return true;
}

MatchType SortedTable::Match(const std::string & key) const
{
    MatchType type = MatchType::NOMATCH;

    auto lb = std::lower_bound(keys_.begin(), keys_.end(), key);
    if (lb != keys_.end()) {
        if((*lb).compare(0, key.length(), key) == 0) {
            type = MatchType::PARTIAL;
            if ((*lb).length() == key.length()) {
                type = MatchType::EXACT;
            }
        }
    }
    return type;
}
size_t SortedTable::GetMaxKeyLength() const
{
    return max_key_length_;
}

void SortedTable::Add(const std::string & key)
{
    keys_.push_back(key);
    if (max_key_length_ < key.length()) {
        max_key_length_ = key.length();
    }
}
