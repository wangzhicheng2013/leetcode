#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
static const char EMPTY_TASK = ' ';
static const char REPLACE_TASK = '$';
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n <= 0) {
            return tasks.size();
        }
        transform_tasks(tasks, n);
        int i = 0;
        int size = tasks_string_.size();
        while (i < size) {
            if ((tasks_string_[i] != EMPTY_TASK) && (tasks_string_[i] != REPLACE_TASK) && (i + n + 1 < size) && (tasks_string_[i] == tasks_string_[i + n + 1]) && (EMPTY_TASK == tasks_string_[i + 1]) && (EMPTY_TASK == tasks_string_[i + n])) {
                replace_between(i, i + n + 1);
                i = i + n + 1;
                continue;
            }
            else if (EMPTY_TASK == tasks_string_[i]) {
                for (int j = i + 1;j < size;j++) {
                    if ((tasks_string_[j] != EMPTY_TASK) && (tasks_string_[j] != REPLACE_TASK)) {
                        tasks_string_[i] = tasks_string_[j];
                        tasks_string_[j] = REPLACE_TASK;
                        break;
                    }
                }
            }
            i++;
        }
        for (i = tasks_string_.size() - 1;i >= 0;i--) {
            if ((REPLACE_TASK == tasks_string_[i]) || (EMPTY_TASK == tasks_string_[i])) {
                continue;
            }
            break;
        }
        int cnt = 0;
        for (;i >= 0;i--) {
            if (REPLACE_TASK == tasks_string_[i]) {
                continue;
            }
            cnt++;
        }
        std::cout << "shedule string:" << tasks_string_ << std::endl;
        return cnt;
    }
private:
    void transform_tasks(vector<char>&tasks, int n) {
        std::string empty_task_str(n, EMPTY_TASK);
        tasks_string_.assign(std::begin(tasks), std::end(tasks));
        int i = 0;
        while (tasks_string_[i]) {
            if (tasks_string_[i + 1]) {
                if (tasks_string_[i + 1] == tasks_string_[i]) {
                    tasks_string_.insert(i + 1, empty_task_str);
                    i += n + 1;
                    continue;
                }
            }
            ++i;
        }
    }
    bool is_in(int start, int end, int pos) {
        for (int i = start + 1;i < end;i++) {
            if ((tasks_string_[pos] == tasks_string_[i]) || (tasks_string_[pos] == tasks_string_[start]) || (EMPTY_TASK == tasks_string_[pos]) || (REPLACE_TASK == tasks_string_[pos])) {
                return true;
            }
        }
        return false;
    }
    void replace_between(int start, int end) {
        int pos = end + 1;
        int size = tasks_string_.size();
        int j = start + 1;
        for (;(pos < size) && (j < end);pos++) {
            if (!is_in(start, end, pos)) {
                tasks_string_[j++] = tasks_string_[pos];
                tasks_string_[pos] = REPLACE_TASK;  
            }
        }
    }
private:
    std::string tasks_string_;
};
class Solution1 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size()==0) {
            return 0;
        }
        //统计各个任务的次数
        int hash[26]={0}, tasksSize = tasks.size();
        for (auto task : tasks){
            hash[task - 'A'] += 1;
        }
        //寻找次数最多的任务maxTaskCnt，maxTasks记录次数最多的任务的个数
        int maxTaskCnt = 0, maxTasks = 0;
        for(int i = 0; i < 26; ++i){
            if(hash[i] > maxTaskCnt) {
                maxTaskCnt = hash[i];
                maxTasks = 1;
            }
            else if(hash[i] == maxTaskCnt){
                maxTasks++;
            }
        }
        //计算需要的最大时间
        int a = tasksSize - maxTaskCnt - maxTasks + 1;//需要插入的个数
        int b = n * (maxTaskCnt - 1);//可插入利用的最大个数
        if(a < b) {//第一种情况，贪心策略，尽量插入间隔
            return (n + 1) * (maxTaskCnt - 1) + maxTasks;
        }
        else {//第二种情况，只要不让相同的任务的距离小于n即可
            return tasksSize;
        }
    }
};
int main() {
    std::vector<char>tasks = { 'A', 'B', 'A' };
    int n = 2;
    Solution ss;
    std::cout << ss.leastInterval(tasks, n) << std::endl;
    Solution1 ss1;
    std::cout << ss1.leastInterval(tasks, n) << std::endl;

    return 0;
}