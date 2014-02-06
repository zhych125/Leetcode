class LRUCache{
public:

//nested class
    class Node {
    private:
        int key;
        int value;
    public:
        Node* prev;
        Node* next;
        Node(int key,int value, Node* prev=NULL,Node* next=NULL):key(key),value(value),prev(prev),next(next){}
        int getValue() {
            return value;
        }
        int getKey() {
            return key;
        }
        void setValue(int value) {
            this->value=value;
        }
    };
    
    LRUCache(int capacity) {
        head=NULL;
        tail=NULL;
        this->capacity=capacity;
        used=0;
        hash.clear();
    }
    
    int get(int key) {
        if(hash.find(key)!=hash.end()){
            move(key);
            return getValue(key);
        }
        else return -1;
    }
    
    void set(int key, int value) {
        if(hash.find(key)!=hash.end()) {
            write(key,value);
            move(key);
        }
        else {
            if(used==capacity) {
                invalidate();
            }
            create(key,value);
        }
    }
    
private:
//internal fields
    Node* head;
    Node* tail;
    int capacity;
    int used;
    map<int,Node*> hash;
    
//internal methods
    int getValue(int key) {
        Node* node=hash[key];
        return node->getValue();
    }
    void move(int key) {
        Node* node=hash[key];
        if(node==head) {
            return;
        } 
        Node* prev=node->prev;
        Node* next=node->next;
        prev->next=next;
        if(node==tail) {
            tail=prev;
        }
        else {
            next->prev=prev;
        }
        node->next=head;
        head->prev=node;
        node->prev=NULL;
        head=node;
    }
    
    void create(int key, int value) {
        Node* node=new Node(key,value);
        hash[key]=node;
        if(head) {
            node->next=head;
            head->prev=node;
            head=node;
        }
        else {
            head=node;
            tail=node;
        }
        used++;
    }
    void write(int key,int value) {
        Node* node=hash[key];
        node->setValue(value);
    }
    void invalidate() {
        if(tail) {
            Node *prev=tail->prev;
            hash.erase(tail->getKey());
            delete tail;
            if(prev) {
                prev->next=NULL;
            }
            else head=NULL;
            tail=prev;
            used--;
        }
    }
    
};
