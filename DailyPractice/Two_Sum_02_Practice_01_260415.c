#include<stdlib.h>
#include"uthash.h"
//int* nums: 一个整型指针，指向传入的连续内存块（即数组）
//numsSize: 记录数组的长度，因为在底层语言中，数组退化为指针后丢失长度信息，必须显式传递
//target：需要凑齐的目标和
//returnSize：这是一个极其关键的输出参数，由于C语言的函数不能直接返回数组的长度，需要通过解引用这个指针，把最终返回的数组大小写入调用者的内存上下文中

//数据结构与初始化：
//struct hashTable{
    //int key;
    //int value;
    //UT_hash_handle hh;
//}*hashTable = NULL, *item, *tmpItem;
//这几行是代码的基石，定义了一个匿名的结构体，并立即声明了三个指向该结构体的指针
//key：在这个特殊逻辑中，这里存储的不是遍历到的数组元素，而是target-nums[i]，也就是期待未来能够遇到的互补数字
//value: 储存产生上述期待的那个原始数字的索引位置
//UT_hash_handle hh: 这是侵入式哈希表（通常源于uthash.h这个宏库）的灵魂，它是一个隐藏在结构体内部的句柄，用于在底层维护哈希桶、双向链表以及处理哈希碰撞。它让这个普通结构体瞬间拥有了成为哈希表节点的能力
//*hashTable=NULL：这部仅仅是良好的编程习惯，更是该哈希库的强制要求，将头指针初始化为NULL，底层宏才知道这是一个全新的、空的哈希表
//*item和*tmpItem：作为后续查询、添加和遍历哈希表时使用的临时操作指针

//核心遍历与检索逻辑
//for(int i=0; i<numsSize; i++){ /*启动一个标准的线性遍历。因为有哈希表的加持，期望在O(N)的时间复杂度内解决整个问题*/
//HASH_FIND_INT(hashTable, &nums[i], item); /*这里调用了查找宏。它的底层逻辑是：拿到当前遍历到的数字nums[i]，计算它的哈希值，然后去hashTable中寻找。注意这里的传参是&nums[i]，传递的是地址，这是宏展开时的硬性要求，查找的结果将被赋值给之前声明的指针item。如果没找到，item会被设为NULL*/
//if(item){ /*核心判断分支。如果item不是NULL，意味着你在当前的数组元素中，找到了之前某个元素所“期待”的那个数字。匹配成功，游戏结束。*/

//命中与内存安全清理
//int* result=malloc(sizeof(int)*2) /*既然匹配成功，你需要向调用方返回结果。这里你在堆区申请了一块大小为两个int的内存，用于存放找到的两个索引*/
//result[0]=item->value;
//result[1]=i;
//*returnSize=2;    /*将哈希表中记录的旧索引赋给结果数组的第一个位置，将当前匹配成功的索引i赋给第二个位置。随后，解引用returnSize指针，将其赋值为2，明确告知调用方返回数组的有效长度*/
//
//HASH_ITER(hh, hashTable, item, tmpItem){
    //HASH_DEL(hashTable, item);
    //free(item);
//}     /*这一段代码体现了对内存操作的敬畏。在遇到符合条件的答案并准备提前return之前，没有丢下烂摊子不管。使用了迭代宏遍历整个哈希表。HASH_DEL负责切断底层数据结构的链表指针，将其从哈希表中摘除，而free(item)则负责将之前通过malloc分配在堆上的结构体内存交还给操作系统。如果在函数返回前不执行这两步，一旦函数栈帧销毁，hashTable指针丢失，堆区里的这些节点就变成了永远无法回收的内存垃圾，从而导致内存泄漏。*/
//
//return result;    /*带着分配好并填满数据的数组指针，干净利落地退出函数。*/
//} /*关闭命中分支的括号*/

