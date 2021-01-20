/*
    해시함수 
    분할 방식 : 주소 = 값 % 테이블의 크기
    해시 함수가 테이블 내의 공간을 효율적으로 사용하기 위해서는
    테이블의 크기 n을 소수로 정하는 것이 좋다.
    ex) 43 % 7 = 1
    미드 스퀘어 방식 : 제곱 요소의 중간 부분이 인덱스
    ex) 21*21 = 4(4)1  index == 4
    숫자 접기 방법
    23576623, 34687734
    해시(키) = 235 +766 +23 =1024
    해시 키) = 34 + 68 + 77 + 34 = 213
*/

#include <iostream>
using namespace std;

//define flags
#define MAX_HASH 10 // hash 테이블의 최대 사이즈
#define HASH_KEY(key) key%MAX_HASH
typedef struct Node
{
    int id;
    Node* hashNext;
}Node;
 
Node* hashTable[MAX_HASH];
 
void AddHashData(int key, Node* node)
{
    int hash_key = HASH_KEY(key);
    // 값이없다면 처음들어온 것이므로 바로 데이터 저장
    if (hashTable[hash_key] == NULL) 
    {
        //
        hashTable[hash_key] = node;
    }
    else
    {
        node->hashNext = hashTable[hash_key];
        hashTable[hash_key] = node;
    }
}

void DelHashData(int id)
{
    int hash_key = HASH_KEY(id);
    if (hashTable[hash_key] == NULL)
        return;
    
    Node* delNode = NULL;
    if(hashTable[hash_key]->id == id)
    {
        delNode = hashTable[hash_key];
        hashTable[hash_key] = hashTable[hash_key]->hashNext;
    }
     else
    {
        Node* node = hashTable[hash_key];
        Node* next = node->hashNext;
        while (next)
        {
            if (next->id == id)
            {
                node->hashNext = next->hashNext;
                delNode = next;
                break;
            }
            node = next;
            next = node->hashNext; 
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
        while (node->hashNext)
        {
            if(node->hashNext->id == id)
            {
                return node->hashNext;
            }
            node = node->hashNext;
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
            while (node->hashNext)
            {
                cout << node->id << " ";
                node = node->hashNext;
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
        Node* node = (Node*)malloc(sizeof(Node));
        node->id = rand() % 1000;
        node->hashNext = NULL;
        AddHashData(node->id, node);
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
    return 0;
}
