# Python

## Python Basics 基礎
- Unlike C, Python is __not a compiled language__.

### Print 文字輸出
- Python 程式碼相對於 C 更簡潔明瞭。
- 基本輸出字串：
    ```py
    print("hello, world")
    ```
- 取得使用者輸入之字串，並使用 `+` 相連輸出：
    ```py
    answer = input("What's your name? ")
    print("hello, " + answer)
    ```
    - CS50 亦有提供相關的 library。
        ```py
        from cs50 import get_string

        answer = get_string("What's your name? ")
        print("hello, " + answer)
        ```
- 使用「格式化輸出 (format string)」：
    ```py
    answer = input("What's your name? ")
    print(f"hello, {answer}")
    ```
    - 在 `print()` 函式內先輸入 `f` 表示格式化輸出，即可在引號內以大括號 `{}` 表示變數。

### Condition 條件判斷
- 使用 `if`, `elif`, `else`：
    ```py
    if x < y:
        print("x is less than y")
    elif x > y:
        print("x is greater than y")
    else:
        print("x is equal to y")
    ```
    - 不同於 C，條件敘述不需要 `{}` 及 `()`。
    - Python 的 `elif` 即 C 的 `else if`。

### Loop 迴圈
- While loop
    ```py
    while True:
        print("hello, world")
    ```
    ```py
    i = 0
    while i < 3:
        print("hello, world")
- For loop
    ```py
    for i in [0, 1, 2]:
        print("hello, world")
    ```
    ```py
    for i in range(3):
        print("hwllo, world")

### Data Types 資料類別
- 資料類別
    - `bool`, `True` or `False`.
    - `float`, floating real numbers.
    - `int`, integers.
    - `str`, strings.
    - `range`, sequence of numbers.
    - `list`, sequence of mutable values, or values we can change.
        - 類似於 C 的 array，但 Python 的 list 可自動擴張或縮減。
    - `tuple`, collection of ordered values like x- and y-coordinates, or longitude and latitude.
    - `dict`, dictionaries, collection of key/value pairs, like a hash table.
    - `set`, collection of unique values, or values without duplicates.
- 強弱型別
    - C 屬於 __強型別語言 (Strongly typed language)__，宣告變數同時需手動宣告其資料類別。
    - Python 屬於 __弱型別語言 (Loosely typed language)__，宣告變數時直接給定內容即可，不需宣告型別，直譯器會自動判別。

### Loop for Dictionary 字典迴圈
```py
pizzas = {
    "cheese": 9,
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12
}
```
> 注意：Dictinoary 資料迴圈可能不會照順序。
- 印出 __key__
    ```py
    for pie in pizzas:
        print(pie)
    ```
- 印出 __value__
    ```py
    for pie, price in pizzas.items():
        print(price)
    ```
    - 需透過 `items()` 將 value 轉換成 list
- 印出 __key 和 value__
    ```py
    for pie, price in pizzas.items():
        prinf("A whole {} pizza costs ${}".format(pie, price))

## Examples 範例

### Blur Images 圖片模糊
```py
from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.BoxBlur(10))
after.save("out.bmp")
```
- 導入 `PIL` 套件，透過該套件的 `BoxBlur` 來模糊圖片。
- `BoxBlur()` 內的參數為盒狀模糊的範圍參數。每一像素為上、下、左、右特定範圍的 RGB 值平均。

### Problem Set - Speller 拼字檢查字典
- 題目需參考：Week 5 Problem Set - Speller
```py
words = set()

def load(dictionary):
  file = open(dictionary, "r")
  for line in file:
      words.add(line.rstrip())
  file.close()
  return True

def check(word):
    if word.lower() in words:
        return True
    else:
        return False

def size():
    return len(words)

def unload():
    return True
```
- `set` 是一個內容不重複的集合。
- `.rstrip()` 會將右側的非一般字元 (如：`\n`) 去除。
- 不同於 C，`unload()` 函數實際上在 Python 中不需要，記憶體配置與釋放會自動完成。

### Input, Operations, and Conditions 輸入、運算與條件
- Truncation
    ```py
    x = int(input("x: "))
    y = int(input("y: "))
    print(x / y)
    ```
    - 其印出結果會是小數。C 的截斷問題 Python 沒有。

### Strings Comparism 字串比較
```py
from cs50 import get_string

s = get_string("Do you agree? ")

if s.lower() in ["y", "yes"]:
    print("Agreed.")
elif s.lower() in ["n", "no"]:
    print("Not agreed.")
```

### Defining Function 自定義函數
```py
def main():
    meow(3)

def meow(n):
    for i in range(n):
        print("meow")

main()
```
- 我們也可以用 `def main()` 來做到類似於 C 的 main function，但 Python 通常不這樣寫。(it's not "pythonic".)

### Overflow and Imprecision 過載與不精確問題
- Overflow
    ```py
    i = 1
    while True:
        print(i)
        i *= 2
    ```
    - 此迴圈持續運算，但不會如 C 有超出範圍的問題。Python 會自動調整記憶體空間配置，但 C 的整數原則上僅限 4 bytes (32 bits)。
- Imprecision
    - 小數點運算的不精確問題依然存在。

### Command-Line Arguments 命令列屬性
```py
from sys import argv

