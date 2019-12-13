#include "serialize_deserialize_tree.h"
#include "gtest/gtest.h"

TEST(SerializeTree, SimpleSerialize){
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

TEST(SerializeTree, SimpleDeserialize){
  std::vector<std::string> keys = {"root", "left", "right"};
  node* root_node = deserialize(keys);
  EXPECT_EQ(root_node->val, keys[0]);
  EXPECT_EQ(root_node->left->val, keys[1]);
  EXPECT_EQ(root_node->right->val, keys[2]);

}

TEST(SerializeTree, SimpleSerialize1){
  node* left = new node("left");
  node* right = new node("right");
  node* root_node = new node("root");
  root_node->left = left;
  root_node->right = right;

  left->left = new node("left-left");
  left->right = new node("left-right");
  right->left = new node("right-left");
  right->right = new node("right-right");

  std::vector<std::string> resulting_string = serialize(*root_node);
  std::vector<std::string> expected_string = {"root", "left", "right",
                                              "left-left", "left-right",
                                              "right-left", "right-right"};
  EXPECT_EQ(resulting_string.size(), expected_string.size());
  EXPECT_EQ(resulting_string, expected_string);
}

TEST(SerializeTree, SimpleDeserialize1){
  std::vector<std::string> keys = {"root", "left", "right",
                                    "left-left", "left-right",
                                    "right-left", "right-right"};
  node* root_node = deserialize(keys);
  node* left = root_node->left;
  node* right = root_node->right;
  EXPECT_EQ(root_node->val, keys[0]);
  EXPECT_EQ(left->val, keys[1]);
  EXPECT_EQ(right->val, keys[2]);
  EXPECT_EQ(left->left->val, keys[3]);
  EXPECT_EQ(left->right->val, keys[4]);
  EXPECT_EQ(right->left->val, keys[5]);
  EXPECT_EQ(right->right->val, keys[6]);

}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
