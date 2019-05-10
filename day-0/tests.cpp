#include "gtest/gtest.h"
#include "sort-k-sorted-lists-each-size-n.h"

namespace {
  TEST(SortTest, Simple) {
    std::vector<int> input_list = { 10, 15, 30, 12, 15, 20, 17, 20, 32 };
    std::vector<int> output_list = sort_k_lists(3, input_list);
    EXPECT_TRUE(std::is_sorted(std::begin(output_list), std::end(output_list)));
  }
}
