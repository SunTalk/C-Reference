#include<bits/stdc++.h>

using namespace std;

bool flag = false;
bool enter = false;
char ins;
int debug;

class RBT;

class TreeNode{

public:

    TreeNode(){
        
        isBlack = true;
        leftchild = NULL;
        rightchild = NULL;
        key = -1;
    }

    TreeNode(int key){

        this->key = key;
        this->isBlack = false;
    }

    int getKey(){

        return key;
    }

private:

    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    int key;
    // 0 for red 1 for black
    bool isBlack;

    friend class RBT;
};

class RBT{

public:

    RBT(){

        leaf = new TreeNode();
        root = leaf;
    }

    TreeNode* Search(int key);
    void LeftRotation(TreeNode *x);
    void RightRotation(TreeNode *x);
    void InsertRBT(int key);
    void FixedRBT(TreeNode *current);
    void DeleteRBT(int key);
    void DFixedRBT(TreeNode* current);
	void Levelorder();


private:

    TreeNode* root;
    TreeNode* leaf;
    TreeNode* leftMost(TreeNode* current);
    TreeNode* successor(TreeNode* current);
};

TreeNode* RBT::Search(int key){

    // cout << key << endl;
    TreeNode *current = root;
    while(current != NULL && key != current->key){

        if(key < current->key){

            current = current->leftchild;
        }
        else{

            current = current->rightchild;
        }
    }
    // if(current == NULL)
    //     cout << "leaf" << endl;
    return current;
}

TreeNode* RBT::leftMost(TreeNode* current){

    while(current->leftchild != leaf){

        current = current->leftchild;
    }
    return current;
}

TreeNode* RBT::successor(TreeNode* current){

    if(current->rightchild != leaf){

        return(RBT::leftMost(current->rightchild));
    }

    TreeNode* suc = current->parent;
    while(suc != leaf && current == suc->rightchild){

        current = suc;
        suc = suc->parent;
    }
    return suc;
}

void RBT::LeftRotation(TreeNode *x){

    TreeNode *y = x->rightchild;
    x->rightchild = y->leftchild;
    if(y->leftchild != leaf){
        
        y->leftchild->parent = x;
    }
    y->parent = x->parent;

    //if x is root then y will become the new root
    if(x->parent == leaf){

        root = y;
    }
    //if x is the left node of it's parent then y will become the new left node
    else if(x == x->parent->leftchild){
        
        x->parent->leftchild = y;
    }
    //right
    else{

        x->parent->rightchild = y;
    }

    y->leftchild = x;
    x->parent = y;

}

void RBT::RightRotation(TreeNode *y){

    TreeNode *x = y->leftchild;

    y->leftchild = x->rightchild;

    if(x->rightchild != leaf){

        x->rightchild->parent = y;
    }

    x->parent = y->parent;

    if(y->parent == leaf){
        // cout << "root" << endl;
        root = x;
    }
    else if(y == y->parent->leftchild){

        y->parent->leftchild = x;
    }
    else{

        y->parent->rightchild = x;
    }

    x->rightchild = y;
    y->parent = x;
}

void RBT::InsertRBT(int key){

	// cout << "in" << endl;
    TreeNode *y = leaf;
    TreeNode *x = root;
    TreeNode *insert_node = new TreeNode(key);
    
    while(x != leaf){

        y = x;
        if(insert_node->key < x->key){

            x = x->leftchild;
        }
        else{

            x = x->rightchild;
        }
    }
    insert_node->parent = y;

    if(y == leaf){

        this->root = insert_node;
    }
    else if(insert_node->key < y->key){

        y->leftchild = insert_node;
    }
    else{

        y->rightchild = insert_node;
    }

    insert_node->leftchild = leaf;
    insert_node->rightchild = leaf;
    insert_node->isBlack = false;   

    FixedRBT(insert_node);
}

void RBT::FixedRBT(TreeNode *current){

    while(!current->parent->isBlack){

        enter = true;
        if(flag)
            cout << endl;
        flag = false;
        cout << "Insert Case ";
        //leftchild
        if(current->parent == current->parent->parent->leftchild){
            
            TreeNode *uncle = current->parent->parent->rightchild;
            //uncle is red
            if(!uncle->isBlack){

                cout << "2 Recolor" << endl;
                current->parent->isBlack = true;
                uncle->isBlack = true;
                current->parent->parent->isBlack = false;
                current = current->parent->parent;
            }

            //uncle is black
            else{
                //rightchild
                if(current == current->parent->rightchild){
                    
                    cout << "1 LR Adjustment" << endl;
                    current = current->parent;
                    RBT::LeftRotation(current);
                }
                else
                    cout << "1 LL Adjustment" << endl;
                //leftchild
                current->parent->isBlack = true;
                current->parent->parent->isBlack = false;
                RBT::RightRotation(current->parent->parent);
            }
        }
        else{
            // cout << "?" << endl;
            TreeNode *uncle = current->parent->parent->leftchild;
            //uncle is red
            if(!uncle->isBlack){
               
                cout << "2 Recolor" << endl;
                current->parent->isBlack = true;
                uncle->isBlack = true;
                current->parent->parent->isBlack = false;
                current = current->parent->parent;
            }

            else{
                
                if(current == current->parent->leftchild){
                    
                    cout << "1 RL Adjustment" << endl;   
                    current = current->parent;
                    RBT::RightRotation(current);
                }
                else
                    cout << "1 RR Adjustment" << endl;

                current->parent->isBlack = true;
                current->parent->parent->isBlack = false;
                RBT::LeftRotation(current->parent->parent);
            }
        }
    }
    root->isBlack = true;
    if(enter)
        RBT::Levelorder();
}

