#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 20         //结点的最大个数

typedef struct node{
    char data;
    struct node *lchild,*rchild;
}BinTNode, *BinTree;            //自定义二叉树的结点类型

int NodeNum = 0;
int leaf;            //NodeNum为结点数，leaf为叶子数
//==========基于先序遍历算法创建二叉树==============
//=====要求输入先序序列，其中加入虚结点"#"以示空指针的位置==========

BinTree CreatBinTree()
{
    char ch; 
	BinTree T; 
	scanf("%c", &ch); 
	if (ch == '#') 
    {
        T = NULL;
		return T;
    }
	else { 
		T = (BinTNode *)malloc(sizeof(BinTNode)); 
		T->data = ch; 
		T->lchild = CreatBinTree(); 
		T->rchild = CreatBinTree(); 
        NodeNum++;
		return T; 
    }
}

//========NLR 先序遍历=============
void PreOrder(BinTree T)
{
    if(T != NULL)
    {
        printf("%c", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
    else
        return;
}

//========LNR 中序遍历===============
 void InOrder(BinTree T)
{
    if(T != NULL){
        InOrder(T->lchild);
        printf("%c", T->data);
        InOrder(T->rchild);
    }
}
//==========LRN 后序遍历============
void PostOrder(BinTree T)
{
    if(T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}
//=====采用后序遍历求二叉树的深度、结点数及叶子数的递归算法========
int TreeDepth(BinTree T)
{
    int hl,hr,max;
    if(T){
        hl = TreeDepth(T->lchild);
        hr = TreeDepth(T->rchild);
        if(hl > hr)
            return (hl+1);
        else
            return (hr+1);
    }
    else return(0);
}

//====利用"先进先出"（FIFO）队列，按层次遍历二叉树==========
void LevelOrder(BinTree T)
{
    int front=0,rear=1;
    BinTNode *cq[Max],*p;   //定义结点的指针数组cq
    cq[1]=T;                //根入队
    while(front != rear)      
    {
        front = (front+1) % Max;
        p = cq[front];
        printf("%c", p->data);

        if(p->lchild != NULL)
        {
            rear = (rear+1) % Max;
            cq[rear] = p->lchild;
        }
        if(p->rchild != NULL)
        {
            rear = (rear+1) % Max;
            cq[rear] = p->rchild;
        }
    }
}

//====数叶子节点个数==========
int countLeaf(BinTree T)
{
    if(T)
    {
        if(T->lchild==NULL && T->rchild==NULL)
            leaf++;
	    countLeaf(T->lchild);
        countLeaf(T->rchild);
    }
    

    return leaf;
}

//==========主函数=================
void main()
{
    BinTree root;
	char i;
    int depth;
    printf("\n");
    printf("Creat Bin_Tree； Input PreOrder:"); //输入完全二叉树的先序序列，
                                                // 用#代表虚结点，如ABD###CE##F##

    root=CreatBinTree();       //创建二叉树，返回根结点
    do {                    //从菜单中选择遍历方式，输入序号。
            printf("\t********** select ************\n");
            printf("\t1: PreOrder Traversal\n");    
            printf("\t2: InOrder Traversal\n");
            printf("\t3: PostOrder traversal\n");
            printf("\t4: PostTreeDepth,Node number,Leaf number\n");
            printf("\t5: Level Depth\n"); //按层次遍历之前，先选择4，求出该树的结点数。
            printf("\t0: Exit\n");
            printf("\t*******************************\n");
            fflush(stdin);
            scanf("%c",&i);    //输入菜单序号（0-5）

            switch (i-'0'){
                case 1: printf("Print Bin_tree PreOrder: ");
                    PreOrder(root);      //先序遍历
                    break;
                case 2: printf("Print Bin_Tree InOrder: ");
                    InOrder(root);      //中序遍历
                    break;
                case 3: printf("Print Bin_Tree PostOrder: ");
                    PostOrder(root);    //后序遍历
                    break;
                case 4: 
                    depth=TreeDepth(root);     //求树的深度及叶子数
                    printf("BinTree Depth=%d  BinTree Node number=%d",depth,NodeNum);
                    printf("  BinTree Leaf number=%d",countLeaf(root));
                    break;
                case 5: printf("LevelPrint Bin_Tree: ");
                    LevelOrder(root);     //按层次遍历
                    break;
                default: exit(1);
	        }
	        printf("\n");
        } while(i!=0);
}
