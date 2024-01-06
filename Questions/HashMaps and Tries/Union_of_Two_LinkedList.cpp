class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        Node* UL = NULL;
        Node*curr = head1;
        map<int,Node*>map;
        //Push LikedList1 in map :
        while(curr){
            map[curr->data] = curr;
            curr = curr->next;
        }
        //Push LinkedList2 in map :
        curr = head2;
        while(curr){
            map[curr->data] = curr;
            curr = curr->next;
        }
        curr = 0;
        //Now map has stored both linkedlists in sorted order
        //now push all elements into Union LinkedList
        for(auto it= map.begin();it != map.end();it++){
            if(!UL){ //while assigning head (null)
                UL = it->second ;
                curr = UL ;
            }
            else{ //assigning head to other sorted linkedlist elements :
                curr->next = it->second ;
                curr = curr->next;
            }
        }
        curr->next = NULL;
        return UL ;
    }
};