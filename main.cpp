#include <iostream>

// ************* 测试程序辅助函数 *******************************
using std::cin;
using std::cout;
using std::string;

long get_a_target_long(){
    long target=0;

    cout<<"target (0~"<<RAND_MAX<<"): ";
    cin>>target;
    return target;
}

string get_a_target_string(){
    long target=0;
    char buf[10];

    cout<<"target (0~"<<RAND_MAX<<"): ";
    cin>>target;
    snprintf(buf,10,"%d",target);
    return string(buf);
}

int compareString(const void *a,const void *b){ // 小于返回-1，等于返回 0 ，大于返回 1
    return *(string*)a < *(string*)b? -1:( *(string*)a == *(string*)b ? 0 : 1) ;
}

//***********************************  test1 ********************************************************
#include <vector>
#include <string>
#include <cstdlib> //void abort(void) 程序异常终止  ( void exit(int status) 程序正常终止  )
#include <cstdio> //snprintf()
#include <iostream>
#include <ctime>
#include <algorithm> //sort()
#include <stdexcept>

using namespace std;

namespace jj01{
    void test_vector(long &value){
        cout<< "\ntest_vector()......................... \n";

        vector<string> c;
        char buf[10];

        clock_t  timeStart=clock();

        for(long i=0;i<value;++i){
            try {
                snprintf(buf,10,"%d",rand());
                c.push_back(string(buf));
            }
            catch(exception& p){
                cout<<"i="<<i<<" "<<p.what() << endl;
                // 曾经最高 i=11958657 bad allocation
                /* vaule=11958656时:
                 * test_vector().........................
                 * milli-seconds : 32139ms
                 * vector.size() : 11958656
                 * vector.front() :  41
                 * vector.capacity() : 11958657
                */
                abort(); // 异常退出
            }
        }
        cout<<"milli-seconds : "<< (clock()-timeStart)<<"ms"<<endl;
        cout<<"vector.size() : "<< c.size()<<endl;
        cout<<"vector.front() :  "<<c.front()<<endl;
        cout<<"vector.capacity() : "<<c.capacity() <<endl;


        string target=get_a_target_string();
        cout<<"target= "<<target<<endl;

        {
            timeStart=clock();
            auto pItem=::find(c.begin(),c.end(),target);
            cout<<"find(),milli-seconds : "<<(clock()-timeStart)<<endl;

            if (pItem !=c.end()){
                cout<<"found , "<<*pItem<<endl;
            }
            else{
                cout<<"not found! "<<endl;
            }
        }

        {
            timeStart=clock();
            sort(c.begin(),c.end());
            string * pItem=(string*) bsearch(&target, (c.data()),c.size(),sizeof(string),compareString);

            cout<<"sort() + bsearch(),milli-second : "<<(clock()-timeStart)<<endl;

            if(pItem != nullptr){ //NULL
                cout<<"found, "<<*pItem<<endl;
            }
            else{
                cout<<"not found! "<<endl;
            }
        }
    }
}

//***********************************  test2 ********************************************************
namespace jj02{
    void test_list(){

    }

}

//***********************************  test3 ********************************************************

namespace  jj03{
    void test_deque(){

    }
}
int main() {

    //******************************** vector **********************
    long value=get_a_target_long();
    jj01::test_vector(value);

    //******************************** list ************************

    //******************************** deque ***********************



    // cout<<(NULL==nullptr)<<endl; // 1

    return 0;
}