/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 26th, 2020, 6:14 PM
 * Purpose:  Example of Mark Sort with Structure
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
Array *filAray(int);
void prntAry(const Array *,int);
void markSrt(Array *);
void cleanUp(Array *);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    int size=100;
    int perLine=10;
    Array *array;
    
    //Initialize all known variables
    array=filAray(size);
    cout<<"Before Sorting"<<endl;
    prntAry(array,perLine);
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    markSrt(array);
    
    //Display the Inputs/Outputs
    cout<<"After Sorting"<<endl;
    prntAry(array,perLine);

    //Clean up the code, close files, deallocate memory, etc....
    cleanUp(array);
    
    //Exit stage right
    return 0;
}

//Function Implementations

void cleanUp(Array *array){
    delete []array->index;
    delete []array->data;
    delete array;
}

void markSrt(Array *a){
    //Find the smallest element in List i
    for(int i=0;i<a->size-1;i++){
        //Swap as you go to place the smallest element at the top
        for(int j=i+1;j<a->size;j++){
            //Logic swap
            if(a->data[a->index[i]]>a->data[a->index[j]]){
                a->index[i]=a->index[i]^a->index[j];
                a->index[j]=a->index[i]^a->index[j];
                a->index[i]=a->index[i]^a->index[j];
            }
        }
    }
}


void prntAry(const Array *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->data[a->index[i]]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *filAray(int n){
    //Declare and allocate the array
    n=n<2?2:n;
    Array *array=new Array;
    array->data=new int[n];
    array->index=new int[n];
    array->size=n;
    for(int i=0;i<n;i++){
        array->data[i]=rand()%90+10;//2 Digit Random Array
        array->index[i]=i;
    }
    return array;
}