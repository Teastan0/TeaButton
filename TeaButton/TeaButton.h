#ifndef TEABUTTON
#define TEABUTTON

#include "main.h"

//GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)

typedef struct {
	bool isPress_f: 1;
	bool isRelease_f: 1;
} TeaButtonFlags;

class TeaButton {
public:
	TeaButton(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

	void tick();

	bool isPress();
	bool isRelease();
private:
	TeaButtonFlags flags;
	GPIO_TypeDef *_GPIOx;
	uint32_t _GPIO_Pin;

	uint8_t debounce = 60;
	uint32_t button_timer = 0;

	GPIO_PinState button_state;
	bool button_flag = false;
};


#endif