void RBT::DeleteRBT(int key){

    TreeNode *delete_node = RBT::Search(key);

    if(delete_node == NULL){

        cout << "Data Not found." << endl;
        return;
    }

    TreeNode *y = NULL;
    TreeNode *x = NULL;

    if(delete_node->leftchild == leaf || delete_node->rightchild == leaf){
 
        y = delete_node;
    }
    else{
        
        y = successor(delete_node);
    }

    if(y->leftchild != leaf){

        x = y->leftchild;
    }
    else{

        x = y->rightchild;
    }

    x->parent = y->parent;

    if(y->parent == leaf){

        this->root = x;
    }
    else if(y == y->parent->leftchild){

        y->parent->leftchild = x;
    }
    else{

        y->parent->rightchild = x;
    }

    if(y != delete_node){

        delete_node->key = y->key;
    }

    if(y->isBlack){

        RBT::DFixedRBT(x);
    }
}

void RBT::DFixedRBT(TreeNode* current){

    TreeNode* tmp = current;

    while(current != root && current->isBlack){

        enter = true;
        if(flag)
            cout << endl;
            flag = false;
        //left
        if(current == current->parent->leftchild){

            TreeNode* sibling = current->parent->rightchild;
            //sibling is red
            if(!sibling->isBlack){
                
                cout << "Remove Case 3 RR Adjustment" << endl;  
                sibling->isBlack = true;
                current->parent->isBlack = false;
                RBT::LeftRotation(current->parent);
                sibling = current->parent->rightchild;
            }

            //subling's child are all black
            if(sibling->leftchild->isBlack && sibling->rightchild->isBlack){
                
                cout << "Remove Case 2 Recolor" << endl;
                sibling->isBlack = false;
                current = current->parent;
            }
            //only one child is black
            else{
				//left is red
                cout << "Remove Case 1 ";
                if(sibling->rightchild->isBlack && !sibling->leftchild->isBlack){

                    cout << "RL Adjustment" << endl;
					sibling->leftchild->isBlack = true;
					sibling->isBlack = false;
					RBT::RightRotation(sibling);
					sibling = current->parent->rightchild;
                }
                else
                    cout << "RR Adjustment" <<  endl;
				//right is red
				sibling->isBlack = current->parent->isBlack;
				current->parent->isBlack = true;
				sibling->rightchild->isBlack = true;
				RBT::LeftRotation(current->parent);
				current = root;
            }
        }
		//right
		else{
            
			TreeNode* sibling = current->parent->leftchild;
			if(!sibling->isBlack){

                cout << "Remove Case 3 LL Adjustment" << endl;
				sibling->isBlack = true;
				current->parent->isBlack = false;
				RBT::RightRotation(current->parent);
				sibling = current->parent->leftchild;
			}

			if(sibling->leftchild->isBlack && sibling->rightchild->isBlack){

                cout << "Remove Case 2 Recolor" << endl;
				sibling->isBlack = false;
				current = current->parent;
			}
			else{

                cout << "Remove Case 1 ";
				if(sibling->leftchild->isBlack){

                    cout << "LR Adjustment" << endl;
					sibling->rightchild->isBlack = true;
					sibling->isBlack = false;
					RBT::LeftRotation(sibling);
					sibling = current->parent->leftchild;
				}
                else
                    cout << "LL Adjustment" << endl;
				sibling->isBlack = current->parent->isBlack;
				current->parent->isBlack = true;
				sibling->leftchild->isBlack = true;
				RBT::RightRotation(current->parent);
				current = root;
			}
		}
    }
	current->isBlack = true;
    this->root->isBlack = true;
    // delete(tmp);
    if(enter)
        RBT::Levelorder();
}

void RBT::Levelorder(){
    
    flag = true;
	queue<TreeNode*> q;
    q.push(this->root);
    while(!q.empty()){

        TreeNode *current;
        int len = q.size();
        // cout << q.size() << endl;
        while(len--){

            current = q.front();
            q.pop();

            cout << current->key;
            current->isBlack? cout << "B" : cout << "R";
            if(len)
                cout << " ";
            else
                cout << endl;
            if(current->leftchild != leaf){
                
                q.push(current->leftchild);
            }
            if(current->rightchild != leaf){

                q.push(current->rightchild);
            }
        }
    }
}

int main(int argc, const char** argv) {
    
	#ifdef DBG
	freopen("1.in", "r", stdin);
	freopen("2.out", "w", stdout);
	#endif

	int key;

    RBT tree;

	while(cin >> ins){

        enter = false;

		if(ins == 'Q')
			break;

		TreeNode* tmp;
		switch(ins){

			case 'I':
                cin >> key;
                debug = key;
				tmp = tree.Search(key);
				if(tmp != NULL){

                    if(flag)
                        cout << endl;
					cout << key << " has already been stored" << endl;
				}
                else{
                    
                    tree.InsertRBT(key);
                }
			break;

            case 'P':

                if(flag)
                    cout << endl;
                // cout << "in" << endl;
                tree.Levelorder();
            break;
			case 'D':
                cin >> key;
                debug = key;
                // cout << "in" << endl;
				tree.DeleteRBT(key);
			break;
		}
	}

    return 0;
}