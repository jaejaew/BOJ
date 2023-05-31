#include <cstring>
#include <string>
#include <vector>
#include <map>

#define MAXNODE     10000
#define MAXCHILD    26
#define OFFSET      'a'

using namespace std;

/* You can use the special method if we can easily maintain child.
 * e.g. lowercase/uppercase/numeric only
 */
struct TrieNode {
    bool isLeaf;
    map<char, TrieNode *> child;    /* 1. general */
    TrieNode *child[MAXCHILD];      /* 2. special */
} trieNode[MAXNODE];
int trieNodeCnt;
struct TrieNode *getTrieNode() {
    struct TrieNode *pNode = &trieNode[trieNodeCnt++];
    pNode->isLeaf = false;
    memset(pNode->child, 0, sizeof(pNode->child));
}

class Trie {
   private:
    struct TrieNode *root;

   public:
    void init() {
        trieNodeCnt = 0;
        root = getTrieNode();
    }

    void insert(const string& str) {
        struct TrieNode *pNode = root;
        for (const auto& c : str) {
            if(pNode->child[c-OFFSET] == nullptr)
                pNode->child[c - OFFSET] = getTrieNode();
            pNode = pNode->child[c - OFFSET];
        }
    }

    void remove(const string& str) {
        struct TrieNode *pNode = root;
        for (const auto& c : str) {
            if (pNode->child[c-OFFSET] == nullptr)
                return;
            pNode = pNode->child[c - OFFSET];
        }
        pNode->isLeaf = false;
    }

    bool find(const string& str) {
        struct TrieNode *pNode = root;
        for (const auto& c : str) {
            if (pNode->child[c-OFFSET] == nullptr)
                return false;
            pNode = pNode->child[c - OFFSET];
        }
        return pNode->isLeaf;
    }
} trie;