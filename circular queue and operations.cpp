#include<iostream>
using namespace std;

class CircularQueue{
    private:
        int rear, front, arr[4], elementCount;
    public:
        CircularQueue(){
            rear=front=-1;
            for(int i=0; i<4; i++){
                arr[i]=0;
            }
            elementCount=0;
        }
        bool isFull(){
            if((rear+1)%4==front){
                return true;
            }
            else{
                return false;
            }
        }
        bool isEmpty(){
            if(rear==-1 && front==-1){
                return true;
            }
            else{
                return false;
            }
        }
        void enqueue(int val){
            if(isFull()){
                cout<<"circular q is full"<<endl;
                return;
            }
            else if(isEmpty()){
                rear=front=0;
                //arr[rear]=val;
            }
            else{
                rear=(rear+1)%4;
                //arr[rear]=val;
            }
            arr[rear]=val;
            elementCount++;
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"circular queue is empty"<<endl;
                return 0;
            }
            else if(rear==front){
                int x=arr[front];
                arr[front]=0;
                front=-1;
                elementCount--;
                return x;
            }
            else{
                int x=arr[front];
                arr[front]=0;
                front=(front+1)%4;
                elementCount--;
                return x;
            }
        }
        int count(){
            return elementCount;
        }
        
        void display(){
            cout<<"Items in the circular queue are:"<<endl;
            for(int i=0; i<4; i++){
                cout<<arr[i]<<endl;
            }
        }
};

int main(){
    CircularQueue cq1;
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
                cq1.enqueue(val);
                break;
            case 2:
                cout<<"The removed value from queue is: "<<cq1.dequeue()<<endl;
                break;
            case 3:
                if(cq1.isEmpty()){
                    cout<<"The queue is empty"<<endl;
                }
                else{
                    cout<<"The queue is not empty"<<endl;
                }
                break;
            case 4:
                if(cq1.isFull()){
                    cout<<"The queue is full"<<endl;
                }
                else{
                    cout<<"The queue is not full"<<endl;
                }
                break;
            case 5:
                cout<<"Number of element in the queue is: "<<cq1.count()<<endl;
                break;
            case 6:
                cq1.display();
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