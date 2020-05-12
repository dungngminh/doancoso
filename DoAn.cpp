#include <bits/stdc++.h>

using namespace std;

struct LinkedList{
    int data;
    struct LinkedList *next;
 };

typedef struct LinkedList *node; 
 
node CreateNode(int value){
    node temp; 
    temp = (node)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    temp->data = value; 
    return temp;
}

node AddTail(node head, int value){
    node temp,p;
    temp = CreateNode(value);
    if(head == NULL){
        head = temp 
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
} 

node AddHead(node head, int value){
    node temp = CreateNode(value); 
    if(head == NULL){
        head = temp;
    }else{
        temp->next = head; 
        head = temp; 
    }
    return head;
} 

node AddAt(node head, int value, int position){
    if(position == 0 || head == NULL)
	{
        head = AddHead(head, value); 
    }
	else{
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            head = AddTail(head, value);            
        }else{
            node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}

node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
 
node DelTail(node head){
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; 
    return head;
}
 
node DelAt(node head, int position){
    if(position == 0 || head == NULL){
        head = DelHead(head); 
    }else{
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            head = DelTail(head);
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}

void Traverser(node head){
    for(node p = head; p != NULL; p = p->next){
        cout << p->data << " ";
    }
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n , val , pos;
	char cmd;
	node head=NULL;
	
	cin >> n;
	for ( int i=0 ; i<n ; i++ )
	{
		cin >> cmd;
		switch (cmd)
		{
			case 'D': 
				{
					cin >> pos;
					head = DelAt(head , pos-1);
					break;
				}
			case 'I':
				{
					cin >> val >> pos;
					head = AddAt(head , val , pos-1);
					break;
				}
		}
	}
	Traverser(head);
}
