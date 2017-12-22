#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */

#define DEBUG(...) printf(__VA_ARGS__);fflush(stdout)

/**
 * @struct s_huffmanTreeNode
 * structure of a Huffman tree
 * If the tree is not a leaf, c is useless
 */
typedef struct struct_huffmanTreeNode{
    char c;             ///< character of the tree (only when it is a leaf)
    int freq;           ///< frequency of the tree
    struct struct_huffmanTreeNode* left;    ///< left subtree
    struct struct_huffmanTreeNode* right;   ///< right subtree
}s_huffmanTreeNode;

/**
 * @struct s_charNode
 * structure of a node for each character his frequency and the subtree
 */
typedef struct struct_charNode{
    char c;         ///< character of the node
    int freq;       ///< Frequency of the character
    struct struct_charNode* next;   ///< pointer on the next node
    s_huffmanTreeNode* tree;        ///< Subtree associated to this node (can be leaf) 
}s_charNode;


//s_huffmanNode* GenerateTree(s_charNode* headSortedFrequ);
s_charNode* computeProbability(char* text, int len_text);
void sortCharNode(s_charNode* head);
void printCharNode(s_charNode* head);
void deleteCharNode(s_charNode** p_head, char c);
void addCharNode(s_charNode** p_head, char c, int freq);

#endif // _HUFFMAN_H_
