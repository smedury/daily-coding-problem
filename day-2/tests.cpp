#include "serialize_deserialize_tree.h"
#include "gtest/gtest.h"

TEST(Serialize, Simple){
  node* left = new node("left");
  node* right = new node("right");
  node* root_node = new node("root");
  root_node->left = left;
  root_node->right = right;
  std::vector<std::string> resulting_string = serialize(*root_node);
  std::vector<std::string> expected_string = {"root", "left", "right"};
  EXPECT_EQ(resulting_string.size(), expected_string.size());
  EXPECT_EQ(resulting_string, expected_string);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
