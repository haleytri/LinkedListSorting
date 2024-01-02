#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct node 
{
  string name;
  int age;
  float deposit;
  int numDrinks;
  node *next;

  node() {
    name = "";
    age = -1;
    deposit = -1;
    numDrinks = -1;

    next = nullptr;
  }

  node(string n, int a, float d, int nDrinks) {
    name = n;
    age = a;
    deposit = d;
    numDrinks = nDrinks;

    next = nullptr;
  }

  node(string n, int a, float d, int nDrinks, node* nextNode) {
    name = n;
    age = a;
    deposit = d;
    numDrinks = nDrinks;

    next = nextNode;
  }
};

class LinkedList {
private:
  node *head;

public:
  LinkedList() { head = nullptr; }

  void insertAtHead(node *tempNode) 
  {
    node *cur = head;
    while (cur->next != nullptr)
    {  
      if(tempNode->name==cur->name && tempNode->age == cur->age)
      {
        node * temp=new node;
        cur->deposit = tempNode->deposit;
        cur->numDrinks = tempNode->numDrinks;
        return;
      }
      cur = cur->next;
      if(tempNode->name==cur->name && tempNode->age == cur->age)
      {
        node * temp=new node;
        cur->deposit = tempNode->deposit;
        cur->numDrinks = tempNode->numDrinks;
        return;
      }
    }
    
    
    tempNode->next=head;
    head=tempNode;
    
  }

  void insertAtEnd(node *tempNode) 
  {
    tempNode->next = nullptr;

    if (head==nullptr)
    {
      head=tempNode;
      return;
    }

    node *cur = head;
    
    while (cur->next != nullptr)
    {
      if(tempNode->name==cur->name && tempNode->age == cur->age)
      {
        node * temp=new node;
        cur->deposit = tempNode->deposit;
        cur->numDrinks = tempNode->numDrinks;
        return;
      }
      cur = cur->next;
      if(tempNode->name==cur->name && tempNode->age == cur->age)
      {
        node * temp=new node;
        cur->deposit = tempNode->deposit;
        cur->numDrinks = tempNode->numDrinks;
        return;
      }
    }
    cur->next = tempNode;
  }
  
  void insertAtPos(node *tempNode, int pos)
  {
    tempNode->next = nullptr;
    if(head==nullptr)
    {
      head = tempNode;
      return;
    }

    node *cur = head;
    node *prev = nullptr;

    while (cur->next != nullptr)
    {
      if(tempNode->name==cur->name && tempNode->age == cur->age)
      {
        node * temp=new node;
        cur->deposit = tempNode->deposit;
        cur->numDrinks = tempNode->numDrinks;
        return;
      }
      cur = cur->next;
      if(tempNode->name==cur->name && tempNode->age == cur->age)
      {
        node * temp=new node;
        cur->deposit = tempNode->deposit;
        cur->numDrinks = tempNode->numDrinks;
        return;
      }
    }

    cur = head;
        for(int i = 0; i < pos; i++)
    {
        if(cur == nullptr) //input validation
        {
            return;
        }

        prev = cur;
        cur = cur->next;
    }
    prev->next = tempNode;
    tempNode->next = cur;
  }

  void removeNumDrinks(int val) 
  {
    if(head==nullptr)
    {
      return;
    }

    node *prev = nullptr;
    node *cur = head;
    int size = 0;
    size = getSize();

    for(int i = -1; i < size; i++)
    {
      if(cur->next == nullptr)
      {
        return;
      }

      else if(cur->numDrinks == val)
      {
        if (prev==nullptr) //if head needs to be deleted
        {
          node *temp = head;
          head = head->next;
          delete temp;
        }
        else
        {
        prev->next = cur->next;
        delete cur;
        }
      }
      prev = cur;
      cur = cur->next;
    }

  }

  void removeDeposit(int val) 
  {
    if(head==nullptr)
    {
      return;
    }

    node *prev = nullptr;
    node *cur = head;
    int size = 0;
    size = getSize();

    for(int i = -1; i < size; i++)
    {
      if(cur->next == nullptr)
      {
        if (cur->deposit == val)
          {
            prev->next = nullptr;
          delete cur;
          }
        return;
      }

      else if(cur->deposit == val)
      {
        if (prev==nullptr) //if head needs to be deleted
        {
          node *temp = head;
          head = head->next;
          delete temp;
        }
        else
        {
        prev->next = cur->next;
        delete cur;
        }
      }
      prev = cur;
      cur = cur->next;
    }

  }

  void removeAge(int val) 
  {
    if(head==nullptr)
    {
      return;
    }

    node *prev = nullptr;
    node *cur = head;
    int size = 0;
    size = getSize();

    for(int i = -1; i < size; i++)
    {
      if(cur->next == nullptr)
      {
        if (cur->age == val)
          {
            prev->next = nullptr;
          delete cur;
          }
        return;
      }

      else if(cur->age == val)
      {
        if (prev==nullptr) //if head needs to be deleted
        {
          node *temp = head;
          head = head->next;
          delete temp;
        }
        else
        {
        prev->next = cur->next;
        delete cur;
        }
      }
      prev = cur;
      cur = cur->next;
    }

  }

