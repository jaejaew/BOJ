#include <cstring>
#include <string>
#include <vector>
#include <map>

#define MAXNODE     10000
#define MAXCHILD    26
#define OFFSET      'a'

using namespace std;

class Trie {
   private:
    /* You can use the special method if we can easily maintain child.
     * e.g. lowercase/uppercase/numeric only
     */ 
    struct TrieNode {
        bool valid;
        map<char, TrieNode *> child;    /* 1. general */
        TrieNode *child[MAXCHILD];      /* 2. special */
    } trieNode[MAXNODE];
    int trieNodeCnt;

    struct TrieNode *root;

    struct TrieNode *getTrieNode() {
        struct TrieNode *pNode = &trieNode[trieNodeCnt++];
        pNode->valid = false;
        /* init child of pNode */
        return pNode;
    }


    void _dfs(TrieNode *pNode) {
        /* dfs as you want */
    }

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
        pNode->valid = true;
    }

    void remove(const string& str) {
        struct TrieNode *pNode = root;
        for (const auto& c : str) {
            if (pNode->child[c-OFFSET] == nullptr)
                return;
            pNode = pNode->child[c - OFFSET];
        }
        pNode->valid = false;
    }

    bool find(const string& str) {
        struct TrieNode *pNode = root;
        for (const auto& c : str) {
            if (pNode->child[c-OFFSET] == nullptr)
                return false;
            pNode = pNode->child[c - OFFSET];
        }
        return pNode->valid;
    }

    void dfs() {
        _dfs(root);
    }
} trie;