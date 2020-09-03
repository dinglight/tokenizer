#include "test_suite.h"
#include "sorted_table.h"

TEST(SortedTableTest, LoadTest)
{
    SortedTable st;
    EXPECT_EQ(true, st.Load("pinyin.txt"));
    EXPECT_EQ(6U, st.GetMaxKeyLength());
}

TEST(SortedTableTest, MatchTest)
{
    SortedTable st;
    st.Add("fa");
    st.Add("fan");
    st.Add("fang");

    MatchType type = MatchType::NOMATCH;
    type = st.Match("f");
    EXPECT_EQ(type, MatchType::PARTIAL);

    type = st.Match("fa");
    EXPECT_EQ(type, MatchType::EXACT);

    type = st.Match("g");
    EXPECT_EQ(type, MatchType::NOMATCH);
}

