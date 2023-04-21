#include<iostream>
#include<tuple>

using namespace std;

// class Tuple
// {
//     public:
//     string a;
//     int b;
//     int c;

// };

int main()
{
    tuple <string,int,int> t;
    t= make_tuple("abc",5,10);

    // get <index> (tupleName)

    cout<<get<0> (t)<<endl;
    cout<< get<1> (t)<<endl;

    get<1> (t)= 25;

    cout<<get<1> (t)<<endl;

    pair<int,int> p;
    p=make_pair(10,15);

    cout<<p.first<<endl;




    return 0;
}