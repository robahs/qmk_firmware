#include "robosaurus.h"
#include "analog.c"
#include "math.h"
#include "pincontrol.h"
#include "pointing_device.h"
#include "print.h"
#include "report.h"
#include "timer.h"

int xPin = 1; // F0
int yPin = 0; // F1
int swPin = C7; // SW

// Set Parameters
int minAxisValue = 0;
int maxAxisValue = 1023;

int maxCursorSpeed = 8;

int precisionSpeed = 5;
int precisionThreshold = 95;

int xPolarity = -1;
int yPolarity = -1;

int cursorTimeout = 10;

int xOrigin, yOrigin;

int lastCursor = 0;

int axisCoordinate(int pin, int origin) {
    int direction;
    int distanceFromOrigin;
    int range;

    int position = analogRead(pin);

    if (origin == position) {
        return 0;
    } else  if (origin > position) {
        distanceFromOrigin = origin - position;
        range = origin - minAxisValue;
        direction = -1;
    } else {
        distanceFromOrigin = position - origin;
        range = maxAxisValue - origin;
        direction = 1;
    }

    float percent = (float)distanceFromOrigin / range;
    int coordinate = (int)(percent * 100);
    if (coordinate < 0) {
        return 0;
    }
    else if (coordinate > 100) {
        return 100 * direction;
    }
    else {
        return coordinate * direction;
    }
}

int axisToMouseComponent(int pin, int origin, int maxSpeed, int polarity) {
    int coordinate = axisCoordinate(pin, origin);

    if (coordinate == 0) {
        return 0;
    }
    else {
        int direction = (coordinate < 0) ? -1 : 1;
        if (abs(coordinate) < precisionThreshold) {
            float percent = (float)coordinate / 100;
            return percent * precisionSpeed * polarity;
        }
        else {
            return maxCursorSpeed * direction * polarity;
        }
    }
}

void pointing_device_task(void){
    report_mouse_t report;
    report.x = 0;
    report.y = 0;
    report.h = 0;
    report.v = 0;
    report.buttons = 0;

    if (timer_elapsed(lastCursor) > cursorTimeout) {
        lastCursor = timer_read();
        report.x = axisToMouseComponent(xPin, xOrigin, maxCursorSpeed, xPolarity);
        report.y = axisToMouseComponent(yPin, yOrigin, maxCursorSpeed, yPolarity);
    }

    if (digitalRead(swPin) == 0) {
        report.buttons |= MOUSE_BTN1;
    }

    pointing_device_set_report(report);
    pointing_device_send();

}

void matrix_init_kb(void) {
    timer_init();
    xOrigin = analogRead(xPin);
    yOrigin = analogRead(yPin);
    DDRC  &= ~(1<<7);
    PORTC |=  (1<<7);
}