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
