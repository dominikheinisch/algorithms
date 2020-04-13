class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class SolutionCopyRandomList {
public:
    Node* copyRandomList(Node* head) {
        if  (!head) {
            return NULL;
        }
        Node* curr = head;
        Node* temp;
        while(curr) {
            temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }

        curr = head;
        while(curr) {
            if (!curr->random) {
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* cpyHead = curr->next;
        Node* cpyCurr = cpyHead;
        while(curr) {
            temp = curr->next->next;
            curr->next = temp;
            if(temp) {
                cpyCurr->next = temp->next;
            }
            curr = curr->next;
            cpyCurr = cpyCurr->next;
        }
        return cpyHead;
    }
};