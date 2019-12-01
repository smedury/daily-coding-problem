#include "array_product_excluding_i.h"
#include "gtest/gtest.h"

TEST(SortTest, Simple){
  std::vector<unsigned long int> input_list = { 1, 2, 3, 4, 5};
  std::vector<unsigned long int> output_list = {120, 60, 40, 30, 24};
  array_product_excluding_i_without_division(input_list);
  EXPECT_EQ(input_list, output_list);
}

TEST(SortTest, LargeVector){
  int n(1000);
  std::vector<unsigned long int> input_list;
  srand(time(0));
  for(int i=0; i<n; i++) input_list.push_back((rand()%n)+1);
  std::vector<unsigned long int> output_list;
  for(int i=0; i<n; i++){
      long int product=1;
	    for(int j=0; j<n; j++){
	        if(j!=i){
	            product*=input_list[j];
	        }
	    }
	    output_list.push_back(product);
  }
  array_product_excluding_i_without_division(input_list);
  EXPECT_EQ(input_list, output_list);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
