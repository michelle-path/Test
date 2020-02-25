#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>
using namespace std;
int* getRandomArray(int n) {
    //int * pointer;
    int* arrayList = new int [n];
    int x;
    for (int j=0; j<n; j++) {
        //cout<<x<<" ";
        arrayList[j]=0;
        
        x=rand();// % 1000 + 1;
        
        if (j==0 ) {
            arrayList[0]=x;
        }
        else {
            // check if random number already exists in the array
            // if exists re-create random number and check if it exists in the array
            int i=0;
            //cout<<"array size: "<<sizeof(arrayList)/sizeof(arrayList[0])<<endl;
            while (i< n) {
                if (arrayList[i] == x ) {
                    x=rand();// % 1000 + 1;
                    //cout<<"dup found"<<endl;
                    i=0;
                }
                else
                {
                    i++;
                }
                //cout<<"j i x:"<<j<<" "<<i-1<<" "<<x<<endl;
            }
            arrayList[j]=x;
        }
    }
    //pointer = arrayList;
    //cout<<"inside function: "<<endl;
    //for (int i=0; i<n; i++) {
        
        //cout<<arrayList[i]<<" ";
    //}
    return arrayList;
}
int main() {
    int n=10;
    //cin>>n;
    
    int *p;
    //int x;
    p = getRandomArray(n);
    cout<<"Output Array: "<<endl;
    for (int i=0; i<n; i++) {
        cout << p[i] << " ";
    }

    return 0;

}