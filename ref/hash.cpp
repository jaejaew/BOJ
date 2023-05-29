#include <string>

typedef unsigned long long ull;

/* string as hash key is slow.
 * each character can be denoted as 5-bit
 * if len(string)<10, 
 *  we can convert the string in one ull variable
 */
ull strToUll(const std::string s) {
    ull key = 0ULL;
    for(const char& c : s) 
        key = (key << 5) + (c - 'a' + 1);
    return key;
}

ull djb2(const std::string s) {
    ull key = 5381;
    for(const char& c : s)
        key = ((key << 5) + key) + c;
    return key;
}

#define MAXN 10000
#define MAXLEN 10

struct Node {
    char str[MAXLEN + 1];
    int data;
    Node* next;
} nodes[MAXN];
int nodeCnt;

Node *getNode(const char *str, int data) {
    std::strcpy(nodes[nodeCnt].str, str);
    nodes[nodeCnt].data = data;
    nodes[nodeCnt].next = nullptr;
    return &nodes[nodeCnt++];
}

class HashMap {
#define TABLE_SIZE (1<<12)
#define DIV (TABLE_SIZE-1)
   private:
    Node table[TABLE_SIZE];

    /* idea: always return prev node for inserting or removing */
    Node *getPrevNode(const char *str) {
        Node *pPrev = &table[djb2(str) & DIV];
        while(pPrev->next && std::strcmp(pPrev->next->str, str))
            pPrev = pPrev->next;
        return pPrev;
    }

   public:
    void init() {
        std::memset(table, 0, sizeof(table));
        nodeCnt = 0;
    }

    void insert(const char *str, int data) {
        Node *const prevNode = getPrevNode(str);
        if(prevNode->next == nullptr)
            prevNode->next = getNode(str, data);
        else
            prevNode->next->data = data;
    }

    void remove(const char *str) {
        Node *const prevNode = getPrevNode(str);
        if(prevNode->next)
            prevNode->next = prevNode->next->next;
    }

    int get(const char *str) {
        Node *const prevNode = getPrevNode(str);
        if(prevNode->next)
            return prevNode->next->data;
        return -1;
    }
} hashTable;