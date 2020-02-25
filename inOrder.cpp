#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 
void sort(vector <int> pArrayList, int start, int end) {
    
    //start=0;
    //end=pArrayList.size() -1 ;
    if (start > end) {
        return;
    }
    else {
        sort(pArrayList, 2*start + 1, end);

        cout<<pArrayList[start]<<endl;

        sort(pArrayList, 2*start + 2, end);

    }
    
    
}

int main () {
    vector <int> ArrayList;
    sort(ArrayList, 0, ArrayList.size()-1);
}