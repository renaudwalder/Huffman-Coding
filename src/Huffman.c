#include "Huffman.h"

/**
 * Compute the frequency of each character from a string
 * @param text input string where the frequency of each signals much be computed
 * @param len_text length of the text
 * @return a linked list with the frequency of each character
 */
s_charNode* computeProbability(char* text, int len_text)
{
    
    s_charNode* head = (s_charNode*)malloc(sizeof(s_charNode));
    head->c = text[0];
    head->freq = 1;
    head->next = NULL;
    
    for(int i=1;i<len_text;i++)
    {
        char c = text[i];
        int find = 0;
        s_charNode* node = head;
        
        while(1)
        {
            if(c == node->c)
            {
                node->freq++;
                find=1;
                break;
            }
            if(node->next == NULL)
                break;
            node = node->next;
        }
       
        if(!find)
        {
            node->next = (s_charNode*)malloc(sizeof(s_charNode));
            node->next->c = text[i];
            node->next->freq = 1;
            node->next->next = NULL;
            node->next->tree = NULL;
        }
    }
    
    // create every leaf
    s_charNode* node = head;
    do{
        node->tree = (s_huffmanTreeNode*)malloc(sizeof(s_huffmanTreeNode));
        node->tree->c = node->c;
        node->tree->freq = node->freq;
        node->tree->left = NULL;
        node->tree->right = NULL;
        node = node->next;
    }while(node != NULL);
    return head;    
}

/**
 *  delete a node from the linked list
 * @param p_head pointeur on the head
 * @param c character of the node to delete
 */
void deleteCharNode(s_charNode** p_head, char c)
{
    s_charNode* head = (*p_head);        
    if(head->c == c)
    {
        (*p_head) = head->next;
        free(head->tree);
        free(head);
        return;
    }
    
    
    s_charNode* node = head;
    do{
        if(node->next->c == c)
        {
            s_charNode* node_to_del = node->next;
            node->next = node->next->next;
            free(node_to_del->tree);
            free(node_to_del);
            return;
        }
        node = node->next;
    }while(node->next!=NULL);
}
/**
 * Allocation of a node and his tree
 * @param c character of the node which need to be allocated
 * @param freq frequency of this node
 * @return a pointer on the memory location
 */
s_charNode* allocNode(char c, int freq)
{
    s_charNode* node = (s_charNode*)malloc(sizeof(s_charNode));
    node->freq = freq;
    node->c = c;
    node->next = NULL;
    
    // alloc the subtree ( as a leaf
    node->tree = (s_huffmanTreeNode*)malloc(sizeof(s_huffmanTreeNode));
    node->tree->c = node->c;
    node->tree->freq = node->freq;
    node->tree->left = NULL;
    node->tree->right = NULL;
    return node;
}
/**
 * Adding a node onto the linked list (decroissant order)
 * @param p_head pointeur on the head of the linked list
 * @param c character to add
 * @param freq frequency of this character
 */
void addCharNode(s_charNode** p_head, char c, int freq)
{
    s_charNode* node = *p_head;
    if(freq < (*p_head)->freq)  // lowest frequecy?
    {
        (*p_head) = allocNode(c,freq);
        (*p_head)->next = node; // change the head node
        return;
    }
    
        
    while((node->next != NULL) && (freq > node->next->freq))
    {
        node = node->next;
    }
    s_charNode* tmp = node->next;
    node->next = allocNode(c,freq);
    node->next->next = tmp;
}
/**
 * print the linked list
 * @param head the head of the linked list
 */
void printCharNode(s_charNode* head)
{
    int i=0;
    s_charNode* node = head;
    do{
        DEBUG("[%c] : %4d    ",node->c, node->freq);
        if(i++==3)
        {
            DEBUG("\n");
            i=0;
        }
        node = node->next;
    }while(node != NULL);
}

/**
 * Sort the linked list of the character node
 * @param head head of the linked list
 */
void sortCharNode(s_charNode* head)
{
    if((head == NULL)||(head->next == NULL))
        return;
    
    int finish;     // exit boolean condition
    do{
        finish=1;
        s_charNode* node = head;
        do{
            if(node->next->freq < node->freq)
            {
                // switch values
                s_charNode temp = *node->next;
                node->next->c = node->c;
                node->next->freq = node->freq;
                node->c = temp.c;
                node->freq = temp.freq;
                finish = 0;
            }
            //printCharNode(node);
            node = node->next;
            //DEBUG("OK");
        }while(node->next != NULL);
    }while(!finish);
}