//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
       int cur=arr[i];
       int par=arr[(i-1)/2];
       
       while(i>0 && par<cur){ //i>0 means its not the root node
           swap( arr[(i-1)/2] , arr[i] ); //swap parent position and cur position
           i=(i-1)/2; //move to new cur which was parent
           
           // updating new values
           cur=arr[i];
           if(i>0){
               par=arr[(i-1)/2];
           }
       }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        //add all elements to heap
        //not including 0th element bz no change is made
       for(int i=1; i<n; i++){
           heapify(arr,n,i); //ensures all property satisfied
       }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        
        int end=n; //not allowed position
        
        while(end>0){
            swap(arr[0],arr[--end]);
            
             int ind=0; //root node
             int cur=arr[ind];
             
             int c1=-1,c2=-1; //children
             
             //index of left child < not possible index
             if(ind*2+1<end)c1=arr[ind*2+1];
             
             //right child
             if(ind*2+2<end)c2=arr[ind*2+2];
             
             while(c1>cur || c2>cur){ //we want all children small bz max heap
                //continue till children are small
                
                //left child is greatest among 3 
                if(c1>c2 && c1>cur){
                    //swap left child and cur
                    swap( arr[ind*2+1], arr[ind] );
                    ind=ind*2+1;
                }
                else if(c2>cur){ //swap right child and cur
                    swap( arr[ind*2+2], arr[ind] );
                    ind=ind*2+2;
                }
                
                //updating new children 
                c1=-1,c2=-1; //children
             
                //index of left child < not possible index
                if(ind*2+1<end)c1=arr[ind*2+1];
             
                //right child
                if(ind*2+2<end)c2=arr[ind*2+2];
                
             }
             
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends