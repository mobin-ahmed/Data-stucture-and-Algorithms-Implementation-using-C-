#include<iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int arr[5];
    
    public:
        Queue(){
            front=-1;
            rear=-1;
            for(int i=0; i<5; i++){
                arr[i]=0;
            }
        }
        
        bool isEmpty(){
            if(front==-1 && rear==-1){
                return true;
            }
            else{
                return false;
            }
        }
        
        bool isFull(){
            if(rear==5-1){
                return true;
            }
            else{
                return false;
            }
        }
        void enqueue(int val){
            if(isFull()){
                cout<<"Queue is full"<<endl;
                return;
            }
            else if(isEmpty()){
                front=rear=0;
                //arr[rear]=val;
            }
            else{
                rear++;
                //arr[rear]=val;
            }
            arr[rear]=val;
        }
        
        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return 0;
            }
            else if(rear == front){
                int x=arr[front];
                arr[front]=0;
                front=rear=-1;
                return x;
            }
            else{
                int x=arr[front];
                arr[front]=0;
                front++;
                return x;
            }
        }
        
        int count(){
            return (rear-front)+1;
        }
        
        void display(){
            cout<<"Items of queue are:"<<endl;
            for(int i=0; i<5; i++){
                cout<<arr[i]<<endl;
            }
        }
        
};

int main(){
    Queue q1;
    int option, val;
    
    do{
        cout<<"What option do you want to perform? Select option number. Enter 0 to exit."<<endl;
        cout<<"1 for enqueue"<<endl;
        cout<<"2 for dequeue"<<endl;
        cout<<"3 for isEmpty"<<endl;
        cout<<"4 for isFull"<<endl;
        cout<<"5 for count"<<endl;
        cout<<"6 for display"<<endl;
        cout<<"7 for screen clear"<<endl<<endl;
        
        cin>>option;
        
        switch(option){
            case 0:
                break;
            case 1:
                cout<<"Enter a value to add in queue:"<<endl;
                cin>>val;
                q1.enqueue(val);
                break;
            case 2:
                cout<<"The removed value from queue is: "<<q1.dequeue()<<endl;
                break;
            case 3:
                if(q1.isEmpty()){
                    cout<<"The queue is empty"<<endl;
                }
                else{
                    cout<<"The queue is not empty"<<endl;
                }
                break;
            case 4:
                if(q1.isFull()){
                    cout<<"The queue is full"<<endl;
                }
                else{
                    cout<<"The queue is not full"<<endl;
                }
                break;
            case 5:
                cout<<"Number of element in the queue is: "<<q1.count()<<endl;
                break;
            case 6:
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            default:
                break;
            
        }
    }while(option!=0);
    
    return 0;
}