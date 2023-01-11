#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node{
    Node *next, *prev;
    int data;
};

struct Seznam{
    Node *head, *tail;
};

Node* cre(int x);
Node* listik(Node *pt, Node **tail, int x);
void tisk(Node *pt);
void del(Seznam* list);
void delNth(Node **pt, int n);   //mazani nte polozky
void buble(Node *pt);
void buble2(Node *uk);              //buble sort
void diff(Node **pt1, Node *pt2);  
void revers(Node **head);



void init(Seznam *seznam, int *pole, int n){
    
    for(int i=0;i<n;i++){
        seznam->head=listik(seznam->head, &seznam->tail, pole[i]);
    }
}

int main(int argc, char **argv)
{
	cout<<"//////////////////////"<<endl;
    
    
    Seznam seznam={
        NULL,
        NULL
    };
    
    //List* head1=NULL, *head2=NULL;
    
    int pole1[]={1,2,3,4,5,6,7,8,9};
    int pole2[]={1,2,3,4,5,6,7,8,10};
    
    init(&seznam, pole1, 9);
    
    cout<<seznam.head->data;
   // int n=sizeof(pole1)/sizeof(*pole1);
    
    /*for(int i=0;i<n;i++){
        seznam.head=listik(seznam.head, &seznam.tail, pole1[i]);
    }*/
    
    int n=0;
    for(int i = 0; i < 10; i++) n++;
        
    
    int pole[n];
    
    
    /*for(int i=0;i<n;i++){
        head2=listik(head2,pole2[i]);
    }*/
    //buble2(head2);
    //cout<<"**********";
   // tisk(head2);
    //revers(&head2);
    //tisk(head2);

    
   
    
    
    
    /*cout<<"**********************"<<endl;
    tisk(head2);
    cout<<"**********************\n"<<endl;
    diff(&head1,head2);
    tisk(head1);
    */
   
	return 0;
}


void revers(Node** head){
    Node* pom=*head;
    Node* next=NULL, *prev=NULL;
    
    while(pom!=NULL){
        
        next=pom->next;
        pom->next=prev;
        prev=pom;
        pom=next;
    }
    *head=prev;
}

void diff(Node **pt1, Node *pt2){
    Node *pom1, *pom2, *pred;
    for(pom2=pt2;pom2!=NULL;pom2=pom2->next){
        int prvek=pom2->data;
        pom1=pred=*pt1;
        while(pom1!=NULL){
            if(prvek==pom1->data){
                if(pred==pom1){
                    *pt1=pom1->next;
                    pred=*pt1;
                    delete pom1;
                    pom1=pred;
                    continue;
                }else {
                    if(pred->next==pom1){
                        pred->next=pom1->next;
                        delete pom1;
                        pom1=pred->next;
                        continue;
                    }
                }
            }else {
                pred=pom1;
                pom1=pom1->next;
            }
        }
    }
}

void buble(Node *pt){
    Node *pom;
    Node *pom2;
    for(pom=pt;pom!=NULL;pom=pom->next){
        for(pom2=pt;pom2!=NULL;pom2=pom2->next){
            if(pom->data > pom2->data){
                int prvek=pom->data;
                pom->data=pom2->data;
                pom2->data=prvek;
            }
        }
    }
}

void buble2(Node *uk){
    Node *pom1, *pom2, *pom3;
    for(pom1=uk;pom1->next!=NULL;pom1=pom1->next){
        pom3=pom1;
        for(pom2=pom1->next;pom2!=NULL;pom2=pom2->next){
            if(pom2->data < pom3->data){
                int prvek=pom2->data;
                pom2->data=pom3->data;
                pom3->data=prvek;
            }
            pom3=pom3->next;
        }
    }
}


/*void del(Node *pt){
    Node *pom=pt;
    while(pt!=NULL){
        pom=pt->next;
        cout<<"maze se: "<<pt->data<<endl;
        delete pt;
        pt=pom;
    }
}*/

void del(Seznam *list){
    Node *pt = list->head;
    Node *pom;
    while(pt != NULL){
        pom = pt->next;
        cout<<"maze se: "<<pt->data<<endl;
        delete pt;
        pt = pom;
    }
    list->head = list->tail = NULL;
}

void delNth(Node **pt,int n){
    Node *pom=(*pt)->next;
    Node *pred=pom;
    if(n==1){
        (*pt)=(*pt)->next;
        delete pred;
        return;
    }
    for(int i=0;i<n-2;i++){
        pred=pom;
        pom=pom->next;
    }
    pred->next=pom->next;
    delete pom;
}

Node* cre(int x){
    
    Node* pt=new Node;
    pt->data = x;
    pt->next = NULL;
    pt->prev = NULL;
    return pt;
}

Node* listik(Node *pt, Node **tail, int x){
    if(pt==NULL){
        pt = cre(x);
        *tail = pt;
        return pt;
    }else{
        Node *pom = cre(x);
        pom->next = pt;
        pt->prev = pom;
        pt=pom;
        return pt;
    }
}

void tisk(Node *pt){
    while(pt!=NULL){
        cout<<pt->data<<" ";
        pt=pt->prev;
    }
    cout<<endl;
}
