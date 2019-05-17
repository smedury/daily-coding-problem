#include "sort-k-sorted-lists-each-size-n.h"
#include "gtest/gtest.h"

TEST(SortTest, Simple){
  std::vector<int> input_list = { 10, 15, 30, 12, 15, 20, 17, 20, 32 };
  std::vector<int> output_list = sort_k_lists(3, input_list);
  EXPECT_TRUE(std::is_sorted(std::begin(output_list), std::end(output_list)));
}

TEST(SortTest, LargeVector){
  int k(10), n(100);
  std::vector<int> input_list = std::vector<int>(n,0);
  srand(time(0));
  for(int i=0; i<n; i=i+k){
    for(int j=i; j<i+k; j++){
      input_list[j]=rand()%100;
    }
  }
  std::vector<int> output_list = sort_k_lists(k, input_list);
  EXPECT_TRUE(std::is_sorted(std::begin(output_list), std::end(output_list)));
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
