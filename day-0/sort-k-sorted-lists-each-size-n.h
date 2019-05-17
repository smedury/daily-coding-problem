#include <vector>
#include <stdexcept>
#include <algorithm>

std::vector<int> sort_k_lists(const int& k,
    const std::vector<int>& input_list) {
  std::vector<int> output_list = std::vector<int>(input_list);
  // Assuming that each list is of same size, 
  // otherwise we need n
  if( input_list.size()%k != 0){
    throw std::invalid_argument("List is not uniform \n");
  }
  make_heap(output_list.begin(), output_list.end());
  sort_heap(output_list.begin(), output_list.end());
  return output_list;
}
