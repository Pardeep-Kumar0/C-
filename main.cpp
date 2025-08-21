/*
===============================================================================
                    COMPLETE C++ LEARNING GUIDE
                    From Basic to Advanced Topics
===============================================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>
#include <functional>
#include <exception>

using namespace std;

/*
===============================================================================
                            1. BASIC FUNDAMENTALS
===============================================================================
*/

// 1.1 Variables and Data Types
void basicDataTypes() {
    cout << "\n=== BASIC DATA TYPES ===" << endl;
    
    // Integer types
    int age = 25;
    long population = 1000000L;
    short temperature = -10;
    unsigned int positive = 100u;
    
    // Floating point
    float price = 19.99f;
    double pi = 3.14159265359;
    
    // Character and string
    char grade = 'A';
    string name = "John Doe";
    
    // Boolean
    bool isActive = true;
    
    // Auto keyword (C++11)
    auto autoVar = 42;        // int
    auto autoStr = "Hello";   // const char*
    
    cout << "Age: " << age << ", Grade: " << grade << endl;
    cout << "Name: " << name << ", Active: " << boolalpha << isActive << endl;
}

// 1.2 Constants and Literals
void constantsAndLiterals() {
    cout << "\n=== CONSTANTS AND LITERALS ===" << endl;
    
    const int MAX_SIZE = 100;           // Runtime constant
    constexpr double GRAVITY = 9.81;    // Compile-time constant
    
    #define PI 3.14159  // Macro (avoid in modern C++)
    
    enum Color { RED, GREEN, BLUE };    // Traditional enum
    enum class Status { ACTIVE, INACTIVE, PENDING }; // Scoped enum (C++11)
    
    Color c = RED;
    Status s = Status::ACTIVE;
    
    cout << "Max size: " << MAX_SIZE << ", Gravity: " << GRAVITY << endl;
    cout << "Color: " << c << ", Status: " << static_cast<int>(s) << endl;
}

// 1.3 Operators
void operators() {
    cout << "\n=== OPERATORS ===" << endl;
    
    int a = 10, b = 3;
    
    // Arithmetic operators
    cout << "Arithmetic: " << a + b << ", " << a - b << ", " << a * b << endl;
    cout << "Division: " << a / b << ", Modulo: " << a % b << endl;
    
    // Comparison operators
    cout << "Comparison: " << (a > b) << ", " << (a == b) << endl;
    
    // Logical operators
    bool x = true, y = false;
    cout << "Logical: " << (x && y) << ", " << (x || y) << ", " << !x << endl;
    
    // Bitwise operators
    cout << "Bitwise AND: " << (a & b) << ", OR: " << (a | b) << endl;
    
    // Assignment operators
    int c = a;
    c += 5;  // c = c + 5
    cout << "After +=: " << c << endl;
    
    // Increment/Decrement
    cout << "Pre-increment: " << ++a << ", Post-increment: " << b++ << endl;
}

/*
===============================================================================
                            2. CONTROL STRUCTURES
===============================================================================
*/

// 2.1 Conditional Statements
void conditionalStatements() {
    cout << "\n=== CONDITIONAL STATEMENTS ===" << endl;
    
    int score = 85;
    
    // if-else if-else
    if (score >= 90) {
        cout << "Grade: A" << endl;
    } else if (score >= 80) {
        cout << "Grade: B" << endl;
    } else if (score >= 70) {
        cout << "Grade: C" << endl;
    } else {
        cout << "Grade: F" << endl;
    }
    
    // Ternary operator
    string result = (score >= 60) ? "Pass" : "Fail";
    cout << "Result: " << result << endl;
    
    // Switch statement
    int day = 3;
    switch (day) {
        case 1: cout << "Monday" << endl; break;
        case 2: cout << "Tuesday" << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        default: cout << "Other day" << endl;
    }
}

