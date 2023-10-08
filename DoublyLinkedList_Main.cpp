// DoublyLinkedList
// Created by Samuel Kwibe on 10/5/23.
//Auther:Samuel Kwibe
//Auther ID: 2278332
//Email:Samuel.kwibe@snhu.edu
//Assignment: Assignment # 3 Linked List Object
//Date:10/05/2023
//Time:9:45 AM


#include <iostream>
#include "DoublyLinkedList.hpp"
using namespace std;
int main() 
{
    DoublyLinkedList studentList;
    cout << "Welcome to SNHU student Generator Student program!" << endl;
    int choice;
    do
    {
        cout <<"========== MENU ==========" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Update Student Info" << endl;
        cout << "4. Find Student" << endl;
        cout << "5. Display All Students" << endl;
        cout << "6. Exit" << endl;
        cout<<"=========================="<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                // this function for adding a student on the list
                DoublyLinkedList::Node newStudent;
                cout << "Enter Student ID: ";
                cin >> newStudent.id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, newStudent.name);
                cout << "Enter Phone: ";
                getline(cin, newStudent.phone);
                cout << "Enter Address: ";
                getline(cin, newStudent.address);
                studentList.AddStudentInfo(newStudent);
                cout << "Student added successfully." << endl;
                cout<<"=========================="<<endl;
                break;
            }
            case 2:
            {
                // This function will be for deleting a student on the list using their stuent ID number
                int id;
                cout << "Enter Student ID to delete: ";
                cin >> id;
                studentList.DelStudentInfo(id);
                cout<<"=========================="<<endl;
                break;
            }
            case 3:
            {
                //This function is for updating student information that have already stored in the list using the studnt Id number
                int id;
                cin >> id;
                DoublyLinkedList::Node updatedStudent;
                cout << "Enter updated Name: ";
                cin.ignore();
                getline(cin, updatedStudent.name);
                cout << "Enter updated Phone: ";
                getline(cin, updatedStudent.phone);
                cout << "Enter updated Address: ";
                getline(cin, updatedStudent.address);
                studentList.UpdateStudentInfo(id, updatedStudent);
                cout << "Student info updated successfully." << endl;
                cout<<"=========================="<<endl;
                break;
            }
            case 4: {
                // This function is for finding a student on the list using student Id number
                int id;
                cout << "Enter Student ID to find: ";
                cin >> id;
                DoublyLinkedList::Node* foundStudent = studentList.FindStudent(id);
                if (foundStudent != nullptr) {
                    cout << "Student found:" << endl;
                    cout << "ID: " << foundStudent->id << endl;
                    
                    cout << "Name: " << foundStudent->name << endl;
                    cout << "Phone: " << foundStudent->phone << endl;
                    cout << "Address: " << foundStudent->address << endl;
                    
                }
                else
                {
                    cout << "Student not found." << endl;
                    cout<<"=========================="<<endl;
                }
                break;
            }
            case 5:
            {
                // This function is for displaying all student on the list with their infomations
                cout << "Student List:" << endl;
                studentList.DisplayStudentInfo();
                cout<<"=========================="<<endl;
                break;
            }
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                cout<<"=========================="<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}
