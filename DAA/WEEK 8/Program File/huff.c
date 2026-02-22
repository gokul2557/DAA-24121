#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Tree structure
struct HuffNode {
    char symbol;
    int weight;
    struct HuffNode *lchild, *rchild;
};

// Create new tree node
struct HuffNode* newHuffNode(char symbol, int weight) {
    struct HuffNode* tempNode = 
        (struct HuffNode*)malloc(sizeof(struct HuffNode));

    tempNode->symbol = symbol;
    tempNode->weight = weight;
    tempNode->lchild = tempNode->rchild = NULL;

    return tempNode;
}

// Sort nodes in ascending order
void arrange(struct HuffNode* list[], int count) {
    for(int x = 0; x < count-1; x++) {
        for(int y = x+1; y < count; y++) {
            if(list[x]->weight > list[y]->weight) {
                struct HuffNode* swapNode = list[x];
                list[x] = list[y];
                list[y] = swapNode;
            }
        }
    }
}

// Print Huffman codes
void displayCodes(struct HuffNode* head, int path[], int level,
                  int *compressedBits, int *charCount) {

    if(head->lchild) {
        path[level] = 0;
        displayCodes(head->lchild, path, level+1,
                     compressedBits, charCount);
    }

    if(head->rchild) {
        path[level] = 1;
        displayCodes(head->rchild, path, level+1,
                     compressedBits, charCount);
    }

    // If leaf node
    if(!head->lchild && !head->rchild) {
        printf("%c : ", head->symbol);

        for(int i = 0; i < level; i++)
            printf("%d", path[i]);

        printf("  (freq=%d, length=%d)\n",
               head->weight, level);

        *compressedBits += head->weight * level;
        *charCount += head->weight;
    }
}

int main() {

    char inputStr[] =
    "DATA ANALYTICS AND INTELLIGENCE LABORATORY";

    int frequency[256] = {0};

    // Step 1: Calculate frequency
    for(int i = 0; inputStr[i] != '\0'; i++) {
        if(inputStr[i] != ' ')
            frequency[(int)inputStr[i]]++;
    }

    struct HuffNode* nodeList[SIZE];
    int nodeTotal = 0;

    // Create initial nodes
    for(int j = 0; j < 256; j++) {
        if(frequency[j] > 0) {
            nodeList[nodeTotal++] =
                newHuffNode((char)j, frequency[j]);
        }
    }

    // Build Huffman Tree
    while(nodeTotal > 1) {

        // Arrange in ascending order
        arrange(nodeList, nodeTotal);

        // Select two smallest
        struct HuffNode* firstNode = nodeList[0];
        struct HuffNode* secondNode = nodeList[1];

        // Create new internal node
        struct HuffNode* mergedNode =
            newHuffNode('#',
                        firstNode->weight +
                        secondNode->weight);

        mergedNode->lchild = firstNode;
        mergedNode->rchild = secondNode;

        // Replace nodes
        nodeList[0] = mergedNode;
        nodeList[1] = nodeList[nodeTotal-1];
        nodeTotal--;
    }

    struct HuffNode* treeRoot = nodeList[0];

    int codeTrack[SIZE];
    int totalCompressed = 0;
    int totalCharacters = 0;

    printf("Huffman Codes:\n\n");

    displayCodes(treeRoot, codeTrack, 0,
                 &totalCompressed, &totalCharacters);

    printf("\nTotal Compressed Bits = %d\n",
           totalCompressed);

    float averageLength =
        (float)totalCompressed / totalCharacters;

    printf("Average Code Length = %.2f bits\n",
           averageLength);

    return 0;
}
