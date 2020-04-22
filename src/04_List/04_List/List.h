#pragma once
#include <iostream>
using namespace std;

template<class Tkey, class TData>
class TNode {
public:
    Tkey key;
    TData* pData;
    TNode* pNext;

    TNode();
    TNode(const TNode&);
    TNode(Tkey, TData*, TNode* _pNext = 0);
    ~TNode();

    friend ostream& operator<<(ostream& out, TNode<Tkey, TData>& node) {
        out << node.key << " - " << node.pData[0];
        return out;
    }
};

template<class Tkey, class TData>
TNode<Tkey, TData>::TNode() {
    pData = new pData;
    pNext = NULL;
}

template<class Tkey, class TData>
TNode<Tkey, TData>::TNode(const TNode& node) {
    key = node.key;
    pData = new TData;
    pData = node.pData;
    pNext = NULL;
}

template<class Tkey, class TData>
TNode<Tkey, TData>::TNode(Tkey _key, TData* _pData, TNode* _pNext) {
    key = _key;
    pData = new TData(*_pData);
    pNext = _pNext;
}

template<class Tkey, class TData>
TNode<Tkey, TData>::~TNode() {
    delete pData;
}


template<class Tkey, class TData>
class TList {
private:
    TNode<Tkey, TData>* pFirst;
    TNode<Tkey, TData>* pPrev;
    TNode<Tkey, TData>* pCurr;
    TNode<Tkey, TData>* pNext;
public:
    TList();
    TList(const TList&);
    TList(TNode<Tkey, TData>* list);
    ~TList;

    void Next();
    void Reset();
    bool IsEnded() const;
    void Back(Tkey _key, TData* pData);
    TNode<Tkey, TData>* Search(Tkey _key);
    void push(Tkey _key, TData* pData);
    void insertAfter(Tkey, TData*, Tkey);
    void insertBefore(Tkey, TData*, Tkey);
    void Remove(Tkey);

    friend ostream& operator<<(ostream& out, TList<Tkey, TData>& list) {
        list.Reset();
        while (!(list.IsEnded())) {
            //out << list.pCurr->key << " - " << list.pCurr->pData << endl;
            out << (*list.pCurr) << endl;
            list.Next();
        }
        return out;
    }
};

template <class Tkey, class TData>
TList<Tkey, TData>::TList() {
    pFirst = NULL;
    pPrev = NULL;
    pCurr = NULL;
    pNext = NULL;
}

template <class Tkey, class TData>
TList<Tkey, TData>::TList(TNode<Tkey, TData>* list) {
    pFirst = list;
    pCurr = pFirst;
    pPrev = NULL;
    pNext = pFirst->pNext;
}

template <class Tkey, class TData>
TList<Tkey, TData>::TList(const TList<Tkey, TData>& list) {
    pFirst = new TNode<Tkey, TData>(*(list.pFirst));
    pCurr = pFirst;
    TNode<Tkey, TData>* node = list.pFirst;
    node = node->pNext;
    while (node != NULL) {

    }
}