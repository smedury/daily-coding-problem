//
// Created by smedury on 12/9/19.
//

#ifndef DAILY_CODING_PROBLEM_SERIALIZE_DESERIALIZE_TREE_H
#define DAILY_CODING_PROBLEM_SERIALIZE_DESERIALIZE_TREE_H

#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <queue>

class node{

  public:
    node(std::string _val) : val(_val), left(nullptr), right(nullptr) {}
    node(const node& _node) : val(_node.val), left(_node.left), right(_node.right) {}
    ~node() {}
    std::string val;
    node *left, *right;
};

std::vector<std::string> serialize(const node& _node_in){

    if( &_node_in == nullptr) throw std::invalid_argument("TREE IS NULL");

    std::vector<std::string> serialized_tree;
    node root(_node_in);
    std::queue<node*> traversal_queue;
    traversal_queue.push(&root);
    while( !traversal_queue.empty() ) {
        node* this_node = traversal_queue.front();
        traversal_queue.pop();
        serialized_tree.push_back(this_node->val);
        if(this_node->left) traversal_queue.push(this_node->left);
        if(this_node->right) traversal_queue.push(this_node->right);
    }

    return serialized_tree;
}

node deserialize(const std::vector<std::string>& serialized_tree) {
    if(serialized_tree.empty()) throw  std::invalid_argument("INPUT STRING IS EMPTY");
    std::queue<node*> traversal_queue;
    int traversal_index(0);
    node* root = new node(serialized_tree[traversal_index]);
    traversal_queue.push(root);
    while (!traversal_queue.empty()){
        if(traversal_index*2 < serialized_tree.size()) {
            traversal_index*=2;
            node* left_node = new node(serialized_tree[traversal_index]);
            traversal_queue.push(left_node);
        }
        if(traversal_index*2 + 1 < serialized_tree.size()) {
            node* right_node = new node(serialized_tree[traversal_index+1]);
            traversal_queue.push(right_node);
        }
    }
}

#endif //DAILY_CODING_PROBLEM_SERIALIZE_DESERIALIZE_TREE_H
