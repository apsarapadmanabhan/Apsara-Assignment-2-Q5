/*
 * ADS Assignment 2 - Question 5
 * Subject: PCCST303 - Data Structures and Algorithms
 * Branch: Artificial Intelligence and Data Science
 *
 * Topic:
 * Organisational hierarchy represented using a tree,
 * level-order traversal, Linear Search and Binary Search.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------- TREE STRUCTURE -------------------- */

struct Node {
    char name[30];
    struct Node *child1;
    struct Node *child2;
    struct Node *child3;
};

/* Create and initialize a tree node */
struct Node *createNode(const char name[]) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newNode->name, name);

    newNode->child1 = NULL;
    newNode->child2 = NULL;
    newNode->child3 = NULL;

    return newNode;
}

/*
 * Level-order traversal:
 * A simple array-based queue is used.
 * Nodes are processed level by level.
 */
void levelOrder(struct Node *root) {
    struct Node *queue[20];
    int front = 0;
    int rear = 0;

    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    queue[rear++] = root;

    printf("\nLevel-order traversal:\n");

    while (front < rear) {
        struct Node *current = queue[front++];

        printf("%s  ", current->name);

        if (current->child1 != NULL)
            queue[rear++] = current->child1;

        if (current->child2 != NULL)
            queue[rear++] = current->child2;

        if (current->child3 != NULL)
            queue[rear++] = current->child3;
    }

    printf("\n");
}

/*
 * Returns the number of levels in the tree.
 *
 * For this hierarchy:
 * Level 1 = CEO
 * Level 2 = HR, Finance, IT
 * Level 3 = Development, Testing
 * Level 4 = Frontend, Backend
 *
 * Therefore, number of levels = 4.
 */
int treeLevels(struct Node *root) {
    int h1, h2, h3, max;

    if (root == NULL)
        return 0;

    h1 = treeLevels(root->child1);
    h2 = treeLevels(root->child2);
    h3 = treeLevels(root->child3);

    max = h1;

    if (h2 > max)
        max = h2;

    if (h3 > max)
        max = h3;

    return max + 1;
}

/* -------------------- LINEAR SEARCH -------------------- */

/*
 * Linear Search checks each department from left to right
 * until the required department is found.
 */
int linearSearch(char departments[][30], int n,
                 const char key[], int *comparisons) {
    int i;

    *comparisons = 0;

    for (i = 0; i < n; i++) {
        (*comparisons)++;

        if (strcmp(departments[i], key) == 0)
            return i;
    }

    return -1;
}

/* -------------------- BINARY SEARCH -------------------- */

/*
 * Binary Search works on the sorted department list.
 * It repeatedly divides the search interval into two halves.
 */
int binarySearch(char departments[][30], int n,
                 const char key[], int *comparisons) {
    int low = 0;
    int high = n - 1;

    *comparisons = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        int result;

        (*comparisons)++;

        result = strcmp(departments[mid], key);

        if (result == 0)
            return mid;
        else if (result < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

/* -------------------- DISPLAY SEARCH RESULT -------------------- */

void performSearch(char departments[][30], int n, const char key[]) {
    int linearPosition;
    int binaryPosition;
    int linearComparisons;
    int binaryComparisons;

    linearPosition =
        linearSearch(departments, n, key, &linearComparisons);

    binaryPosition =
        binarySearch(departments, n, key, &binaryComparisons);

    printf("\nSearch key: %s\n", key);

    if (linearPosition != -1)
        printf("Linear Search : Found\n");
    else
        printf("Linear Search : Not Found\n");

    printf("Linear Search comparisons = %d\n", linearComparisons);

    if (binaryPosition != -1)
        printf("Binary Search : Found\n");
    else
        printf("Binary Search : Not Found\n");

    printf("Binary Search comparisons = %d\n", binaryComparisons);
}

/* -------------------- FREE TREE MEMORY -------------------- */

void freeTree(struct Node *root) {
    if (root == NULL)
        return;

    freeTree(root->child1);
    freeTree(root->child2);
    freeTree(root->child3);

    free(root);
}

/* -------------------- MAIN FUNCTION -------------------- */

int main(void) {

    /*
     * Part A:
     * Construct the organisational hierarchy.
     *
     * CEO
     * ├── HR
     * ├── Finance
     * └── IT
     *     ├── Development
     *     │   ├── Frontend
     *     │   └── Backend
     *     └── Testing
     */

    struct Node *CEO = createNode("CEO");

    CEO->child1 = createNode("HR");
    CEO->child2 = createNode("Finance");
    CEO->child3 = createNode("IT");

    CEO->child3->child1 = createNode("Development");
    CEO->child3->child2 = createNode("Testing");

    CEO->child3->child1->child1 = createNode("Frontend");
    CEO->child3->child1->child2 = createNode("Backend");

    printf("==================================================\n");
    printf("       ORGANISATIONAL HIERARCHY - QUESTION 5\n");
    printf("==================================================\n");

    printf("\nA) ORGANISATIONAL HIERARCHY\n\n");

    printf("CEO\n");
    printf("|-- HR\n");
    printf("|-- Finance\n");
    printf("|-- IT\n");
    printf("    |-- Development\n");
    printf("    |   |-- Frontend\n");
    printf("    |   |-- Backend\n");
    printf("    |-- Testing\n");

    levelOrder(CEO);

    printf("\nNumber of levels = %d\n", treeLevels(CEO));
    printf("Tree height (when counted as edges) = %d\n",
           treeLevels(CEO) - 1);

    /*
     * Part B:
     * Department names are stored in alphabetical order.
     * Sorting is necessary for Binary Search.
     */
    char departments[][30] = {
        "Backend",
        "Development",
        "Finance",
        "Frontend",
        "HR",
        "IT",
        "Testing"
    };

    int n = 7;

    printf("\n==================================================\n");
    printf("             DEPARTMENT SEARCH\n");
    printf("==================================================\n");

    printf("\nSorted department representation:\n");

    for (int i = 0; i < n; i++)
        printf("%d. %s\n", i + 1, departments[i]);

    printf("\nThree search operations:\n");

    performSearch(departments, n, "Frontend");
    performSearch(departments, n, "HR");
    performSearch(departments, n, "Testing");

    /*
     * Part C:
     * Complexity analysis.
     */
    printf("\n==================================================\n");
    printf("             COMPLEXITY ANALYSIS\n");
    printf("==================================================\n");

    printf("\nTree construction : O(n) time, O(n) space\n");
    printf("Level-order       : O(n) time, O(n) auxiliary space\n");
    printf("Linear Search     : O(n) time, O(1) auxiliary space\n");
    printf("Binary Search     : O(log n) time, O(1) auxiliary space\n");

    printf("\nFINAL CONCLUSION\n");
    printf("The tree representation is suitable for the\n");
    printf("organisational hierarchy because it represents\n");
    printf("parent-child relationships clearly.\n");

    printf("\nLevel-order traversal is suitable for\n");
    printf("organisational reporting because it processes\n");
    printf("the hierarchy level by level.\n");

    printf("\nFor department searching, Binary Search can\n");
    printf("reduce the number of comparisons when the\n");
    printf("department names are maintained in sorted order.\n");

    /* Release dynamically allocated memory */
    freeTree(CEO);

    return 0;
}
