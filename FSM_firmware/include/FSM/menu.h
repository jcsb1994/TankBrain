//***********************************************************************************
// Copyright 2021 JCSB1994
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//***********************************************************************************
//
// Description:
//    This file provides a menu interface for screens. It manages widget selection,
//    but not the widgets and their effects when pressed
//    Widgets are managed as 2 dimension coordinates. any nb of row and col can be created
//    Rows are counted first, 
//    Widget order should be designed in a way that it makes sense for the user to move down
//    and select the next widget, and move sideways and select widget[current+row_nb]
//    widget[X,Y] 
//        
//      ______SCREEN_________
//      | Widget1   Widget4  |
//      | Widget2   Widget5  |
//      | Widget3   Widget6  |
//      ----------------------
//***********************************************************************************
//
// Widget map   : This menu i.f. lays the screen as a map made out of widgets in x and y coord
// Cursor       : The cursor is the x and y coord currently targeted
// Taget widget : Widget currently targeted by the cursor
// Edit widget  : When target widget is selected, becomes edit widget. user may edit/interact with it
//
//***********************************************************************************

#ifndef MENU_H
#define MENU_H

#include <Arduino.h>

#define X_COORD_INDEX (0)
#define Y_COORD_INDEX (1)
#define NOT_EDITING_WIDGET (-1)

#define WIDGET_CURSOR_MAP(x, max_x, y) (((max_x - 1) * x) + y) // Maps the current cursor pos to the map array

class menu
{
private:
    uint8_t _cursor_pos[2] = {0, 0};

    uint8_t _widget_map_size[2] = {0, 0};

    uint8_t _target_widget;
    bool _edit_widget;

    // called when cursor pos is changed or widget count is changed
    void enclose_cursor();
    void update_target_widget_from_cursor();

public:
    menu() {}
    ~menu() {}

    uint8_t get_widget_x_nb() { return _widget_map_size[X_COORD_INDEX]; }
    uint8_t get_widget_y_nb() { return _widget_map_size[Y_COORD_INDEX]; }
    uint8_t get_widget_nb() { return (_widget_map_size[X_COORD_INDEX] * _widget_map_size[Y_COORD_INDEX]); }

    uint8_t *get_widget_map_dimensions() { return _widget_map_size; }
    uint8_t *get_cursor_pos() { return _cursor_pos; }
    uint8_t get_target_widget() { return _target_widget; }
    /*     uint8_t *gen_widget_map_values(int target_widget_value, int inactive_widget_value)
    {
        static int map[get_widget_nb()];
        return cursor_pos;
    } */

    void enter_edit_widget() { _edit_widget = true; }
    void quit_edit_widget() { _edit_widget = false; }
    bool is_editing_widget() { return _edit_widget; }

    void move_cursor(uint8_t dim, int amount);

    void update_widget_map_size(uint8_t x_count, uint8_t y_count); // when changing state, resets active widget

    int *pop_widget_val_map(int *map, unsigned int len, int inactive_widget_value, int target_widget_value, int edit_widget_value);

    // color display menues
    /*     unsigned int get_widget_color(int8_t widget_map_index)
    {
        if (widget_map_index >= 0 && (widget_map_index < (widget_count[X_COORD_INDEX] * widget_count[Y_COORD_INDEX])))
            return widget_map[widget_map_index];
        else
            return 0;
    } */

    //unsigned int* set_widget_color_map(unsigned int inactive_col, unsigned int active_col);
};

#endif // MENU_H