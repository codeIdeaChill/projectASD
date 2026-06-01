
# Problem Solving Documentation - ADS2 Project

## Module 1 — Arrays (Part A: 1D Static Arrays)

### Function: initArray
- Input: `arr[]` — the array, `*size` — pointer to the current element count.
- Output: Modifies the value pointed to by `size` to 0.
- Edge cases: None. The function safely resets the logical size regardless of the garbage values in memory.
#### Algorithm
1. Access the memory location pointed to by `size`.
2. Assign the value 0 to this location.
#### Worked Example
- Before: `arr = [4, 8, 15]`, `*size = 3`
- Execution: `initArray(arr, &size)`
- After: `*size = 0` (The array is logically empty).

---
### Function: printArray
- Input: `arr[]` — the array, `size` — current element count.
- Output: Prints the array to standard output in the format `[a, b, c]`. Returns nothing.
- Edge cases: Empty array (`size == 0`) should print `[]`.
#### Algorithm
1. Print the opening bracket `[`.
2. Loop through the array from index `0` to `size - 1`.
3. Print the element at the current index.
4. If the current element is not the last element, print a comma and a space `, `.
5. Print the closing bracket `]\n`.
#### Worked Example
- Input: `arr = [5, 10, 15]`, `size = 3`
- Output on screen: `[5, 10, 15]`

---
### Function: insertAt
- Input: `arr[]`, `*size`, `index`, `value`.
- Output: returns 0 on success, -1 on error; modifies `arr[]` and increments `*size`.
- Edge cases: `index` out of bounds, array is completely full (`*size >= MAX_1D`).
#### Algorithm
1. Check if `index` is valid and array has space. Return -1 if invalid.
2. Iterate backwards from `i = *size` down to `index + 1`.
3. Shift each element one position to the right (`arr[i] = arr[i - 1]`).
4. Insert `value` at `arr[index]`.
5. Increment `*size` by 1 and return 0.
#### Worked Example
- Before: `arr = [10, 20, 30]`, `size = 3`, Insert `15` at `index = 1`
- Shift: `[10, 20, 20, 30]`. Insert: `[10, 15, 20, 30]`. `size = 4`.

---
### Function: deleteAt
- Input: `arr[]`, `*size`, `index`.
- Output: returns 0 on success, -1 on error; modifies `arr[]` and decrements `*size`.
- Edge cases: `index` out of bounds, attempting to delete from an empty array.
#### Algorithm
1. Check if `*size == 0` or if `index` is out of bounds. Return -1 if true.
2. Loop from `i = index` up to `*size - 2`.
3. Shift each element one position to the left (`arr[i] = arr[i + 1]`).
4. Decrement `*size` by 1 and return 0.
#### Worked Example
- Before: `arr = [10, 15, 20, 30]`, `size = 4`, Delete at `index = 1`
- After: `size = 3`, array is `[10, 20, 30]`.

---
### Function: linearSearch
- Input: `arr[]`, `size`, `value`.
- Output: Returns the index of the first occurrence of the target, or `-1` if not found.
- Edge cases: Empty array (`size == 0`).
#### Algorithm
1. Loop through the array using index `i` from `0` to `size - 1`.
2. If `arr[i] == value`, immediately return `i`.
3. If the loop finishes without finding a match, return `-1`.
#### Worked Example
- Input: `arr = [7, 3, 9, 2]`, `size = 4`, Target `9`
- i=2: `arr[2] == 9`. Return 2.

---
### Function: binarySearch
- Input: `arr[]` (sorted), `size`, `value`.
- Output: Returns the index of the target if found, or `-1`.
- Edge cases: Array is empty.
#### Algorithm
1. Initialize pointers: `low = 0` and `high = size - 1`.
2. Loop while `low <= high`:
   a. Calculate `mid = low + (high - low) / 2`.
   b. If `arr[mid] == value`, return `mid`.
   c. If `arr[mid] < value`, set `low = mid + 1`.
   d. If `arr[mid] > value`, set `high = mid - 1`.
3. Return -1 if not found.
#### Worked Example
- Input: `arr = [2, 4, 6, 8, 10]`, Target `8`
- mid=2 (value 6). `6 < 8`, low=3. mid=3 (value 8). Match. Return 3.

