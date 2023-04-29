/*
 Author : Taymour
 */
#include <iostream>
#include <algorithm>
#include <ctime>
#include<map>

using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template<typename T>
// selection sort
//o(n^2)
void selectionSort(T array[], int n) {
    //index to the current unordered minimum value
    int minimum;
    for (int i = 0; i < n - 1; i++) {
        minimum = i;
        /*
         *selects the minimum array item and puts it in place with the sorted array part
         */
        for (int j = i + 1; j < n; ++j) {
            if (array[j] < array[minimum]) {
                minimum = j;
            }
            if (minimum != i) {
                swap(array[minimum], array[i]);
            }

        }
    }
}

template<typename T>
/* best case o(n)
   worst case o(n^2)
*/
void insertionSort(T array[], int n) {
    T current;
    int j;
    //for loops starts from 1 not 0 since we let the first element is the sorted one
    for (int i = 1; i < n; ++i) {
        current = array[i];
        j = i - 1;
        /*
         * Loops on every pair of the array then swaps if one is not in his place
         * The loop goes n-1,n-2,n-3 ......3,2,1 loops as the right side of the array gets sorted automatically.
         */
        while (j >= 0 && array[j] > current) {
            swap(array[j + 1], array[j]);
            j = j - 1;
        }
        array[j + 1] = current;
    }
}

template<typename T>
/*
best case o(1)
average case o(n^2)
worst case o(n^2)
*/
void BubbleSort(T array[], int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }

}

// Merge Sort algorithm

template<typename T>
void merge(T arr[], int Lindex, int middle, int Rindex) {
    int leftSize = middle - Lindex + 1;  // left array size
    int rightSize = Rindex - middle; // Right array size
    //Create the Two sub-arrays
    T leftArr[leftSize];
    T rightArr[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[Lindex + i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int leftIndexArr = 0;
    int rightIndexArr = 0;
    int mergedIndex = Lindex;
    //compare the two arrays untill one ends 
    while (leftIndexArr < leftSize && rightIndexArr < rightSize) {
        if (leftArr[leftIndexArr] <= rightArr[rightIndexArr]) {     // if the left item is lower 
            // improt it to the big array
            arr[mergedIndex++] = leftArr[leftIndexArr++];
        } else {                                                    // if the right item is lower 
            // improt it to the big array
            arr[mergedIndex++] = rightArr[rightIndexArr++];
        }
    }

    while (leftIndexArr < leftSize) {       // unless it's the end of the first array ipmort the
        //items into the bigger array
        arr[mergedIndex++] = leftArr[leftIndexArr++];
    }

    while (rightIndexArr < rightSize) {     // unless it's the end of the second array ipmort the
        //items into the bigger array
        arr[mergedIndex++] = rightArr[rightIndexArr++];
    }
}

template<typename T>
// all cases o(n log n )
void mergeSort(T arr[], int Lindex, int Rindex) {
    //test base case if size of array =1 
    if (Lindex >= Rindex) {
        return;
    }

    int middle = (Lindex + Rindex) / 2; // calculate the mid index

    mergeSort(arr, Lindex, middle); // split the first half and sort
    mergeSort(arr, middle + 1, Rindex); // split the second half and sort

    merge(arr, Lindex, middle, Rindex); // merge the final array sorted
}

// best case o(n^1.5)
// worst case o(n^2)
int shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; i += 1) {

            int temp = arr[i];


            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return 0;
}

template<typename T>
T partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }

    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);

}

template<typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        T partt = partition(arr, low, high);
        quickSort(arr, low, partt - 1);
        quickSort(arr, partt + 1, high);
    }


}

class doubleLinkedList {
private:
    struct Node {
        Node *next{};
        Node *previous{};
        int data{};

        Node(int data) : data(data) {};
    };

private:
    Node *head{};
    Node *tail{};

public:
    void push(int val) {
        Node *temp = new Node(val);
        if (!head && !tail) {
            head = tail = temp;
        }


        tail->next = temp;
        temp->previous = tail;
        tail = temp;
    }

    void print() {
        for (Node *cur = head; cur != NULL; cur = cur->next)
            cout << cur->data << " ";

    }


    void reverse() {
        for (Node *cur = head; cur != nullptr;) {
            Node *temp = cur->next;
            cur->next = cur->previous;
            cur->previous = temp;
            cur = cur->previous;
        }
        Node *t = head;
        head = tail;
        tail = t;
        tail->next = NULL;

    }

};

