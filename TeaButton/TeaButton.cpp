#include "TeaButton.h"

TeaButton::TeaButton(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin){
	_GPIOx = GPIOx;
	_GPIO_Pin = GPIO_Pin;
}

void TeaButton::tick(){
	uint32_t thisMs = HAL_GetTick();
	button_state = HAL_GPIO_ReadPin(_GPIOx, _GPIO_Pin);

    //Button press
	if (button_state && !button_flag){
		if (thisMs - button_timer >= debounce){
			button_flag = true;
			flags.isPress_f = true;
		}
	}
	// Button release
	if (!button_state && button_flag){
		button_flag = false;
		button_timer = HAL_GetTick();
		flags.isRelease_f = true;
	}
}

bool TeaButton::isPress(){

	TeaButton::tick();
	if(flags.isPress_f){
		flags.isPress_f = false;
		return true;
	}
	else {
		return false;
	}
}

bool TeaButton::isRelease(){

	TeaButton::tick();

	if(flags.isRelease_f){
		flags.isRelease_f = false;
		return true;
	}
	else {
		return false;
	}
}
