//***********************************************************************************
// Copyright 2021 jcsb1994
// Written by jcsb1994
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//***********************************************************************************
//
// Description:
//    This file provides a class for user interfaces to implement in embedded systems.
//
//***********************************************************************************


#ifndef UI_H
#define UI_H

#include "../FSM/tact.h"
#include "../FSM/menu.h"


class UI
{
private:

    tact _Tacts[TACT_NB];

    event _incoming_event = nothing;

public:
    UI();
    ~UI();

    menu Menu;

    void poll_tacts();

    event extract_event();
};




#endif