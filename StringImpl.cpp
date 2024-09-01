#include <iostream>
using namespace std;
class String{
    char* str;
    unsigned len;
    
    public:
        String():str(nullptr),len(0)
        {}
        
        String(const char* ss){
            len=0;
            while(ss[len]!='\0'){
                len++;
            }
            str = new char[len+1];
            //Method 1 to assign the resource
            char* tmp=str;
            for(int i=0;ss[i]!='\0';i++){
                *tmp=ss[i];
                tmp++;
            }
            // Method 2
            // copy( ss, ss+len, str);
        }
        String(const String& ss){
            len = ss.len;
            str = new char[len+1];
            //Method1 to assign the resource
            char* tmp=str;
            for(int i=0;ss.str[i]!='\0';i++){
                *tmp=ss.str[i];
                tmp++;
            }
            //Method2 
            // copy(ss.str,ss.str+len,str);
        }
        unsigned int length(){
            return len;
        }
        String& operator=(const String& ss){
            len = ss.len;
            str = new char[len+1];
            char* tmp=str;
            for(int i=0;ss.str[i]!='\0';i++){
                *tmp=ss.str[i];
                tmp++;
            }
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& os, const String& ss);
        friend std::istream& operator>>(std::istream& in, const String& ss);

        ~String(){
            if(str){
                delete[] str;
                str = nullptr;
                len=0;
            }
        }
};

std::ostream& operator<<(std::ostream& os, const String& ss){
    return os << ss.str;
}

std::istream& operator>>(std::istream& in, String& ss){
    char buffer[1024];
    in >> buffer;
    ss = buffer;
    return in;
}

int main(){
    String s1;  //constructor
    String s2("abcd");  //parameterized constructor
    String s3="efgh";   //parameterized constructor
    printf("%d",s2.length());
    String s4(s3);      //copy constructor
    String s5 = s2;     //assignment operator
    cout << s5;
    cin >> s1;
    cout<<s1<<s1.length();
}
