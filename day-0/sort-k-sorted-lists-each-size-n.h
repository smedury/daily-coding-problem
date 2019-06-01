#include <list>
#include <stdexcept>
#include <algorithm>
#include<iostream>
#include<vector>

std::vector<int> sort_k_lists(const int& k,
    const std::vector<int>& input_list) {
  std::vector<int> output_list = std::vector<int>();
  int size_of_each_list = input_list.size()/k;
  // Assuming that each list is of same size, 
  // otherwise we need n
  if( input_list.size()%k != 0){
    throw std::invalid_argument("List is not uniform \n");
  }

  struct triple{
    int val;
    int list_index;
    int element_index;
  };

  struct comparator{
    bool operator()(const triple& a, const triple& b) const {
      return a.val>b.val;
    }
  };

  std::vector<triple> heap = std::vector<triple>();
  for(int i=0; i<(int)input_list.size(); i+=size_of_each_list){
    for(int j=i; j<(i+k); j++){
      triple t = {input_list[j],j/size_of_each_list,j-i};
      heap.push_back(t); 
    }
  }

  make_heap(heap.begin(), heap.end(),comparator());

  while(heap.size()>0){
    pop_heap(heap.begin(), heap.end(), comparator());
    triple t1 = heap.back();
    heap.pop_back();
    output_list.push_back(t1.val);
    if((t1.element_index+1)<(size_of_each_list)&&(t1.element_index>=k-1)){
      triple next_triple = {input_list[(t1.list_index*size_of_each_list)+t1.element_index+1],
                      t1.list_index, t1.element_index+1};
      heap.push_back(next_triple);
      push_heap(heap.begin(), heap.end(), comparator());
    }
  }
  return output_list;
}
