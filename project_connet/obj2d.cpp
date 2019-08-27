//******************************************************************************
//
//
//      obj2d
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"

//------< �ϐ� >----------------------------------------------------------------

//------< �\���� >---------------------------------------------------------------

//------< �v���g�^�C�v�錾 >-----------------------------------------------------

//--------------------------------
// �󂫂�T����OBJ2D�𐶐�����iVersion2�j
//--------------------------------
OBJ2D* searchSet(OBJ2D arr[], int arrayNum, int type, VECTOR2 pos)
{
    int i;
    for (i = 0; i < arrayNum; i++)
    {
        if (arr[i].exist == TRUE) continue;
        ZeroMemory(&arr[i], sizeof(OBJ2D));
        arr[i].type = type;
        arr[i].pos = pos;
        arr[i].scale = VECTOR2(1, 1);
        arr[i].color = VECTOR4(1, 1, 1, 1);
        arr[i].exist = TRUE;
        return &arr[i]; // ��������arr[i]�̃A�h���X��Ԃ�
    }
    return NULL;        // �����ł��Ȃ������̂�NULL��Ԃ�
}

//--------------------------------
// OBJ2D�̃G���A�O�`�F�b�N
//--------------------------------
BOOL areaCheck(OBJ2D* obj, float limit)
{
    if (obj->pos.x < -limit ||
        obj->pos.x > system::SCREEN_WIDTH + limit ||
        obj->pos.y < -limit ||
        obj->pos.y > system::SCREEN_HEIGHT + limit)
    {
        obj->exist = FALSE;
    }

    return obj->exist;
}



