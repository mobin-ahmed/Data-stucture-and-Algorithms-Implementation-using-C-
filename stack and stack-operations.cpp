#include<iostream>
#include<string>
using namespace std;

class Stack{
    private:
        int top;
        int arr[5];
    public:
        Stack(){
            top=-1;
            for(int i=1; i<5; i++){
                arr[i]=0;
            }
        }
        
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        
        bool isFull(){
            if(top==4){
                return true;
            }
            else{
                return false;
            }
        }
        
        void push(int val){
            if(isFull()){
                cout<<"stack overflow!"<<endl;
            }
            else{
                top++;
                arr[top]=val;
            }
        }
        
        int pop(){
            if(isEmpty()){
                cout<<"stack underflow!"<<endl;
                return 0;
            }
            else{
                int popval=arr[top];
                arr[top]=0;
                top--;
                return popval;
            }
        }
        
        int count(){
            return(top+1);
        }
        
        int peak(int pos){
            if(isEmpty()){
                cout<<"stack underflow!"<<endl;
                return 0;
            }
            else{
                return arr[pos];
            }
        }
        
        void change(int pos, int val){
            arr[pos]=val;
            cout<<"Value has changed at location: "<<pos<<endl;
        }
        
        void display(){
            cout<<"All values in the stack are:"<<endl;
            for(int i=4; i>0; i--){
                cout<<arr[i]<<endl;
            }
        }
};

int main(){
    Stack s1;
    int option, pos, val;
    
    do{
        cout<<"What option do you want to perform? Select option number. Enter 0 to exit."<<endl;
        cout<<"1 for push"<<endl;
        cout<<"2 for pop"<<endl;
        cout<<"3 for isEmpty"<<endl;
        cout<<"4 for isFull"<<endl;
        cout<<"5 for peak"<<endl;
        cout<<"6 for count"<<endl;
        cout<<"7 for change"<<endl;
        cout<<"8 for display"<<endl;
        cout<<"9 for clrear screen"<<endl<<endl;
        
        cin>>option;
        
        switch(option){
            case 0:
                break;
            case 1:
                cout<<"Enter an item to push into the stack:"<<endl;
                cin>>val;
                s1.push(val);
                break;
                
            case 2:
                cout<<"Popped value is: "<<s1.pop()<<endl;
                break;
                
            case 3:
                if(s1.isEmpty()){
                    cout<<"The stack is empty"<<endl;
                }
                else{
                    cout<<"The stack is not empty"<<endl;
                }
                break;
                
            case 4:
                if(s1.isFull()){
                    cout<<"The stack is full"<<endl;
                }
                else{
                    cout<<"The stack is not full"<<endl;
                }
                break;
                
            case 5:
                cout<<"Enter position of item you want to peak:"<<endl;
                cin>>pos;
                cout<<"Value at position "<<pos<<" is "<<s1.peak(pos)<<endl;
                break;
                
            case 6:
                cout<<"The number of items in the stack is: "<<s1.count()<<endl;
                break;
                
            case 7:
                cout<<"Enter the postion and value you want to change"<<endl;
                cin>>pos>>val;
                s1.change(pos, val);
                break;
                
            case 8:
                s1.display();
                break;
                
            case 9:
                system("cls");
                break;
                
            default:
                cout<<"Enter proper option number!"<<endl;
                
        }
    }while(option!=0);
    
    return 0;
}