// 2.2 Loops
void loops() {
    cout << "\n=== LOOPS ===" << endl;
    
    // For loop
    cout << "For loop: ";
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // While loop
    cout << "While loop: ";
    int j = 0;
    while (j < 3) {
        cout << j << " ";
        j++;
    }
    cout << endl;
    
    // Do-while loop
    cout << "Do-while loop: ";
    int k = 0;
    do {
        cout << k << " ";
        k++;
    } while (k < 2);
    cout << endl;
    
    // Range-based for loop (C++11)
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Range-based for: ";
    for (const auto& num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    // Break and continue
    cout << "Break example: ";
    for (int i = 0; i < 10; i++) {
        if (i == 3) break;
        if (i == 1) continue;
        cout << i << " ";
    }
    cout << endl;
}

/*
===============================================================================
                            3. FUNCTIONS
===============================================================================
*/

// 3.1 Basic Functions
int add(int x, int y) {
    return x + y;
}

// Function with default parameters
int multiply(int a, int b = 2) {
    return a * b;
}

// Function overloading
double multiply(double a, double b) {
    return a * b;
}

// Pass by reference
void increment(int& value) {
    value++;
}

// Pass by const reference (efficient for large objects)
void printString(const string& str) {
    cout << "String: " << str << endl;
}

void functionExamples() {
    cout << "\n=== FUNCTIONS ===" << endl;
    
    cout << "Add: " << add(5, 3) << endl;
    cout << "Multiply (default): " << multiply(5) << endl;
    cout << "Multiply (double): " << multiply(3.14, 2.0) << endl;
    
    int value = 10;
    increment(value);
    cout << "After increment: " << value << endl;
    
    printString("Hello World");
}

// 3.2 Lambda Functions (C++11)
void lambdaFunctions() {
    cout << "\n=== LAMBDA FUNCTIONS ===" << endl;
    
    // Basic lambda
    auto square = [](int x) { return x * x; };
    cout << "Square of 5: " << square(5) << endl;
    
    // Lambda with capture
    int multiplier = 3;
    auto multiplyBy = [multiplier](int x) { return x * multiplier; };
    cout << "5 * 3 = " << multiplyBy(5) << endl;
    
    // Lambda with mutable capture
    auto counter = [count = 0]() mutable { return ++count; };
    cout << "Counter: " << counter() << ", " << counter() << endl;
    
    // Using lambda with STL algorithms
    vector<int> numbers = {1, 2, 3, 4, 5};
    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n*2 << " "; });
    cout << endl;
}

/*
===============================================================================
                            4. ARRAYS AND STRINGS
===============================================================================
*/

