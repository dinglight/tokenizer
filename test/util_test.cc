#include "test_suite.h"
#include "util.h"

TEST(StringUtilTest, LTrimTest)
{
    std::string s {"  hello"};
    util::StringUtil::LTrim(s);
    EXPECT_STREQ("hello",s);
}

TEST(StringUtilTest, RTrimTest)
{
    std::string s {"hello\r\n"};
    util::StringUtil::RTrim(s);
    EXPECT_STREQ("hello",s);
}

TEST(StringUtilTest, TrimTest)
{
    std::string s {"  \thello\r\n"};
    util::StringUtil::Trim(s);
    EXPECT_STREQ("hello",s);
}
