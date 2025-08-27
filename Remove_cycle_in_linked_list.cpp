#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void inserttail(node* &head ,int val){
    node*n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void makecycle(node*&head,int pos){
    node*temp=head;
    node*starnode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            starnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=starnode;
}
bool detectcycle(node*&head){
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
void removecycle(node* &head){
    node*slow=head;
    node*fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }slow->next=NULL;
}
void display(node *head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node*head=NULL;
    inserttail(head,1);
    inserttail(head,2);
    inserttail(head,3);
    inserttail(head,4);
    inserttail(head,5);
    makecycle(head,3);
    cout<<detectcycle(head)<<endl;
    removecycle(head);
    cout<<detectcycle(head)<<endl;
    display(head);
    return 0;
}
