/*===================================
有一个农夫带一只羊、一筐菜和一只狼过河。如果
没有农夫看管，则狼要吃羊，羊要吃菜。但是船很
小，只够农夫带一样东西过河。问农夫该如何解此
难题？
===================================*/

/*
此题采用图的思想求解，要得到从初始状态结点到最终状态结点的无回路路径。
这个图具有所有的状态结点（包括合法与非法的），且是完全有向图，其边就代表过河操作；
采用深度优先搜索寻找路径，碰到不合法的状态转移则折返（不合法的状态或无法完成的操作）
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//记录当前序列中出现过的状态，防止状态重复（死循环或非最优解）
int state_in_que[16] = {0};

//共8种操作
string action[8] = {"sheep_go", "sheep_come", "vegetable_go", "vegetable_come",
                    "wolf_go", "wolf_come", "nothing_go", "nothing_come"};

//状态
struct State
{
    int farmer, sheep, veg, wolf; //0-未过河，1-过河
    State(int f, int s, int v, int w) : farmer(f), sheep(s), veg(v), wolf(w) {}
    /*
    非法状态：
    1000,1010,1001,0111,0101,0110
    转换成整数：
    8,10,9,7,5,6
    */
};

//将状态转换成整数
int trans(State s)
{
    return 8 * s.farmer + 4 * s.sheep + 2 * s.veg + s.wolf;
}

//接收当前状态及操作数，输出下一个状态
State crossRiver(State now, int action)
{
    int f, s, v, w;
    f = now.farmer, s = now.sheep, v = now.veg, w = now.wolf; //当前状态
    switch (action)
    {
    case 0:                   //sheep_go
        if (f == 0 && s == 0) //农夫与羊均未过河
        {
            State next(1, 1, v, w);
            return next;
        }
        else //农夫与羊不在一边，无法完成操作，则置next状态与当前now一致
            return now;
        break;
    case 1:                   //sheep_come
        if (f == 1 && s == 1) //农夫与羊均过河
        {
            State next(0, 0, v, w);
            return next;
        }
        else
            return now;
        break;
    case 2:                   //vegetable_go
        if (f == 0 && v == 0) //农夫与菜均未过河
        {
            State next(1, s, 1, w);
            return next;
        }
        else
            return now;
        break;
    case 3:                   //vegetable_come
        if (f == 1 && v == 1) //农夫与菜均过河
        {
            State next(0, s, 0, w);
            return next;
        }
        else
            return now;
        break;
    case 4:                   //wolf_go
        if (f == 0 && w == 0) //农夫与狼均未过河
        {
            State next(1, s, v, 1);
            return next;
        }
        else
            return now;
        break;
    case 5:                   //wolf_come
        if (f == 1 && w == 1) //农夫与狼均过河
        {
            State next(0, s, v, 0);
            return next;
        }
        else
            return now;
        break;
    case 6:         //nothing_go
        if (f == 0) //农夫未过河
        {
            State next(1, s, v, w);
            return next;
        }
        else
            return now;
        break;
    case 7:         //nothing_come
        if (f == 1) //农夫过河
        {
            State next(0, s, v, w);
            return next;
        }
        else
            return now;
        break;
    default:
        return now;
        break;
    }
}

//判断该次操作是否合法
bool isValid(State now, State next)
{
    int idx = trans(next);
    if (idx == trans(now)) //前后状态一样，非法
        return false;
    else if (idx == 5 || idx == 6 || idx == 7 || idx == 8 || idx == 9 || idx == 10) //非法状态
        return false;
    else if (state_in_que[idx] == 1) //之前已经出现过该状态，非法
        return false;
    else
        return true;
}

//判断是否为最终状态
bool isFinished(State s)
{
    if (trans(s) == 15) //最终状态1111
        return true;
    else
        return false;
}

int main()
{
    State now(0, 0, 0, 0);   //状态初始化
    vector<State> stateQue;  //状态序列
    vector<int> nextAction;  //操作指示，指示DFS过程中处于状态序列中对应位置的状态时当前应该进行的操作
    vector<int> actionQue;   //操作序列
    stateQue.push_back(now); //初始状态入列
    nextAction.push_back(0); //初始状态从0号操作开始
    while (!isFinished(now)) //序列最后一个状态不是最终状态，循环
    {
        now = stateQue[stateQue.size() - 1];         //获取当前状态
        state_in_que[trans(now)] = 1;                //标记此状态已经历过
        int idx = nextAction[nextAction.size() - 1]; //获取当前应该执行的操作
        if (idx == 8)                                //当前状态可行的操作已遍历完却未解决问题，回溯
        {
            stateQue.pop_back();          //当前状态出列
            nextAction.pop_back();        //操作指示出列
            actionQue.pop_back();         //获得当前状态的操作出列
            state_in_que[trans(now)] = 0; //取消该状态的标记
            continue;
        }
        for (int i = idx; i < 8; i++) //从当前应该执行的操作开始向后寻找合法的操作
        {
            State next = crossRiver(now, i);
            if (!isValid(now, next)) //非法操作，跳过并尝试下一个操作
            {
                nextAction[nextAction.size() - 1] = i + 1;
                continue;
            }
            else
            {
                nextAction[nextAction.size() - 1] = i + 1; //下次返回此状态时从下一个操作开始
                actionQue.push_back(i);                    //当前操作入列
                stateQue.push_back(next);                  //下一个状态入列
                nextAction.push_back(0);                   //下一个状态为新状态，进行的操作应从0号开始
                break;
            }
        }
    }
    for (int i = 0; i < actionQue.size(); i++)
        cout << action[actionQue[i]] << endl;
    cout << "succeed" << endl;
    return 0;
}

/*
  此题应该是有两个解，这里的代码得到一个解就马上输出了，不过平台的测试也没有很严格，输出一个正确解即可
  网络上是找得到比这更好的能输出两个正确解的代码的
  纯手打，技术有限可能不够简洁，网上有大佬的代码量更少，多多参考
*/