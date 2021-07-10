# Sorting 排序
- 使用 binary search 前，資料需經過排序，以下為幾種常見的排序法。
---
## Selection Sort
- Pseudocode：
    ```
    For i from 0 to n–1
        Find smallest item between i'th item and last item
        Swap smallest item with i'th item
    ```
- Example
    - 欲排序資料：`6 3 8 5 2 7 4 1`
    - 指標於第一筆，第一筆到最後一筆，`1`最小，將第一筆與`1`交換，`1 3 8 5 2 7 4 6`。
    - 指標於第二筆，第二筆到最後一筆，`2`最小，將第二筆與`2`交換，`1 2 8 5 3 7 4 6`。
    - 以此類推...
    - 
- 第一次執行 $n$ 次，第二次執行 $n-1$ 次...，共 $n+(n-1)+(n-2)+...+1$ 次。
    - $n + (n – 1) + (n – 2) + ... + 1$
    - $n(n + 1)/2$
    - $(n^2 + n)/2$
    - $n^2/2 + n/2$
    - $O(n^2)$
- Worst-case Scenario：需從第一個執行至最後，此流程需重複n次，每次只有一元素被排序。
- Best-case Scenario：同最差情況，每個項目均需被執行過才能確保每個元素已被排序。
> Selection Sort 時間複雜度：$O(n^2)$、$\Omega (n^2)$、$\Theta (n^2)$。

## Bubble Sort
- Pseudocode：
    ```
    Repeat until sorted (No swap anymore)
        For i from 0 to n–2
            If i'th and i+1'th elements out of order
                Swap them
    ```
- Example
    - 欲排序資料：`6 3 8 5 2 7 4 1`
    - 從第一筆開始相鄰兩者檢查是否需交換。
    - `6`、`3`交換，`3 6 8 5 2 7 4 1`。
    - `8`、`6`交換，`3 8 6 5 2 7 4 1`。
    - `8`、`5`交換，`3 6 8 5 2 7 4 1`。
    - 以此類推...
    - 第一輪結束之結果為：`3 6 5 2 7 4 1 8`，最大值已經被swap至最後。
    - 重複執行第一到第七筆資料、第一到第六筆...，直到每一個都不用再交換。
- Worst-casr Scenario：原始資料正好為顛倒排序。每次都需要swap，所有較大的資料皆需移至最右側，而所有佐次資料皆須移至最左側。 
- Best-case Scenario：在第一輪檢查，所有資料皆不需交換，即最佳情況。
> Bubble Sort 時間複雜度：$O(n^2)$、$\Omega (n)$。

## Merge Sort
- 需用到遞迴之觀念，如下段。
- 概念上，即將資料拆分成左與右半部，並將其排序合成。
- Pseudocode：
    ```
    If only one number
        Return
    Else
        Sort left half of number
        Sort right half of number
        Merge sorted halves
    ```
- Example
    1. 將欲排序資料切開一半，`6 3 8 5`|`2 7 4 1`。
    2. 將左半部再切一半，`6 3`|`8 5`。
    3. 左半部再切一半，`6`|`3`，獨立陣列不需被排序，故排序兩獨立陣列`6`與`3`。兩者需交換排序並合成：
        ```
        - - 8 5 2 7 4 1
        3 6
        ```
    4. 回到原始資料一半的另一半，切開為 `8`|`5`，排序兩獨立陣列`8`與`5`，將其排序並合成：
        ```
        - - - - 2 7 4 1
        3 6|5 8
        ```
    5. 將 `3 6 |5 8`排序並合成，取兩組間最左邊者比較大小，`3`較小：
        ```
        - - - - 2 7 4 1
        - 6|5 8
        3
        ```
    6. `6`與`5`相比，`5`較小，排序並合成：
        ```
        - - - - 2 7 4 1
        - 6|- 8
        3 5
        ```
    7. 以此類推，完成左半邊：
        ```
        - - - - 2 7 4 1
        - - - -
        3 5 6 8
        ```
    8. 重複 2. ~ 7. 步驟，完成右半邊：
        ```
        - - - - - - - -
        - - - - - - - -
        3 5 6 8|1 2 4 7
    9. 將左右半邊排序並合成：
        ```
        - - - - - - - -
        - - - - - - - -
        - - - - - - - -
        1 2 3 4 5 6 7 8
        ```
- Worst-case Scenario：需將 $n$ 筆資料全部分開並重組，使得已排序的子陣列數加倍。(ex. combind TWO sorted 1-element arrays into ONE sorted 2-element array.)
- Best-case Scenario：已經排序完成，但仍需逐一分開並檢查大小、重組。
> Merge Sort 時間複雜度：$O(n \log n)$、$\Omega (n \log n)$、$\Theta (n \log n)$。

## 補充說明
- 在已排序資料的情況下，Bubble sort 最快、Selection sort 最慢。
- 完全倒序的資料下，Merge sort 最快、Bubble sort 最慢。
    - 注意，Bubble 與 Selection 的 worst-case time complexity 都是 $O(n^2)$ ，但實際上 Bubble sort 最慢。
- Selection sort 在時間複雜度的表示法上，可能看起來永遠是最差的；但實際上，在 random 資料的情況下，Bubble sort 可能最慢。

&nbsp;
&nbsp;

# Recursion 遞迴
---
- 「遞迴」指一個函數本身自己呼叫自己。
- 使用遞迴的技巧可以使程式碼更美觀且避免冗長的迴圈。
- 使用尚須小心，很可能造成無限遞迴。
- Example
    - 「階乘」及含有遞迴的概念，fact(n) 即 n 階乘：
        - fact(1) = 1
        - fact(2) = 2 * 1
        - fact(3) - 3 * 2 * 1
    - 亦可轉換為：
        - fact(1) = 1
        - fact(2) = 2 * fact(1)
        - fact(3) = 3 * fact(2)
    - Code *(by recursion)*：
        ```c
        int fact(int n)
        {
            // base case (prevent from infinite loop)
            if (n == 1)
                return 1;
            // recursive case
            else
                return n * fact(n-1);
        }
        ```
        - We can remove the curly braces `{}` because there is only one line of code inside the if-else function.
    - Code *(by iteration, but not RECURSION)*：
        ```c
        int fact(int n)
        {
            int product = 1;
            while (n > 0)
            {
                product *= n;
                n--;
            }
            return product;
        }
        ```
- Base case 或 recursive case 可能不只一個條件。
- 其他常見的遞迴應用：費波那契函數、Collatz conjecture。
- Example，Collatz conjecture：(需花費步驟數回到1)
    ```c
    int collatz(int n)
    {
        // base case
        if (n == 1)
            return 0;
        // recursive case: even number
        else if ((n % 2) == 0)
            return 1 + collatz(n/2);
        // recursive case: odd number 
        else
            return 1 + collatz(3*n + 1);
    }
    ```