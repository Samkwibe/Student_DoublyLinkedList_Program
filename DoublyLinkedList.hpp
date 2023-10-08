//  DoublyLinkedList.hpp
//  DoublyLinkedList
//  Created by Samuel Kwibe on 10/5/23.


#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp
#include <stdio.h>

#include <string>

class DoublyLinkedList {
public:
    struct Node {
        int id;
        std::string name;
        std::string phone;
        std::string address;
        Node* next;
        Node* prev;
    };
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    int GetNumOfItems() const;
    void AddStudentInfo(const Node& student);
    void DelStudentInfo(int id);
    void UpdateStudentInfo(int id, const Node& updatedStudent);
    Node* FindStudent(int id);
    void DisplayStudentInfo() const;
private:
    Node* head_;
    Node* tail_;
    int num_entries_;
};
#endif /* DoublyLinkedList_hpp */
