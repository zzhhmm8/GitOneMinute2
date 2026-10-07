#include <iostream>
#include <string>
#include <vector>

int main() {
    // 格式：你的名字 hello git! 你学习该项目的时间戳（带时区）。
    // 学习完成后，在列表中新增一行自己的信息，保留其他人的记录。
    const std::vector<std::string> learners = {
        "示例同学 hello git! 2026-10-07T18:00:00+08:00"
        // 在上一行末尾加英文逗号，然后在这里加入你的记录。
    };

    for (const std::string& learner : learners) {
        std::cout << learner << '\n';
    }
    return 0;
}