template<typename T>
void countSort(T arr[], int n) {
    long Max = getmax(arr, n);
    long output[n + 1];
    long Count[Max + 1];

    for (int i = 0; i < Max; i++) {
        Count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        Count[arr[i]]++;
    }
    for (int i = 1; i <= Max; i++) {
        Count[i] += Count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[Count[arr[i]] - 1] = arr[i];
        Count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

}

struct Node {
    int info{};
    Node *link{};
    Node *previous{};
};


class linked {
public:
    Node *head;
    Node *tail;
    int size;
    Node *current;

    linked() {
        size = 0;
        head = NULL;
    }

    void push(int n) {
        if (size = 0) {
            Node *currentnode;
            currentnode->info = n;
            currentnode->link = NULL;
            head = currentnode;
            current = head;
        } else {
            Node *currentnode;
            currentnode->info = n;
            currentnode->link = NULL;
            current->link = currentnode;

        }
    }
};

class Stack {
private:
    int size;
    int *arr;
    int max;
public:
    Stack(int n) {
        arr = new int[n];
        max = n;
    }

    void top() {
        cout << arr[size - 1];
    };

    void pop() {
        if (size != 0) {
            cout << arr[size - 1];
            size--;
        }
    };

    void clear() {
        size = 0;
    };

    bool isEmpty() {
        return (size == 0);
    };

    void push(int x) {
        if (size <= max) {
            size++;
            arr[size - 1] = x;

        } else {
            cout << "Stack is Full !";
        }

    };

};

template<class T>
class Queue {
private:
    int size, leftPointer, rightPointer;
    T *arr;
public:
    explicit Queue(int n) {
        leftPointer = rightPointer = 0;
        size = n;
        arr = new T[n + 5];
    }

    Queue() {}

    void enqueue(T data) {
        // check queue is full or not
        if (size == rightPointer) {
            cout << "Queue is full" << endl;
            return;
        }

            // insert element at the rear
        else {
            arr[rightPointer++] = data;
        }
    }

    T dequeue() {
        // if queue is empty
        T data = arr[0];
        if (leftPointer == rightPointer) {
            cout << "QUEUE IS EMPTY" << endl;
            return T();
        } else {
            for (int i = 0; i < rightPointer - 1; i++) {
                arr[i] = arr[i + 1];
            }
            rightPointer--;
        }
        return data;
    }

    T first() {
        return arr[leftPointer];
    }

    bool isEmpty() {
        return (rightPointer - leftPointer == 0);
    }

    int queueSize() {
        return rightPointer - leftPointer;
    }

    void clear() {
        rightPointer = leftPointer = 0;
    }

    void print() {
        for (int i = leftPointer; i < rightPointer; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    void reverseQueue() {
        reverse(arr, arr + rightPointer);
    }

    void sort() {
        set<T> s;
        while (!isEmpty()) {
            s.insert(dequeue());
        }
        for (auto &i: s) {
            enqueue(i);
        }
    }
};

void mergeLinkedLists(vector<LinkedList<int>> &VLL) {
    LinkedList<int> result;
    result = VLL.front();
    for (int i = 1; i < (int) VLL.size(); i++) {
        auto curr = VLL[i].Head;
        while (curr != nullptr) {// loop on the current linked list
            // add numbers from current linked list one by one inside RESULT
            auto currResult = result.Head;
            int pos = 0;
            while (currResult != nullptr) {
                if (currResult->val >= curr->val)break;
                pos++;
                currResult = currResult->next;
            }
            result.InsertAt(pos, curr->val);
            curr = curr->next;
        }
    }
    result.Print();
}

void CombineNodesBetweenZeros(LinkedList<int> &linkedList) {
    LinkedList<int> resultingLinkedList;
    auto curr = linkedList.Head;
    int zeros = 0, result = 0;
    while (curr != nullptr) {
        if (curr->val == 0)
            zeros++;
        if (zeros == 2) {
            resultingLinkedList.pushBack(result);
            zeros--;
            result = 0;
        } else
            result += curr->val;
        curr = curr->next;
    }
    resultingLinkedList.Print();
}

void generateBinary(int n, Queue<int> &q) {
    if (n == 0)return;
    generateBinary(n / 2, q);
    q.enqueue(n & 1);
}

void binaryNumbers(int n) {
    Queue<int> q(32);
    for (int i = 1; i <= n; i++) {
        generateBinary(i, q);
        while (!q.isEmpty()) {
            cout << q.dequeue();
        }
        cout << ' ';
        q.clear();
    }
}

template<class T>
class StackUsingQueue {
    Queue<T> q;
public:
    explicit StackUsingQueue(int n) {
        Queue<T> qq(n);
        q = qq;
    }

    void push(T n) {
        q.enqueue(n);
    }

    void pop() {
        q.reverseQueue();
        q.dequeue();
        q.reverseQueue();
    }

    void print() {
        q.print();
    }
};

int main() {

    //---------------------------------------------------------------------

    // Merge K Sorted Linked Lists

    /*vector<LinkedList<int>> vectorOfLinkedLists;
    int no_of_LinkedLists;
    cin >> no_of_LinkedLists;
    vectorOfLinkedLists.resize(no_of_LinkedLists);
    for (int i = 0; i < (int) vectorOfLinkedLists.size(); i++) {
        cout << "ENTER " << i + 1 << "th Linked List Size" << endl;
        int n;
        cin >> n;
        while (n--) {
            int x;
            cin >> x;
            vectorOfLinkedLists[i].pushBack(x);
        }
    }
    mergeLinkedLists(vectorOfLinkedLists);*/

    //---------------------------------------------------------------------

    // Combine Nodes Between Zeros

    /*vector<int> v = {0,3,1,0,4,5,2,0};
    vector<int> z = {0, 1, 0, 3, 0, 2, 2, 0};
    LinkedList<int> linkedList;
    for(auto &i:v){
        linkedList.pushBack(i);
    }
    CombineNodesBetweenZeros(linkedList);*/

    //---------------------------------------------------------------------
    // Binary Numbers From 1 to N

    /*binaryNumbers(5);*/

    //---------------------------------------------------------------------

    // Stack Using Queue

    /*StackUsingQueue<int> STC(10);
    STC.push(10);
    STC.push(20);
    STC.push(30);
    STC.push(40);
    STC.push(50);
    STC.push(60);
    STC.print();
    STC.pop();
    STC.print();
    STC.pop();*/

    //---------------------------------------------------------------------

    // sort Queue

    /*Queue<int> q(50);
    q.enqueue(50);
    q.enqueue(40);
    q.enqueue(30);
    q.enqueue(20);
    q.enqueue(10);
    q.sort();
    q.print();*/

    //---------------------------------------------------------------------

}
