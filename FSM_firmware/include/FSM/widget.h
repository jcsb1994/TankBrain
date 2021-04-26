#ifndef WIDGET_H
#define WIDGET_H

class widget
{
private:
    int * const _value;
    bool _isEditable;
    unsigned int _incrementSize;
    void (*activationFct)();

public:
  /**********************************************************************/
  /*!
    @brief  Ctor for non modifiable widgets, that trigger an action when pressed
    @param  activation_function function to run when widget is pressed
  */
  /**********************************************************************/
    widget(void (activation_function)()) : _value(0) { activationFct = activation_function; _isEditable = false; }
  /**********************************************************************/
  /*!
    @brief  Ctor for modifiable widgets, that contain a value that can be inc/decremented
    @param  displayedValue variable to link to the widget
    @param  incrementAmount Numeric amount by which the displayed value is changed when edited
  */
  /**********************************************************************/
    widget(int *displayedValue, unsigned int incrementAmount) : _value(displayedValue), _incrementSize(incrementAmount)  {_isEditable = true; }
    ~widget() {}
    bool is_editable() { return _isEditable; }
    void activate() {  activationFct(); }
    void increment() { *_value += _incrementSize; }
    void decrement() { *_value -= _incrementSize; }
};

#endif