---
### Function: bubbleSort
- Input: `arr[]`, `size`.
- Output: Sorts the array in ascending order in-place.
- Edge cases: Array is already sorted, size <= 1.
#### Algorithm
1. Loop `i` from `0` to `size - 1`.
2. Initialize `early_exit = 0`.
3. Inner loop `j` from `0` to `size - i - 2`:
   a. If `arr[j] > arr[j + 1]`, swap them and set `early_exit = 1`.
4. If `early_exit == 0`, array is sorted. Break loop.
#### Worked Example
- Before: `arr = [5, 1, 4]`
- Pass 1: Swaps -> `[1, 4, 5]`. Pass 2: No swaps. Done.

---
### Function: selectionSort
- Input: `arr[]`, `size`.
- Output: Sorts the array in ascending order in-place.
- Edge cases: size <= 1.
#### Algorithm
1. Loop `i` from `0` to `size - 2`.
2. Set `min_index = i`.
3. Inner loop `j` from `i + 1` to `size - 1`. If `arr[j] < arr[min_index]`, update `min_index = j`.
4. Swap `arr[i]` with `arr[min_index]` if they are different.
#### Worked Example
- Before: `arr = [8, 4, 2]`
- i=0: Min is 2. Swap(8, 2) -> `[2, 4, 8]`.

---
### Function: insertionSort
- Input: `arr[]`, `size`.
- Output: Sorts the array in-place by building a sorted prefix.
- Edge cases: Already sorted array (best case).
#### Algorithm
1. Loop `i` from `1` to `size - 1`.
2. `key = arr[i]`, `j = i - 1`.
3. While `j >= 0` and `arr[j] > key`: shift `arr[j + 1] = arr[j]`, decrement `j`.
4. Insert `arr[j + 1] = key`.
#### Worked Example
- Before: `arr = [5, 3, 4]`
- i=1: key=3. 5>3 (shift). Insert 3 -> `[3, 5, 4]`.

---
### Function: mergeSort
- Input: `arr[]`, `left`, `right`.
- Output: Sorts the specified segment recursively.
- Edge cases: `left >= right` (base case).
#### Algorithm
1. If `left >= right`, return.
2. `mid = left + (right - left) / 2`.
3. Call `mergeSort(arr, left, mid)`.
4. Call `mergeSort(arr, mid + 1, right)`.
5. Call `merge(arr, left, mid, right)` to combine halves.
#### Worked Example
- Input: `[38, 27]` -> Split into `[38]`, `[27]`. Merge into `[27, 38]`.

---
### Function: quickSort
- Input: `arr[]`, `low`, `high`.
- Output: Sorts the array in-place recursively.
- Edge cases: `low >= high`.
#### Algorithm
1. If `low >= high`, return.
2. Partition the array around a pivot (e.g., `arr[high]`).
3. Recursively call `quickSort` on the left sub-array (before pivot).
4. Recursively call `quickSort` on the right sub-array (after pivot).
#### Worked Example
- Input: `[4, 1, 3]`. Pivot=3. Partition -> `[1, 3, 4]`.

---
### Function: findMax
- Input: `arr[]`, `size`.
- Output: Returns the maximum integer value.
- Edge cases: `size == 0`.
#### Algorithm
1. Initialize `max_val = arr[0]`.
2. Loop `i` from `1` to `size - 1`.
3. If `arr[i] > max_val`, update `max_val = arr[i]`.
4. Return `max_val`.
#### Worked Example
- Input: `[-5, 10, 3]`. max_val becomes 10. Returns 10.

---
### Function: findMin
- Input: `arr[]` — the array, `size` — element count.
- Output: Returns the minimum integer value in the array.
- Edge cases: Array size of 0.
#### Algorithm
1. Initialize a variable `min_val` with the first element (`arr[0]`).
2. Loop `i` from `1` to `size - 1`.
3. If `arr[i] < min_val`, update `min_val = arr[i]`.
4. Return `min_val`.
#### Worked Example
- Input: `arr = [5, 10, -3]`, `size = 3`
- `min_val` initializes to 5. Finds -3. Returns -3.

---
### Function: sumArray
- Input: `arr[]` — the array, `size` — element count.
- Output: Returns the sum of all elements as an integer.
- Edge cases: Array size of 0.
#### Algorithm
1. Initialize an accumulator variable `sum = 0`.
2. Check if `size == 0`. If true, return `0`.
3. Loop `i` from `0` to `size - 1`.
4. Add each element to the accumulator: `sum += arr[i]`.
5. Return `sum`.
#### Worked Example
- Input: `arr = [2, 4, 6]`, `size = 3`
- `sum = 0 + 2 + 4 + 6 = 12`. Returns 12.

