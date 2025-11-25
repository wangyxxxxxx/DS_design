#include <iostream>
#include "MainWindow.h"
using namespace std;
int main(int argc, char *argv[]) {

    // 设置控制台输出中文
    SetConsoleOutputCP(65001);

    // NaturalLanguageToDSL translator;
    //

    //
    // // 测试用例
    // std::vector<std::string> test_cases = {
    //     "创建一个序列1,2,3,4,5然后执行插入排序",
    //     "添加顶点A和顶点B，然后在它们之间添加一条权重为5的边",
    //     "从顶点A开始进行深度优先搜索",
    //     "计算最小生成树",
    //     "删除顶点A和从A到B的边",
    //     "这是一个无法识别的命令"
    // };
    //
    // for (const auto& test_case : test_cases) {
    //     std::cout << "\n=========================================" << std::endl;
    //     std::cout << "自然语言: " << test_case << std::endl;
    //     std::string dsl_code = translator.translate(test_case);
    //     std::cout << "生成的DSL代码:\n" << dsl_code;
    //     std::cout << "=========================================" << std::endl;
    // }

    QApplication a(argc, argv);
    MainWindow window;

    window.show();

    return a.exec();
}

