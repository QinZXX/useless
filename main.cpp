#include <iostream>
#include <list>

using namespace std;

//��һ�ַ�ʽ
template <class Iter>
struct iter_traits//�򻯰��iterator_traits��ֻ������value_type��Ϊ��������STL�е�iterator::traits������Ҳ��Ϊiter_traits
{
    typedef typename Iter::value_type value_type; // ����Ϊʲô��typename
};

//�ڶ��ַ�ʽ��ƫ�ػ�
template <class Type>
struct iter_traits<Type *>
{
    typedef Type value_type;
};

// algorithm
template <class Iter>
void iter_print(const Iter &a, const Iter &b)
{
    typedef typename iter_traits<Iter>::value_type T;
    //�˴��ǹؼ�����˼��һ�£����a��b��ָ��Ļ���������iter_traits�ĵڶ��ַ�ʽ������ʲô�취���Ի��a��b��ָ������ݵ����ͣ�
    T key;
    Iter p;
    for(p=a;p!=b;p++)
    {
        key = *p;
        cout << key << ",";
    }
    cout <<endl;
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    list<string> b{"A","B","C","D","E","F","G"};

    iter_print<int *>(a,a+10);
    iter_print< list<string>::iterator >(b.begin(), b.end());
    return 0;
}