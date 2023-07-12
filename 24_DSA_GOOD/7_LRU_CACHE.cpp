/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/


//dost ismei na queue hi implement karni hai bas wo double linked list se hogii taki big O of one mei hojaye sara kaam

//Least frequently used wali bhi aise hi implement hoti haii bas usmei hum current node ko uske agge wallo mei mix kardete haiii kyuki increase toh har barri one se hi hogaa na
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int value){
        prev=NULL;
        next=NULL;
        data=value;
    }
};

class LRUCache {
    int size;
    int max_size;
    unordered_map<int,pair<int,Node*>> mp;
    Node* head;
    Node* tail;

public:


    LRUCache(int capacity) {
        max_size=capacity;
        size=0;
        head=NULL;
        tail=NULL;


    }

    void adjust(Node* move_forward ){
   
        if(move_forward==tail){
            return ;
        }
        if(move_forward==head){
            tail->next=head;
            head=head->next;
            head->prev=NULL;
            tail->next->prev=tail;
            tail=tail->next;
            tail->next=NULL;
            return;
        }

        move_forward->next->prev=move_forward->prev;
        move_forward->prev->next=move_forward->next;
        tail->next=move_forward;
        move_forward->prev=tail;
        tail=move_forward;
        tail->next=NULL;

        

    }

    int get(int key) {
      if(mp.find(key)!=mp.end()){
          adjust(mp[key].second);
          return mp[key].first;
      }
      else{
          return -1;
      }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].first=value;
            adjust(mp[key].second);
            return ;
        }

        size++;
        if(size<=max_size){
            if(head==NULL){
                Node* temp= new Node(key);
                head=temp;
                tail=temp;
                mp[key]={value,temp};
            }
            else{
                Node* temp=new Node(key);
                tail->next=temp;
                temp->prev=tail;
                tail=temp;
                mp[key]={value,temp};
            }
        }
        else{
            if(max_size==1){
               Node* temp= new Node(key);
                head=temp;
                tail=temp;
                mp.clear();

                mp[key]={value,temp};
            }
            else{
                auto it=mp.find(head->data);
                mp.erase(it);
                head=head->next;
                head->prev=NULL;
                Node* temp= new Node(key);
                tail->next=temp;
                temp->prev=tail;
                tail=temp;     
                mp[key]={value,temp};
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */