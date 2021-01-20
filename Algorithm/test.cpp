/*
 C++ "."과 "->"" 차이
 . : 참조로 요소 선택 
 점 앞에 변수나 포인터가 아닌 저장하려는 데이터
 가 있을 때 사용
 -> : 포인터로 요소 선택
 화살표 앞에 포인터가 있을 경우 사용.

*/
#include <iostream>
using namespace std;

#define MAX_HASH 10 // HASH 사이즈 (정적 해시)
#define HASH_KEY(key) key%MAX_HASH // 주소값 구하기

typedef struct Node{ //인덱스에서 가리킬 노드 생성(연결 리스트)
    int id;
    Node* hashnext;    
}Node;

Node* hashTable[MAX_HASH]; //Hash 테이블 생성

void AddHashData(int key, Node* node)
{
    int hash_key = HASH_KEY(key);

    // 값이 없다면 처음들어온 것이므로 바로 데이터 저장
    if(hashTable[hash_key] == NULL) 
    {
        hashTable[hash_key] = node;
    }
    else // 값이 있다면
    {
        /*
        값이 추가되면 index[0] -> node1 에서 node2를 추가하려고하면
        우선 node2 -> node1 을 가리키게하고. 
        index[0]이 node 2를 가리키게 해서
        index[0] -> node 2 -> node1
        */
        //현재 추가하는 노드의 hashNext는 hashTable[hash_key]를 가르키게 합니다.
        //값을 포인터로 접근한다?? 고보면됨.
        //AddHashData(node->id, node)
        node->hashnext = hashTable[hash_key]; 

        // 이후 hashTable[hash_key]값은 새로 추가될 노드를 가르키면
        // 자연스럽게 기존 추가 노드들이 연결.
        hashTable[hash_key] = node;
    }
    
}

void DelHashData(int id)
{
    int hash_key = HASH_KEY(id);  
    if(hashTable[hash_key] == NULL)
        return;
    
    Node* delNode = NULL;
    /*hashTable[hash_key] 데이터를 삭제할 노드로 만들고 
    [hash_key == 주소값]
    */
    if(hashTable[hash_key]->id == id)
    {
        //
        delNode = hashTable[hash_key];
        hashTable[hash_key] = hashTable[hash_key]->hashnext;
    }
    else
    {
        Node* node = hashTable[hash_key];
        Node* next = node->hashnext;
        while(next)
        {
            if (next->id == id)
            {
                node->hashnext = next->hashnext;
                delNode = next;
                break;
            }
            node = next;
            next = node->hashnext;
        }
    }
    free(delNode);
    
}

Node* FindHashData(int id)
{
    int hash_key = HASH_KEY(id);
    if(hashTable[hash_key] == NULL)
        return NULL;
    if(hashTable[hash_key] ->id == id)
    {
        return hashTable[hash_key];
    }
    else
    {
        Node* node = hashTable[hash_key];
        while (node->hashnext)
        {
            if(node->hashnext->id == id)
            {
                return node->hashnext;
            }
            node = node->hashnext;
        }
    }
    return NULL;
}

void PrintAllHashData()
{
    cout << "###Print All Hash Data###" << endl;
    for (int i = 0; i < MAX_HASH; i++)
    {
        cout << "idx:" << i << endl;
        if (hashTable[i] != NULL)
        {
            Node* node = hashTable[i];
            // 연결리스트의 다음 값이 없을때 까지
            while (node->hashnext) 
            {
                cout << node->id << " ";
                //node를 다음 노드로 이동.
                node = node->hashnext;
            }
            cout << node->id << endl;
        }
    }
    cout << endl << endl;;
}

int main()
{
    int saveidx[101] = { 0, };
    for (int i = 0; i < 100; i++)
    {
        //malloc(sizeof(Node)) / void 형 -> (Node*)타입으로 형변환
        Node* node = (Node*)malloc(sizeof(Node));
        cout << node << endl;
        //1000 까지 랜덤한 id값을 만듬.
        node->id = rand() % 1000; //주소에 해당 하는값을 가져옴.
        node->hashnext = NULL;
        //1000까지 랜덤한 id값을 만든 후 hashtable에 저장.
        AddHashData(node->id, node);
        //주소값??
        saveidx[i] = node->id;
    }
    PrintAllHashData();
 
 
    for (int i = 0; i < 50 ; i++)
    {
        DelHashData(saveidx[i]);
    }
    PrintAllHashData();
 
    for (int i = 50; i < 100; i++)
    {
        DelHashData(saveidx[i]);
    }
    PrintAllHashData();

    cout << "FindHashData : "<<FindHashData(4) << endl;
    return 0;
}