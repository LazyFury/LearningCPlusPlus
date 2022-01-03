// TrbleX.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TrbleX.h"


bool PlayGameWidtDifficulty(int Diffculty) {
    //difficutly not use
    std::cout << std::endl << "#已进入第 " << Diffculty << " 道安全门" << std::endl;
    //int number
    int CodeA = rand() % 10 + 2 * Diffculty;
    int CodeB = rand() % 10 + 2 * Diffculty;
    int CodeC = rand() % 10 + 2 * Diffculty;

    //calc sum product
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //tips
    std::cout << "现在有三个数字:" << std::endl;
    std::cout << "其和：" << CodeSum << std::endl;
    std::cout << "其积：" << CodeProduct << std::endl;
    //std::cout << CodeA << "," << CodeB << "," << CodeC << std::endl;

    //guess
    int GuessSum = 0;
    int GuessProduct = 0;
    std::cout << "请输入:";

    int GuessA,GuessB,GuessC;
    //get Input
    std::cin >> GuessA  >> GuessB  >> GuessC;

    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    //判断正负
    bool IsCorrect = (GuessSum == CodeSum && GuessProduct == CodeProduct);
    std::cout << "U Are " << (IsCorrect ? "Win" : "Fail") << std::endl;


    return  IsCorrect;
}


void PrintIntor()
{
    std::cout << "Hello World!\n";
    std::cout << "输入正确的三个数字代码骇入\n";
}

void PlayGame()
{
    int Difficulty = 1;
    int MaxDiffiCulty = 10;
    while (Difficulty < MaxDiffiCulty) {
        bool LevelComplete = PlayGameWidtDifficulty(Difficulty);

        std::cin.clear();
        std::cin.ignore();
        if (LevelComplete)Difficulty++;
    }

    std::cout << "已骇入.";
}

int main()
{
    srand(time(NULL));

    PrintIntor();

    PlayGame();

    return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