if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")
```
- 使用前須先從 `sys` 系統套件導入 `argv`。
- 如同 C 語言的使用方式，`argv[0]` 為程式本身名稱。

### Exit Code 退出狀態
```py
import sys

if len(sys.argv) != 2:
    print("missing command-line argument")
    sys.exit(1)
else:
    print(f"hello, {sys.argv[1]}")
    sys.exit(0)
```

### Algorithms 演算法
- List
    ```py
    import sys

    numbers = [4, 6, 8, 2, 7, 5, 0]

    if 0 in numbers:
        print("Found")
        sys.exit(0)
    else:
        print("Not found")
        sys.exit(1)
    ```
    - 在 `list` 中 Python 會使用線性搜尋。
- Dictionary
    ```py
    from cs50 import get_string

    people = {
        "Brian": "+1-617-495-1000",
        "David": "+1-949-468-2750"
    }

    name = input("Name: ")
    if name in people:
        print(f"Number: {people[name]}")
    ```
    - 在 `dict` 和 `set` 中 Python 通常會使用類似於 hash table 的結構來儲存並進行搜尋，以取得接近 constant time 的搜尋時間。

### Swap 交換
```py
x = 1
y = 2

print(f"x is {x}, y is {y}")
x, y = y, x
print(f"x is {x}, y is {y}")
```
- 直接以 `x, y = y, x` 即可，不需要煩惱記憶體配置與指標問題。

## Files 檔案

### CSV Files 逗點分隔值檔案
- 可以導入 `csv` 套件來處理 CSV 檔案。
    ```py
    import csv

    file = open("phonebook.csv", "a")

    name = input("Name: ")
    number = input("Number: ")

    writer = csv.writer(file)
    writer.writerow([name, number])

    file.close()
    ```
    - 呼叫 `csv.writer()` 建立寫入器。
    - 呼叫 `writer.writerow()` 將 list 逐列寫入 CSV 檔案內。
- 可以使用 `with` 來自動關閉完成寫入的檔案。
    ```py
    with open("phonebook.csv", "a") as file:
        writer = csv.writer(file)
        writer.writerow((name, number))
    ```
- 可以透過讀取 CSV 檔案的方式，統計各個項目或值出現的次數。
    ```py
    import csv

    houses = {
        "Gryffindor": 0,
        "Hufflepuff": 0,
        "Ravenclaw": 0,
        "Slytherin": 0
    }

    with open("Sorting Hat (Responses) - Form Responses 1.csv", "r") as file:
        reader = csv.reader(file)
        next(reader)
        for row in reader:
            house = row[1]
            houses[house] += 1

    for house in houses:
        print(f"{house}: {houses[house]}")
    ```
    - 呼叫 `csv.reader()` 建立讀取器。
    - `next(reader)` 意指請求讀取器忽略第一列。(第一列通常為欄位名稱)
    - 最後逐項印出各項的次數值。

## Demonstrate - More Libraries 更多套件示範

### Speech 演講
```py
import pyttsx3

name = input("What's your name? ")
engine = pyttsx3.init()
engine.say(f"hello, {name}")
engine.runAndWait()
```

### Face Recognition 臉部辨識
```py
# Find faces in picture
# https://github.com/ageitgey/face_recognition/blob/master/examples/find_faces_in_picture.py

from PIL import Image
import face_recognition

# Load the jpg file into a numpy array
image = face_recognition.load_image_file("office.jpg")

# Find all the faces in the image using the default HOG-based model.
# This method is fairly accurate, but not as accurate as the CNN model and not GPU accelerated.
# See also: find_faces_in_picture_cnn.py
face_locations = face_recognition.face_locations(image)

for face_location in face_locations:

    # Print the location of each face in this image
    top, right, bottom, left = face_location

    # You can access the actual face itself like this:
    face_image = image[top:bottom, left:right]
    pil_image = Image.fromarray(face_image)
    pil_image.show()
```

### QR Code 二維條碼
- 為一網址建立 QR Code。
```py
import os
import qrcode

img = qrcode.make("https://youtu.be/oHg5SJYRHA0")
img.save("qr.png", "PNG")
os.system("open qr.png")
```

### Audio Input Recognition 音訊輸入辨識
- 透過 Python 啟用麥克風，並辨識使用者語音輸入。
- 可以將使用者所說的話印出，並根據關鍵字給予相對應回應。
```py
import speech_recognition

# Obtain audio from the microphone
recognizer = speech_recognition.Recognizer()
with speech_recognition.Microphone() as source:
    print("Say something:")
    audio = recognizer.listen(source)

# Recognize speech using Google Speech Recognition
print("You said:")
print(recognizer.recognize_google(audio))

words = recognizer.recognize_google(audio)

# Respond to speech
if "hello" in words:
    print("Hello to you too!")
elif "how are you" in words:
    print("I am well, thanks!")
elif "goodbye" in words:
    print("Goodbye to you too!")
else:
    print("Huh?")
```