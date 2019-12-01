#include "sort-k-sorted-lists-each-size-n.h"
#include "gtest/gtest.h"

TEST(SortTest, Simple){
  std::vector<int> input_list = { 10, 15, 30, 35, 5, 8, 15, 19, 1, 3, 6, 24};
  std::vector<int> output_list = sort_k_lists(3, input_list);
  EXPECT_EQ(output_list.size(), input_list.size());
  EXPECT_TRUE(std::is_sorted(std::begin(output_list), std::end(output_list)));
  std::vector<int> actual_result = std::vector<int>(input_list);
	std::sort(actual_result.begin(), actual_result.end());
  EXPECT_EQ(actual_result, output_list);

}

TEST(SortTest, LargeVector){
  int k(10), n(1000);
  std::vector<int> input_list;
  srand(time(0));
  for(int i=0; i<n; i=i+(n/k)){
	std::vector<int> sorted_random_integers;
	for(int j=i; j<i+(n/k); j++){
	    sorted_random_integers.push_back(rand()%(n/k));
	}
	sort(sorted_random_integers.begin(), sorted_random_integers.end());
    input_list.insert(input_list.end(), sorted_random_integers.begin(), sorted_random_integers.end());
  }
  std::vector<int> output_list = sort_k_lists(k, input_list);
  EXPECT_EQ(output_list.size(), input_list.size());
  EXPECT_TRUE(std::is_sorted(std::begin(output_list), std::end(output_list)));
  std::vector<int> actual_result = std::vector<int>(input_list);
	std::sort(actual_result.begin(), actual_result.end());
  EXPECT_EQ(actual_result, output_list);
}
TEST(SortTest, LargeVectorOddnumberSize){
  int k(7), n(140);
  std::vector<int> input_list;
  srand(time(0));
  for(int i=0; i<n; i=i+(n/k)){
    std::vector<int> sorted_random_integers;
	for(int j=i; j<i+(n/k); j++){
	    sorted_random_integers.push_back(rand()%(n/k));
    }
    sort(sorted_random_integers.begin(), sorted_random_integers.end());
    input_list.insert(input_list.end(), sorted_random_integers.begin(), sorted_random_integers.end());
  }
  std::vector<int> output_list = sort_k_lists(k, input_list);
  std::vector<int> actual_result = std::vector<int>(input_list);
	std::sort(actual_result.begin(), actual_result.end());
  EXPECT_EQ(output_list.size(), input_list.size());
  EXPECT_TRUE(std::is_sorted(std::begin(output_list), std::end(output_list)));
  EXPECT_TRUE(std::is_sorted(std::begin(actual_result), std::end(actual_result)));
  EXPECT_EQ(actual_result, output_list);
}
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
