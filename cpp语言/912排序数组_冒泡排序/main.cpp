#include<iostream>
#include<vector>
#include<utility>//c++11 swap();
using namespace std;

vector<int>& BubbleSort(vector<int>& vec);
int main(){
    vector<int> intVec={-1,0,9,2,-2,1,2,7,5,3,2,4,8,6,1};
    BubbleSort(intVec);
    return 0;
}

vector<int>& BubbleSort(vector<int>& vec){
    int n=vec.size();
    
    for(int i=0;i<n-1;i++){
        bool flag=false;
        for(int j=0;j<n-1-i;j++){
         if (vec[j]>vec[j+1]){
             swap(vec[j],vec[j+1]);  
             flag=true;
            }
         }
         if(!flag)
           break;
    
    }      

    return vec;
}
