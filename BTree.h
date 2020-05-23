// Note: You need to add additional member variables and functions as you need.

#define NUM_KEYS 10
// NUM_KEYS should be set to make each tree node as large as 4KB.
// But for this assignment, we will set the degree of node to 10 just to make debugging and grading easy
// Please do not change this number.
// In practice, DBMS employs 'slotted page structure' to store variable-length records in B+tree.
// But again, the purpose of this assignment is to make students familiar with B-tree itself.

enum NodeType {
	ROOT,
	INTERNAL,
	LEAF
};

class BTreeNode{
   private:
    static int num_node;
   protected:
	NodeType type;
	int key_cnt;
   public:
	BTreeNode();
	virtual ~BTreeNode() {}
	NodeType getNodeType(){return type;};
	int getNodeNum(){return num_node;};
	int getKeyCnt(){return key_cnt;};
	void IncreaseKeyCnt(){key_cnt++;};
	void DecreaseKeyCnt(){key_cnt--;};
};

class BTreeInternalNode:public BTreeNode{
   private:
	long long keys[NUM_KEYS];
	BTreeNode* child[NUM_KEYS+1];
   public:
	BTreeInternalNode();
	~BTreeInternalNode();
	int getKeyValue(int pos){return keys[pos];}
};

class BTreeLeafNode:public BTreeNode{
   private:
	long long keys[NUM_KEYS];
	BTreeLeafNode* right_sibling;
   public:
	BTreeLeafNode();
	~BTreeLeafNode();
	void insert_key(int pos, long long value){keys[pos]=value;}
	int getKeyValue(int pos){return keys[pos];}
	void printLeafNode(); // print all keys in the current leaf node, separated by comma.
};


class BTree{
    private:
	BTreeNode *root;
    public:
	// You are not allowed to change the interfaces of these public methods.
	BTree();
	~BTree();
	void insert(long long value);
	void remove(long long value);
	void printLeafNode(long long value);
	// find the leaf node that contains 'value' and print all values in the leaf node.
	void pointQuery(long long value);
	// print the found value or "NOT FOUND" if there is no value in the index
	void rangeQuery(long long low, long long high);
	// print all found keys (low <= keys < high), separated by comma (e.g., 10, 11, 13, 15\n)

	//my func
	void insert(BTreeNode* nodepointer, long long value, BTreeNode* newchildnode);
};

