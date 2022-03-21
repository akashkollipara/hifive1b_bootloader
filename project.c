/*
 * CYANCORE LICENSE
 * Copyrights (C) 2019, Cyancore Team
 *
 * File Name		: project.c
 * Description		: This file consists of project srouces
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

#include <status.h>
#include <stdio.h>
#include <terravisor/bootstrap.h>
#include <arch.h>
#include <driver.h>
#include <interrupt.h>
#include <platform.h>
#include <hal/clint.h>
#include <hal/gpio.h>

void no_program(void);
void plug()
{
	bootstrap();
	driver_setup_all();
	platform_print_cpu_info();
	link_interrupt(int_arch, 2, no_program);

	unsigned int i = 0;
	unsigned long long t;
	gpio_port_t bled;
	gpio_pin_alloc(&bled, PORTA, 5);
	gpio_pin_mode(&bled, out);
	gpio_pin_set(&bled);

	printf("Bootloader!\nWaiting for 2secs ...\n");
	for(i = 0; i < 40; i++)
	{
		gpio_pin_toggle(&bled);
		t = clint_read_time();
		while((clint_read_time() - t) < 1638)
			asm volatile("");
	}
	arch_di();
	void (*jmp)(void) = (void *) 0x20010000;
	gpio_pin_clear(&bled);
	jmp();
	return;
}

void no_program()
{
	printf("< x > No User program found!\n");
	while(1)
		arch_wfi();
}

void play()
{
	return;
}

