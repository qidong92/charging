#include <iostream>

using namespace std;

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructCore
(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder)
{
    //前序遍历的第一个节点即为树的根节点
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    if(startPreorder == endPreorder)//判断输入
    {
        if(startInorder == endInorder && *startPreorder == *endPreorder)
            return root;
        else
            throw exception("Invalid input.");
    }

    //
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
            ++rootInorder;
    if(rootInorder == endInorder && *rootInorder != rootValue)
        throw exception("Invalid input");

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength
    //构建左子树
    if(leftLength > 0)
    {
        root->m_pLeft = ConstructCore(startPreorder + 1,leftPreorderEnd,startInorder,rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        //构建右子树
        root->m_pRight = ConstructCore(leftPreorderEnd + 1,endPreorder,rootInorder + 1,endInorder);

    }
    return root;
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