---
### Function: averageArray
- Input: `arr[]`, `size`.
- Output: Returns a `double` representing the arithmetic mean.
- Edge cases: `size == 0` (must return `0.0`).
#### Algorithm
1. If `size == 0`, return `0.0`.
2. Call `sumArray(arr, size)` and store in `total`.
3. Return `(double)total / size`.
#### Worked Example
- Input: `[5, 2]`. Total=7. Returns `3.5`.

---
### Function: reverseArray
- Input: `arr[]`, `size`.
- Output: Reverses elements in-place.
- Edge cases: `size <= 1`.
#### Algorithm
1. Loop `i` from `0` to `(size / 2) - 1`.
2. Swap `arr[i]` with `arr[size - 1 - i]`.
#### Worked Example
- Input: `[1, 2, 3]`. Swaps 1 and 3. Result: `[3, 2, 1]`.

---
### Function: rotateLeft
- Input: `arr[]`, `size`, `k`.
- Output: Shifts elements left by `k`.
- Edge cases: `k > size`.
#### Algorithm
1. Normalize shifts: `k = k % size`.
2. Loop `k` times.
3. Store `arr[0]`. Shift `arr[1]` to `arr[size-1]` left by one. Place `arr[0]` at the end.
#### Worked Example
- Input: `[1, 2, 3]`, k=1. Result: `[2, 3, 1]`.

---
### Function: mergeSortedArrays
- Input: `a[]`, `b[]`, `na`, `nb`, `out[]`.
- Output: Merges `a` and `b` into `out`.
- Edge cases: One array is empty.
#### Algorithm
1. Loop while `i < na` AND `j < nb`. Compare `a[i]` and `b[j]`, copy the smaller to `out[k]`, advance pointers.
2. Copy remaining elements from `a` (if any).
3. Copy remaining elements from `b` (if any).
#### Worked Example
- `a=[1, 5]`, `b=[2, 6]`. Output: `[1, 2, 5, 6]`.

---

## Module 1 — Arrays (Part B: 2D Static Matrices)

### Function: initMatrix
- Input: `m[][MAX_COLS]`, `*rows`, `*cols`.
- Output: Reads dimensions and elements from user.
- Edge cases: Invalid dimensions (<=0 or >MAX).
#### Algorithm
1. Prompt user for rows and cols. Validate bounds.
2. Use nested loops (`i` for rows, `j` for cols).
3. `scanf` into `m[i][j]`.
#### Worked Example
- User inputs 2x2. Elements 1,2,3,4. Matrix is initialized.

---
### Function: printMatrix
- Input: `m[][MAX_COLS]`, `rows`, `cols`.
- Output: Prints matrix in a grid.
- Edge cases: 0 rows/cols.
#### Algorithm
1. Loop `i` for rows, `j` for cols.
2. Print `m[i][j]` with fixed width (e.g., `%4d`).
3. Print newline `\n` after each row.
#### Worked Example
- 2x2 Matrix prints as:
  1   2
  3   4

---
### Function: transposeMatrix
- Input: `m[][MAX_COLS]`, `rows`, `cols`, `out[][MAX_COLS]`.
- Output: Populates `out` with transposed data.
- Edge cases: Rectangular matrices (dimensions flip).
#### Algorithm
1. Nested loops `i` (0 to rows-1), `j` (0 to cols-1).
2. Assign `out[j][i] = m[i][j]`.
#### Worked Example
- Input 2x3. Output becomes 3x2. `out[0][1] = m[1][0]`.

---
### Function: addMatrices
- Input: `a[][]`, `b[][]`, `r[][]`, `rows`, `cols`.
- Output: Element-wise sum in `r`.
- Edge cases: Matrices must have identical dimensions.
#### Algorithm
1. Nested loops for rows and cols.
2. `r[i][j] = a[i][j] + b[i][j]`.
#### Worked Example
- `a[0][0]=5`, `b[0][0]=3` -> `r[0][0]=8`.

---
### Function: multiplyMatrices
- Input: `a[][]`, `b[][]`, `r[][]`, `n`.
- Output: Dot product stored in `r`.
- Edge cases: `n = 0`.
#### Algorithm
1. Initialize `r[i][j] = 0` inside nested loops `i` and `j`.
2. Loop `k` from `0` to `n - 1`.
3. `r[i][j] += a[i][k] * b[k][j]`.
#### Worked Example
- standard row-by-column dot product calculation.

