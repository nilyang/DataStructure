//˳���ʵ��

#include"List.h"

PList MakeEmpty()
{
    PList L = std::make_shared<List>();
    L->Last = -1;
    return L;
}

// Ԫ�ز���
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

// �������,PΪ��0��ʼ������λ��
bool Insert(PList &L, List::element_t X, List::position_t P)
{
    List::position_t i;

    // ����
    if (L->Last == MAX_SIZE - 1) {
        return false;
    }

    // ����λ�ò��Ϸ�
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

// ɾ������
bool Delete(PList &L, List::position_t P)
{
    List::position_t i = 0;
    // �ѿ�
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