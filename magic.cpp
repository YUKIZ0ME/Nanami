#include<iostream>
#include<cassert>
using namespace std;
template<class Type>class Stack{
    private:
        Type *urls;
        int max_size,top_index;
    public:
        Stack(int length_input){
            urls = new Type[length_input];
            max_size = length_input;
            top_index = -1;
        }
    
        ~Stack(){
            delete[] urls;
        }
    
        bool push(const Type &element){
            if(top_index >= max_size - 1){
                return false;
            }
            
            top_index++;
            urls[top_index] = element;
            return true;
        }
    
        bool pop(){
            assert(top_index >= 0);
            top_index--;
            return true;
        }
    
        Type top(){
            assert(top_index >= 0);
            return urls[top_index];
        }
    
        bool empty(){
            if(top_index < 0){
                return true;
            }
            else
                return false;
        }
};



int main(){
    int n,judge;
    int j = 1;
    cin>>n;
    int *a = new int[n];
    Stack<int> stack(n);
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    for(int i = 1; i <= n; i++){
        judge = 0;
        while(judge != 1 && j <= n){
            if(stack.empty()){
                stack.push(j);
            }
            else if(a[i - 1] == stack.top()){
                stack.pop();
                judge = 1;
                break;
            }
            else{
                j++;
                stack.push(j);
            }
        }
        if(j > n){
            judge = 0;
            break;
        }
     }
    if(judge == 0){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    
    return 0;
}
