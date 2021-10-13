#pragma once

class Component
{
    public:
        // updateOrder���������قǍX�V������
        Component(class Actor* owner, int updateOrder = 100);
        virtual ~Component();

        virtual void Update();
        int GetUpdateOrder() const { return updateOrder; }
    protected:
        class Actor* owner;
        // �R���|�[�l���g�̍X�V����
        int updateOrder;
};