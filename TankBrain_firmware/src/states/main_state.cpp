
#include "main.h"
#include "FSM/states.h"
#include "FSM/events.h"
#include "FSM/widget.h"

typedef enum
{
    edit1,
    edit2,
    edit3,
    edit4,
    fireCannon,
    loadCannon,
    W_MAIN_NB
} main_state_widgets;

// dummy vars
// use global object variables instead *use pointer get fct
int var_one = 1;
int var_two = 2;
int var_three = 3;
int var_four = 4;

void wd_loadCannon()
{
    tft.setCursor(0, 200);
    tft.print("click ");
}

void wd_fireCannon()
{
    tft.setCursor(100, 200);
    tft.print("pow! ");
}

widget mainWidgets[W_MAIN_NB] = {
    widget(&var_one, 1),
    widget(&var_two, 2),
    widget(&var_three, 5),
    widget(&var_four, 10),
    widget(wd_fireCannon),
    widget(wd_loadCannon),
};

void main_state_handler()
{
    if (refreshFlag)
    {
        tft.setTextSize(2);
        tft.fillScreen(ST77XX_BLACK);
        tft.setCursor(0, 0);
        tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
        tft.print("Values: ");

        refreshFlag = false;
        valuesRefreshFlag = true;
    }

    if (valuesRefreshFlag)
    {
        int widget_value_map[machine.get_widget_count()];
        int *val_map = widget_value_map;
        val_map = machine.pop_widget_val_map(val_map, machine.get_widget_count(), ST77XX_WHITE, ST77XX_MAGENTA, ST77XX_GREEN);

        tft.setCursor(0, 80);
        tft.setTextColor(val_map[0], ST77XX_BLACK);
        tft.println(var_one);
        tft.setTextColor(val_map[1], ST77XX_BLACK);
        tft.println(var_two);
        tft.setTextColor(val_map[2], ST77XX_BLACK);
        tft.println(var_three);

        tft.setCursor(60, 80);
        tft.setTextColor(val_map[3], ST77XX_BLACK);
        tft.print(var_four);
        tft.setCursor(60, 100);
        tft.setTextColor(val_map[4], ST77XX_BLACK);
        tft.print("Fire");
        tft.setCursor(60, 120);
        tft.setTextColor(val_map[5], ST77XX_BLACK);
        tft.print("Load");

        tft.print(machine.get_target_widget());


        valuesRefreshFlag = false;
    }

    switch (machine.poll())
    {

    case event::up:
        valuesRefreshFlag = true;
        if (machine.is_editing_widget()) {
            mainWidgets[machine.get_target_widget()].increment();
        }
        else
            machine.move_cursor_y(-1);
        break;

    case event::right:
        valuesRefreshFlag = true;
        machine.move_cursor_x(1);
        break;

    case event::left:
        valuesRefreshFlag = true;
        machine.move_cursor_x(-1);
        break;

    case event::down:
        valuesRefreshFlag = true;

        if (machine.is_editing_widget())
            mainWidgets[machine.get_target_widget()].decrement();
        else
            machine.move_cursor_y(1);
        break;

    case event::enter:
        valuesRefreshFlag = true;

        if (!machine.is_editing_widget())
        {
            (mainWidgets[machine.get_target_widget()].is_editable() ? machine.enter_edit_widget() : mainWidgets[machine.get_target_widget()].activate());
        }
        else
        {
            machine.quit_edit_widget();
        }

        break;

    case event::nothing:
    default:
        break;
    }
}