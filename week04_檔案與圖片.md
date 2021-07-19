# Files and Graphics
- With the ability to use pointers, we can also open or write a file, and understand the graphics in computer.

## Files 檔案讀寫
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);
}
```
- `fopen()`：打開檔案，並回傳新的資料型態`FILE`，以供讀取、寫入等。
    - 第一個 argument 為檔案名稱，含副檔名。
    - 第二個 argument 為開啟檔案的模式，`w`為寫入(覆寫)、`r`為讀取、`a`為新增(加入檔案末端)。
- `fprintf()`：將內容寫入 file。
- `fclose()`：關閉檔案。
- `fgetc()`：取得文件的下一個字符。通常為文件的第一個字。(文件指標下一個字為文件內首個字。) __(注意：文件必須以閱讀模式 r 打開)__
    ```c
    FILE *ptr = fopen("file.txt", "r");
    char ch;
    while ((ch = fgetc(ptr)) != EOF)
    {
        printf("%c", ch);
    }
    ```
    - This function actually read and print all the contents in the file.
    - `EOF` means "End Of File" character.
- `fputc()`：寫入單一字元到該檔案。 __(注意：文件必須以寫入模式 w 或新增模式 a 打開)__
    ```c
    FILE *ptr = fopen("file.txt", "r");
    fputc('A', ptr);
    ```
- `fread()`：__(注意：文件必須以閱讀模式 r 打開)__
    ```c
    fread(<buffer>, <size>, <qty>, <file pointer>);
    ```
    - Read `<qty>` units of size `<size>` from the file pointed to and store them in memory in a buffer (usually an array) pointed to by `<buffer>`
    ```c
    int *arr = malloc(sizeof(int) * 10);
    fread(arr, sizeof(int), 10, ptr);
    ```
    - 讀取文件中40個 bytes 並將其儲存於 `arr`。
- `fwrite()`：__(注意：文件必須以寫入模式 w 或新增模式 a 打開)__
    ```c
    fwrite(<buffer>, <size>, <qty>, <file pointer>);
    ```
    - Write `<qty>` units of size `<size>` from the file pointed to by reading them from a buffer (usually an array) pointed to by `<buffer>`
    ```c
    double *arr = malloc(sizeof(double) * 80);
    fwrite(arr, sizeof(double), 80, ptr);
    ```
    - 取得 `arr` 內的資訊並將其寫入檔案內。


## Graphics 圖片檔
- 由於每張圖片所用的 bits 數固定，因此資訊量有限，圖片的放大是有其極限的。
- 開啟 JPEG 圖檔：
    ```c
    #include <stdint.h>
    #include <stdio.h>

    typedef uint8_t BYTE;

    int main(int argc, char *argv[])
    {
        // Check usage
        if (argc != 2)
        {
            return 1;
        }

        // Open file
        FILE *file = fopen(argv[1], "r");
        if (!file)
        {
            return 1;
        }

        // Read first three bytes
        BYTE bytes[3];
        fread(bytes, sizeof(BYTE), 3, file);

        // Check first three bytes
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
        {
            printf("Maybe\n");
        }
        else
        {
            printf("No\n");
        }

        // Close file
        fclose(file);
    }
    ```
    - 為使 C 語言更容易讀取 byte，透過 `typedef` 定義 `BYTE` 為 8 bits。
    - 透過 `fopen()` 嘗試打開檔案。
    - JPEG檔前三個 bytes 固定為 `0xff`、`0xd8`、`0xff`，若前三個位元組為此，則「可能」為JPEG檔。否則，該檔案不可能為JPEG檔。
- 複製JPEG檔：
    ```c
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>

    typedef uint8_t BYTE;

    int main(int argc, char *argv[])
    {
        // Ensure proper usage
        if (argc != 3)
        {
            fprintf(stderr, "Usage: copy SOURCE DESTINATION\n");
            return 1;
        }

        // open input file
        FILE *source = fopen(argv[1], "r");
        if (source == NULL)
        {
            printf("Could not open %s.\n", argv[1]);
            return 1;
        }

        // Open output file
        FILE *destination = fopen(argv[2], "w");
        if (destination == NULL)
        {
            fclose(source);
            printf("Could not create %s.\n", argv[2]);
            return 1;
        }

        // Copy source to destination, one BYTE at a time
        BYTE buffer;
        while (fread(&buffer, sizeof(BYTE), 1, source))
        {
            fwrite(&buffer, sizeof(BYTE), 1, destination);
        }

        // Close files
        fclose(source);
        fclose(destination);
        return 0;
    }
    ```
    - 透過 `while` 迴圈，將 `fread()` 所讀取到原始檔的每一個位元組都複製下來並透過 `fwirte()` 寫入新檔案中。
- 除複製圖片外，亦可以透過 pointers 對於每一個 bytes 的操作來進行圖片模糊化、改變色調等等。