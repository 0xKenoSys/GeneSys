//Two sum
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.

//You can return the answer in any order.

//Example 1:

//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

//two for-loops
//提问：咋映射过去呢？indices的中括号里的内容，和指针的偏移量如何建立映射？
//Created by Madeleine on 2026/3/24.

#include<stdio.h>
#include <stdlib.h>

/*int* nums：传入的整型数组，数组作为参数传递时，会自动退化为指针，指向数组的第一个元素。因此我们在函数内部无法直接通过sizeof算出数组的整体长度。*/
/*int numsSize: 正是因为上面的指针退化现象，调用者必须显式地把数组的长度传进来，告诉我们这个数组里到底有多少个元素，防止我们越界访问*/
/*int target: 这是我们要寻找的目标和*/
/*int* returnSize: 这是一个关键的输出参数（Out Parameter），C语言的函数只能有一个返回值，我们已经用它来返回数组的首地址了，但调用方（也就是Leetcode的判题系统）还需要知道你返回的这个数组到底有多长。所以，调用方传递了一个变量的地址进来，我们需要在函数内部通过解引用，把实际的返回长度（找到答案就是2，没找到就是0）写进这个地址里去*/
//if (nums[j] == target - nums[i]): x = target - current 要去找的元素应该是目标减去现在指向的元素
    int* twoSum(int* nums,int numsSize, int target, int* returnSize) {
        for (int i = 0; i < numsSize; i++) {    //这是最外层的循环。变量i代表当前考察的第一个数字的索引。我们从数组的最开头，也就是索引0开始，一直遍历到数组的末尾。只要i还没有到达numsSize，循环就会继续。这个外层循环的作用是“固定”一个基准元素
            for (int j = i + 1; j < numsSize; j++) {    //这是内层循环。注意看它的初始化条件：int j = i + 1。这非常重要。为什么不从0开始？因为题目通常要求不能重复使用同一个元素，如果我们从0开始，当i和j相等时，我们就会错误地把同一个数字加了两次。为什么是i + 1？因为i之前的元素已经在之前的一轮外层循环中和所有其他元素匹配过了，如果我们从头开始匹配，就是在做无用功。这里的设计保证了我们只遍历所有可能的“组合”，而不是“排列”，极大地减少了不必要的计算
                if (nums[j] == target - nums[i]) {  //这是逻辑判断的核心。我们在检查当前的两个元素之和是否等于目标值。注意它的写法，它并没有写成nums[i]+nums[j]==target，而是将加法移项变成了减法。虽然在普通的刷题场景下，两者等效，但在严谨的工程实践中，两个较大的整数相加可能会触发整数溢出（integer overflow），导致程序崩溃或出现逻辑错误。而用目标值减去其中一个数再去比较，则规避了这种潜在的风险。
                    int* result = malloc(sizeof(int) * 2);  //这一是整段代码最能体现底层内存管理机制的地方。当我们找到了符合条件的两个索引时，我们需要把它们装进一个数组里返回，但是我们绝对不能写成int result[2]。为什么？因为如果只声明一个普通的局部数组，它会被分配在系统的“栈区”。当这个函数执行到最后的return并结束时，它所在的栈帧会被立刻销毁，局部数组的内存也会被系统回收。如果你把指向这块被回收内存的指针返回给了调用方，调用方拿到的就是一个“悬垂指针（Dangling Pointer）”，去访问它会导致未定义行为。
                                                                //为了解决这个问题，我们必须使用malloc函数向系统申请分配在“堆区”的内存。堆内存的生命周期是手动的，只要我们不主动调用free去释放它，它就会一直存在，这样调用方就能安全地读取里面的数据了。sizeof(int)会计算出当前系统架构下一个整型占据的字节数，乘以2就是我们需要容纳两个索引的总字节数。
                                                                //我觉得这个堆和栈的问题很关键，我对函数这个东西的使用理解还不深，稍后去查
                    result[0] = i;  //内存分配成功后，我们拿到了指向这块堆内存首地址的指针result。底层语言允许我们将指针作为数组名来使用，这叫作指针算术的语法糖。我们将外层循环的当前索引i存入第一个位置，将内层循环的当前索引j存入第二个位置。这就是我们最终要交付的答案。
                    result[1] = j;
                    *returnSize = 2;    //使用第一行的int* returnSize。因为调用方需要知道我们返回的数组有几个元素，所以我们对这个指针进行解引用（加上星号*），将数值2直接写入调用方提供的内存地址中。这样，即使函数结束，调用方也能准确知道它该读取几个数据。
                    return result;      //找到了答案，分配了内存，填好了数据，也告诉了调用方长度。接下来就是干净利落地把指向答案堆内存的指针返回，同时结束整个函数的执行流程。
                }
            }
        }   //这三个反括号分别闭合了if判断、内层循环和外层循环的代码块。它们界定了变量的作用域，并控制着程序的执行流向。

        //Return an empty array if no solution is found
        *returnSize = 0;    //代码执行到这里，意味着上面的双重循环全部跑完，却依然没有触发那个return result;。说明在这个数组中，根本不存在两个数字的和等于target。这是一个边缘情况(edge case)。按照约定，如果没有找到解，我们需要告诉调用方返回的数组长度是0.所以我们再次解引用，将0赋值进去。
        return malloc(sizeof(int) * 0); //这是函数的最后一步。既然没有找到解，我们要返回一个空数组。这里它使用了malloc(sizeof(int)*0)，这种写法其实有些取巧，在标准规定中，分配零字节内存的行为是依赖于具体实现的，它可能会返回一个空指针NULL，也可能返回一个唯一的、合法的但不允许访问的指针。
                                            //Leetcode的判题后端在某些测试用例中，需要拿到一个合法的非空指针来进行内部处理，所以这里选择分配并返回一个大小为0的堆内存指针。在实际的工程开发中，如果没有找到结果，通常直接返回NULL会是更明确、更不易出错的做法。
    }   //这段代码的时间复杂度是O(N^2)，因为有两层嵌套循环，当数组极度庞大时，它的运行效率会呈现指数级下降。空间复杂度是O(1)，因为我们除了分配最后返回结果所需的常数级别内存以外，没有使用任何额外的数据结构。
        //早点把哈希表O(N)的优化版写出来
int main() {
        int nums[] = {2, 7, 11, 15};
        int target = 9;
        int returnSize;

        int* result = twoSum(nums, 4, target, &returnSize); //全是变量名

        if (returnSize == 2) {
            printf("Indices: %d, %d\n", result[0], result[1]);
        }else {
            printf("No solution found.\n");
        }

        free(result);
        return 0;
    }














//
// Created by Madeleine on 2026/4/13.
//
