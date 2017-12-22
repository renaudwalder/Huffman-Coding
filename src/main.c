#include <stdio.h>
#include <string.h>
#include "Huffman.h"
#define STR "In computer science and information theory, "\
"a Huffman code is a particular type of optimal"\
" prefix code that is commonly used for lossless data compression"
int main(int argc, char* argv[])
{
	for(int i = 0; i< argc; i++)
		printf("arg[%d] : %s\n",i,argv[i]);	

	printf("Probability : \n");
        s_charNode* head = computeProbability(STR, strlen(STR));
        printCharNode(head);
        
        printf("\n\nSorted Probability\n");
        sortCharNode(head);
        printCharNode(head);
        
        printf("\n\nDelete [ ]\n");
        deleteCharNode(&head,' ');
        printCharNode(head);

        printf("\n\nDelete [m]\n");
        deleteCharNode(&head,'m');
        printCharNode(head);

        printf("\n\nDelete [I]\n");
        deleteCharNode(&head,'x');
        printCharNode(head);
        
        printf("\n\nAdd [z,0]\n");
        addCharNode(&head,'z',0);
        printCharNode(head);

        printf("\n\nAdd [?,8]\n");
        addCharNode(&head,'?',8);
        printCharNode(head);
        
        printf("\n\nAdd [!,1000]\n");
        addCharNode(&head,'!',1000);
        printCharNode(head);
        
        
	return 0;
}