// 4.1 Arrays
void arrayExamples() {
    cout << "\n=== ARRAYS ===" << endl;
    
    // C-style arrays
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "C-style array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // std::array (C++11)
    array<int, 4> stdArr = {10, 20, 30, 40};
    cout << "std::array: ";
    for (const auto& element : stdArr) {
        cout << element << " ";
    }
    cout << endl;
    
    // 2D arrays
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "2D array:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// 4.2 String Operations
void stringExamples() {
    cout << "\n=== STRINGS ===" << endl;
    
    string str1 = "Hello";
    string str2 = "World";
    string str3 = str1 + " " + str2;
    
    cout << "Concatenation: " << str3 << endl;
    cout << "Length: " << str3.length() << endl;
    cout << "Substring: " << str3.substr(0, 5) << endl;
    
    // String methods
    cout << "Find 'World': " << str3.find("World") << endl;
    
    string str4 = str3;
    str4.replace(6, 5, "C++");
    cout << "After replace: " << str4 << endl;
    
    // C-string to string conversion
    const char* cstr = "C-style string";
    string converted(cstr);
    cout << "Converted: " << converted << endl;
    
    // String to number conversion
    string numStr = "42";
    int num = stoi(numStr);
    cout << "String to int: " << num << endl;
}

/*
===============================================================================
                            5. POINTERS AND REFERENCES
===============================================================================
*/

// 5.1 Pointers
void pointerExamples() {
    cout << "\n=== POINTERS ===" << endl;
    
    int value = 42;
    int* ptr = &value;  // Pointer to value
    
    cout << "Value: " << value << endl;
    cout << "Address: " << &value << endl;
    cout << "Pointer: " << ptr << endl;
    cout << "Dereferenced: " << *ptr << endl;
    
    // Modifying through pointer
    *ptr = 100;
    cout << "After modification: " << value << endl;
    
    // Pointer arithmetic
    int arr[] = {1, 2, 3, 4, 5};
    int* arrPtr = arr;
    cout << "Array elements via pointer: ";
    for (int i = 0; i < 5; i++) {
        cout << *(arrPtr + i) << " ";
    }
    cout << endl;
    
    // Null pointer
    int* nullPtr = nullptr;
    if (nullPtr == nullptr) {
        cout << "Pointer is null" << endl;
    }
}

// 5.2 References
void referenceExamples() {
    cout << "\n=== REFERENCES ===" << endl;
    
    int original = 10;
    int& ref = original;  // Reference to original
    
    cout << "Original: " << original << endl;
    cout << "Reference: " << ref << endl;
    
    ref = 20;  // Modifies original
    cout << "After modifying reference: " << original << endl;
    
    // References in functions (already shown above in increment function)
}

// 5.3 Dynamic Memory Allocation
void dynamicMemory() {
    cout << "\n=== DYNAMIC MEMORY ===" << endl;
    
    // Dynamic allocation with new/delete
    int* dynamicInt = new int(42);
    cout << "Dynamic int: " << *dynamicInt << endl;
    delete dynamicInt;  // Don't forget to delete!
    
    // Dynamic array allocation
    int size = 5;
    int* dynamicArray = new int[size];
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i * 2;
    }
    
    cout << "Dynamic array: ";
    for (int i = 0; i < size; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;
    delete[] dynamicArray;  // Use delete[] for arrays
}

/*
===============================================================================
                            6. CLASSES AND OBJECTS (OOP)
===============================================================================
*/

// 6.1 Basic Class
class Rectangle {
private:
    double width, height;

public:
    // Constructor
    Rectangle(double w = 0, double h = 0) : width(w), height(h) {}
    
    // Destructor
    ~Rectangle() {
        cout << "Rectangle destroyed" << endl;
    }
    
    // Getters (accessors)
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    
    // Setters (mutators)
    void setWidth(double w) { 
        if (w >= 0) width = w; 
    }
    void setHeight(double h) { 
        if (h >= 0) height = h; 
    }
    
    // Member functions
    double area() const {
        return width * height;
    }
    
    double perimeter() const {
        return 2 * (width + height);
    }
    
    // Static member
    static int objectCount;
    static int getObjectCount() { return objectCount; }
    
    // Friend function declaration
    friend void printRectangle(const Rectangle& r);
};

// Static member definition
int Rectangle::objectCount = 0;

// Friend function definition
void printRectangle(const Rectangle& r) {
    cout << "Rectangle: " << r.width << " x " << r.height << endl;
}

// 6.2 Inheritance
class Shape {
protected:
    string color;
    
public:
    Shape(const string& c = "black") : color(c) {}
    virtual ~Shape() = default;  // Virtual destructor
    
    // Pure virtual function (makes Shape abstract)
    virtual double area() const = 0;
    
    // Virtual function
    virtual void display() const {
        cout << "Shape with color: " << color << endl;
    }
    
    string getColor() const { return color; }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r = 0, const string& c = "black") 
        : Shape(c), radius(r) {}
    
    double area() const override {
        return 3.14159 * radius * radius;
    }
    
    void display() const override {
        cout << "Circle with radius " << radius 
             << " and color " << color << endl;
    }
    
    double getRadius() const { return radius; }
};

// 6.3 Polymorphism Example
void polymorphismExample() {
    cout << "\n=== POLYMORPHISM ===" << endl;
    
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(5.0, "red"));
    shapes.push_back(make_unique<Circle>(3.0, "blue"));
    
    for (const auto& shape : shapes) {
        shape->display();
        cout << "Area: " << shape->area() << endl;
    }
}

/*
===============================================================================
                            7. STL CONTAINERS
===============================================================================
*/

void stlContainers() {
    cout << "\n=== STL CONTAINERS ===" << endl;
    
    // Vector - dynamic array
    vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);
    cout << "Vector size: " << vec.size() << endl;
    cout << "Vector elements: ";
    for (const auto& v : vec) cout << v << " ";
    cout << endl;
    
    // List - doubly linked list
    list<string> lst = {"apple", "banana", "cherry"};
    lst.push_front("apricot");
    cout << "List: ";
    for (const auto& item : lst) cout << item << " ";
    cout << endl;
    
    // Set - ordered unique elements
    set<int> s = {3, 1, 4, 1, 5, 9};  // Duplicates removed
    cout << "Set: ";
    for (const auto& elem : s) cout << elem << " ";
    cout << endl;
    
    // Map - key-value pairs
    map<string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    ages["Charlie"] = 35;
    
    cout << "Map (ages):" << endl;
    for (const auto& pair : ages) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Queue and Stack
    queue<int> q;
    stack<int> st;
    
    for (int i = 1; i <= 3; i++) {
        q.push(i);
        st.push(i);
    }
    
    cout << "Queue (FIFO): ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    cout << "Stack (LIFO): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

