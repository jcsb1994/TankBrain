

#include "FSM/menu.h"

void menu::update_target_widget_from_cursor()
{
    _target_widget = ((_widget_map_size[Y_COORD_INDEX]) * _cursor_pos[X_COORD_INDEX]) + _cursor_pos[Y_COORD_INDEX];
    //target_widget ++;
}

void menu::enclose_cursor()
{
    if (_cursor_pos[X_COORD_INDEX] > (_widget_map_size[X_COORD_INDEX] - 1))
    {
        _cursor_pos[X_COORD_INDEX] = 0;
    }
    if (_cursor_pos[Y_COORD_INDEX] > (_widget_map_size[Y_COORD_INDEX] - 1))
    {
        _cursor_pos[Y_COORD_INDEX] = 0;
    }
}

void menu::move_cursor(uint8_t dim, int amount)
{
    _cursor_pos[dim] += amount;
    enclose_cursor();
    update_target_widget_from_cursor();
}


void menu::update_widget_map_size(uint8_t x_dimension, uint8_t y_dimension)
{
    _widget_map_size[X_COORD_INDEX] = x_dimension;
    _widget_map_size[Y_COORD_INDEX] = y_dimension;

    _target_widget = 0;
    quit_edit_widget(); // leave editing mode, safeguard code
}

int *menu::pop_widget_val_map(int *map, unsigned int len, int inactive_widget_value, int target_widget_value, int edit_widget_value)
{
    for (unsigned int i = 0; i < len; i++)
    {
        if (get_target_widget() == i)
        {
            if (is_editing_widget())
                map[i] = edit_widget_value;
            else
                map[i] = target_widget_value;
        }
        else
            map[i] = inactive_widget_value;
    }
    return map;
}

//---------------------------------------------

/* unsigned int* menu::set_widget_color_map(unsigned int inactive_col, unsigned int active_col)
{
    // create array
    unsigned int color_map[widget_count[X_COORD_INDEX] * widget_count[Y_COORD_INDEX]];

    // populate with inactive colors
    for (uint8_t i = 0; i < sizeof(color_map) / sizeof(color_map[0]); i++)
        color_map[i] = inactive_col;

    // set active col to active widget
    color_map[active_widget] = active_col;

    // copy to widget_map
    memmove(widget_map, color_map, sizeof(color_map));
    widget_map = color_map;

    return color_map;
} */