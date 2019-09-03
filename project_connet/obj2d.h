#ifndef INCLUDED_OBJ2D
#define INCLUDED_OBJ2D

//******************************************************************************
//
//
//      obj2d.h
//
//
//******************************************************************************

//------< �萔 >----------------------------------------------------------------

//------< �\���� >---------------------------------------------------------------

//==============================================================================
//
//      OBJ2D
//
//==============================================================================
struct OBJ2D
{
    // �X�v���C�g�֘A
    Sprite* data;           // �X�v���C�g�|�C���^
    VECTOR2 texPos;         // �摜�ʒu
    VECTOR2 texSize;        // �摜�T�C�Y
    VECTOR2 texPivot;       // �摜�̊�_
    int     anime;          // �A�j���[�V�����p�i���j

    // OBJ2D�̃^�C�v�E���݃t���O
    int     type;           // �^�C�v
    BOOL    exist;          // ���݃t���O

    // �ėp�I�Ȃ���
    VECTOR2 pos;            // �ʒu
    VECTOR2 scale;          // �X�P�[��
    float   angle;          // �p�x
    VECTOR4 color;          // �F�ixyzw���ꂼ��rgba�j
    float   radius;         // ���a
    int     state;          // ��ԑJ�ڗp
    int     timer;          // �^�C�}�[
    VECTOR2 speed;          // ���x
    int     cnt;            // �ėp�J�E���^�i�g�����͎��R�j
    BOOL    hostilityFg;    // �G�t���O�i���񂩂�ǉ��j
	int		direction;		// ����


    // ����Ȃ���
    BOOL    groundFlag;     // �n��t���O�i�n��̂��̂�TRUE�j
    float   rotate;         // ���񂷂�p�x
    OBJ2D*  parent;         // �e�I�u�W�F�N�g���w���|�C���^
    VECTOR2 rpos;           // ���ΓI�Ȉʒu�irelative position)
    int     hp;             // �q�b�g�|�C���g
    int     atk;            // �U����
    int     damageTimer;    // �_���[�W�^�C�}�[
    int     score;          // ���̓G��|�����牽�_���邩
	VECTOR2 hookPos;		//
	BOOL	hookFlag;		//
	BOOL    connectFlag;    //
	int     guideState;
};

//------< �v���g�^�C�v�錾 >-----------------------------------------------------
OBJ2D* searchSet(OBJ2D[], int, int, VECTOR2);
BOOL areaCheck(OBJ2D*, float);

#endif // !INCLUDED_OBJ2D
