# Compiling
---
## Clang
- 指令 `make` 實際上是呼叫 `clang` 指令，其會直接將目前的 `.c` 檔案編譯為同名稱的執行檔。
- `clang` 指令亦可達成 `make` 的效果。可加入更多「指令屬性」(Command-Line Arguments)來執行該指令。
    - Example
        ```
        clang -o hello hello.c
        ```
        - `-o` 指 output
        - 第二個屬性為輸出執行檔之名稱。
        - 第三個屬性為欲編譯的 `.c` 檔。
- 若要使用標準函式庫以外的函式庫，使用 `clang` 時需將其連結。
    - Example：連結 `cs50.h`
        ```
        clang -o hello hello.c -lcs50
        ```
        - `-l` 指 Link，其同時包含程式中需用到之函式的 machine code。
- 「編譯」包含：
    1. Preprocessing
        - 將程式內被 `#include` 的標頭檔文件取代至程式碼中。
    2. Compiling
        - 將原始程式碼轉換成「組合語言」(assembly code)。
        - 組合語言為一種低階程式語言，其更接近二進位的指令，使電腦處理器能夠更快速理解與處理。
    3. Assembling
        - 將組合語言轉換成二進制指令，又稱為 machine code，電腦CPU可以直接進行運算。
    4. Linking
        - 將先前連結的 `#include` 的函式庫轉為二進制指令並將其與主程式其他區塊連結與組合。
    >`make` 指令實際上包含以上四部分。

&nbsp;
&nbsp;

# Array
---
## Memory
- 電腦中短期快速存取的資料存於「記憶體」內。
- RAM, Random-Access Memory.
- RAM 的波動性很大，亦須供電才能運作並儲存資料。
- C語言中，不同資料型態佔用記憶體中的不同區塊大小。
    - `bool`：1 byte
    - `char`：1 byte
    - `int`：4 bytes
    - `float`：4 bytes
    - `double`：8 bytes
    - `long`：8 bytes
    - `string`：? bytes
    - ...
> 1個 byte 包含8個 bits。

> C語言實際上不具有 `string` 的資料型別，但可透過 `char` 的陣列來達成。

## Arrays
- 陣列(Array)是一種基礎的資料結構。
- 陣列本身不能被視為變數(variable)，無法透過 assignment operator 指派某陣列到另一陣列。也因此，其並非 passed by value，而是 passed by reference，callee 會直接取得被呼叫的陣列。
    - Wrong Example
        ```c
        int foo[5] = {1, 2, 3, 4, 5}
        int bar[5]

        // Illegal in C.
        bar = foo;
        ```
    - Correct Way
        ```c
        int foo[5] = {1, 2, 3, 4, 5}
        int bar[5]

        // Copy the contents in foo to bar.
        for (int i = 0; i < 5; i++)
        {
            bar[i] = foo[i];
        }
        ```
- 一個 array 可以被拆分為多個 elements，每個 element 可以儲存 datas，可以是各種型態的資料，並且可以被透過 index 的方式讀取。
- C語言並 __不會__ 阻止使用者抓取超過特定陣列範圍以外的資訊。(Segmentation Fault)
- 若要儲存三個變數，可透過宣告三個整數的方式。
    - Example
        ```c
        #include <stdio.h>

        int main(void)
        {
            int score1 = 72;
            int score2 = 73;
            int score3 = 33;

            printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
        }
        ```
    - 將 `3` 寫為 `3.0`，C語言集會將整個結果轉換為浮點數，避免運算過程截斷。
    - 記憶體將有共十二個 bytes 被調用，四個 byte 儲存一個整數。
