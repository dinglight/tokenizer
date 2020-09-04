// Copyright 2020 ding liang
#include "tokenizer.h"

#include <algorithm>

#include "dictionary.h"
#include "directed_acyclic_graph.h"

static int GetWeigthByMatchType(MatchType type)
{
    switch (type) {
    case MatchType::EXACT:
        return 1;
    case MatchType::PARTIAL:
        return 1;
    default:
        return 65535;
    }
}

Tokenizer::Tokenizer(const std::shared_ptr<Dictionary>& dict)
:dict_(dict),
 dag_(std::make_unique<DirectedAcyclicGraph>())
{
}
Tokenizer::~Tokenizer()
{}

void Tokenizer::AddChar(char c)
{
    raw_input_.push_back(c);
    dag_->AppendVertex();
    size_t max_len = std::min(dict_->GetMaxKeyLength(), raw_input_.size());
    bool empty = true;
    for (size_t len = max_len; len > 0; --len) {
        std::string suffix = raw_input_.substr(raw_input_.size()-len, len);
        MatchType type = dict_->Match(suffix);
        if (type != MatchType::NOMATCH) {
            dag_->AddEdge(raw_input_.size()-len, raw_input_.size(), GetWeigthByMatchType(type));
            empty = false;
        }
    }

    // add the last character to dag
    if (empty) {
        std::string suffix = raw_input_.substr(raw_input_.size() - 1, 1);
        dag_->AddEdge(raw_input_.size()-1, raw_input_.size(), GetWeigthByMatchType(dict_->Match(suffix)));
    }
}

std::vector<std::string> Tokenizer::GetTokens()
{
    std::vector<std::string> tokens;
    std::vector<int> path = dag_->GetShortestPath(0, raw_input_.size());

    for (size_t i = 0; i < path.size()-1; ++i) {
        int pos = path[i];
        int len = path[i+1] - path[i];
        std::string token = raw_input_.substr(pos, len);
        tokens.push_back(token);
    }

    return tokens;
}
