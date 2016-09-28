/*很多同学都玩过著名的 RTS 游戏《星际争霸II——自由之翼》——现在主角 Jim Raynor 正在跟最终 BOSS ——人类帝国皇帝 Mengsk 进行最后的决战。在这场大战中，双方都使用相同的科技树（即人族 Terran），下面请编写一个程序，展现双方基地在给定的水晶（Minerals）下，按顺序训练新的单位的过程。具体规则如下：

双方能生产的兵种都有三种：农民（即建造机器人 SCV ），枪兵（陆战队员 Marine）和护士（医疗兵 Medic），消耗的水晶数分别是 1010, 55, 44
每经过一个时间单位，双方的基地各有一个新的单位被训练出来
Raynor 的建造序列是 SCV ， Marine ， Medic ，Mengsk 的建造序列是 Marine， Medic， SCV，在资源耗尽之前双方将一直循环建造
如果当前剩余资源无法建造当前要建造的单位，则自动顺延至下一个单位——如果所有单位都无法建造的话，则建造停止。
输入格式说明

输入一个数字为双方分别拥有的水晶数，该数字为大于 00 小于 100100 的整数

输出格式说明

要求输出双方的基地在每一个时间单位正在执行的操作——建造了某个单位，或者建造停止

先输出 Raynor 的建造顺序，再输出 Mengsk 的建造顺序——两者的时间计数是彼此独立的。每次建造操作，如果失败（水晶数不足）则继续尝试建造下一个单位，如果成功则输出一行：

Time: 时间（从0开始） 基地名 单位 单位编号（从0开始） born with HP 生命值（与建造需要的水晶数相同） 当前基地内的该单位总数 单位
（注意这里的“时间”和“基地名”之间有两个空格）

每次完成建造之后，都检查一次剩余水晶数，如果剩余水晶数已小于 44 （即不足以建造任何一个单位）则输出当前的时间，以及“XX base stop training troopers.”
样例输入

38
样例输出

Time: 0  Raynor SCV 0 born with HP 10 1 SCV in base Raynor
Time: 1  Raynor Marine 1 born with HP 5 1 Marine in base Raynor
Time: 2  Raynor Medic 2 born with HP 4 1 Medic in base Raynor
Time: 3  Raynor SCV 3 born with HP 10 2 SCV in base Raynor
Time: 4  Raynor Marine 4 born with HP 5 2 Marine in base Raynor
Time: 5  Raynor Medic 5 born with HP 4 2 Medic in base Raynor
Time: 5  Raynor base stop training troopers.
Time: 0  Mengsk Marine 0 born with HP 5 1 Marine in base Mengsk
Time: 1  Mengsk Medic 1 born with HP 4 1 Medic in base Mengsk
Time: 2  Mengsk SCV 2 born with HP 10 1 SCV in base Mengsk
Time: 3  Mengsk Marine 3 born with HP 5 2 Marine in base Mengsk
Time: 4  Mengsk Medic 4 born with HP 4 2 Medic in base Mengsk
Time: 5  Mengsk SCV 5 born with HP 10 2 SCV in base Mengsk
Time: 5  Mengsk base stop training troopers.
提示信息

这是一道比较复杂的问题，涉及到了之前学过的很多知识——不过所有需要的知识都是你已经学过的，我们相信你是能完成它的！

这里给出几个提示：

单位的名称可以用string类来保存，可参见之前的难题
以下是一种设计类的思路，仅供参考：你可以建立一个troop类用于保存兵种自身的信息，再建立一个base类用于保存基地应该保存的信息，然后通过在主函数中调用base类的成员函数，执行建造和判断水晶剩余数的操作*/



#include <iostream>
#include <string>
using namespace std;

class base{
    public:
      int Time;
      //int number = 0; 
      int total_number = 0;
};

int main(){
    int Minerals;
    int MMinerals;
    int time = 0;
    int Mtime = 0;
    cin>>Minerals;
    MMinerals = Minerals;
    base SCV;
    base Mar;
    base Med;
    base MSCV;
    base MMar;
    base MMed;
    for(int i = 0; ; i++){
        if(Minerals < 4)
                {
                    if(i == 0)
                        cout<<"Time: "<<time<<"  Raynor base stop training troopers."<<endl;
                    else
                        cout<<"Time: "<<time - 1<<"  Raynor base stop training troopers."<<endl;
                    break;
                }
        switch (i % 3) {
            case 0 : {
                if(Minerals - 10 >= 0){
                    Minerals = Minerals - 10;
                    SCV.total_number++;
                    cout<<"Time: "<<time<<"  Raynor SCV "<<time<<" born with HP 10 "
                        <<SCV.total_number<<" SCV in base Raynor"<<endl;
                    time++;
                    }
                    break;
                }
            case 1 : {
                if(Minerals - 5 >= 0){
                    Minerals = Minerals - 5;
                    Mar.total_number++;
                    cout<<"Time: "<<time<<"  Raynor Marine "<<time<<" born with HP 5 "
                        <<Mar.total_number<<" Marine in base Raynor"<<endl;
                    time++;
                     }
                    break;
                }
                
            case 2 : {
                if(Minerals - 4 >= 0){
                    Minerals = Minerals - 4;
                    Med.total_number++;
                    cout<<"Time: "<<time<<"  Raynor Medic "<<time<<" born with HP 4 "
                        <<Med.total_number<<" Medic in base Raynor"<<endl;
                   time++;
                    }
                    break;
                }
        }
    }
    
    for(int i = 0; ; i++){
        if(MMinerals < 4)
                {
                    if(i == 0)
                        cout<<"Time: "<<Mtime<<"  Mengsk base stop training troopers."<<endl;
                    else
                        cout<<"Time: "<<Mtime - 1<<"  Mengsk base stop training troopers."<<endl;
                    break;
                }
        switch (i % 3) {
                case 2 : {
                if(MMinerals - 10 >= 0){
                    MMinerals = MMinerals - 10;
                    MSCV.total_number++;
                    cout<<"Time: "<<Mtime<<"  Mengsk SCV "<<Mtime<<" born with HP 10 "
                        <<MSCV.total_number<<" SCV in base Mengsk"<<endl;
                    Mtime++;
                    }
                    break;
                }
            case 0 : {
                if(MMinerals - 5 >= 0){
                    MMinerals = MMinerals - 5;
                    MMar.total_number++;
                    cout<<"Time: "<<Mtime<<"  Mengsk Marine "<<Mtime<<" born with HP 5 "
                        <<MMar.total_number<<" Marine in base Mengsk"<<endl;
                    Mtime++;
                     }
                    break;
                }
                
            case 1 : {
                if(MMinerals - 4 >= 0){
                    MMinerals = MMinerals - 4;
                    MMed.total_number++;
                    cout<<"Time: "<<Mtime<<"  Mengsk Medic "<<Mtime<<" born with HP 4 "
                        <<MMed.total_number<<" Medic in base Mengsk"<<endl;
                    Mtime++;
                   }
                    break;
                }
          
        }
               
    }
    return 0;
}
