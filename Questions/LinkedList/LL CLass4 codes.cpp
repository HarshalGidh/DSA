//codes mene likha hai 
#include<iostream>
#include<vector>
using namespace std ;
class Node {
        public:
        int data;
        Node* next;

        Node() {
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }


};
void insertAtHead(Node* &head, Node* &tail, int data) {
        //check for Empty LL
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
        }
        else {
                //step1:
                Node* newNode = new Node(data);
                //step2:
                newNode -> next = head;
                //step3:
                head = newNode;
        }


}
void insertAtTail(Node* &head,Node* &tail, int data) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                
        }
        else {
            //step1: creatae a node
            Node* newNode = new Node(data);
            //step2: connect woth tail ndoe
            tail->next = newNode;
            //step3: update tail;
            tail = newNode;
        }

}
int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}
void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
}
 bool checkLoop(Node* head){
    Node* slow = head ;
    Node* fast = head ;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next ;
            slow = slow->next;
        }
        if(slow == fast){
            return true;
        }
    }
    return false;
 }
 Node* startingPointofLoop(Node* head){
    Node* slow = head ;
    Node* fast = head ;
    while(fast != NULL){
        fast = fast->next ;
        if(fast != NULL){
            fast = fast->next ;
            slow = slow->next ; 
        }
        if(slow == fast){
            break; //using break to exit the loop
        }
    }
    slow = head ; //starting slow back from head of the Linked List
    while(slow != fast){ //we will run this loop untill slow == fast when they meet that will be starting point of loop
        slow = slow->next ;
        fast = fast->next ;
    }
    Node* startingPoint = slow ; // could have taken fast as well
    return startingPoint ;
 }
  Node* removingLoop(Node* head){
    Node* slow = head ;
    Node* fast = head ;
    while(fast != NULL){
        fast = fast->next ;
        if(fast != NULL){
            fast = fast->next ;
            slow = slow->next ; 
        }
        if(slow == fast){
            break; //using break to exit the loop
        }
    }
    slow = head ; //starting slow back from head of the Linked List
    while(slow != fast){ //we will run this loop untill slow == fast when they meet that will be starting point of loop
        slow = slow->next ;
        fast = fast->next ;
    }
    Node* startingPoint = slow ; // could have taken fast as well
    Node* temp = fast ;
    while(temp->next != startingPoint){
        temp = temp->next ;
    }
    temp->next = NULL; //removing loop by ending the tail at NULL
 }
 Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head ;

    while(curr != NULL){
        Node* nextNode = curr->next ;
        curr->next = prev;
        prev = curr;
        curr = nextNode ;
    }
    return prev ;
 }
    Node* reverseUsingRecursion(Node* prev, Node* curr) {
        //base case
        if(curr == NULL) {
            return prev;
        }
        //1 case hum solve krenge
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        //baaaki kon sambhalega - recursion
        return reverseUsingRecursion(prev, curr);
    }
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        return reverseUsingRecursion(prev,curr);

        // while(curr != NULL) {
        //     ListNode* nextNode = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nextNode;
        // }
        // return prev;
    }
void addOneLL(Node* &head){
    head = reverseList(head);
    Node* temp = head ;
    int carry = 1;
    int digit ;
    while (temp->next != NULL)
    {
        int totalsum = temp->data + carry ;
        digit = totalsum % 10 ; //to get the new digit AFter addition
        carry = totalsum / 10 ; //to get the carry 
        temp->data = digit ;
        temp = temp->next;
        if(carry == 0){
            break; //no need to traverse the LL as there is no carry
        }
       
    }
    if(carry != 0){
        //we need to do processing for the last node as there is a carry which needs to be added to last node
        int totalsum = temp->data + carry ;
        int digit = totalsum % 10;
        carry = totalsum / 10;
        temp->data = digit;
        if(carry != 0){
            Node* newNode = new Node(carry) ; //creating new node because there is a carry left but LL got over so LL Size has to increase 
            temp->next = newNode; 
        }
    }
    
    head = reverseList(head) ;
    
 }
//  Node* add2LinkedListsHelper(Node* head1,Node* head2){
    
