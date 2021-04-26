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
//    This file contains the events implemented in the FSM
//
//***********************************************************************************


#ifndef EVENTS_H
#define EVENTS_H

enum event
{
    nothing, // Value 0 when no events are incoming
    left,
    right,
    up,
    down,
    enter,
    switchMenuPage
};

#endif // EVENTS_H