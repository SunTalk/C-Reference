### 題目說明

* 每次給一個人一疊積木，若是給的人已經有一疊以上，他會有多疊的積木
* 給完之後要找出誰的積木中有一段是一個固定順序的積木，有幾個

## Input Format
* 一開始有一個數字N告知要給幾次積木
* 接著有N行
* 每行為 `人名` `積木`
    * 一串string表一疊積木
    * 一個大寫英文字元表示一個積木
* 最後有一行string表想找出的積木順序為何

## Output Format

* 總共有M行
* 每行為 `人名` `Y/N` `Number`
    * 根據 Number進行排序 再根據人名進行排序
    * 如果是 `N` 直接輸出 `\n` 

## Sample Input
```
9
SunTalk EEFIKLD
ICEJJ HSVADOH
Roy NSAUIHERA
HalloWorld IHUADKJ
Chess KJVAOI
Roy KJLBAIQOI
Bobo QWPB
ICEJJ PAVLSDOIH
CashLu OSBHQDF
O

```
## Sample Output
```
ICEJJ Y 2
CashLu Y 1
Chess Y 1
Roy Y 1
Bobo N
HalloWorld N
SunTalk N

```
### generate N
* 可產生一開始數字為N的測資(Input)
