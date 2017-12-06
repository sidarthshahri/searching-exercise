#include <iostream>

struct node {
    int data;
    node* next;
};

// Function Prototypes
int menu();
void generateArray(int*, int);
int sequentialSearch(int, int*, int);
int sequentialSearchRecursion(int*, int, int, int);
void generateOrderedArray(int*, int);
int binarySearch(int*, int, int);
int binarySearchRecursive(int, int, int*, int);
node* generateLinkedList(int);
int linkedListSearch(node*, int);
int linkedListRecursiveSearch(node*, int, int);

using namespace std;

int main() {
    int input;
    int numOfElements;
    int numToSearchFor;
    int index;
    node* head;

    do {
        input = menu();
        int* array;
        switch(input) {
            case 1:         // Sequential Search
                cout << "Enter how many elements to search: ";
                cin >> numOfElements;
                cout << endl;
                array = new int[numOfElements];
                generateArray(array, numOfElements);
                cout << "Specify the element to be searched for: ";
                cin >> numToSearchFor;
                cout << endl;
                index = sequentialSearch(numToSearchFor, array, numOfElements);
                if(index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else
                    cout << "Element not found!" << endl;
                delete array;
                break;

            case 2:         // Sequential Search with Recursion
                cout << "Enter how many elements to search: ";
                cin >> numOfElements;
                cout << endl;
                array = new int[numOfElements];
                generateArray(array, numOfElements);
                cout << "Specify the element to be searched for: ";
                cin >> numToSearchFor;
                cout << endl;
                index = sequentialSearchRecursion(array, numToSearchFor, 0, numOfElements);
                if(index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else
                    cout << "Element not found!" << endl;
                delete array;
                break;

            case 3:         // Binary Search
                cout << "Enter how many elements to search: ";
                cin >> numOfElements;
                cout << endl;
                array = new int[numOfElements];
                generateOrderedArray(array, numOfElements);
                cout << "Specify the element to be searched for: ";
                cin >> numToSearchFor;
                cout << endl;
                index = binarySearch(array, numOfElements, numToSearchFor);
                if(index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else
                    cout << "Element not found!" << endl;
                delete array;
                break;

            case 4:         // Binary search with recursion
                cout << "Enter how many elements to search: ";
                cin >> numOfElements;
                cout << endl;
                array = new int[numOfElements];
                generateOrderedArray(array, numOfElements);
                cout << "Specify the element to be searched for: ";
                cin >> numToSearchFor;
                cout << endl;
                index = binarySearchRecursive(0, numOfElements-1, array, numToSearchFor);
                if(index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else
                    cout << "Element not found!" << endl;
                delete array;
                break;

            case 5:         // Linked list search
                cout << "Enter how many elements to search: ";
                cin >> numOfElements;
                cout << endl;
                head = generateLinkedList(numOfElements);
                cout << "Specify the element to be searched for: ";
                cin >> numToSearchFor;
                cout << endl;
                index = linkedListSearch(head, numToSearchFor);
                if(index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else
                    cout << "Element not found!" << endl;
                break;

            case 6:         // Linked list search with recursion
                cout << "Enter how many elements to search: ";
                cin >> numOfElements;
                cout << endl;
                head = generateLinkedList(numOfElements);
                cout << "Specify the element to be searched for: ";
                cin >> numToSearchFor;
                cout << endl;
                index = linkedListRecursiveSearch(head, numToSearchFor, 0);
                if(index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else
                    cout << "Element not found!" << endl;
                break;

            default:
                break;
        }
        cout << endl;
    } while(input != 0);
    return 0;
}

// Generates menu and receives input from user
int menu() {
    int input;
    cout << "Choose you search type: " << endl;
    cout << "1. Arrays: Sequential search without recursion" << endl;
    cout << "2. Arrays: Sequential search with recursion" << endl;
    cout << "3. Ordered Arrays: Binary Search without recursion" << endl;
    cout << "4. Ordered Arrays: Binary Search with recursion" << endl;
    cout << "5. Linked List: Search without recursion" << endl;
    cout << "6. Linked List: Search with recursion" << endl;
    cout << "Enter 0 to exit." << endl;
    cout << "Your choice: ";
    cin >> input;
    cout << endl;
    while (input > 6 || input < 0) {
        cout << "Please enter a number from the list only." << endl;
        cout << "Your choice: ";
        cin >> input;
    }
    return input;
}

// Generates an array with random numbers
void generateArray(int* array, int numOfElements) {
    srand(time(NULL));
    cout << "Elements added to the array: ";
    for(int i = 0; i < numOfElements; i++) {
        array[i] = rand() % 100;
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

// Generates an ordered array with random numbers
void generateOrderedArray(int* array, int numOfElements) {
    srand(time(NULL));
    array[0] = rand() % 10;
    cout << "Elements added to the array: " << array[0] << " ";
    for(int i = 1; i < numOfElements; i++) {
        array[i] = rand() % array[i-1]*2 + array[i-1]+1;
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

// Generates forward Linked List with random numbers
node* generateLinkedList(int numOfElements) {
    node* head = NULL;
    node* helper = NULL;
    srand(time(NULL));
    cout << "Elements added to linked list: ";
    for(int i = 0; i < numOfElements; i++) {
        node* newNode = new node;
        newNode->next = NULL;
        newNode->data = rand() % 100;
        if(head == NULL) {
            head = newNode;
            helper = newNode;
            cout << head->data << "->";
        } else {
            helper->next = newNode;
            helper = helper->next;
            cout << helper->data;
            if(i+1 != numOfElements)
                cout << "->";
        }
    }
    cout << endl << endl;
    return head;
}

// Searches an array sequentially for a specified element
int sequentialSearch(int numToSearchFor, int* array, int numOfElements) {
    for(int i = 0; i < numOfElements; i++) {
        if(numToSearchFor == array[i]) {
            return i;
        }
    }
    return -1;      // Will not be reached if element is found
}

// Searches an array sequentially with recursion for a specified element
int sequentialSearchRecursion(int* array, int numToSearchFor, int index, int numOfElements) {
    // Base case; when element is not found
    if(index == numOfElements)
        return -1;
    else if(array[index] == numToSearchFor)  // General case
        return index;
    else
        return sequentialSearchRecursion(array, numToSearchFor, index+1, numOfElements);
}

// Searches an ordered array with binary search for a specified element
int binarySearch(int* array, int numOfElements, int numToSearchFor) {
    int lowerBound = 0;
    int upperBound = numOfElements - 1;
    int midPoint = 0;

    while(lowerBound <= upperBound) {
        midPoint = (lowerBound + upperBound) / 2;
        if(array[midPoint] == numToSearchFor)
            return midPoint;
        else if(array[midPoint] > numToSearchFor)
            upperBound = midPoint - 1;
        else if(array[midPoint] < numToSearchFor)
            lowerBound = midPoint + 1;
    }
    return -1;
}

// Recursive binary search
int binarySearchRecursive(int lowerBound, int upperBound, int* array, int numToSearchFor) {
    // Base case; when element is not found
    if(lowerBound > upperBound) {
        return -1;
    } else {
        int middle = (upperBound + lowerBound) / 2;
        if(array[middle] == numToSearchFor)     // General case if tree
            return middle;
        else if(array[middle] > numToSearchFor)
            return binarySearchRecursive(lowerBound, upperBound - 1, array, numToSearchFor);
        else
            return binarySearchRecursive(lowerBound + 1, upperBound, array, numToSearchFor);
    }
}

// Searches a linked list for a specified element
int linkedListSearch(node* head, int numToSearchFor) {
    node* helper = head;
    int index = 0;
    while(helper != NULL) {
        if(numToSearchFor == helper->data)
            return index;
        index++;
        helper = helper->next;
    }
    return -1;      // Will not be reached if element is found
}

// Recursive linked list search
int linkedListRecursiveSearch(node* helper, int numToSearchFor, int count) {
    // Base case; when element is not found
    if(helper == NULL)
        return -1;
    if(helper->data == numToSearchFor)      // General Case
        return count;
    else
        return linkedListRecursiveSearch(helper->next, numToSearchFor, count+1);
}