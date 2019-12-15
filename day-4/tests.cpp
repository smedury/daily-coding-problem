#include <random>
#include "first_missing_positive_number.h"
#include "gtest/gtest.h"

TEST(FirstMissingPositiveNumber, SimpleArrays){
  std::vector<int> input_list = { 3, 4, -1, 1 };
  EXPECT_EQ(2, FirstMissingPositiveNumber(input_list));
  input_list.clear();
  input_list = { 3, 4, -1, 1 };
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(input_list), std::end(input_list), rng);
  EXPECT_EQ(2, FirstMissingPositiveNumber(input_list));

  input_list.clear();
  input_list = { 1, 2, 0};
  EXPECT_EQ(3, FirstMissingPositiveNumber(input_list));
  input_list.clear();
  input_list = { 1, 2, 0};
  std::shuffle(std::begin(input_list), std::end(input_list), rng);
  EXPECT_EQ(3, FirstMissingPositiveNumber(input_list));

}

TEST(FirstMissingPositiveNumber, LargeArray){
  std::vector<int> input_list(1000);
  std::iota(std::begin(input_list), std::end(input_list), 1);
  int result = 579;
  input_list[result] = -5;
  EXPECT_EQ(result + 1, FirstMissingPositiveNumber(input_list));
  input_list.clear();
  input_list = std::vector<int>(1000);
  std::iota(std::begin(input_list), std::end(input_list), 1);
  input_list[result] = -5;
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(input_list), std::end(input_list), rng);
  EXPECT_EQ(result + 1, FirstMissingPositiveNumber(input_list));
}


int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
