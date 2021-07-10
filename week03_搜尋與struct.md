# Searching 搜尋法
---
- 電腦無法如人類一樣同時看到所有資訊，但其可以一個一個查看。
- 透過搜尋法，電腦可逐一確認，並回傳布林值 `bool`，告知是否為搜尋目標。

## Time Complexity 時間複雜度
- 不同演算法的「資料量與耗費時間」關係圖可能如下：
    ![running_time](./img/running_time.png)

### 時間複雜度上限 (upper bound) $O$
- 描述「最大時間複雜度」，通常使用大寫O符號 $O$ 表示(On the order of...)。
- 通常將係數忽略，並只會取最 dominate 的 n 之函數。
    - 例如：時間為 $n/2$ ，則時間複雜度為 $O(n)$。
    - 例如：時間耗費呈指數型，則為$O(\log n)$，忽略底數。
- 常見的時間複雜度上限：
    - $O(n^2)$
    - $O(n \log n)$
    - $O(n)$
    - $O(\log n)$
    - $O(1)$

### 時間複雜度下限 (lower bound) $\Omega$
- 描述「最小時間複雜度」，使用"Omega"符號($\Omega$)。
- 常見的時間複雜度下限：
    - $\Omega(n^2)$
    - $\Omega(n \log n)$
    - $\Omega(n)$
    - $\Omega(\log n)$
    - $\Omega(1)$

### 平均時間複雜度 (average time complexity) $\Theta$
- 當一演算法「時間複雜度上限」與「時間複雜度下限」相等時，具有「平均時間複雜度」
- Example
    - Selection Sort 具有平均時間複雜度 $\Theta (n^2)$
    - Merge Sort 具有時間複雜度 $\Theta (n \log n)$

## Linear Search (線性搜尋法)
- 線性搜尋(或順序搜)尋是一種尋找某一特定值的搜尋算法，指按一定的順序檢查數組中每一個元素，直到找到所要尋找的特定值為止。是最簡單的一種搜尋算法。
- Example，目標搜尋值 `0`
    ```c
    #include <stdio.h>

    int main(void)
    {
        int numbers[] = {4, 6, 8, 2, 7, 5, 0};

        for (int i = 0; i < 7; i++)
        {
            if (numbers[i] == 0)
            {
                printf("Found\n");
                return 0;
            }
        }
        printf("Not found\n");
        return 1;
    }
    ```
- Example，目標搜尋 `Ron`
    ```c
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>

    int main(void)
    {
        string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

        for (int i = 0; i < 7; i++)
        {
            if (strcmp(names[i], "Ron") == 0)
            {
                printf("Found\n");
                return 0;
            }
        }
        printf("Not found\n");
        return 1;
    }
    ```
    - `strcmp()` 函數(string compare)隸屬於 `string.h`，若字串結果符合，回傳0，否則回傳1。
    - 注意：`names` 已經按照字母排序完成，因此實際上可使用二元搜尋法。
> 「線性搜尋」的時間複雜度：$O(n)$、$\Omega (1)$。

## Binary Search (二分搜尋法)
- 搜尋過程從陣列的中間元素開始，如果中間元素正好是要搜尋的元素，則搜尋過程結束；如果某一特定元素大於或者小於中間元素，則在陣列大於或小於中間元素的那一半中搜尋，而且跟開始一樣從中間元素開始比較。如果在某一步驟陣列為空，則代表找不到。這種搜尋演算法每一次比較都使搜尋範圍縮小一半。
- 注意：需為「已排序」的資料才能使用。
> 「二分搜尋法」的時間複雜度：$O(\log n)$、$\Omega (1)$

&nbsp;
&nbsp;

# Struct 結構體
---
-  結構體(struct)指的是一種資料結構，是C語言中複合資料類型(aggregate data type)的一類。結構體可以被聲明為變數、指標或陣列等，用以實現較複雜的資料結構。結構體同時也是一些元素的集合，這些元素稱為結構體的成員(member)，且這些成員可以為不同的類型，成員一般用名字存取。
- Example，創造電話簿的資料結構：
    ```c
    typedef struct
    {
        string name;
        string number;
    }
    person;
    ```
- Example，建立結構內的資料：
    ```c
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>

    typedef struct
    {
        string name;
        string number;
    }
    person;

    int main(void)
    {
        person people[2];

        people[0].name = "Brian";
        people[0].number = "+1-617-495-1000";

        people[1].name = "David";
        people[1].number = "+1-949-468-2750";

        for (int i = 0; i < 2; i++)
        {
            if (strcmp(people[i].name, "David") == 0)
            {
                printf("Found %s\n", people[i].number);
                return 0;
            }
        }
        printf("Not found\n");
        return 1;
    }
    ```
    - `people[0].names = ...` 即透過 `person` 這個自定義的結構所建立的 `people` 之資料，加入第1筆的name屬性。
    - We create an array of the `person` struct type, and name it `people` (as in `int numbers[]`, though we could name it arbitrarily, like any other variable). We set the values for each field, or variable, inside each `person` struct, using the dot operator, `.`.
    - 可透過此方式更明確的尋找某人所對應的電話號碼，避免分別建立兩個 array 卻導致使用過程中 index 意外出錯。