- 實際上，可以直接透過「陣列」抓取連續的區間。
    - 中括號 `[ ]` 代表「陣列」，裡面放數需要的數量。
    - Example (個別宣告每一格的變數，總數不變)
        ```c
        #include <cs50.h>
        #include <stdio.h>

        int main(void)
        {
            int scores[3];
            scores[0] = get_int("Score: ");
            scores[1] = get_int("Score: ");
            scores[2] = get_int("Score: ");

            // Print average
            printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
        }
        ```
    - Example (透過迴圈來宣告陣列內變數，總數不變)
        ```c
        #include <cs50.h>
        #include <stdio.h>

        const int TOTAL = 3;

        int main(void)
        {
            int scores[TOTAL];
            for (int i = 0; i < TOTAL; i++)
            {
            scores[i] = get_int("Score: ");
            }

            printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / TOTAL);
        }
        ```
        -  `const` 會告知編譯器其為不可變的變數。
    - Example (透過迴圈與自訂函數來宣告陣列內變數，總數可變)
        ```c
        ...
        float average(int length, int array[])
        {
            int sum = 0;
            for (int i = 0; i < length; i++)
            {
                sum += array[i];
            }
            return sum / (float) length;
        }
        ...
        ```
        - 傳送「所需陣列大小」及「陣列」進入此函數。
        - 此函數將回傳平均值。

## Characters 
- 一個 character 實際上取用 1 byte (8 bits) 來儲存。
- 若將 `char` 型態之資料轉換成 `int`，可印出其 ASCII 代碼。(即查看該字元在記憶體中如何被儲存)
- Example
    ```c
    #include <stdio.h>

    int main(void)
    {
        char c = '#';
        printf("%i\n", (int) c);
    }
    ```

## Strings
- C語言其實上沒有 `stirng` 這個資料類別，而 `<string.h>` 所產生的字串型態其實就是 `char` 的陣列。
- 可以透過以 `int` 印出的形式查看一字串內的各個字母在記憶體中被儲存的形式。
- Example
    ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {
        string s = "HI!";
        printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
    }
    ```
    - `s[3]` 為 0，實際上為 NULL character，即 `\0`，代表該字串的結尾。
- 以char陣列的方式，將使用者輸入的字串印出：
- Example
    ```c
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>

    int main(void)
    {
        string s = get_string("Input: ");
        printf("Output:\n");
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            printf("%c\n", s[i]);
        }
    }
    ```
    - `strlen()` 包含在 `string.h` 內，用於計算字串長度。
    - 迴圈開始時，初始化 `i` 和 `n` 兩變數，迴圈執行條件為其陣列的 index 並未大於字串長度(即未超過字串範圍)。
- 字串的大小寫轉換，可以透過 `ctype.h` 函式庫達成。
- Example 
    ```c
    #include <cs50.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>

    int main(void)
    {
        string s = get_string("Before: ");
        printf("After:  ");
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            printf("%c", toupper(s[i]));
        }
        printf("\n");
    }
    ```

## Command-Line Arguments
- 以C語言完成之執行檔亦可以透過 Command-Line 的方式執行，即在主程式 `main` 中給定屬性即可。
- Example
    ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(int argc, string argv[])
    {
        if (argc == 2)
        {
            printf("hello, %s\n", argv[1]);
        }
        else
        {
            printf("hello, world\n");
        }
    }
    ```
    - `argc` 為「屬性計數器」，計算 command Line 中共有多少個 args，包含程式名稱本身。
    - `argv[1]` 代表 Command Line 中二個屬性，即輸入的程式名稱指令後第一個參數。
- 對於由字串組成的陣列，可以用兩組中括號取得其中一個字串的其中一個char。
    - 如：`argc[0][1]` 即陣列中第一個字串的第二個字母。

## Exit Code
```c
int main(void)
{

}
```
- `main` funciton 回傳值為正整數。若程式正常執行且結束，回傳 0。
- 可以自行定義發生錯誤時要回傳的錯誤值。
- Example
    ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(int argc, string argv[])
    {
        if (argc != 2)
        {
            printf("missing command-line argument\n");
            return 1;
        }
        printf("hello, %s\n", argv[1]);
        return 0;
    }
    ```
    - 如上範例，正常結束回傳`0`，若 command-Line 有缺失的屬性即回傳錯誤代碼`1`。

## Application: Cryptography
- 密碼學上，可以透過不同字母對應不同 ASCII Code 的特性來平移以進行訊息加密。
- Example：原始文本(__plaintext__)`I LOVE YOU` 透過平移一單位，可加密成加密訊息(__ciphertext__)`J MPWF ZPV`。
- 加密者將加密訊息傳送給接收端時，尚須傳送「鑰匙」(Key)，以上例來說鑰匙即`1`，解密時只需將加密訊息往反向平移1單位即可解密。