#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct treeNode
{
    char data[20];
    int count;
    struct treeNode *leftNode, *rightNode;
} TreeNode;

void uppercase(char *s)
{
    int i;
    for (i = 0; s[i]; i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
    }
}

void insertNode(TreeNode **root, char *word)
{
    TreeNode *temp = NULL;
    if (*root == NULL)
    {
        temp = (TreeNode *)malloc(sizeof(TreeNode));
        temp->leftNode = NULL;
        temp->rightNode = NULL;
        temp->count = 1;
        strcpy(temp->data, word);
        *root = temp;
    }
    else if (strcmp(word, (*root)->data) < 0)
    {
        insertNode(&((*root)->leftNode), word);
    }
    else if (strcmp(word, (*root)->data) > 0)
    {
        insertNode(&((*root)->rightNode), word);
    }
    else
    {
        (*root)->count++;
    }
}

void printToOutput(TreeNode *root, FILE *ofp)
{
    if (root != NULL)
    {
        printToOutput(root->leftNode, ofp);
        fprintf(ofp, "%s %d\n", root->data, root->count);
        printToOutput(root->rightNode, ofp);
    }
}

int main(int argc, char *argv[])
{
    FILE *ifp, *ofp;
    char file1, file2;
	strcpy(file1,argv[1]);
	strcpy(file2,argv[2]); 
    if (argc != 3)
    {
        printf("Khong du tham so\n");
        exit(1);
    }
    if ((ifp = fopen(file1, "r")) == NULL)
    {
        printf("Khong the mo %s.\n", argv[1]);
        exit(1);
    }
    if ((ofp = fopen(file2, "w")) == NULL)
    {
        printf("Khong the mo %s.\n", argv[1]);
        exit(1);
    }
    printf("Mo thanh cong file %s.\n", argv[1]);
    printf("Mo thanh cong file %s.\n", argv[2]);
    char *s = (char *)malloc(sizeof(char));
    TreeNode *root = NULL;
    int c, i, j, lengthOfS, countCharacter;
    do
    {
        c = fscanf(ifp, "%s", s);
        if (c != EOF)
        {
            i = 0, j = 0, countCharacter = 0;
            lengthOfS = strlen(s);
            char word[20];
            while (i <= lengthOfS)
            {
                if (isalnum(s[i]))
                {
                    word[j] = s[i];
                    j++;
                    countCharacter++;
                }
                else if (countCharacter != 0)
                {
                    word[countCharacter] = '\0';
                    j = 0;
                    countCharacter = 0;
                    uppercase(word);
                    insertNode(&root, word);
                }
                i++;
            }
        }
    } while (c != EOF);
    printToOutput(root, ofp);
    return 0;
}