    void removeName(string nameFind) 
  {
    if(head==nullptr)
    {
      return;
    }

    node *prev = nullptr;
    node *cur = head;
    int size = 0;
    size = getSize();

    for(int i = -1; i < size; i++)
    {
      if(cur->next == nullptr)
      {
          if (cur->name == nameFind)
          {
            prev->next = nullptr;
          delete cur;
          }
      }

      else if(cur->name == nameFind)
      {
        if (prev==nullptr) //if head needs to be deleted
        {
          node *temp = head;
          head = head->next;
          delete temp;
        }
        else
        {
        prev->next = cur->next;
        delete cur;
        }
      }
      prev = cur;
      cur = cur->next;
    }

  }

  void print(ofstream &ofs) 
  {
    node *cur = head;
    // format: [name: Rob; age: 34; deposit: 1234; number of drinks: 1]
    while (cur != nullptr)
    {
      ofs << "[name: " << cur->name << "; age: ";
      ofs << cur->age << "; deposit: " << cur->deposit << "; number of drinks: ";
      ofs << cur->numDrinks << "]" << endl;
      cur = cur->next;
    }
  }

  void print() 
  {
    node *cur = head;
    // format: [name: Rob; age: 34; deposit: 1234; number of drinks: 1]
    while (cur != nullptr)
    {
      cout << "[name: " << cur->name << "; age: ";
      cout << cur->age << "; deposit: " << cur->deposit << "; number of drinks: ";
      cout << cur->numDrinks << "]" << endl;
      cur = cur->next;
    }
  }

  int getSize()
    {
      node *cur = head;
      int size=-1;
    while (cur != nullptr)
    {
        size++;
        cur = cur->next;
    }
    return size;
    }

  void sortDeposit()
  {
    if(head == nullptr || head->next == nullptr)
      return;
    bool isSorted = false;
      node *cur;

    while(!isSorted)
    {
      isSorted = true;
      cur = head;
    while(cur->next != nullptr)
      {
      if(cur->deposit > cur->next->deposit)
        {
          node *temp=new node;
          temp->deposit = cur->deposit;
          temp->age = cur->age;
          temp->name = cur->name;
          temp->numDrinks = cur->numDrinks;

          cur->deposit = cur->next->deposit;
          cur->age = cur->next->age;
          cur->name = cur->next->name;
          cur->numDrinks = cur->next->numDrinks;


          cur->next->deposit = temp->deposit;
          cur->next->age = temp->age;
          cur->next->name = temp->name;
          cur->next->numDrinks = temp->numDrinks;

          isSorted = false;
        }
      cur = cur->next;
      }
    }
  }

  void sortAge()
  {
    if(head == nullptr || head->next == nullptr)
      return;
    bool isSorted = false;
      node *cur;
      while(!isSorted)
    {
      isSorted = true;
      cur = head;
    while(cur->next != nullptr)
    {
    if(cur->age > cur->next->age)
              {
          node *temp=new node;
          temp->deposit = cur->deposit;
          temp->age = cur->age;
          temp->name = cur->name;
          temp->numDrinks = cur->numDrinks;

          cur->deposit = cur->next->deposit;
          cur->age = cur->next->age;
          cur->name = cur->next->name;
          cur->numDrinks = cur->next->numDrinks;


          cur->next->deposit = temp->deposit;
          cur->next->age = temp->age;
          cur->next->name = temp->name;
          cur->next->numDrinks = temp->numDrinks;

          isSorted = false;
        }
    cur = cur->next;
    }
    }
  }

  void sortDrinks()
  {
    if(head == nullptr || head->next == nullptr)
      return;
    bool isSorted = false;
      node *cur;
      while(!isSorted)
    {
      isSorted = true;
      cur = head;
    while(cur->next != nullptr)
    {
    if(cur->numDrinks > cur->next->numDrinks)
        {
          node *temp=new node;
          temp->deposit = cur->deposit;
          temp->age = cur->age;
          temp->name = cur->name;
          temp->numDrinks = cur->numDrinks;

          cur->deposit = cur->next->deposit;
          cur->age = cur->next->age;
          cur->name = cur->next->name;
          cur->numDrinks = cur->next->numDrinks;


          cur->next->deposit = temp->deposit;
          cur->next->age = temp->age;
          cur->next->name = temp->name;
          cur->next->numDrinks = temp->numDrinks;

          isSorted = false;
        }
    cur = cur->next;
    }
    }
  }

void sortNames()
  {
    if(head == nullptr || head->next == nullptr)
      return;
    bool isSorted = false;
      node *cur;
      while(!isSorted)
    {
      isSorted = true;
      cur = head;
    while(cur->next != nullptr)
    {
    if(cur->name[0] > cur->next->name[0])
        {
          node *temp=new node;
          temp->deposit = cur->deposit;
          temp->age = cur->age;
          temp->name = cur->name;
          temp->numDrinks = cur->numDrinks;

          cur->deposit = cur->next->deposit;
          cur->age = cur->next->age;
          cur->name = cur->next->name;
          cur->numDrinks = cur->next->numDrinks;


          cur->next->deposit = temp->deposit;
          cur->next->age = temp->age;
          cur->next->name = temp->name;
          cur->next->numDrinks = temp->numDrinks;

          isSorted = false;
        }
    cur = cur->next;
    }
    }
  }

  
};

#endif