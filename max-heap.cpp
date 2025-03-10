#include <iostream>

using namespace std;

class MaxHeap {
    private:
        int* arr;
        int heap_size;

    public:
        MaxHeap(int size, int data[]){
            arr = data;
            heap_size = size;
            for(int idx = getParent(heap_size-1); idx >= 0; idx--){
                MaxHeapify(idx);
            }
        }

        int getParent(int idx){
            return (idx - 1)/2;
        }

        int getLeftChild(int idx){
            return (idx * 2) + 1;
        }

        int getRightChild(int idx){
            return (idx * 2) + 2;
        }

        void MaxHeapify(int idx){
            int l = getLeftChild(idx);
            int r = getRightChild(idx);
            int largest = idx;
            if (l < heap_size && arr[l] > arr[idx])
                largest = l;
            if (r < heap_size && arr[r] > arr[largest])
                largest = r;
            if (largest != idx) {
                swap(arr[idx], arr[largest]);
                MaxHeapify(largest);
            }
        }

        void swap(int &val1, int &val2){
            int temp = val1;
            val1 = val2;
            val2 = temp;
        }

        void display(){
            cout << "Heap size : " << heap_size << endl;
            cout << "Max Heap : ";
            for(int idx = 0; idx < heap_size; idx++){
                cout << arr[idx];
                if(idx != heap_size - 1){
                    cout << ", ";
                } else {
                    cout << endl;
                }
            }
            cout << endl;
        }

};

int main(){
    int data[10] = {2, 5, 7, 20, 11, 18, 9, 15, 13, 25};
    MaxHeap heap = MaxHeap(10, data);

    heap.display();
}

