#include<iostream>
#include <vector>

void array_product_excluding_i(std::vector<int>& input){
    long int total_product(1);
    for(int ele: input){
        total_product*=ele;
    }
    for(int i=0; i<input.size(); i++){
        input[i]=total_product/input[i];
    }
}

void array_product_excluding_i_without_division(std::vector<unsigned long int>& input){
    unsigned long int part_product(1);
    std::vector<unsigned long int> left_product(input.size()), right_product(input.size());
    for(int i=0; i<input.size(); i++){
       part_product*=input[i];
       left_product[i]=part_product;
    }
    part_product = 1;
    for(int i=input.size()-1; i>=0; i--){
       part_product*=input[i];
       right_product[i]=part_product;
    }
    input[0] = right_product[1];
    input[input.size()-1]=left_product[input.size()-2];
    for(int i=1; i<input.size()-1; i++){
        input[i] = left_product[i-1] * right_product[i+1];
    }
}