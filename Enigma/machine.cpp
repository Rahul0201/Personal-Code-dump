#include<iostream>
#include<string>

class Rotor{
    private:
        int encode[27];
        int decode[27];
    public:
        Rotor(const char s[28]){
            for(int i=0; i<27; i++){
                encode[i] = (int)s[i]-64;
            }
        }
        void rotate(){ for(int i=26; i>=0; i--) encode[(i+1)%27] = encode[i]; }
        int goforward(int simple){ return encode[simple]; }
        int gobackward(int simple){
            for(int i=1; i<27; i++){
                if(encode[i] == simple) return i;
            }
            return 0;
        }
};

int main(){
    Rotor R1("HJGDQOXUSCAMIFRVTPNEWKBLZYH");
    Rotor R2("QNTZPSFBOKMWRCJDIVLAEYUXHGQ");
    Rotor R3("LJVIUBHTCDYAKEQZPOSGXNRMWFL");
    Rotor reflector("LQYHOGNECVPUZTFDJAXWMKISRBL");
    std::string simple;
    char coded;
    int R1_rotation_count = 0, R2_rotation_count = 0, R3_rotation_count = 0;
    while(true){
        std::cout << "\n>>>  ";
        std::cin >> simple;
        if( simple.length()!=1 || !( (simple[0]>64 && simple[0]<91)||(simple[0]>96 && simple[0]<123) ) ){
            std::cout << "\t!Only alphabets are supported";
            continue;
        }
        if( (simple[0]>96 && simple[0]<123) ) simple[0] -= 32;
        

        int temp = (int)simple[0] - 64;

        // ENOCDING
        temp = R1.goforward(temp);
        temp = R2.goforward(temp);
        temp = R3.goforward(temp);
        temp = reflector.goforward(temp);
        temp = R3.gobackward(temp);
        temp = R2.gobackward(temp);
        temp = R1.gobackward(temp);
        // ROTATIONS
        R1.rotate();
        R1_rotation_count = (R1_rotation_count+1)%26;
        if(R1_rotation_count == 0){
            R2.rotate();
            R2_rotation_count = (R2_rotation_count+1)%26;
            if(R2_rotation_count == 0){
                R3.rotate();
                R3_rotation_count = (R2_rotation_count+1)%26;
            }
        }
        

        coded = (char)(temp+64);
        std::cout << coded;

    }
}