# Trace Table - Question 5

## 1. Tree Construction Trace

The hierarchy is constructed according to the question.

| Step | Node Added | Parent Node | Level |
|---:|---|---|---:|
| 1 | CEO | Root | 1 |
| 2 | HR | CEO | 2 |
| 3 | Finance | CEO | 2 |
| 4 | IT | CEO | 2 |
| 5 | Development | IT | 3 |
| 6 | Testing | IT | 3 |
| 7 | Frontend | Development | 4 |
| 8 | Backend | Development | 4 |

## 2. Level-Order Traversal Trace

A queue is used. The root is inserted first. Its children are then
inserted into the queue and processed from front to rear.

| Step | Node Removed/Processed | Children Added | Traversal Output |
|---:|---|---|---|
| 1 | CEO | HR, Finance, IT | CEO |
| 2 | HR | None | CEO, HR |
| 3 | Finance | None | CEO, HR, Finance |
| 4 | IT | Development, Testing | CEO, HR, Finance, IT |
| 5 | Development | Frontend, Backend | CEO, HR, Finance, IT, Development |
| 6 | Testing | None | CEO, HR, Finance, IT, Development, Testing |
| 7 | Frontend | None | CEO, HR, Finance, IT, Development, Testing, Frontend |
| 8 | Backend | None | CEO, HR, Finance, IT, Development, Testing, Frontend, Backend |

### Final Level-Order Traversal

**CEO → HR → Finance → IT → Development → Testing → Frontend → Backend**

## 3. Linear Search Trace

Department list:

`Backend, Development, Finance, Frontend, HR, IT, Testing`

### Search 1: Frontend

| Comparison No. | Compared Department | Result |
|---:|---|---|
| 1 | Backend | Not equal |
| 2 | Development | Not equal |
| 3 | Finance | Not equal |
| 4 | Frontend | Found |

**Total comparisons = 4**

### Search 2: HR

| Comparison No. | Compared Department | Result |
|---:|---|---|
| 1 | Backend | Not equal |
| 2 | Development | Not equal |
| 3 | Finance | Not equal |
| 4 | Frontend | Not equal |
| 5 | HR | Found |

**Total comparisons = 5**

### Search 3: Testing

| Comparison No. | Compared Department | Result |
|---:|---|---|
| 1 | Backend | Not equal |
| 2 | Development | Not equal |
| 3 | Finance | Not equal |
| 4 | Frontend | Not equal |
| 5 | HR | Not equal |
| 6 | IT | Not equal |
| 7 | Testing | Found |

**Total comparisons = 7**

## 4. Binary Search Trace

The department list is sorted alphabetically.

### Search 1: Frontend

Initial range: Backend to Testing

| Step | Low | High | Middle | Comparison Result |
|---:|---|---|---|---|
| 1 | Backend | Testing | Frontend | Found |

**Total comparisons = 1**

### Search 2: HR

| Step | Low | High | Middle | Comparison Result |
|---:|---|---|---|---|
| 1 | Backend | Testing | Frontend | HR comes after Frontend |
| 2 | HR | Testing | IT | HR comes before IT |
| 3 | HR | HR | HR | Found |

**Total comparisons = 3**

### Search 3: Testing

| Step | Low | High | Middle | Comparison Result |
|---:|---|---|---|---|
| 1 | Backend | Testing | Frontend | Testing comes after Frontend |
| 2 | HR | Testing | IT | Testing comes after IT |
| 3 | Testing | Testing | Testing | Found |

**Total comparisons = 3**

## 5. Summary of Observed Comparisons

| Search Key | Linear Search | Binary Search |
|---|---:|---:|
| Frontend | 4 | 1 |
| HR | 5 | 3 |
| Testing | 7 | 3 |
