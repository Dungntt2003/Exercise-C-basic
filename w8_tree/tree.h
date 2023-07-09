#ifndef __TREE_H__
#define __TREE_H__

typedef int elmType;
// whatever type of element

typedef struct nodeType {
  elmType element;
  struct nodeType *left, *right;
} node_type;

typedef struct nodeType *treetype;

void makeNullTree(treetype *t);
node_type *create_node(elmType NewData);
int isEmptyTree(treetype T);
treetype LeftChild(treetype n);
treetype RightChild(treetype n);
int IsLeaf(treetype n);
int nb_nodes(treetype T);
treetype createfrom2(elmType v, treetype l, treetype r);
treetype Add_Left(treetype *Tree, elmType NewData);
treetype Add_Right(treetype *Tree, elmType NewData);

#endif