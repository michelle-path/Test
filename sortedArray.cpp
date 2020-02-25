#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 

using namespace std;
int * getSortedArray(int n) {
    int* arrayList = new int [n];
    //int x;
    for (int i=0; i<n; i++) {
        arrayList[i]=n-i;
    }
    return arrayList;
}

int main() {
    int n=10;
    //cin>>n;
    
    int *p;
    //int x;
    p = getSortedArray(n);
    cout<<"Output Array: "<<endl;
    for (int i=0; i<n; i++) {
        cout << p[i] << " ";
    }

    return 0;

}