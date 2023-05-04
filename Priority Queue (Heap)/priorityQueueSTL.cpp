#include<iostream>
#include<queue>
using namespace std;

int main()
{   

    // MAX PRIORITY QUEUE
    priority_queue<int> pq;

    pq.push(30);
    pq.push(18);
    pq.push(75);

    cout<<pq.top()<<endl;

    pq.push(89);
    cout<<pq.top()<<endl;

    pq.pop();
    pq.pop();

    cout<<pq.top()<<endl;

    //
    // priority_queue<dataType,vector<dataType>,greater<dataType>> pq;

    // MIN PQ
    priority_queue<int,vector<int>,greater<int>> minPQ;

    minPQ.push(34);
    minPQ.push(12);
    minPQ.push(89);

    cout<<minPQ.top()<<endl;

    return 0;
}