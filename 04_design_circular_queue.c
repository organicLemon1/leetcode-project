typedef struct {
    int* array;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    queue->array = (int*)malloc((k + 1) * sizeof(int));
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = k;
    return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    obj->array[obj->rear] = value;
    obj->rear = (obj->rear + 1) % (obj->capacity + 1);
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    obj->front = (obj->front + 1) % (obj->capacity + 1);
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->array[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->array[(obj->rear - 1 + obj->capacity + 1) % (obj->capacity + 1)];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->array);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/