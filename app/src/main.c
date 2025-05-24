#include <zephyr/random/random.h>
#include "say_hello.h"
// Settings
static const int32_t sleep_time_ms = 1000;

int main(void)
{
    uint32_t rnd;
    double rnd_float;

    // Do forever
    while (1) 
	{

        // Print random number
        rnd = sys_rand32_get();
		printk("Random number: %u\r\n", rnd);
		say_hello();
        // Sleep
        k_msleep(sleep_time_ms);
    }

    return 0;
}