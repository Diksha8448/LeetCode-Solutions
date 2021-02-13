/*
Given an array of the size n and k . Print the first k largest elements.
Time Complexity: O(N*log(k))
Space Complexity: O(k)
*/
vector<int>Klargest(int input[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    for(int i=k;i<n;i++){
        if(input[i]>pq.top()){
            pq.top();
            pq.push(input[i]);
        }
    }
    vector<int>output;
    while(!pq.empty()){
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}