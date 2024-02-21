// 
//

#include <iostream>
using namespace std;

struct tovar {
    int id;
    int p;
    tovar* next;
};

void AddFirst(tovar*& head, int id, int p) {
    tovar* newtovar = new tovar;
    newtovar->id = id;
    newtovar->p = p;
    newtovar->next = head;
    head = newtovar;
}
void Printlist(tovar* head) {
    tovar* tmp = head;
    while (tmp != nullptr) {
        cout << "ID Tovar: " << tmp->id << " Price: " << tmp->p << endl;
        tmp = tmp->next;
    }
}
void AddAfter (tovar*& head, int sid,int id, int q){
	if (head == NULL){
	cout<< "This list is empty \n"
	return;
	}
	tovar* tmp = head;
	while(tmp !=NULL && tmp->id != sid){
		tmp
	}

}
int main()
{
	AddAfter


//merge with prev task

