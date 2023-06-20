#ifndef TRANSACTION_ACTION_H
#define TRANSACTION_ACTION_H

#include <iostream>

namespace Transaction{
    class UndoAction{
        public:
        virtual ~UndoAction() = default;
        virtual void Init() = 0;
        virtual void Ok() = 0;
        virtual void Fail() = 0;
    };

    class KeepInt : public UndoAction{
        private:
            int& _value;
            int _oldValue;
        public:
            KeepInt(int& val): _value(val), _oldValue(val){}

            void Init() override{
            }
            
            void Ok() override{
            }
            
            void Fail() override{
                _value = _oldValue;
            }
    };
}
#endif