#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int d){
        data=d;
        next=NULL;
    }
};
void print_list(node* head){
    //node* temp=head;
    if(!head){
        cout<<"\nList is Empty\n";
    }
    while(head!=NULL){

        cout<< head->data<<" ";
        head=head->next;
    }
}
node* deletefront(node* head){
    head=head->next;
    //display remaining elements
    cout<<"\nDelete head\n";
    print_list(head);
}
void deleteatlast(node* head){
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    //display remaining elements
    cout<<"\nDelete at last\n";
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
void insertatfront(node** head,int data){
    node* temp=new node(data);
    temp->next=*head;
    *head=temp;
}
void insertatend(node** head,int data){
    node* newnode=new node(data);
    node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    
}
void insertatpos(node* head,int val,int pos){
    if(!head)
    return ;
    node* temp=head;
    node* newnode=new node(val);
    for(int i=1;i<(pos-1);i++){
        if(temp->next != NULL)
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void deleteatpos(node* head,int pos){
    node* temp=head;
    for(int i=1;i<(pos-1);i++){
        if(temp->next != NULL)
        temp=temp->next;
    }
    temp->next=temp->next->next;
}
void search(node* head,int value){
    node* temp=head;
    int pos=0,f=0;
    while(temp->next != NULL){
        ++pos;
        if(temp->data == value){
            ++f;
        cout<<"Entered Element Found at Position: "<<pos<<"\n";
        break;
        }
        temp=temp->next;
    }
    if(!f){
    cout<<"Element Not Found ";
    }

}
void reverse(node* head){
    node* current=head;
    node* next=NULL;
    node* prev=NULL;

    while(current != NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    print_list(head);
}
void sort(node* head){
    node *cur=head,*index=NULL;
    int temp;
    if(head==NULL)
    return;
    else{
        while(cur != NULL){
            index=cur->next;
            while(index != NULL){
            if(cur->data > index->data){
                temp=cur->data;
                cur->data=index->data;
                index->data=temp;
            }
            index=index->next;
        }
        cur=cur->next;
    }
    }
    print_list(head);
}
int main(){
    node* head=NULL;
    int ch,data,choice=1;
    do{
    cout<<"\n1.Insert at Front\n2.Insert at End\n3.Delete at front\n4.Delete at Last\n5.Display List\n6.Insert at position\n7.Delete from position\n8.Search\n9.Reverse\nEnter your Choice: ";
    cin>>ch;
    switch (ch)
    {
    case 1:
        int nf;
        cout<<"Enter the number of items to insert: ";
        cin>>nf;
        while(nf--){
        cout<<"\nInsert Item\n";
        cin>>data;
        insertatfront(&head,data);
        }
    break;

    case 2:
        int ne;
        cout<<"Enter the number of items to insert: ";
        cin>>ne;
        while(ne--){
        cout<<"\nInsert Item\n";
        cin>>data;
        insertatend(&head,data);
        }
    break;

    case 3:
       // cout<<"\nDelete at front\n";
        deletefront(head);
        break;
    case 4:
        deleteatlast(head);
        break;
    case 5:
        print_list(head);
        break;
    case 6:
        int val,pos;
        cout<<"Enter Position to Insert: ";
        cin>>pos;
        cout<<"Enter The Element: ";
        cin>>val;
        insertatpos(head,val,pos);
        break;
    case 7:
        int posi;
        cout<<"Enter position: ";
        cin>>posi;
        deleteatpos(head,posi);
        break;
    case 8:
        int v;
        cout<<"Enter Value: ";
        cin>>v;
        search(head,v);
    break;
    case 9:
        reverse(head);
    break;
    case 10:
        sort(head);
        break;
    default:
        cout<<"Wrong Choice";
        break;
    }
    cout<<"\n1 for continue:- ";
    cin>>choice;
    }while(choice!=0);
}
