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

void Delete(tovar*& head, int id) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->id == id) {
        tovar* temp = head;
        head = head->next;
        delete temp;
        cout << "Item with ID " << id << " successfully deleted." << endl;
        return;
    }

    tovar* current = head;
    while (current->next != nullptr) {
        if (current->next->id == id) {
            tovar* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "Item with ID " << id << " successfully deleted." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Item with ID " << id << " not found in the list." << endl;
}

void AddLast(tovar*& head, int id, int p) {
    tovar* newtovar = new tovar;
    newtovar->id = id;
    newtovar->p = p;
    newtovar->next = nullptr;

    if (head == nullptr) {
        head = newtovar;
    } else {
        tovar* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newtovar;
    }
}

void AddGroup(group*& head, int group_num) {
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

void PrintGroups(group* head) {
}

int main() {
    tovar* head_tovar = nullptr;
    order* head_order = nullptr;
    group* head_group = nullptr;

    AddFirst(head_tovar, 1, 10);
    AddFirst(head_tovar, 2, 20);

    tovar* items1 = nullptr;
    AddFirst(items1, 1, 10);
    AddFirst(items1, 2, 20);

    AddOrder(head_order, 1, items1);

    AddGroup(head_group, 1);
    AddGroup(head_group, 2);

    cout << "List of items:" << endl;
    Printlist(head_tovar);

    cout << "=====================" << endl;

    cout << "List of orders:" << endl;
    PrintOrders(head_order);

    cout << "List of product groups:" << endl;
    PrintGroups(head_group);

    cout << "Adding a new item after " << endl;
    AddAfter(head_tovar, 1, 3, 30);

    cout << "Updated list of items:" << endl;
    Printlist(head_tovar);

    cout << "Adding an item at the end of the list" << endl;
    AddLast(head_tovar, 4, 40);

    cout << "Updated list of items:" << endl;
    Printlist(head_tovar);

    cout << "Deleting item with ID 2" << endl;
    Delete(head_tovar, 2);

    cout << "Updated list of items:" << endl;
    Printlist(head_tovar);

    return 0;
}
