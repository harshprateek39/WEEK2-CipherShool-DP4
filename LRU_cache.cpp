class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key_ , int val_){
        key = key_;
        val  = val_;
    }
    
};
class LRUcache{
public:
  Node* head = new Node(-1 , -1);
  Node* tail = new Node(-1 , -1);
  int cap;
  unordered_map<int ,Node*>mp;
  LRUcache(int capacity){
    cap = capacity;
    head->next = tail;
    tail->prev = head;
  }

void addnode(Node* node){
    Node* temp = head->next;
    node->prev = head;
    node->next = temp;
    temp->prev = node;
    head->next = node;
}


void deletenode(Node* delnode){
    Node* temp1 = delnode->prev;
    Node* temp2 = delnode->next;
    temp1->next = temp2;
    temp2->prev = temp1;
}
  ////////GET function in LRU CACHE/////////////

  int get(int key_){
        if(mp.find(key_) != mp.end()){
            Node* resnode = mp[key_];
            int res = resnode->val;
            mp.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            mp[key_] = head->next;
            return res;
        }
        return -1;
  }


  //////////PUT//////////

void put(int key_ , int value){
        if(mp.find(key_) != mp.end()) {
            Node* temp = mp[key_];
            mp.erase(key_);
            deletenode(temp);
        }
        if(mp.size()  == cap){
            deletenode(tail->prev);
            mp.erase(tail->prev->key);
        }
        addnode(new Node(key_ , value));
        mp[key_] = head->next;

}

};

int main() {
    int cap = 3;
LRUcache* obj = new LRUcache(cap);
int key = 2;
  int param_1 = obj->get(key);
  int val = 3;
 obj->put(key,val);
}