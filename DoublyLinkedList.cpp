//  Created by Samuel Raymond on 10/7/23.

#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;
DoublyLinkedList::DoublyLinkedList() 
{
    head_ = nullptr;
    tail_ = nullptr;
    num_entries_ = 0;
}
DoublyLinkedList::~DoublyLinkedList()
{
    Node* current = head_;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
int DoublyLinkedList::GetNumOfItems() const {
    return num_entries_;
}
void DoublyLinkedList::AddStudentInfo(const Node& student) 
{
    // Adding new student on the list
    Node* newNode = new Node(student);
    if (head_ == nullptr) 
    {
        head_ = newNode;
        tail_ = newNode;
} else
{
    newNode->prev = tail_;
    
    tail_ = newNode;
}
    num_entries_++;
}
void DoublyLinkedList::DelStudentInfo(int id) 
{
    // This is for deleting a student using the Id
    Node* current = head_;
    while (current != nullptr) 
    {
        if (current->id == id)
        {
            if (current == head_)
            {
                head_ = current->next;
                if (head_ != nullptr)
                {
                    head_->prev = nullptr;
                }
            } else if (current == tail_)
            {
                tail_ = current->prev;
                tail_->next = nullptr;
            } else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            num_entries_--;
            break;
        }
        current = current->next;
    }
}
void DoublyLinkedList::UpdateStudentInfo(int id, const Node& updatedStudent)
{
// This is the fucntion that will make the user to be able to update student info using the ID numer
    Node* current = head_;
    while (current != nullptr)
    {
        if (current->id == id)
        {
            current->name = updatedStudent.name;
            current->phone = updatedStudent.phone;
            current->address = updatedStudent.address;
            break;
        }
        current = current->next;
    }
}
DoublyLinkedList::Node* DoublyLinkedList::FindStudent(int id) 
{
    // Thsi will be for searching a student on the list using the ID numebr
    Node* current = head_;
    while (current != nullptr) 
    {
        if (current->id == id)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
void DoublyLinkedList::DisplayStudentInfo() const
{
//This will desplay all the student tht are on the list and show all the student information
    Node* current = head_;
    while (current != nullptr) {
        cout << "ID: " << current->id << endl;
        cout << "Name: " << current->name << endl;
        cout << "Phone: " << current->phone << endl;
        cout << "Address: " << current->address << endl;
        
        current = current->next;
    }
}