//未命中与哈希表填充
//item=malloc(sizeof(struct hashTable));    /*如果前面的if(item)判断为假（即当前的数字并不是任何已有数字期待的互补数），程序会走到这里 。必须把当前的数字的“期望”记录下来，以备后续数字查询。这里再次向系统申请一块内存，用来实例化一个新的哈希节点*/
//item->key=target-nums[i];  /*这行是算法设计的点睛之笔。算出了当前数字与目标和之间的差值，并将其作为检索的键（Key）存起来*/
//item->value=i;    /*把当前数字的索引存为值（Value），等待未来的有缘人来提取*/
//HASH_ADD_INT(hashTable, key, item);   /*调用添加宏，将刚刚组装好的item节点塞进哈希表当中。这里的key参数是在告诉底层的宏：去结构体里找那个名为key的成员变量，用它来计算哈希值。*/
//} /*关闭for循环的括号*/

//兜底处理与资源回收
//HASH_ITER(hh, hashTable, item, tmpItem){
    //HASH_DEL(hashTable, item);
    //free(item);
//} /*如果代码运行到了这里，说明整个for循环都已经跑完，依然没有找到任何一对符合条件的数字。同理，在宣告失败之前，必须做一次全盘的内存大扫除，销毁整个哈表，防止内存泄漏。*/
//
//*returnSize=0;    /*严谨地将返回值长度置为0，防止调用端发生越界读取*/
//
// //If no valid pair is found, return an empty array
//return malloc(sizeof(int)*0); /*这最后一行很有意思，在C语言的标准规范里，传入0给malloc的行为是“实现定义的(Implementation-defined)”。在绝大多数现代编译器和系统平台中，它要么返回一个NULL指针，要么返回一个能够被安全free掉的有效但不可解引用的特殊指针。虽然返回NULL在这里会显得更直观和符合常规语义，但这种写法在语法上是成立的，也能让调用者统一使用free来处理返回的指针而不会引发崩溃*/

//1.内存的地契：结构体与堆空间
//（1）结构体的物理真相：在C语言中，结构体并不是一个对象，它只是对一块连续内存空间的逻辑划分。当定义这个结构体时，只是在告诉编译器“如果我申请了这样一块地，前4个字节存key，紧接着的4个字节存value，剩下的部分交给哈希句柄（这是一个复杂的内部结构，占用几十个字节）。”
//（2）堆与栈：
//栈：像int i这种变量是存在栈里的，函数运行完，内存自动回收。
//堆：像malloc申请的内存。如果不调用free主动退还，即使函数执行结束，这块地依然被占用。
//为什么哈希表必须用堆内存？因为哈希表的生命周期往往比某个循环更长，如果在循环里用栈变量，循环一结束，数据就灰飞烟灭。所以必须用item=malloc(sizeof(struct hashTable));手动去堆区申请内存，并拿到一个指向这块地的地址（指针item）。

//2.哈希表的本质：“空间换时间”的契约。哈希表的查找速度是O(1)
//（1）寻址
//计算机内存本质上是一个巨大的数组，如果知道某个数据的具体地址，CPU拿取它的时间是恒定的。通过一个数学函数（Hash Function）把数字直接转换成一个内存偏移量，直接去地址取数字就行。
//（2）UT_hash_handle黑盒
//UT_hash_handle hh极其关键，这是这个开源库uthash的核心。C语言本身并不支持哈希表，这个hh就像是一个“钩子”，当调用HASH_ADD_INT时，宏会顺着这个钩子，在内存节点之间建立复杂的链接关系（通常是双向链表和哈希桶）。简单来说，结构体本身只存数据，而hh负责管理数据之间的组织关系，比如处理“哈希碰撞”（即两个不同的键算出了同一个位置）。


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable {
        int key;
        int value;
        UT_hash_handle hh;
    } *hashTable = NULL, *item, *tmpItem;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;
            HASH_ITER(hh, hashTable, item, tmpItem) {
                HASH_DEL(hashTable, item);
                free(item);
            }
            return result;
        }
        item = malloc(sizeof(struct hashTable));
        item->key = target - nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }
    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }
    *returnSize = 0;
    //If no valid pair is found, return an empty array
    return malloc(sizeof(int) * 0);
}


//
// Created by Madeleine on 2026/4/15.
//
