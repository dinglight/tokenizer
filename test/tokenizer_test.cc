#include "test_suite.h"
#include "sorted_table.h"
#include "tokenizer.h"

TEST(TokenizerTest, GetTokensTest1)
{
    auto st = std::make_shared<SortedTable>();
    EXPECT_EQ(true, st->Load("pinyin.txt"));
    Tokenizer tokenizer(st);
    
    // "fangan";
    std::vector<std::string> tokens;
    tokenizer.AddChar('f');
    tokens = tokenizer.GetTokens();
    EXPECT_EQ(1U, tokens.size());
    EXPECT_STREQ("f", tokens[0]);

    tokenizer.AddChar('a');
    tokens = tokenizer.GetTokens();
    EXPECT_EQ(1U, tokens.size());
    EXPECT_STREQ("fa", tokens[0]);

    tokenizer.AddChar('n');
    tokens = tokenizer.GetTokens();
    EXPECT_EQ(1U, tokens.size());
    EXPECT_STREQ("fan", tokens[0]);

    tokenizer.AddChar('g');
    tokens = tokenizer.GetTokens();
    EXPECT_EQ(1U, tokens.size());
    EXPECT_STREQ("fang", tokens[0]);

    tokenizer.AddChar('a');
    tokens = tokenizer.GetTokens();
    EXPECT_EQ(2U, tokens.size());
    EXPECT_STREQ("fan", tokens[0]);
    EXPECT_STREQ("ga", tokens[1]);

    tokenizer.AddChar('n');
    tokens = tokenizer.GetTokens();
    EXPECT_EQ(2U, tokens.size());
    EXPECT_STREQ("fan", tokens[0]);
    EXPECT_STREQ("gan", tokens[1]);
}

TEST(TokenizerTest, GetTokensTest2)
{
    auto st = std::make_shared<SortedTable>();
    EXPECT_EQ(true, st->Load("pinyin.txt"));
    Tokenizer tokenizer(st);
    
    std::string s{"pinyinshurufa"};
    
    for (const auto c : s) {
        tokenizer.AddChar(c);
    }

    std::vector<std::string> tokens = tokenizer.GetTokens();
    for (const auto token : tokens) {
        std::cout << token << std::endl;
    }
}

TEST(TokenizerTest, GetTokensTest3)
{
    auto st = std::make_shared<SortedTable>();
    EXPECT_EQ(true, st->Load("pinyin.txt"));
    Tokenizer tokenizer(st);
    
    std::string s{"pyshur"};
    
    for (const auto c : s) {
        tokenizer.AddChar(c);
        std::vector<std::string> tokens = tokenizer.GetTokens();
        for (const auto token : tokens) {
            std::cout << token << std::endl;
        }
        std::cout << "-------------" << std::endl;
    }
}

TEST(TokenizerTest, GetTokensTest4)
{
    auto st = std::make_shared<SortedTable>();
    EXPECT_EQ(true, st->Load("pinyin.txt"));
    Tokenizer tokenizer(st);
    
    std::string s{"ivuhi"};
    
    for (const auto c : s) {
        tokenizer.AddChar(c);
        std::vector<std::string> tokens = tokenizer.GetTokens();
        for (const auto token : tokens) {
            std::cout << token << std::endl;
        }
        std::cout << "-------------" << std::endl;
    }
}
