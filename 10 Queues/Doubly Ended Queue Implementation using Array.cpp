#include <iostream>
using namespace std;

class Deque{
        public:
        int *arr;
        int size;
        int front;
        int rear;

        Deque(int size) {
                this->size = size;
                arr = new int[size];
                front= -1;
                rear = -1;
        }

        void pushRear(int data) {
                 //TODO: add one more condition in the QUEUE FULL if block
                if((front == 0 && rear == size-1) || (front == rear + 1)) {
                        cout << "Q is fulll, cannot insert" << endl;
                        return;
                }
                else if(front == -1) {
                        //single element
                        front = rear = 0;
                        
                }
                else if(rear == size-1 && front != 0 ) {
                        //space available at front of the queue
                        //circular nature
                        rear = 0;
                        
                }
                else{
                        //default
                        rear++;
                        
                }
                arr[rear]= data; 
        }

        void pushFront(int data) {
                //TODO: add one more condition in the QUEUE FULL if block
                if((front == 0 && rear == size-1) || (front == rear + 1)) {
                        cout << "Q is fulll, cannot insert" << endl;
                        return;
                }
                else if(front == -1) {
                        //singel element
                        front = rear = 0;     
                }
                else if (front == 0 && rear != size-1 ) {
                        //space available at the end of queue
                        //circular nature
                        front = size-1;
                }
                else{
                        //default
                        front--;    
                }
                arr[front]= data; 
        }

        void popFront() {
                if(front == -1) {
                        cout << "Q is empty , cannot pop" << endl;
                        return;
                }
                else if (front == rear) {
                        //single element
                        arr[front] = -1;
                        //after popping queue is empty
                        front = -1;
                        rear = -1;  
                }
                else if(front == size-1) {
                        //circular nature
                        arr[front] = -1;
                        front = 0;
                }
                else {
                        //default
                        arr[front] = -1;
                        front++;
                }
                
        }

        void popRear() {
                if(front == -1) {
                        cout << "Q is empty , cannot pop" << endl;
                        return;
                }
                else if (front == rear) {
                        //single element
                        arr[front] = -1;
                        //after popping queue is empty
                        front = -1;
                        rear = -1;  
                }
                else if(rear == 0) {
                        //circular nature
                        arr[rear] = -1;
                       rear = size-1;
                }
                else {
                        //default
                        arr[rear] = -1;
                        rear--;
                }
                
        }

        void print() {
                for(int i=0; i<size; i++) {
                        cout << arr[i] << " ";
                }
                cout << endl;
        }
 };

int main() {
  Deque dq(10);
  dq.print();

  dq.pushRear(10);
  dq.pushRear(20);
  dq.pushRear(30);
  dq.pushRear(40);
  dq.pushRear(50);
  dq.pushRear(60);
  dq.pushRear(70);
  dq.pushRear(80);

  dq.print();

  dq.popRear();
  dq.print();

  dq.popRear();
  dq.print();

  dq.popFront();
  dq.print();

    dq.popFront();
  dq.print();

    dq.popFront();
  dq.print();

  dq.pushFront(101);
  dq.print();

  dq.pushFront(102);
  dq.print();

  dq.pushFront(103);
  dq.print();

    dq.pushFront(104);
  dq.print();

  dq.popFront();
  dq.print();

  dq.popFront();
  dq.print();

  dq.pushRear(201);
  dq.print();

    dq.pushRear(202);
  dq.print();

    dq.pushRear(203);
  dq.print();
    dq.pushRear(204);
  dq.print();

    dq.pushRear(205);
  dq.print();


  return 0;
}