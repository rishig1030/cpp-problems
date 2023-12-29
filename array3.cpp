// find second largest number in an array
#include<iostream>
#include<vector>
using namespace std;
int secondlargest(vector <int> a){
    int max=INT16_MIN,max2=INT16_MIN;
    for(int i=0;i<a.size();i++){
        if(max<a[i] && max2<a[i]){
            max2=max;
            max=a[i];
        }
        else if(max2<a[i] && max>a[i]){
            max2=a[i];
        }
    }
    return max2;
}
int main(){
    int y;
    vector <int> a;
    a={3225,42,3225,42,527,321};
    y=secondlargest(a);
    cout<<y;
}
/*another approach is that , i can traverse twice to find the second largest in an array   OR  
i can simply change the value of largest element with the smallest element */
//these are the two more method to find the second largest element 
