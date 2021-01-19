#include<iostream>
using namespace std;
union UBox{
    bool a;
    int x,y;
};

void UnionFunc(UBox* up, int t){
    up->x = t;
    if(up->x !=0){
        cout << "UBox x variable not null" <<endl;
    }else{
        up->x =1;
    }
}
void UnionTest(UBox up,int a, int b){
    up.x = a;
    if(up.x < b){
        up.x = b;
    }else{
        up.x = a;
    }
    
}

int main(){
    UBox u1;
    UnionFunc(&u1, 10);
    UnionTest(u1,3,2);
    cout << u1.x << endl;
}