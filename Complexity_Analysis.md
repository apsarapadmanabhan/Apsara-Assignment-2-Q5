# Complexity Analysis - Question 5

## 1. Tree Structure

The organisational hierarchy contains 8 nodes:

1. CEO
2. HR
3. Finance
4. IT
5. Development
6. Testing
7. Frontend
8. Backend

The tree has 4 levels.

If tree height is defined as the number of edges on the longest
root-to-leaf path, its height is 3.

Longest path:

`CEO → IT → Development → Frontend`

## 2. Tree Construction

Each department node is created once.

### Time Complexity

For n nodes:

**O(n)**

### Space Complexity

The tree stores n nodes:

**O(n)**

## 3. Level-Order Traversal

Level-order traversal visits every node exactly once.

### Time Complexity

**O(n)**

### Auxiliary Space

A queue is used to store nodes waiting to be processed.

Worst-case auxiliary space:

**O(n)**

## 4. Linear Search

Linear Search checks department names sequentially.

### Best Case

The required department is the first element.

**O(1)**

### Average Case

Several elements may be checked.

**O(n)**

### Worst Case

The last element is checked, or the item is absent.

**O(n)**

### Auxiliary Space

The iterative search uses a constant amount of extra memory.

**O(1)**

## 5. Binary Search

Binary Search is applied to the sorted department list.

After each comparison, approximately half of the remaining elements
are discarded.

### Best Case

The middle element is the required department.

**O(1)**

### Average Case

**O(log n)**

### Worst Case

**O(log n)**

### Auxiliary Space

The program uses an iterative implementation.

**O(1)**

## 6. Overall Complexity Table

| Operation | Time Complexity | Auxiliary Space |
|---|---|---|
| Tree construction | O(n) | O(n) |
| Level-order traversal | O(n) | O(n) |
| Linear Search | O(n) | O(1) |
| Binary Search | O(log n) | O(1) |

## 7. Analysis of Execution Results

For the selected searches:

- Frontend: Linear = 4, Binary = 1
- HR: Linear = 5, Binary = 3
- Testing: Linear = 7, Binary = 3

The observed results show fewer comparisons for Binary Search on the
sorted department representation.

## 8. Final Analysis

The organisational hierarchy is naturally represented by a tree because
one CEO can have departments and a department can have sub-departments.

Level-order traversal is appropriate for reporting the hierarchy
level by level.

For repeated department searching, Binary Search provides a lower
asymptotic search time than Linear Search, provided the searchable
department representation is sorted.