//     Node* temp1 = head1 ;
//     Node* temp2 = head2 ;
//     Node* rev_head1 = reverseList(head1);
//     Node* rev_head2 = reverseList(head2);
//     // Node* ans = new Node(0) ;
//     int carry = 0;
//     int size1 = findLength(rev_head1);
//     int size2 = findLength(rev_head2);
//     if(size1 > size2){
//         while(rev_head2->next != NULL){
//             int totalsum = rev_head1->data + rev_head2->data + carry ;
//             int digit = totalsum % 10 ;
//             carry = totalsum / 10 ;
//             rev_head1->data = digit ;
//             rev_head1 = rev_head1->next;
//             rev_head2 = rev_head2->next;
//         }
//         if(carry != 0){ //rev_head2 ka last element 
//             int totalsum = rev_head1->data + rev_head2->data + carry ;
//             int digit = totalsum % 10 ;
//             carry = totalsum / 10 ;
//             rev_head1->data = digit ;
//             while(carry != 0 && rev_head1 != NULL){ //jab tak rev_head1 nul pe nahi aur carry=0 nahi 
//                 totalsum = rev_head1->data + carry ;
//                 digit = totalsum % 10 ;
//                 rev_head1->data = digit ;
//                 rev_head1 = rev_head1->next ;
//             }
//             if(carry != 0){ //rev_head1 ke sab elements khatam but carry!=0
//                 Node* newNode = new Node(carry + rev_head1->data);
//                 rev_head1->next = newNode ; // new head will be newNode
//             }
//         }
//         head1 = reverseList(rev_head1);
//         print(head1);
//         return head1;
//     }
//     if(size1 <= size2){
//         while(rev_head1->next != NULL){
//             int totalsum = rev_head1->data + rev_head2->data + carry ;
//             int digit = totalsum % 10 ;
//             carry = totalsum / 10 ;
//             rev_head2->data = digit ;
//             rev_head2 = rev_head1->next;
//             rev_head1 = rev_head2->next;
//         }
//         if(carry != 0){ //rev_head2 ka last element 
//             int totalsum = rev_head1->data + rev_head2->data + carry ;
//             int digit = totalsum % 10 ;
//             carry = totalsum / 10 ;
//             rev_head2->data = digit ;
//             while(carry != 0 && rev_head2 != NULL){ //jab tak rev_head1 nul pe nahi aur carry=0 nahi 
//                 totalsum = rev_head2->data + carry ;
//                 digit = totalsum % 10 ;
//                 rev_head2->data = digit ;
//                 rev_head2 = rev_head2->next ;
//             }
//             if(carry != 0){ //rev_head2 ke sab elements khatam but carry!=0
//                 Node* newNode = new Node(carry + rev_head2->data);
//                 rev_head2->next = newNode ; // new head will be newNode
//             }
//         }
//         head2 = reverseList(rev_head2);
//         print(head2);
//         return head2;
//     }
   

