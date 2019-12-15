#include <algorithm>
#include <vector>

int FirstMissingPositiveNumber(std::vector<int>& _input_list){
    int j=-1;
    for(int i=0; i<_input_list.size(); i++){
        if(_input_list[i]<=0){
            int temp = _input_list[i];
            j+=1;
            _input_list[i] = _input_list[j];
            _input_list[j] = temp;
        }
    }

    for(int i=j+1; i<_input_list.size(); i++){
        if((abs(_input_list[i]) -  1) <_input_list.size() && abs(_input_list[i] - 1) > 0) 
            _input_list[abs(_input_list[i]) - 1] = -_input_list[abs(_input_list[i])-1];
    }

    auto result = std::find_if(_input_list.begin() + j + 1, _input_list.end(), [] (int n) { return n>=0;});

    if(result!=_input_list.end()) return (std::distance(_input_list.begin(), result)+1);
    else return -1;
}