#ifndef ACCOUNT_STATE_H
#define ACCOUNT_STATE_H

#include "TransactionAction.h"
#include <vector>

namespace Transaction{
    class AccountState{
        private:
            std::vector<UndoAction*> _acc;
            static bool _finished;
        public:
        AccountState(UndoAction* a){
            _acc.push_back(a);
            a->Init();
            _finished = false;
        }

        ~AccountState(){
            if(_acc.empty()){
                return;
            }


            if(_acc.front()){
                if(_finished){  
                    _acc.front()->Ok();
                }else{
                    _acc.front()->Fail();
                }
                delete _acc.front();
            }
        }

        static void AllOk(){
            _finished = true;
        }
    };
    bool AccountState::_finished = false;
}
#endif