# Comparison Table - Question 5

## A. Linear Search and Binary Search

| Feature | Linear Search | Binary Search |
|---|---|---|
| Basic method | Checks elements one by one | Divides the sorted search range into halves |
| Sorted data required | No | Yes |
| Data representation used | Array/list | Sorted array/list |
| Best-case time | O(1) | O(1) |
| Average-case time | O(n) | O(log n) |
| Worst-case time | O(n) | O(log n) |
| Auxiliary space in this program | O(1) | O(1) |
| Main observation | Number of comparisons can grow with position | Search interval becomes smaller after each comparison |

## B. Observed Search Comparisons

| Department | Linear Search Comparisons | Binary Search Comparisons |
|---|---:|---:|
| Frontend | 4 | 1 |
| HR | 5 | 3 |
| Testing | 7 | 3 |

## C. Interpretation

1. Linear Search starts from the first element and checks each element
   until the required department is found.

2. Binary Search uses the middle element and eliminates approximately
   half of the remaining search range after each comparison.

3. Binary Search requires the department names to be sorted. Therefore,
   the searchable representation in this program is stored alphabetically.

4. For the three selected searches, Binary Search used fewer comparisons.

## D. Tree Representation and Traversal

| Aspect | Observation |
|---|---|
| Number of nodes | 8 |
| Number of levels | 4 |
| Height in edges | 3 |
| Traversal used | Level-order traversal |
| Data structure for traversal | Queue |
| Traversal time | O(n) |
| Traversal auxiliary space | O(n) worst case |

## E. Suitability for the Given Application

The tree is suitable for organisational reporting because departments
and sub-departments have a natural parent-child relationship.

Level-order traversal is suitable when the hierarchy needs to be viewed
level by level.

For department searching, a sorted searchable representation together
with Binary Search is appropriate when efficient repeated searching is
required and the data can be maintained in sorted order.
