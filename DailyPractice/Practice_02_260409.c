#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//绘制拜伦状态的蓝图
typedef struct {
    int melancholy_index;   //忧郁指数，占一点空间
    int inspiration_level;  //灵感水位，占一点空间
    char *inner_monologue;  //内心独白，这是一个指针，只占很小一块地，但指向巨大的另一块地
} ByronCoreState;

int main() {
    //1.为整个核心架构申请一块地
    ByronCoreState *simulator_engine = NULL;

    //拿出卷尺sizeof(ByromCoreState)，精准测量这个包含了两个整数和一个指针的蓝图总共需要多大面积
    simulator_engine = (ByronCoreState*)malloc(sizeof(ByronCoreState)); //这一行为什么这样写，尤其是*号，不懂。如何读指针，中心法则是吗

    if (simulator_engine == NULL) {
        printf("核心引擎部署失败，内存空间不允许他的降临。\n");
        return 1;
    }

    //2.初始化实体参数。注意，因为simulator_engine是指针，所以必须用->来穿透并访问它内部的房间
    simulator_engine->melancholy_index = 95;
    simulator_engine->inspiration_level = 100;


    //3.嵌套圈地（最容易出错的地方）
    //注意：上面那一步malloc只为inner_monologue这个指针本身分配了存放坐标的空间
    //它现在指向虚无。我们必须再单独为它指向的“独白内容”申请一块足够大的地。
    simulator_engine->inner_monologue = (char*)malloc(500 * sizeof(char));

    if (simulator_engine->inner_monologue != NULL) {
        strcpy(simulator_engine->inner_monologue, "There is a pleasure in the pathless woods, There is a rapture on the lonely shore...");
        printf("引擎运转中。忧郁指数：%d\n当前独白：%s\n", simulator_engine->melancholy_index, simulator_engine->inner_monologue);
    }

    //4.拆迁的艺术：从内向外拆除
    //就像拆一座别墅，不能先把承重墙（结构体本身）拆了，那里面的家具（内部指针指向的内存）就被彻底掩埋，再也找不到了（导致内存泄漏）
    //第一步：先拆软装，释放内部指针指向的土地
    free(simulator_engine->inner_monologue);
    //第二步：拆除主体承重墙， 释放结构体本身的土地
    free(simulator_engine);
    //第三部：销毁总地契
    simulator_engine = NULL;

    return 0;
}

//
// Created by Madeleine on 2026/4/9.
//
