#include <stdio.h>
#include <stdlib.h> //涉及向系统malloc和free，带上这个工具箱

int main() {
    //1.准备第契，需要指针来记住地的确切坐标
    //在这块地批下来之前，它什么也不指，或者指向乱码，这很危险
    char *verse_buffer = NULL;

    //2.正式向系统提交圈地申请
    //假设这句诗最长有120个字符
    //sizeof(char)是卷尺，确保量出的每一个单位都是标准的字符大小
    //malloc(120 * sizeof(char))的意思是：划一块能容纳120个标准字符的连片土地
    //(char *)是在告诉系统，这块地，要定义为专门存放字符的区域
    verse_buffer = (char *)malloc(120 * sizeof(char));

    //3.极其重要的安检：系统不是每次都会同意申请（比如内存耗尽）
    //如果申请失败，系统会塞过来一个NULL，必须检查
    if (verse_buffer == NULL) {
        printf("系统拒绝内存分配，拜伦的灵魂无处安放。\n");
        return 1;
    }

    //4.圈地成功，开始刻下文字
    sprintf(verse_buffer, "She walks in beauty, like the night / Of cloudless climes and starry skies");
    printf("拜伦的吟唱：%s\n", verse_buffer);

    //5.铁律：尘归尘，土归土
    //当这句诗输出完毕，这块地的使命就结束了。必须摧毁它，必须还给系统。
    free(verse_buffer);

    //6.抹除痕迹：地虽然还了，但地契（指针）上还残留着那个坐标
    //为了防止以后不小心又拿着旧坐标去访问已经不属于自己的地（这叫悬空指针，会引发灾难）
    //必须把地契彻底烧毁，把指针指向NULL
    verse_buffer = NULL;

    return 0;
}


//
// Created by Madeleine on 2026/4/9.
//
