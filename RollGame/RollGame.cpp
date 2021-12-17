#include <iostream>
#include <cstdlib>
#include <ctime>//用于获取系统时间
using namespace std;
int pScore = 0;//定义全局函数并赋初值：玩家总分
int cScore = 0;//定义全局函数并赋初值：电脑总分
int turn = 0;//定义全局函数并赋初值：当前局数

//Create a game where the player rolls a dice and the computer rolls a dice. 
//The player gets to roll until it gets a 1. 
//If the player rolls a 1, the game ends. 
//If the player rolls a 6, the player gets to roll again and the player wins the points. 

class gameData {//定义类：游戏数据
public:
    int roll, score, total;
    friend int status(bool status) {
        gameData data;
        if (status = true)
            data.RollAgain = true;
        else
            data.RollAgain = false;
        return 0;
    };
private:
    bool RollAgain;
};

bool playerRoll(int rollpoints) {//玩家掷骰子
    int score;
    if (rollpoints == 1) {
        cout << "Player rolled a one. Game over. " << endl;
        return false;
    }
    else {
        cout << "Player rolled a " << rollpoints << ". Roll again. " << endl;
        return true;
    }
}

bool computerRoll(int rollpoints) {//电脑掷骰子
    int score;
    if (rollpoints == 1) {
        cout << "Computer rolled a one. Game over. " << endl;
        return false;
    }
    else {
        cout << "Computer rolled a " << rollpoints << ". Roll again. " << endl;
        return true;
    }
}

void mainGame(int modecode, int pr, int cr) {//游戏主函数
    if (modecode == 1) {
        cout << "Player first." << endl;
        cout << "Player rolled " << pr << " and computer rolled " << cr << " . " << endl;
        playerRoll(pr);
        computerRoll(cr);
    }
    else if (modecode == 2) {
        cout << "Computer first." << endl;
        cout << "Computer rolled " << pr << " and player rolled " << cr << " . " << endl;
        computerRoll(cr);
        playerRoll(pr);
    }
    else {
        cout << "Still under developing..." << endl;
    }
}

void endGame(int ps, int cs) {//当游戏结束时调用
     if (ps > cs) {
         cout << "Player win. " << endl;
     }
     else if (ps < cs) {
         cout << "Computer win. " << endl;
     }
     else {
         cout << "Draw. Nobody win. " << endl;
     }
}

void gameplay(int modecode) {//游戏数据处理与交互
    srand((unsigned)time(NULL));//使用系统时间初始化种子，避免每次生成随机数一样。
    gameData Player;
    gameData Computer;
    Player.roll = rand() % 6 + 1;
    Computer.roll = rand() % 6 + 1;
    mainGame(modecode, Player.roll, Computer.roll);
    pScore = pScore + Player.roll;
    cout << "Now the gama data:" << endl;
    cout << "Player score: " << pScore << ". " << endl;
    cScore = cScore + Computer.roll;
    cout << "Computer score: " << cScore << ". " << endl;
    turn = turn + 1;
    cout << turn << " round." << endl;
    cout << "Continue? (1.Yes/0.No)" << endl;
    int u_ans;
    cin >> u_ans;
    if (u_ans == 0) {
        endGame(pScore, cScore);
    }
    else if (u_ans == 1) {
        if (Player.roll > Computer.roll) {
            gameplay(1);
        }
        else if (Player.roll < Computer.roll) {
            gameplay(2);
        }
        else {
            endGame(pScore, cScore);
        }
    }
}

void main(void) {//主程序函数，包含运行时的欢迎界面与
    cout << " ____       _ _  ____" << endl;
    cout << "|  _ \\ ___ | | |/ ___| __ _ _ __ ___   ___ " << endl;
    cout << "| |_) / _ \\| | | |  _ / _` | '_ ` _ \\ / _ \\" << endl;
    cout << "|  _ < (_) | | | |_| | (_| | | | | | |  __/" << endl;
    cout << "|_| \\_\\___/|_|_|\\____|\\__,_|_| |_| |_|\\___|" << endl << endl;
    int gamemode = 0;
    cout << "Welcome!" << endl << "Choose a game mode: " << endl << "1:Player first" << endl << "2.Computer first" << endl << "3.Play together" << endl;
    int modecode;
    cin >> modecode;
    if (modecode == 1) {
        gameplay(modecode);
    }
    else if (modecode == 2) {
        gameplay(modecode);
    }
    else if (modecode == 3) {
        cout << "Still under developing..." << endl;
    }
    else {
        cout << "Invalid input. Exit game. " << endl;
    };
}