//  }
Node* add2LinkedListsHelper(Node* head1, Node* head2) {
    Node* rev_head1 = reverseList(head1);
    Node* rev_head2 = reverseList(head2);

    Node* result = new Node(0); // A dummy node to start the result list
    Node* current = result; //temp pointer for result
    int carry = 0;

    while (rev_head1 != NULL || rev_head2 != NULL || carry != 0) {
        int digit1 = (rev_head1 != NULL) ? rev_head1->data : 0; //checking if rev_head1 aint null
        int digit2 = (rev_head2 != NULL) ? rev_head2->data : 0; //checking if rev_head2 aint null

        int totalsum = digit1 + digit2 + carry;
        int digit = totalsum % 10;
        carry = totalsum / 10;

        current->next = new Node(digit);
        current = current->next;

        if (rev_head1 != NULL) {
            rev_head1 = rev_head1->next;
        }

        if (rev_head2 != NULL) {
            rev_head2 = rev_head2->next;
        }
    }

    Node* finalResult = reverseList(result->next); // Skip the dummy node(0 wala node)
    print(finalResult);
    return finalResult;
}


 Node* add2LinkedLists(Node* head1 , Node* head2){
    if(head1 != NULL || head2 != NULL){
        Node* result = add2LinkedListsHelper(head1 , head2);
       // print(result);
        return result ;
    }


 }
 Node* reverseKGroups(Node* head,int k){
    //Base Case
    if(head == NULL){ // head = NULL case
        return head;
    }
    if(head->next == NULL){ // Single Elememt LL
        return head; 
    }
    Node* prev = NULL;
    Node* curr = head ;
    Node* nextNode = curr->next;
    int len = findLength(head);
    int pos = 0 ;
    //1 case ka processing :
    while(pos < k){ // reversing k groups
        nextNode = curr->next ;
        pos++;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    if(nextNode != NULL){//if we havent reached taill then let recursion handle
    //Recursion call
        Node* recursionKaAns = reverseKGroups(nextNode , k);
        head->next = recursionKaAns ; //Joining the 
    }
    return prev; //our head of Linked List is at prev so returning Prev
 }
int main(){

  Node* head = NULL;
  Node* tail = NULL;
  //Q1 Add 1 to a LinkedList
  //Q2 Add 2 LinkedList

//   insertAtHead(head, tail, 9);
//   insertAtHead(head, tail, 9);
// //   insertAtHead(head, tail, 9);
//   print(head);
//   cout<<endl;
//   Node* LinkedList1 = new Node(9);
//   LinkedList1->next = head;
//   head = LinkedList1 ;
// //   print(LinkedList1);
// //   cout<<endl;
//   //addOneLL(head) ;
//   cout<<"First LinkedList :";
//   print(head);
//   cout<<endl;
//   //Second LL
//   Node* head2 = NULL;
//   Node* tail2 = NULL;
// //   insertAtHead(head2, tail2, 0);
// //   insertAtHead(head2, tail2, 9);
// //   insertAtHead(head2, tail2, 9);
// //   insertAtHead(head2, tail2, 9);
// //   insertAtHead(head2, tail2, 9);
//   print(head2);
//   cout<<endl;
//   Node* LinkedList2 = new Node(0);
// //   Node* LinkedList2 = new Node(9);
//   LinkedList2->next = head2;
//   head2 = LinkedList2 ;
// //   print(LinkedList2);
// //   cout<<endl;
//   //addOneLL(head2) ;
//   cout<<"Second LinkedList : "<<endl;
//   print(head2);
//   cout<<"\nAdding the two LikedList :"<<endl;
//   Node* ans = add2LinkedLists(head,head2);
//   cout<<endl;
//   cout<<"Answer is :"<<endl;
//   print(ans);

// Q1. Check Loop , 
// Q2. Starting point of Loop ,
// Q3. remove loop
//   insertAtHead(head, tail, 8);
//   insertAtHead(head, tail, 7);
//   insertAtHead(head, tail, 6);
//   insertAtHead(head, tail, 5);
//   insertAtHead(head, tail, 4);
//   insertAtHead(head, tail, 3);
//   insertAtHead(head, tail, 2);
//   insertAtHead(head, tail, 1);
//   print(head);
//   cout<<endl;
//   //creating loop at 4
//   tail->next = head->next->next->next;
//   if(checkLoop){
//       cout<<"true"<<endl;
//   }
//   else{
//       cout<<"false"<<endl;
//   }
//   Node* startingPoint = startingPointofLoop(head) ;
//   cout<<"Starting Point of Loop is :"<<startingPoint->data<<endl;
//   //removing a loop
//   removingLoop(head) ;//calling function to remove loop

// Q1 ReverseKGroups 
  insertAtHead(head, tail, 10);
  insertAtHead(head, tail, 8);
  insertAtHead(head, tail, 6);
  insertAtHead(head, tail, 4);
  insertAtHead(head, tail, 2);
  insertAtHead(head, tail, 0);
  cout<<"\nBefore Reversing LinkedList :"<<endl ;
  print(head);
  Node* headr = head ;
  int k = 2;
  Node* ansr = reverseKGroups(headr , k) ;
  cout<<"\nAfter Reversing K Groups"<<endl;
  print(ansr);
    return 0;
}