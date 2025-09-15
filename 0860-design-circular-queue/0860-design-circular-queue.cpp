class MyCircularQueue {
public:

    vector<int> v;
    int size=0,capacity;

    int front,rear;
   

    MyCircularQueue(int k) {

        v.resize(k);
        size=0;
        capacity=k;

        front=0;
        rear=-1;
     
        
    }
    
    bool enQueue(int value) {

       if (this->isFull()) {
            return false;
        }
        rear = (rear + 1) % capacity;
        v[rear] = value;
        size++;
        return true;

        
    }
    
    bool deQueue() {

        if (this->isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() {
        
        if (this->isEmpty()) {
            return -1;
        }
        return v[front];
         

    }
    
    int Rear() {

        if (this->isEmpty()) {
            return -1;
        }
        return v[rear];
        
        
    }
    
    bool isEmpty() {

      return size==0;
        
    }
    
    bool isFull() {

       return size==capacity;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */