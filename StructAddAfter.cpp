// Добавлено AddAfter, добавить в середине, добавить delete, (6 функций)
//
#include <iostream>
using namespace std;

struct tovar {
    int id;
    int p;
    tovar* next;
};

struct order {
    int order_id;
    tovar* items;
    order* next;
};
struct group {
	int group_num;
	tovar* next;
};

void AddFirst(tovar*& head, int id, int p) {
    tovar* newtovar = new tovar;
    newtovar->id = id;
    newtovar->p = p;
    newtovar->next = head;
    head = newtovar;
}

void AddOrder(order*& head, int order_id, tovar* items) {
    order* new_order = new order;
    new_order->order_id = order_id;
    new_order->items = items;
    new_order->next = nullptr;

    if (head == nullptr) {
        head = new_order;
    } else {
        order* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_order;
    }
}

void AddAfter(tovar*& head, int id, int new_id, int p) {
    tovar* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            tovar* newtovar = new tovar;
            newtovar->id = new_id;
            newtovar->p = p;
            newtovar->next = current->next;
            current->next = newtovar;
            return;
        }
        current = current->next;
    }
    cout << "ID not found in the list." << endl;
}

void AddGroup (group*& head, int group_num) {
	}

void Printlist(tovar* head) {
    tovar* tmp = head;
    while (tmp != nullptr) {
        cout << "ID Tovar: " << tmp->id << " Price: " << tmp->p << endl;
        tmp = tmp->next;
    }
}

void PrintOrders(order* head) {
    order* tmp = head;
    while (tmp != nullptr) {
        cout << "Order ID: " << tmp->order_id << endl;
        cout << "Items in this order:" << endl;
        Printlist(tmp->items);
        cout << "---------------------" << endl;
        tmp = tmp->next;
    }
}

int main() {
    tovar* head_tovar = nullptr;
    order* head_order = nullptr;

    AddFirst(head_tovar, 1, 10);
    AddFirst(head_tovar, 2, 20);

    tovar* items1 = nullptr;
    AddFirst(items1, 1, 10);
    AddFirst(items1, 2, 20);

    AddOrder(head_order, 1, items1);

    cout << "List of items:" << endl;
    Printlist(head_tovar);

    cout << "=====================" << endl;

    cout << "List of orders:" << endl;
    PrintOrders(head_order);
    
    cout << "List of product groups" << endl;
    

    cout << "Adding a new item after " << endl;
    AddAfter(head_tovar, 1, 3, 30);

    cout << "Updated list of items:" << endl;
    Printlist(head_tovar);

    return 0;
}