/*
===============================================================================
                            8. STL ALGORITHMS
===============================================================================
*/

void stlAlgorithms() {
    cout << "\n=== STL ALGORITHMS ===" << endl;
    
    vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    
    // Sort
    sort(numbers.begin(), numbers.end());
    cout << "Sorted: ";
    for (const auto& n : numbers) cout << n << " ";
    cout << endl;
    
    // Find
    auto it = find(numbers.begin(), numbers.end(), 25);
    if (it != numbers.end()) {
        cout << "Found 25 at position: " << distance(numbers.begin(), it) << endl;
    }
    
    // Binary search (requires sorted container)
    bool found = binary_search(numbers.begin(), numbers.end(), 22);
    cout << "22 exists: " << boolalpha << found << endl;
    
    // Count
    vector<int> data = {1, 2, 2, 3, 2, 4, 2};
    int count = count(data.begin(), data.end(), 2);
    cout << "Count of 2s: " << count << endl;
    
    // Transform
    vector<int> squared(data.size());
    transform(data.begin(), data.end(), squared.begin(), 
              [](int x) { return x * x; });
    cout << "Squared: ";
    for (const auto& n : squared) cout << n << " ";
    cout << endl;
    
    // Accumulate (sum)
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum: " << sum << endl;
}

/*
===============================================================================
                            9. TEMPLATES
===============================================================================
*/

// 9.1 Function Templates
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Function template specialization
template<>
const char* maximum<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

// 9.2 Class Templates
template<typename T>
class Stack {
private:
    vector<T> elements;
    
public:
    void push(const T& element) {
        elements.push_back(element);
    }
    
    void pop() {
        if (elements.empty()) {
            throw runtime_error("Stack is empty");
        }
        elements.pop_back();
    }
    
    T top() const {
        if (elements.empty()) {
            throw runtime_error("Stack is empty");
        }
        return elements.back();
    }
    
    bool empty() const {
        return elements.empty();
    }
    
    size_t size() const {
        return elements.size();
    }
};

void templateExamples() {
    cout << "\n=== TEMPLATES ===" << endl;
    
    // Function templates
    cout << "Max of 10, 20: " << maximum(10, 20) << endl;
    cout << "Max of 3.14, 2.71: " << maximum(3.14, 2.71) << endl;
    cout << "Max of strings: " << maximum(string("apple"), string("banana")) << endl;
    
    // Class templates
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    
    cout << "Stack size: " << intStack.size() << endl;
    cout << "Top element: " << intStack.top() << endl;
    
    Stack<string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    cout << "String stack top: " << stringStack.top() << endl;
}

/*
===============================================================================
                            10. EXCEPTION HANDLING
===============================================================================
*/

