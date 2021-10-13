#pragma once

class Component
{
    public:
        // updateOrderが小さいほど更新が早い
        Component(class Actor* owner, int updateOrder = 100);
        virtual ~Component();

        virtual void Update();
        int GetUpdateOrder() const { return updateOrder; }
    protected:
        class Actor* owner;
        // コンポーネントの更新順序
        int updateOrder;
};