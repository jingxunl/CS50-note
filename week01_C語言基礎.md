## Code - Considerations
- __Correctness__, or whether our code works correctly, as intended.
- __Design__,or a subjective measure of how well-written our code is, based on how efficient it is and how elegant or logically readable it is, without unnecessary repetition.
- __Style__, or how aesthetically formatted our code is.

## Compiling
- To translate the source code that we write in C language into machine code, we need "compiler(直譯器)".
- Use `make` in terminal to process compiling.
    -  `make` .c file name(without `.c`)
    - example: `make hello`
- To execute the program that was made:
    - example:`./hello`
    - `./` means the current folder.

## Functions and Arguments
- __Functinos__ are small actions or verbs that we can use in our program to do something. (程式碼中的某些行動或活動指示，以使程式執行某些行為。)
    - example: `printf()` in C.
    - It has 2 types of outputs:
        1. __Side effect__: such as something printed on screen.
        2. __Return value__: a value that is passed back to the program and can be stored and reused.
- __Arguments__ are the *inputs* to the functions.
    - example: `printf("hello, world")` in C.

## Output
- `printf` 指 *print formatted*
- 分號(`;`)在程式碼結尾中是必要的。
    - Example:
        ```c
        printf("hello, world");
        ```

## Main
- C語言執行時即執行主程式`main`，並以大括號`{}`包含主程式內容。
    ```c
    int main(void)
    {

    }
    ```

## Header Files (標頭檔)
- 標頭檔即`.h`結尾之檔案，其內容為可以在程式碼中使用的程式碼集，類似於資源庫(library)。
    ```c
    #include <stdio.h>
    ```
    - `<stdio>`：standard input/output，標準輸出入。

## Data Types
- 資料型態：
    - `int`：整數，32位元，範圍約「負二十億」到「正二十億」。
    - `unsigned int`：非負整數，32位元，範圍約從「零」到「正四十億」，犧牲負數部分換取更高的正整數值。
    - `float`：浮點數，32位元。精確度可能受位元限制而有所影響。
    - `char`：單一字母，8位元，已足夠包含所有鍵盤上的文字。如'A'為ASCII的65；'a'為97。使用單引號 `''` 來包住內容。
    - `string`：字串。*注意：C語言不存在「字串」型別，其實際上是由`char`所組成的陣列。*
    - `double`：浮點數，64位元。
    - `long`：擁有更多位元的整數，範圍較int更大。
    - `bool`：布林值，true 或 false。0代表 false，任何非零數值為 true。
- 在`printf()`中使用：
    - `%s` for strings
    - `%i` for integers
    - `%c` for characters
    - `%f` for floats and doubles
    - `%li` for longs

## Operators, Limitations, Truncation
- 運算子
    - `+`, `-`, `*`, `/` 即對應加、減、乘、除。
    - `%` 為除法之餘數。
- 邏輯運算子
    - `||` 代表 OR (其中一者為true即為true)
    - `&&` 代表 AND (兩者均為true才是true)
    - `!` 代表 NOT
    - `==` 代表 等於
- 關係運算子
    - `<` 代表 小於
    - `<=` 代表 小於等於
    - `>` 代表 大於
    - `>=` 代表 大於等於
    - `==` 代表 等於
    - `!=` 代表 不等於
- 運算限制
    - Example
        ```c
        #include <cs50.h>
        #include <stdio.h>

        int main(void)
        {
            int x = get_int("x: ");
            int y = get_int("y: ");
            printf("%i\n", x + y);
        }
        ```
    - 若 x 與 y 輸入`4,000,000,000`(40億)，程式會要求重新輸入。`int`具有32位元之限制。
    - 若 `x + y` 的值超過`int`的32位元限制，亦無法輸出。
    - 可將 `int` 改為 `long`，`%i` 改為 `%li` 即可。