class CustomException : public exception {
private:
    string message;
    
public:
    CustomException(const string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

void riskyFunction(int value) {
    if (value < 0) {
        throw invalid_argument("Value cannot be negative");
    }
    if (value == 0) {
        throw CustomException("Custom error: Value is zero");
    }
    cout << "Value is: " << value << endl;
}

void exceptionHandling() {
    cout << "\n=== EXCEPTION HANDLING ===" << endl;
    
    vector<int> testValues = {5, -1, 0, 10};
    
    for (int val : testValues) {
        try {
            riskyFunction(val);
        }
        catch (const invalid_argument& e) {
            cout << "Invalid argument: " << e.what() << endl;
        }
        catch (const CustomException& e) {
            cout << "Custom exception: " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "Generic exception: " << e.what() << endl;
        }
        catch (...) {
            cout << "Unknown exception caught" << endl;
        }
    }
    
    // RAII example with smart pointers (automatic cleanup)
    try {
        unique_ptr<int[]> arr(new int[1000]);
        // Even if exception occurs, memory is automatically freed
        throw runtime_error("Something went wrong");
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << " (memory still cleaned up)" << endl;
    }
}

/*
===============================================================================
                            11. SMART POINTERS (C++11)
===============================================================================
*/

class Resource {
public:
    Resource(const string& name) : name_(name) {
        cout << "Resource " << name_ << " created" << endl;
    }
    
    ~Resource() {
        cout << "Resource " << name_ << " destroyed" << endl;
    }
    
    void use() {
        cout << "Using resource " << name_ << endl;
    }
    
private:
    string name_;
};

void smartPointers() {
    cout << "\n=== SMART POINTERS ===" << endl;
    
    // unique_ptr - exclusive ownership
    {
        unique_ptr<Resource> res1 = make_unique<Resource>("A");
        res1->use();
        
        // Transfer ownership
        unique_ptr<Resource> res2 = move(res1);
        if (!res1) {
            cout << "res1 is now empty" << endl;
        }
        res2->use();
    } // res2 automatically destroyed here
    
    // shared_ptr - shared ownership
    {
        shared_ptr<Resource> res1 = make_shared<Resource>("B");
        cout << "Reference count: " << res1.use_count() << endl;
        
        {
            shared_ptr<Resource> res2 = res1;  // Shared ownership
            cout << "Reference count: " << res1.use_count() << endl;
            res2->use();
        } // res2 goes out of scope, but resource not destroyed
        
        cout << "Reference count after res2 destroyed: " << res1.use_count() << endl;
        res1->use();
    } // Now resource is destroyed
    
    // weak_ptr - non-owning observer
    weak_ptr<Resource> weak;
    {
        shared_ptr<Resource> shared = make_shared<Resource>("C");
        weak = shared;
        
        if (auto locked = weak.lock()) {
            locked->use();
        }
    } // shared goes out of scope, resource destroyed
    
    if (weak.expired()) {
        cout << "Weak pointer expired" << endl;
    }
}

/*
===============================================================================
                            12. FILE I/O
===============================================================================
*/

void fileIO() {
    cout << "\n=== FILE I/O ===" << endl;
    
    // Write to file
    ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << "Hello, File I/O!" << endl;
        outFile << "Line 2" << endl;
        outFile << "Numbers: ";
        for (int i = 1; i <= 5; i++) {
            outFile << i << " ";
        }
        outFile << endl;
        outFile.close();
        cout << "Data written to file" << endl;
    }
    
    // Read from file
    ifstream inFile("example.txt");
    if (inFile.is_open()) {
        string line;
        cout << "Reading from file:" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    
    // Binary file operations
    ofstream binFile("data.bin", ios::binary);
    if (binFile.is_open()) {
        int numbers[] = {1, 2, 3, 4, 5};
        binFile.write(reinterpret_cast<const char*>(numbers), sizeof(numbers));
        binFile.close();
    }
    
    ifstream binRead("data.bin", ios::binary);
    if (binRead.is_open()) {
        int readNumbers[5];
        binRead.read(reinterpret_cast<char*>(readNumbers), sizeof(readNumbers));
        cout << "Binary data read: ";
        for (int i = 0; i < 5; i++) {
            cout << readNumbers[i] << " ";
        }
        cout << endl;
        binRead.close();
    }
    
    // String streams
    stringstream ss;
    ss << "Age: " << 25 << ", Score: " << 98.5;
    cout << "String stream: " << ss.str() << endl;
    
    // Parse from string stream
    stringstream parseStream("42 3.14 Hello");
    int intVal;
    double doubleVal;
    string stringVal;
    parseStream >> intVal >> doubleVal >> stringVal;
    cout << "Parsed: " << intVal << ", " << doubleVal << ", " << stringVal << endl;
}

/*
===============================================================================
                            13. MULTITHREADING (C++11)
===============================================================================
*/

void workerFunction(int id) {
    for (int i = 0; i < 3; i++) {
        cout << "Worker " << id << " working... step " << i + 1 << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "Worker " << id << " finished" << endl;
}

mutex mtx;
int sharedCounter = 0;

void incrementCounter(int id) {
    for (int i = 0; i < 1000; i++) {
        lock_guard<mutex> lock(mtx);  // Automatic lock/unlock
        sharedCounter++;
    }
    cout << "Thread " << id << " finished incrementing" << endl;
}

int calculateSquare(int x) {
    this_thread::sleep_for(chrono::milliseconds(1000));
    return x * x;
}

void multithreading() {
    cout << "\n=== MULTITHREADING ===" << endl;
    
    // Basic thread creation
    thread t1(workerFunction, 1);
    thread t2(workerFunction, 2);
    
    t1.join();  // Wait for thread to complete
    t2.join();
    
    // Thread synchronization with mutex
    sharedCounter = 0;  // Reset counter
    thread inc1(incrementCounter, 1);
    thread inc2(incrementCounter, 2);
    
    inc1.join();
    inc2.join();
    
    cout << "Final counter value: " << sharedCounter << endl;
    
    // Async and futures
    future<int> result = async(launch::async, calculateSquare, 5);
    cout << "Calculating square asynchronously..." << endl;
    
    // Do other work while calculation runs
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Doing other work..." << endl;
    
    // Get result (will wait if not ready)
    int square = result.get();
    cout << "Square result: " << square << endl;
    
    // Promise and future
    promise<string> prom;
    future<string> fut = prom.get_future();
    
    thread([&prom]() {
        this_thread::sleep_for(chrono::milliseconds(1000));
        prom.set_value("Hello from promise!");
    }).detach();
    
    cout << "Waiting for promise..." << endl;
    cout << "Promise result: " << fut.get() << endl;
}

/*
===============================================================================
                            14. MODERN C++ FEATURES
===============================================================================
*/

// 14.1 Move Semantics and Perfect Forwarding
class MovableClass {
private:
    int* data;
    size_t size;
    
public:
    // Constructor
    MovableClass(size_t s) : size(s), data(new int[s]) {
        cout << "Constructor: allocated " << size << " elements" << endl;
        for (size_t i = 0; i < size; i++) {
            data[i] = static_cast<int>(i);
        }
    }
    
    // Copy constructor
    MovableClass(const MovableClass& other) : size(other.size), data(new int[size]) {
        cout << "Copy constructor called" << endl;
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    
    // Move constructor (C++11)
    MovableClass(MovableClass&& other) noexcept : size(other.size), data(other.data) {
        cout << "Move constructor called" << endl;
        other.data = nullptr;
        other.size = 0;
    }
    
    // Copy assignment operator
    MovableClass& operator=(const MovableClass& other) {
        cout << "Copy assignment called" << endl;
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    // Move assignment operator (C++11)
    MovableClass& operator=(MovableClass&& other) noexcept {
        cout << "Move assignment called" << endl;
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
    
    // Destructor
    ~MovableClass() {
        delete[] data;
        cout << "Destructor: freed memory" << endl;
    }
    
    size_t getSize() const { return size; }
    int* getData() const { return data; }
};

MovableClass createMovableObject() {
    return MovableClass(5);  // RVO or move
}

// Perfect forwarding example
template<typename T>
void wrapper(T&& arg) {
    // Forward arg to another function while preserving its value category
    processValue(forward<T>(arg));
}

void processValue(const int& val) {
    cout << "Processing lvalue: " << val << endl;
}

void processValue(int&& val) {
    cout << "Processing rvalue: " << val << endl;
}

void modernCppFeatures() {
    cout << "\n=== MODERN C++ FEATURES ===" << endl;
    
    // Move semantics
    cout << "--- Move Semantics ---" << endl;
    MovableClass obj1(3);
    MovableClass obj2 = move(obj1);  // Move constructor
    MovableClass obj3 = createMovableObject();  // Move or RVO
    
    // Auto and decltype
    cout << "\n--- Auto and Decltype ---" << endl;
    auto x = 42;        // int
    auto y = 3.14;      // double
    auto z = "hello";   // const char*
    
    vector<int> vec = {1, 2, 3};
    auto it = vec.begin();  // vector<int>::iterator
    
    decltype(x) another_x = 100;  // int
    cout << "Auto variables: " << x << ", " << y << endl;
    
    // Range-based for loops (C++11)
    cout << "\n--- Range-based For ---" << endl;
    for (const auto& element : vec) {
        cout << element << " ";
    }
    cout << endl;
    
    // Uniform initialization (C++11)
    cout << "\n--- Uniform Initialization ---" << endl;
    int a{42};
    vector<int> numbers{1, 2, 3, 4, 5};
    map<string, int> ages{"Alice", 30, "Bob", 25};
    
    // Initializer lists
    auto initList = {1, 2, 3, 4, 5};
    for (auto val : initList) {
        cout << val << " ";
    }
    cout << endl;
    
    // nullptr (C++11)
    cout << "\n--- Nullptr ---" << endl;
    int* ptr = nullptr;  // Better than NULL
    if (ptr == nullptr) {
        cout << "Pointer is null" << endl;
    }
    
    // Strongly typed enums (C++11)
    enum class Color { RED, GREEN, BLUE };
    enum class Size { SMALL, MEDIUM, LARGE };
    
    Color c = Color::RED;
    // Size s = Size::RED;  // Error: different enum types
    
    // constexpr (C++11)
    constexpr int factorial(int n) {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    }
    
    constexpr int fact5 = factorial(5);  // Computed at compile time
    cout << "5! = " << fact5 << endl;
}

/*
===============================================================================
                            15. ADVANCED TOPICS
===============================================================================
*/

// 15.1 Function Objects and Functors
class Multiplier {
private:
    int factor;
    
public:
    Multiplier(int f) : factor(f) {}
    
    int operator()(int x) const {
        return x * factor;
    }
};

// 15.2 Template Metaprogramming
template<int N>
struct Factorial {
    static const int value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

// 15.3 SFINAE (Substitution Failure Is Not An Error)
template<typename T>
typename enable_if<is_integral<T>::value, T>::type
safeAdd(T a, T b) {
    return a + b;
}

template<typename T>
typename enable_if<is_floating_point<T>::value, T>::type
safeAdd(T a, T b) {
    return a + b + 0.001;  // Add small epsilon for floating point
}

// 15.4 Variadic Templates (C++11)
template<typename T>
void print(const T& value) {
    cout << value << endl;
}

template<typename T, typename... Args>
void print(const T& first, const Args&... args) {
    cout << first << " ";
    print(args...);  // Recursive call
}

// 15.5 Type Traits
template<typename T>
void analyzeType(const T& value) {
    cout << "\nType analysis:" << endl;
    cout << "Is integral: " << boolalpha << is_integral<T>::value << endl;
    cout << "Is floating point: " << is_floating_point<T>::value << endl;
    cout << "Is pointer: " << is_pointer<T>::value << endl;
    cout << "Is reference: " << is_reference<T>::value << endl;
    cout << "Size: " << sizeof(T) << " bytes" << endl;
}

void advancedTopics() {
    cout << "\n=== ADVANCED TOPICS ===" << endl;
    
    // Function objects
    cout << "--- Function Objects ---" << endl;
    Multiplier times3(3);
    cout << "5 * 3 = " << times3(5) << endl;
    
    vector<int> nums = {1, 2, 3, 4, 5};
    transform(nums.begin(), nums.end(), nums.begin(), times3);
    cout << "After multiplication by 3: ";
    for (auto n : nums) cout << n << " ";
    cout << endl;
    
    // Template metaprogramming
    cout << "\n--- Template Metaprogramming ---" << endl;
    cout << "Factorial<5>::value = " << Factorial<5>::value << endl;
    
    // SFINAE
    cout << "\n--- SFINAE ---" << endl;
    cout << "safeAdd(5, 3) = " << safeAdd(5, 3) << endl;
    cout << "safeAdd(5.5, 3.2) = " << safeAdd(5.5, 3.2) << endl;
    
    // Variadic templates
    cout << "\n--- Variadic Templates ---" << endl;
    print("Hello", 42, 3.14, "World", true);
    
    // Type traits
    analyzeType(42);
    analyzeType(3.14);
    int* ptr = nullptr;
    analyzeType(ptr);
}

/*
===============================================================================
                            16. DESIGN PATTERNS
===============================================================================
*/

// 16.1 Singleton Pattern
class Singleton {
private:
    static Singleton* instance;
    Singleton() = default;  // Private constructor
    
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
    
    void doSomething() {
        cout << "Singleton is doing something..." << endl;
    }
    
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

Singleton* Singleton::instance = nullptr;

// 16.2 Observer Pattern
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(int value) = 0;
};

class Subject {
private:
    vector<Observer*> observers;
    int state;
    
public:
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }
    
    void removeObserver(Observer* obs) {
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }
    
    void setState(int newState) {
        state = newState;
        notifyObservers();
    }
    
    int getState() const { return state; }
    
private:
    void notifyObservers() {
        for (auto* obs : observers) {
            obs->update(state);
        }
    }
};

class ConcreteObserver : public Observer {
private:
    string name;
    
public:
    ConcreteObserver(const string& n) : name(n) {}
    
    void update(int value) override {
        cout << "Observer " << name << " received update: " << value << endl;
    }
};

// 16.3 Factory Pattern
class Product {
public:
    virtual ~Product() = default;
    virtual void use() = 0;
};

class ConcreteProductA : public Product {
public:
    void use() override {
        cout << "Using Product A" << endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() override {
        cout << "Using Product B" << endl;
    }
};

class Factory {
public:
    enum ProductType { TYPE_A, TYPE_B };
    
    static unique_ptr<Product> createProduct(ProductType type) {
        switch (type) {
            case TYPE_A:
                return make_unique<ConcreteProductA>();
            case TYPE_B:
                return make_unique<ConcreteProductB>();
            default:
                return nullptr;
        }
    }
};

void designPatterns() {
    cout << "\n=== DESIGN PATTERNS ===" << endl;
    
    // Singleton
    cout << "--- Singleton Pattern ---" << endl;
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout << "Same instance: " << boolalpha << (s1 == s2) << endl;
    s1->doSomething();
    
    // Observer
    cout << "\n--- Observer Pattern ---" << endl;
    Subject subject;
    ConcreteObserver obs1("Observer1");
    ConcreteObserver obs2("Observer2");
    
    subject.addObserver(&obs1);
    subject.addObserver(&obs2);
    
    subject.setState(42);
    subject.setState(100);
    
    // Factory
    cout << "\n--- Factory Pattern ---" << endl;
    auto productA = Factory::createProduct(Factory::TYPE_A);
    auto productB = Factory::createProduct(Factory::TYPE_B);
    
    productA->use();
    productB->use();
}

/*
===============================================================================
                                MAIN FUNCTION
===============================================================================
*/

int main() {
    cout << "===========================================" << endl;
    cout << "    COMPLETE C++ LEARNING GUIDE" << endl;
    cout << "    From Basic to Advanced Topics" << endl;
    cout << "===========================================" << endl;
    
    try {
        // Execute all sections
        basicDataTypes();
        constantsAndLiterals();
        operators();
        
        conditionalStatements();
        loops();
        
        functionExamples();
        lambdaFunctions();
        
        arrayExamples();
        stringExamples();
        
        pointerExamples();
        referenceExamples();
        dynamicMemory();
        
        // Create some objects to demonstrate OOP
        cout << "\n=== CLASSES AND OBJECTS ===" << endl;
        Rectangle rect(5.0, 3.0);
        cout << "Rectangle area: " << rect.area() << endl;
        cout << "Rectangle perimeter: " << rect.perimeter() << endl;
        printRectangle(rect);
        
        polymorphismExample();
        
        stlContainers();
        stlAlgorithms();
        
        templateExamples();
        exceptionHandling();
        smartPointers();
        fileIO();
        multithreading();
        modernCppFeatures();
        advancedTopics();
        designPatterns();
        
        cout << "\n===========================================" << endl;
        cout << "    LEARNING GUIDE COMPLETED!" << endl;
        cout << "===========================================" << endl;
        
    } catch (const exception& e) {
        cout << "Exception occurred: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

/*
===============================================================================
                        COMPILATION AND STUDY NOTES
===============================================================================

COMPILATION:
To compile this program, use:
g++ -std=c++14 -pthread -o cpp_guide cpp_guide.cpp

Or for more recent features:
g++ -std=c++17 -pthread -o cpp_guide cpp_guide.cpp

STUDY PROGRESSION:
1. Start with sections 1-3 (Basics, Control Structures, Functions)
2. Master sections 4-6 (Arrays/Strings, Pointers, OOP)
3. Learn STL thoroughly (sections 7-8)
4. Understand Templates and Exception Handling (sections 9-10)
5. Modern C++ features (sections 11-12)
6. Advanced topics and patterns (sections 13-16)

KEY CONCEPTS TO PRACTICE:
- Memory management (pointers, references, RAII)
- Object-oriented programming (inheritance, polymorphism)
- STL containers and algorithms
- Template programming
- Exception safety
- Move semantics and modern C++ idioms
- Concurrent programming with threads
- Design patterns and best practices

ADDITIONAL RESOURCES:
- Practice coding problems on platforms like LeetCode, HackerRank
- Read "Effective C++" series by Scott Meyers
- Study the C++ Core Guidelines
- Contribute to open-source C++ projects
- Build personal projects to apply learned concepts

COMMON PITFALLS TO AVOID:
- Memory leaks (always delete what you new, prefer smart pointers)
- Dangling pointers and references
- Buffer overflows with C-style arrays
- Not handling exceptions properly
- Ignoring const-correctness
- Using raw pointers when smart pointers are better
- Not understanding move semantics in modern C++

===============================================================================
*/
