#ifndef MY_ARRAY_H_

static const int MAX_ARRAY_SIZE = 2000; 

class MyArray {
    
    private:
        int currSize; 
        int* arr;
        int numel;
        int maxSize;
    
    public: 
        MyArray(int aMaxSize = MAX_ARRAY_SIZE);
        ~MyArray();

        /**Get the number of elements in the array*/
        int size() { return numel; }

        /** Adds the element at the end of the array
        *
        * Returns the position/index at which the next element will be inserted
        * Returns -1 if append() fails, e.g., max size reached, or no memory available
        */
        int append(int aVal);

        /** Get element at given position*/
        int get(int pos) { return arr[pos];}

        /** human-readable print out of the elements of the array*/
        void print();
        
};

#endif