- 截斷 Truncation
    - Example
    ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {
        // Get numbers from user
        int x = get_int("x: ");
        int y = get_int("y: ");

        // Divide x by y
        float z = x / y;
        printf("%f\n", z);
    }
    ```
    - x 輸入 1，y 輸入 10，其結果為`0.000000`。
    - 運算 `x / y`時，小數部分就已經被截斷，因此結果仍不會有小數部分。
    - 修復方式：改為 `float z = (float) x / (float) y`，保留運算過程小數的部分。

## Variables, Syntax Sugar
- 可直接宣告並指定一變數的值。
    ```c
    int num = 0
    ```
- 若要增加該值，可作：
    ```c
    num = num + 1
    ```
- 或透過語法糖，作：
    ```c
    num += 1
    ```
    ```c
    num++
    ```

## Conditions
- 條件判斷比較 x 與 y 的值。
    ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {
        // Prompt user for x
        int x = get_int("x: ");

        // Prompt user for y
        int y = get_int("y: ");

        // Compare x and y
        if (x < y)
        {
            printf("x is less than y\n");
        }
        else if (x > y)
        {
            printf("x is greater than y\n");
        }
        else
        {
            printf("x is equal to y\n");
        }
    }
    ```
- 條件判斷可使用 or 及 and 等
    ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {
        char c = get_char("Do you agree? ");

        // Check whether agreed
        if (c == 'Y' || c == 'y')
        {
            printf("Agreed.\n");
        }
        else if (c == 'N' || c == 'n')
        {
            printf("Not agreed.\n");
        }
    }
    ```
    - 注意：`char` 使用單引號 `''` 來包住內容。
- `switch`
    ```c
    #include <stdio.h>
    #include <cs50.h>

    int x = GetInt()

    switch(x)
    {
        case 1:
            printf("One!\n");
            break;
        case 2:
            printf("Two!\n");
            break;
        case 3:
            printf("Three!\n");
            break;
        default:
            print("Sorry!\n");
    }
    ```
    - `break;`是必要的，否則若其將會執行符合條件之case以下的所有程式碼。
- Ternaty operator, `?` and `:`
    - 執行簡單的條件取值，可用以下簡化：
        ```c
        int x = (/*boolean expression*/) ? 1 : 2;
        ```
    - 若條件為true，x = 1；否則 x = 2

## Loops
- `while` loop (__infinite loop__)
    ```c
    while (true)
    {
        printf("hello, world\n");
    }
    ```
    - `while` loop (with vertain times)
        ```c
        int i = 1
        while (i <= 50)
        {
            printf("hello, world\n");
            i++;
        }
        ```
- `for` loop
    ```c
    for (int i = 1; i <= 50; i++)
    {
        printf("hello, world\n");
    }
    ```
- `do`-`while` loop
    ```c
    do
    {
        // Do first
    }
    while (/* condition */);
    ```
    - 先執行 `do`，再檢查是否需要進入迴圈。當達成 `while` 之條件，重新進入 `do`。

## Abstraction
- 自定義函數 `meow()`
    ```c
    #include <stdio.h>

    void meow(void) {
        printf("meow\n");
    }

    int main(void)
    {
        for (int i = 0; i < 3; i++)
        {
            meow();
        }
    }
    ```
- 讓使用者輸入次數
    ```c
    #include <cs50.h>
    #include <stdio.h>

    int get_positive_int(void);

    int main(void)
    {
        int i = get_positive_int();
        printf("%i\n", i);
    }

    // Prompt user for positive integer
    int get_positive_int(void)
    {
        int n;
        do
        {
            n = get_int("Positive Integer: ");
        }
        while (n < 1);
        return n;
    }
    ```

## Memory, Imprecision, and Overflow
- Example
    ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {
        float x = get_float("x: ");
        float y = get_float("y: ");

        printf("%.50f\n", x / y);
    }
    ```
- 輸出取小數後50位，x 輸入 1，y 輸入 10，取值結果可能為`0.10000000149011611938476562500000000000000000000000`。
- 此現象稱為 floating-point imprecision，沒有足夠的位元可以儲存後面的值，因此只能儲存一個概似值。

## Variable Scope
- 區域變數
    - 被呼叫的函數(此指callee)呼叫區域變數，其取得的是遞送值的「副本」，而非該值本身。
    - 呼叫函數的函數(caller)，其本身的值並不會改變。
- 全域變數
    - 宣告於 `main` function 之外。