#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    Node(T data, Node* next)
    : data(data)
    , next(next){}
    ~Node(){ cout << "Destructor called!" << endl; delete next;}
    T data;
    Node* next;
};

template <typename T>
void PrintLinkedList(Node<T>* head)
{
    std::cout << "--------Printing linked list:------" << std::endl;
    while (head)
    {
        std::cout << head->data << " "; 
        head = head->next;
    }
    std::cout << endl;
    std::cout << "--------------end--------------" << std::endl;
}

template <typename T>
void ReverseLinkedList(Node<T>*& head)
{
    std::cout << "----------Reversing Linked List----------" << std::endl;
    if (!head) { return; }
    
    Node<T>* next = NULL;
    while (head)
    {
        Node<T>* nextNode = head->next;
        head->next = next;
        next = head;
        head = nextNode;
    }

    head = next;

    std::cout << "-------------END----------------" << std::endl;
}

template <typename T>
Node<T>* ReverseLinkedListRecursive(Node<T>* head, Node<T>* pre)
{
    if (!head) { return pre; }
    Node<T>* next = head->next;
    head->next = pre;
    return ReverseLinkedListRecursive<T>(next, head);
}

template <typename T>
void ReverseLinkedListRecursive(Node<T>*& head)
{
    cout << "----------------Reverse Linked List Recursion--------------" << endl;
    head = ReverseLinkedListRecursive<T>(head, NULL);
    cout << "-------------------------END-------------------------" << endl;
}

int main(void)
{
    typedef Node<int> _Node;
    _Node* head = new _Node(1, new _Node(2, new _Node(3, new _Node(4, new _Node(5,NULL)))));
    PrintLinkedList(head);
    ReverseLinkedList(head);
    PrintLinkedList(head);
    ReverseLinkedListRecursive(head);
    PrintLinkedList(head);
    delete head;
    return 0;
}

