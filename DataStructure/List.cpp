//顺序表实现

#include"List.h"

PList MakeEmpty()
{
    PList L = std::make_shared<List>();
    L->Last = -1;
    return L;
}

// 元素查找
List::position_t Find(const PList &L, const List::element_t& X)
{
    List::position_t pos = 0;
    if (L->Last == -1) {
        return LIST_ERROR;
    }
    while (pos <= L->Last && L->Data[pos] != X) pos++;
    if (pos > L->Last) return LIST_ERROR;
    else return pos;
}

// 插入操作,P为从0开始的索引位置
bool Insert(PList &L, List::element_t X, List::position_t P)
{
    List::position_t i;

    // 表满
    if (L->Last == MAX_SIZE - 1) {
        return false;
    }

    // 插入位置不合法
    if (P < 0 || P > L->Last + 1) {
        return false;
    }

    for (i = L->Last + 1; i > P; i--)
        L->Data[i] = L->Data[i - 1];

    L->Data[P] = X;
    L->Last++;

    return true;
}

bool Insert(PList & L, List::element_t X)
{
    return Insert(L,X,L->Last+1);
}

// 删除操作
bool Delete(PList &L, List::position_t P)
{
    List::position_t i = 0;
    // 已空
    if (L->Last == -1) {
        return false;
    }
    if (P < 0 || P>L->Last) {
        return false;
    }

    for (i = P; i < L->Last; i++) {
        L->Data[i] = L->Data[i + 1];
    }

    L->Last--;
    return true;
}