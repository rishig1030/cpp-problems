// given an array find the next smallest element of each element in an array,
// where the next smallest is the element right to the given element smaller than the element

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

//method - 1 by O(n2) time complexity , not desirable

//method - 2
void nextsmaller(int arr[],int n){
    stack<int> st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        if(st.top()<arr[i]){
            int data = arr[i];
            arr[i] = st.top(); 
            st.push(data);
        }
        else{
            while(st.top()>=arr[i]){
                st.pop();
            }
            int data= arr[i];
            arr[i]=st.top();
            st.push(data);   
        }
    }
}


int main(){
    int n;
    cin>>n; int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    nextsmaller(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}