---
### Function: isSymmetric
- Input: `m[][MAX_COLS]`, `n`.
- Output: Returns 1 if symmetric, 0 otherwise.
- Edge cases: 1x1 matrix is trivially symmetric.
#### Algorithm
1. Loop `i` from `0` to `n - 1`. Inner loop `j` from `0` to `i - 1`.
2. If `m[i][j] != m[j][i]`, return 0.
3. If loop finishes, return 1.
#### Worked Example
- `m[1][0] == m[0][1]`. If all match, returns 1.

---

## Module 1 — Arrays (Part C: Dynamic Arrays)

### Function: createDynamicArray
- Input: `capacity`.
- Output: Returns `int*` to heap memory.
- Edge cases: Memory allocation fails (NULL).
#### Algorithm
1. Call `malloc(capacity * sizeof(int))`.
2. If NULL, handle error. Else, return pointer.
#### Worked Example
- `malloc(5 * 4)` returns memory address `0x...`

---
### Function: fillArray
- Input: `int* arr`, `size`.
- Output: Populates array using `scanf`.
- Edge cases: `arr` is NULL.
#### Algorithm
1. Loop `i` from `0` to `size - 1`.
2. `scanf("%d", &arr[i])`.
#### Worked Example
- Fills dynamic block with user integers.

---
### Function: printDynamicArray
- Input: `int* arr` — pointer to the dynamic array, `size` — element count.
- Output: Prints the dynamic array to standard output.
- Edge cases: `arr` is NULL or `size == 0`.
#### Algorithm
1. Check if `arr` is NULL or `size == 0`. Print `[]` if true.
2. Print the opening bracket `[`.
3. Loop `i` from `0` to `size - 1` and print `arr[i]`.
4. Add `, ` if it's not the last element.
5. Print `]\n`.
#### Worked Example
- Input: `arr` points to `{10, 20}`, `size = 2`
- Output: `[10, 20]`

---
### Function: resizeArray
- Input: `int* arr`, `newCapacity`.
- Output: Returns resized memory pointer.
- Edge cases: `realloc` fails (returns NULL).
#### Algorithm
1. Call `realloc(arr, newCapacity * sizeof(int))`.
2. Store in `temp`. If `temp != NULL`, return `temp`.
#### Worked Example
- Original capacity 5. New 10. Memory expanded safely.

---
### Function: freeArray
- Input: `int* arr`.
- Output: Frees memory.
- Edge cases: Passing a NULL pointer.
#### Algorithm
1. Check if `arr != NULL`.
2. Call `free(arr)`.
#### Worked Example
- `free(arr)` returns block to OS.

---

## Module 4 — String Utilities

### Function: reverseString
- Input: `char* s` (null-terminated).
- Output: Reverses string in-place.
- Edge cases: Empty string.
#### Algorithm
1. Find length manually.
2. Initialize `i = 0`, `j = length - 1`.
3. While `i < j`, swap `s[i]` and `s[j]`. Advance pointers.
#### Worked Example
- `"ADS"` -> Swap A and S -> `"SDA"`.

---
### Function: countVowels
- Input: `const char* s`.
- Output: Number of vowels.
- Edge cases: No vowels, mixed cases.
#### Algorithm
1. Initialize `count = 0`.
2. Loop through `s[i]`. Convert to lowercase logic.
3. If 'a','e','i','o','u', increment `count`.
#### Worked Example
- `"Hello"` -> 'e', 'o' -> returns 2.

---
### Function: countConsonants
- Input: `const char* s`.
- Output: Number of consonants.
- Edge cases: Numbers, symbols.
#### Algorithm
1. Loop through `s[i]`.
2. If letter AND NOT vowel, increment `count`.
#### Worked Example
- `"Hi 123!"` -> 'H' -> returns 1.

---
### Function: countWords
- Input: `const char* s`.
- Output: Number of words.
- Edge cases: Multiple spaces, leading spaces.
#### Algorithm
1. `count = 0`, `inWord = 0`.
2. Loop `s[i]`. If space/tab/newline, `inWord = 0`.
3. Else if `inWord == 0`, `inWord = 1`, increment `count`.
#### Worked Example
- `"  C  Library"` -> count transitions -> returns 2.

```