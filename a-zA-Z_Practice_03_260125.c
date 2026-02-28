#include<stdio.h>
int main() {
    char str1[30];
    char str2[30];

    scanf("%[abcd]",str1);//只读取abcd字母
    scanf("%*[^\n]");scanf("%*c");//清空缓冲区
    scanf("%[a-zA-Z]",str2);//%[a-zA-Z]只读取小写和大写的英文字母 断句是：a to z and A to Z
    printf("str1:%s\nstr2:%s",str1,str2);

    return 0;
}


//为什么加个-就能表示中间所有的字？因为在计算机眼里，字母都是数字（ASCII码），a-z就是告诉计算机读取编号97到122之间的所有字符
// 这个-连字符只有加在两个字符中间时，才表示范围。如果要scanf读取一个真正的横杠符号，必须把-放在最前面或者最后面，比如%[a-z-]：读取小写字母 或者 横杠
// 这比普通的%s强大，因为%s读到空格就停下，而这样写就可以读进空格：%[a-zA-Z ]（注意里面有个空格）遇到标点或者数字才停。
// Created by Madeleine on 2026/1/25.
//