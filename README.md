# ADS Assignment 2 - Question 5

## Subject

**PCCST303 - Data Structures and Algorithms**

## Branch

**Artificial Intelligence and Data Science (ADS)**

## Assignment

**Assignment 2**

## Question

**Question 5**

---

## 1. Problem Statement

A company has the following organisational hierarchy:

- CEO → HR, Finance, IT
- IT → Development, Testing
- Development → Frontend, Backend

The task is to:

1. Represent the hierarchy using a suitable tree structure.
2. Implement the construction of the hierarchy.
3. Display the hierarchy using level-order traversal.
4. Store department names in a suitable searchable representation.
5. Compare Linear Search and Binary Search for locating departments.
6. Record the number of comparisons for at least three searches.
7. Analyse tree height, traversal behaviour, search comparisons and time complexity.
8. Determine whether the chosen representation is suitable for organisational reporting and department searching.

---

## 2. Organisational Hierarchy

```text
CEO
├── HR
├── Finance
└── IT
    ├── Development
    │   ├── Frontend
    │   └── Backend
    └── Testing
```

The CEO is the root of the tree.

HR, Finance and IT are direct children of the CEO.

Development and Testing are children of IT.

Frontend and Backend are children of Development.

---

## 3. Tree Representation

A tree is suitable because the organisation naturally follows a
parent-child relationship.

The hierarchy contains 8 nodes:

- CEO
- HR
- Finance
- IT
- Development
- Testing
- Frontend
- Backend

There are 4 levels:

- Level 1: CEO
- Level 2: HR, Finance, IT
- Level 3: Development, Testing
- Level 4: Frontend, Backend

The height is 3 when height is counted as edges.

---

## 4. Level-Order Traversal

Level-order traversal processes the tree one level at a time.

A queue is used for this traversal.

### Result

```text
CEO → HR → Finance → IT → Development → Testing → Frontend → Backend
```

This traversal is useful for organisational reporting because it presents
the hierarchy from the top level towards lower levels.

---

## 5. Searchable Representation

The department names are stored in alphabetical order:

```text
Backend
Development
Finance
Frontend
HR
IT
Testing
```

The sorted order is necessary for Binary Search.

Three search operations are performed:

1. Frontend
2. HR
3. Testing

---

## 6. Search Results

| Search Key | Linear Search | Binary Search |
|---|---:|---:|
| Frontend | 4 comparisons | 1 comparison |
| HR | 5 comparisons | 3 comparisons |
| Testing | 7 comparisons | 3 comparisons |

Binary Search used fewer comparisons for all three selected searches.

---

## 7. Complexity Analysis

| Operation | Time Complexity | Auxiliary Space |
|---|---|---|
| Tree construction | O(n) | O(n) |
| Level-order traversal | O(n) | O(n) |
| Linear Search | O(n) | O(1) |
| Binary Search | O(log n) | O(1) |

### Linear Search

Linear Search does not require sorted data. It checks departments
sequentially.

### Binary Search

Binary Search requires sorted data. It repeatedly divides the search
range into two parts, reducing the number of elements that need to be
checked.

---

## 8. Execution Conclusion

The tree representation is suitable for the organisational hierarchy
because it represents parent-child relationships clearly.

Level-order traversal is suitable for organisational reporting because
it visits the hierarchy level by level.

For department searching, Binary Search can reduce the number of
comparisons when the department names are maintained in sorted order.

Therefore, the selected tree and searchable representation satisfy the
requirements of the question.

---

## 9. Files Included

| File | Purpose |
|---|---|
| `Question5.c` | Complete C implementation |
| `Input.txt` | Input data and selected search keys |
| `Output.txt` | Expected/recorded program output |
| `Trace_Table.md` | Detailed execution trace |
| `Comparison_Table.md` | Search and representation comparisons |
| `Complexity_Analysis.md` | Time and space complexity |
| `README.md` | Complete assignment explanation |

---

## 10. How to Execute

Compile:

```text
gcc Question5.c -o Question5
```

Run:

```text
./Question5
```

On Windows using MinGW:

```text
gcc Question5.c -o Question5.exe
Question5.exe
```
